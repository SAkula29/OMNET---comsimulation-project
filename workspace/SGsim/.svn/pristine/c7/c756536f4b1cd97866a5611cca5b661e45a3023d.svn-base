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
 * used to control a DER (e.g., PV)
 */
#undef UNICODE

#include "DERApp.h"

std::ofstream ofDER("Voltage-All-DER.out", std::ofstream::out);
std::ofstream ofeditder("debug_edit_command_DER.txt", std::ofstream::out);

Define_Module(DERApp);

using namespace std;

void DERApp::initialize(int stage)
{
    // because of IPvXAddressResolver, we need to wait until interfaces are registered,
    // address auto-assignment takes place etc.
    if (stage != 3)
    {
        return;
    }

    sgsim = check_and_cast<SGSimInterface*>(getParentModule()->getParentModule()->getSubmodule("SGSimInterface"));

    numSent     = 0;
    numReceived = 0;

    WATCH(numSent);
    WATCH(numReceived);

    Interval   = par("Interval");      // 1s
    firsttime  = true;
    localPort  = par("localPort");     // 100
    destPort   = par("destPort");      // 100
    NrPoints   = par("NrPoints");      // def. 24
    DataPeriod = par("DataPeriod");    // def. 1
    nextSendTime = 0.81;
    var          = 0;

    socket.setOutputGate(gate("udpOut"));
    socket.bind(localPort);

    const char * localAddress = par("localAddress");    // def. ""
    int          tcplocalPort = par("TCPlocalPort");    // def. 1000

    tcpsocket.setOutputGate(gate("tcpOut"));
    tcpsocket.readDataTransferModePar(*this);
    tcpsocket.setDataTransferMode(TCP_TRANSFER_OBJECT);
    tcpsocket.bind(localAddress[0] ? IPvXAddress(localAddress) : IPvXAddress(), tcplocalPort);
    tcpsocket.listen();


    if (strcmp(par("Irrad"), "") != 0)    // "PVirrad93pu.txt"
    {
        std::ifstream file(par("Irrad"));
        for (int i = 0; i < NrPoints; i++)
        {
            file >> Irrad[i];
        }

        cMessage * setDataMsg = new cMessage("setData");
        scheduleAt(SimTime() + 0.2, setDataMsg);
    }

    cMessage * solveMsg = new cMessage("Solve");
    scheduleAt(simTime() + nextSendTime, solveMsg);



}

void DERApp::handleMessage(cMessage * msg)
{
    char * name = (char *) (getParentModule() -> getFullName());

    if (msg -> isSelfMessage())
    {
        if (strcmp(msg -> getName(), "setData") == 0)
        {
            EditParameters(0, var, 0);
        }

        if (strcmp(msg -> getName(), "Solve") == 0)
        {
            AllValues allvalues;
            char *    activeobject;

            std::string str  = std::string("PVsystem.") + name;
            char *      cstr = new char[str.length() + 1];
            strcpy(cstr, str.c_str());
            activeobject = cstr;

            // get_value_active_object(PVsystem.PVx)
            allvalues = sgsim->getValuesActiveObject(activeobject);


            cout<<"DERApp: Smart house App Voltage at: "<<activeobject<<"\t"<<"Power: "<<allvalues.P1+allvalues.P2+allvalues.P3<<"Voltage: "<<sqrt(allvalues.V1r*allvalues.V1r+allvalues.V1i*allvalues.V1i)<<endl;
            double voltage = sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i);
            double power1  = allvalues.P1 + allvalues.P2 + allvalues.P3;

            ofDER << simTime() << "\t" << activeobject << "\t" << power1 << "\t"
                  << allvalues.Q1 + allvalues.Q2 + allvalues.Q3 << "\t" << voltage << endl;

            if (ev.isGUI())
            {
                char buf[40];

                sprintf(buf, "V: %04f\n P: %04f", voltage, power1);
                getParentModule() -> getDisplayString().setTagArg("t", 0, buf);
            }

            SmartData * DataMessage;

            if ((voltage < 212))
            {
                DataMessage = new SmartData("LVWarning");                   // low voltage Warning

                DataMessage -> setSource(getParentModule() -> getFullName());
                DataMessage -> setVoltage(voltage);
                DataMessage -> setTime(simTime());

                cPacket *   payload  = DataMessage;
                IPvXAddress destAddr =
                    IPvXAddressResolver().resolve(par("destAddresses"));    // message to CVRController

                socket.sendTo(payload, destAddr, destPort);

                nextSendTime = nextSendTime + Interval * 4;    // update sending time
            }

            if ((simTime() >= nextSendTime))
            {
                DataMessage = new SmartData("Voltage");

                DataMessage -> setSource(getParentModule() -> getFullName());
                DataMessage -> setVoltage(voltage);
                DataMessage -> setTime(simTime());

                cPacket *   payload  = DataMessage;
                IPvXAddress destAddr = IPvXAddressResolver().resolve(par("destAddresses"));

                socket.sendTo(payload, destAddr, destPort);

                nextSendTime = nextSendTime + Interval * 4;
            }
        }

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
    else if (msg -> getKind() == TCP_I_PEER_CLOSED)
    {
        // we close too
        msg -> setName("close");
        msg -> setKind(TCP_C_CLOSE);
        send(msg, "tcpOut");
    }
    else if ((msg -> getKind() == TCP_I_DATA) || (msg -> getKind() == TCP_I_URGENT_DATA))
    {
        if ((strcmp("PVControl", msg -> getClassName()) == 0))
        {
            PVControl * controlmessage = dynamic_cast<PVControl *>(msg);
            if (controlmessage -> getType() == CONT_VAR)
            {
                var = controlmessage -> getVar();
                EditParameters(0, var, CONT_VAR);
            }
        }

        delete msg;
    }
    else
    {
        //cout << "deleting a message" << msg -> getKind() << endl;

        delete msg;
    }
}

DERApp::~DERApp()
{
}

void DERApp::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
}

void DERApp::EditParameters(double kw,
                            double kvar,
                            int    Control)
{
    double x = SIMTIME_DBL(simTime());
    double y = x / (DataPeriod);
    int    i = (int) (y);
    double irrad = Irrad[i];
    double kva = par("KVA");
    char * name = (char *) (getParentModule() -> getFullName());

    std::ostringstream ss;
    std::ostringstream ss1;
    std::ostringstream ss2;

    ss  << irrad;
    ss1 << kvar;
    ss2 << kva;

    std::string s(ss.str());
    std::string s1(ss1.str());
    std::string s2(ss2.str());

    std::string str  = std::string("edit PVsystem.") + name + " KVA=" + s2 + " irrad=" + s + " kvar= " + s1;
    char *      cstr = new char[str.length() + 1];

    strcpy(cstr, str.c_str());

    cout<<simTime()<<"DERApp: ChangeN PV active and reactive power with command:"<<cstr<<endl;
    ofeditder << simTime() << " DERN: Change PV active and reactive power with command:" << cstr << endl;

    cout << "DERApp: sgsim->runCommand( " << cstr  << " )" << endl;

    sgsim->runCommand(cstr);
}
