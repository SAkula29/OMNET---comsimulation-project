//
// Copyright (C) 2014-2016 Abdalkarim Awad <abdalkarim.awad@cs.fau.de>
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// Please cite our papers:
//Abdalkarim Awad, Peter Bazan and Reinhard German, "SGsim: a Simulation Framework for Smart Grid Applications," Proceedings of the IEEE International Energy Conference, Dubrovnik, Croatia, pp. 730-736, May 2014



/*
 * this application can be used to control an element in the circuit such as LTC
 */
#undef UNICODE

#include "Controller.h"

std::ofstream outfile1("Controller-LocalValues.out", std::ofstream::out);
std::ofstream outfile2("Controller-VoltagesFromAll.out", std::ofstream::out);
std::ofstream outfile3("LVWarning.txt", std::ofstream::out);
std::ofstream ofedit1("debug_edit_command_controller.txt", std::ofstream::out);
std::ofstream ofenergy("energy.out", std::ofstream::out);
std::ofstream outfileL("Controller-LocalValues-Losses.out", std::ofstream::out);

// std::ofstream outfileB("Battery.txt", std::ofstream::out);
Define_Module(Controller);

using namespace std;

void Controller::initialize(int stage)
{
    // because of IPvXAddressResolver, we need to wait until interfaces are registered,
    // address auto-assignment takes place etc.
    if (stage != 3)
    {
        return;
    }

    sgsim = check_and_cast<SGSimInterface*>(getParentModule()->getParentModule()->getSubmodule("SGSimInterface"));

    firsttime   = true;
    numSent     = 0;
    numReceived = 0;

    WATCH(numSent);
    WATCH(numReceived);

    minvoltage    = 250;
    CVR           = false;
    energy        = 0;
    minSendTime   = 0;
    minGetTime    = 0;
    emergencyTime = 0;
    emergency     = 0;
    TotalLosses   = 0;
    NrPV          = 0;
    localPort     = par("localPort");     // 100
    destPort      = par("destPort");      // 100
    CVR           = par("CVR");           // false
    OptCVR        = par("OptCVR");        // false
    Interval      = par("Interval");      // 1s
    NrPoints      = par("NrPoints");      // def. 24
    DataPeriod    = par("DataPeriod");    // def. 1
    V1            = par("V1");            // 220
    V2            = par("V2");            // 212
    ROptCVR       = par("ROptCVR");       // false
    VProt         = par("VProt");         // true
    Lvoltage_time = 0;
    LowVoltage    = false;

    const char *     token;
    const char *     destAddrs = par("destAddresses");    // "PV1"
    cStringTokenizer tokenizer(destAddrs);

    while ((token = tokenizer.nextToken()) != NULL)
    {
        IPvXAddress addrX = IPvXAddressResolver().resolve(token);

        destAddresses.push_back(addrX);

        cout << "Controller: destAddresses " << addrX.str() << endl;

        NrPV++;
    }

    socket.setOutputGate(gate("udpOut"));
    socket.bind(localPort);

    // read optimal voltage settings from "ltc_voltage96.txt"
    if (strcmp(par("VoltageFN"), "") != 0)
    {
        std::ifstream file(par("VoltageFN"));

        for (int i = 0; i < NrPoints; i++)
        {
            file >> Voltage[i];
        }
    }

    // read optimal PV var settings from "QPV_opt96.txt"
    if (strcmp(par("OptimalVARFN"), "") != 0)
    {
        std::ifstream file1(par("OptimalVARFN"));

        for (int i = 0; i < NrPoints; i++)
        {
            for (int j = 0; j < (NrPV + 1); j++)
            {
                file1 >> QPV[i][j];
            }
        }
    }

    if (strcmp(par("Irrad"), "") != 0)
    {
        std::ifstream file(par("Irrad"));

        for (int i = 0; i < NrPoints; i++)
        {
            file >> Irrad[i];
        }
    }

    // schedule messages
    cMessage * timerMsg = new cMessage("Solve");

    scheduleAt(SimTime() + 0.52 + Interval, timerMsg);

    if (CVR)
    {    // def false
        cMessage * timerMsg = new cMessage("CVR");

        scheduleAt(SimTime() + 0.53 + Interval, timerMsg);
    }

    if (OptCVR)    // def false
    {
        cMessage * timerMsg1 = new cMessage("OptCVR");

        scheduleAt(SimTime() + 0.51, timerMsg1);
    }

    if (ROptCVR)    // def false
    {
        cMessage * timerMsg1 = new cMessage("Opt");

        scheduleAt(SimTime() + 1.0, timerMsg1);
    }

    const char * address = par("address");         // def. ""
    int          port    = par("TCPlocalport");    // def. 1000

    connectPort = par("TCPdestport");    // def. 1000

    // open sockets
    for (int i = 0; i < NrPV; i++)
    {
        tcpsocket[i].setOutputGate(gate("tcpOut"));
        tcpsocket[i].setDataTransferMode(TCP_TRANSFER_OBJECT);
        tcpsocket[i].bind(address[0] ? IPvXAddress(address) : IPvXAddress(), port);
        tcpsocket[i].connect(destAddresses[i], connectPort);
    }

    const char * name;

    name = (char *) (getParentModule() -> getFullName());

    BatSocket.setOutputGate(gate("tcpOut"));
    BatSocket.setDataTransferMode(TCP_TRANSFER_OBJECT);

    cout << "Controller: ownAddress " << IPvXAddressResolver().resolve(name).str() << endl;

    BatSocket.bind(*name ? IPvXAddressResolver().resolve(name) : IPvXAddress(), port + NrPV);

    IPvXAddress destination;

    IPvXAddressResolver().tryResolve(par("BatAddress"), destination);    // def. "BAT1"

    cout << "Controller: Bat1 address " << destination.str() << endl;

    if (destination.isUnspecified())
    {
        // cout << "Controller: cannot resolve destination address: " << (const char) par("BatAddress") << endl;
    }
    else
    {
        BatSocket.connect(destination, connectPort);

        // cout << "Controller: connected to destination address: " << destination << endl;
    }
}

Controller::~Controller()
{
}

void Controller::finish()
{
    ofenergy << "Energy= " << energy << " TotalLosses= " << TotalLosses << " TotalLineLosses= " << TotalLineLosses
             << endl;

    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);

    for (int i = 0; i < NrPV; i++)
    {
        tcpsocket[i].close();
    }
}

void Controller::CallDSS()
{
    bubble("Solving OpenDSS!");

    AllValues   allvalues;
    std::string Element      = par("Element");    // "line.Line01"
    char *      activeobject = new char[Element.length() + 1];

    strcpy(activeobject, Element.c_str());

    allvalues = sgsim->getValuesActiveObject(activeobject);  // retrieve values from "line.Line01"

    double Losses     = sgsim->getTotalLosses();    // retrieve total network losses
    double LineLosses = sgsim->getLineLosses();     // retrieve line losses!
    double power1     = allvalues.P1 + allvalues.P2 + allvalues.P3;

    currentVoltage  = sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i);
    energy          = energy + (allvalues.P1 + allvalues.P2 + allvalues.P3) * (Interval / 3600.0);
    TotalLosses     = TotalLosses + (Losses) *(Interval / 3600.0);
    TotalLineLosses = TotalLineLosses + (LineLosses) *(Interval / 3600.0);

    outfile1 << simTime() << "\t" << allvalues.P1 + allvalues.P2 + allvalues.P3 << "\t" << allvalues.P1 << "\t"
             << allvalues.P2 << "\t" << allvalues.P3 << "\t" << allvalues.Q1 << "\t" << allvalues.Q2 << "\t"
             << allvalues.Q3 << "\t" << allvalues.V1r << "\t" << allvalues.V1i << "\t" << allvalues.I1r << "\t"
             << allvalues.I1i << "\t" << sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i)
             << endl;
    outfileL << simTime() << "\t" << allvalues.P1 + allvalues.P2 + allvalues.P3 << "\t" << Losses << "\t"
             << LineLosses << "\t" << allvalues.Q1 + allvalues.Q2 + allvalues.Q3 << "\t"
             << sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i) << endl;

    if (ev.isGUI())
    {
        char buf[40];

        sprintf(buf, "E: %04f\n V: %04f\n P: %04f", energy, currentVoltage, power1);
        getParentModule() -> getDisplayString().setTagArg("t", 0, buf);
    }

    if ((simTime() - emergencyTime) > 10 * Interval)
    {
        emergency = 0;
    }
}

void Controller::handleMessage(cMessage * msg)
{
    ev << "Controller: I got a message Name=" << msg -> getName() << endl;

    if (msg -> isSelfMessage())                 // Only regard "solve" self-messages ignore the rest
    {
        if (strcmp(msg -> getName(), "Solve") == 0)
        {
            CallDSS();

            simtime_t d = simTime() + Interval;

            if ((stopTime == 0) || (d < stopTime))
            {
                scheduleAt(d, msg);
            }
            else
            {
                delete msg;
            }
        }
    }
    else if (msg -> getKind() == UDP_I_DATA)    // message name = Voltage
    {
        // process incoming packet
        processPacket(PK(msg));
    }
    else if (msg -> getKind() == UDP_I_ERROR)
    {
        EV << "Ignoring UDP error report\n";

        delete msg;
    }
    else if (msg -> getKind() == TCP_I_PEER_CLOSED)
    {
        // close the socket
        msg -> setName("close");
        msg -> setKind(TCP_C_CLOSE);
        send(msg, "tcpOut");
    }
    else if ((msg -> getKind() == TCP_I_DATA) || (msg -> getKind() == TCP_I_URGENT_DATA))
    {
        delete msg;
    }
    else
    {
        // must be data or some kind of indication -- can be dropped
        delete msg;
    }
}

void Controller::processPacket(cPacket * pk)
{
    numReceived++;

    SmartData * tmsg = check_and_cast<SmartData *>(pk);

    // cout<<"Controller: I got something: "<<simTime()<< "    From"<<tmsg->getSource()<<"  P= "<<tmsg->getAPower()<<"   V= "<<tmsg->getVoltage()<<endl;
    // cout<<"Controller: I got something from "<<tmsg->getSource()<<"  P= "<<tmsg->getAPower()<<"   V= "<<tmsg->getVoltage()<<endl;

    // cout << "VProt: " << VProt << endl;
    if (strcmp(tmsg -> getName(), "Voltage") == 0)
    {
        if ((tmsg -> getVoltage() > 249) && (VProt))    // above threshold (249) and voltage protection (?)
        {
            // cout<<"Controller: send control battery Charge (Voltage)"<<tmsg->getVoltage()<<endl;//<<(const char)par("BatAddress")<<endl;
            BATControl * Controlmessage = new BATControl("BATControlmessage");

            Controlmessage -> setType(CONT_CHARGE);
            Controlmessage -> setKw(15);
            Controlmessage -> setByteLength(100);
            BatSocket.setDataTransferMode(TCP_TRANSFER_OBJECT);
            BatSocket.send(Controlmessage);
        }

        if ((tmsg -> getVoltage() < 244) && (VProt)
                && (LowVoltage == false))    // below threshold(244) and VProt LowVoltage = false -> set it to true
        {
            Lvoltage_time = simTime();
            LowVoltage    = true;
        }

        if ((tmsg -> getVoltage() > 244) && (VProt)
                && (LowVoltage
                    == true))    // above threshold(244) and VProt and it was LowVoltage before -> set it to false
        {
            Lvoltage_time = simTime();
            LowVoltage    = false;
        }

        if ((tmsg -> getVoltage() < 244) && (VProt) && ((simTime() - Lvoltage_time) > 5)
                && LowVoltage)    // below threshold and VProt and last change > 5s and Low Voltage set battery to ifle
        {
            // cout<<"Controller: send control battery Idle (Voltage)" << tmsg->getVoltage() << endl;//<<(const char)par("BatAddress")<<endl;
            BATControl * Controlmessage = new BATControl("BATControlmessage");

            Controlmessage -> setType(CONT_IDLE);
            Controlmessage -> setKw(15);
            Controlmessage -> setByteLength(100);
            BatSocket.setDataTransferMode(TCP_TRANSFER_OBJECT);
            BatSocket.send(Controlmessage);
        }

        delete pk;
    }
}
