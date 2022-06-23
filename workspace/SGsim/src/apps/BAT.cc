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
 * this application can be used to control a battery, it should have the same name in dss file
 */
#undef UNICODE

#include "BAT.h"

std::ofstream ofBAT1("Battery-values.out", std::ofstream::out);
std::ofstream ofeditbat1("debug_edit_command_bat.txt", std::ofstream::out);

Define_Module(BAT);

using namespace std;

void BAT::initialize(int stage)
{
    // because of IPvXAddressResolver, we need to wait until interfaces are registered,
    // address auto-assignment takes place etc.
    if (stage != 3)
    {
        return;
    }

    sgsim =  check_and_cast<SGSimInterface*>(getParentModule()->getParentModule()->getSubmodule("SGSimInterface"));

    numSent        = 0;
    numReceived    = 0;
    nextSendTime   = 0.81;
    var            = 0;

    WATCH(numSent);
    WATCH(numReceived);

    Interval  = par("Interval");
    KWR       = par("KWR");
    localPort = par("localPort");
    destPort  = par("destPort");

    socket.setOutputGate(gate("udpOut"));
    socket.bind(localPort);

    const char * localAddress = par("localAddress");
    int          tcplocalPort = par("TCPlocalPort");

    tcpsocket.setOutputGate(gate("tcpOut"));
    tcpsocket.readDataTransferModePar(*this);
    tcpsocket.setDataTransferMode(TCP_TRANSFER_OBJECT);
    tcpsocket.bind(localAddress[0] ? IPvXAddress(localAddress) : IPvXAddress(), tcplocalPort);
    tcpsocket.listen();

    cMessage * solveMsg = new cMessage("Solve");
    cMessage * setModeMsg = new cMessage("setMode");

    scheduleAt(simTime() + nextSendTime, solveMsg);
    scheduleAt(SimTime() + 0.2, setModeMsg);
}

void BAT::handleMessage(cMessage * msg)
{
    ev << "BAT: I got a message Name=" << msg -> getName() << endl;

    char * name = (char *) (getParentModule() -> getFullName());

    if (msg -> isSelfMessage())
    {
        if (strcmp(msg -> getName(), "setMode") == 0)
        {
            // if (VVC)
            if ((simTime() > par("startcharge")) && (simTime() < par("stopcharge")))
            {
                EditParameters(0, 0, CHARGING);
            }
            else if ((simTime() > par("startdischarge")) && (simTime() < par("stopdischarge")))
            {
                EditParameters(0, 0, DISCHARGING);
            }

            // else
            // EditParameters(0,0,IDLING);
        }

        if (strcmp(msg -> getName(), "Solve") == 0)
        {
            AllValues allvalues;
            char *    activeobject;

            std::string str  = std::string("Storage.") + name;
            char *      cstr = new char[str.length() + 1];

            strcpy(cstr, str.c_str());

            activeobject = cstr;
            allvalues    = sgsim->getValuesActiveObject(activeobject);

            double      voltage       = sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i);
            std::string Element1      = name;
            char *      activeobject1 = new char[Element1.length() + 1];

            strcpy(activeobject1, Element1.c_str());

            double B_energy = sgsim->getEnergyActiveObject(activeobject1);

            ofBAT1 << simTime() << "\t" << activeobject << "\t" << B_energy << "\t"
                   << allvalues.P1 + allvalues.P2 + allvalues.P3 << "\t"
                   << allvalues.Q1 + allvalues.Q2 + allvalues.Q3 << "\t"
                   << sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i) << endl;

            if (ev.isGUI())
            {
                char buf[40];

                sprintf(buf, "V: %04f\n E: %04f", voltage, B_energy);
                getParentModule() -> getDisplayString().setTagArg("t", 0, buf);
            }

            SmartData * DataMessage;

            if (voltage < 212)
            {
                DataMessage = new SmartData("LVWarning");      // low voltage Warning

                DataMessage -> setSource(getParentModule() -> getFullName());
                DataMessage -> setVoltage(voltage);
                DataMessage -> setTime(simTime());

                cPacket *   payload  = DataMessage;
                IPvXAddress destAddr = IPvXAddressResolver().resolve(par("destAddresses"));

                socket.sendTo(payload, destAddr, destPort);

                nextSendTime = nextSendTime + Interval * 4;    // update sending time
            }

            if (simTime() >= nextSendTime) {
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
        cout << name << "BAT: I got TCP message" << endl;

        if ((strcmp("PVControl", msg -> getClassName()) == 0))
        {
            PVControl * controlmessage = dynamic_cast<PVControl *>(msg);

            cout << "BAT: I got TCP message, Var=" << controlmessage -> getVar() << endl;

            if (controlmessage -> getType() == CONT_VAR)
            {
                var = controlmessage -> getVar();

                EditParameters(0, var, CONT_VAR);
            }
        }

        if ((strcmp("BATControl", msg -> getClassName()) == 0))
        {
            BATControl * controlmessage = dynamic_cast<BATControl *>(msg);

            cout << "BAT: I got TCP message, Var=" << controlmessage -> getVar() << endl;

            if (controlmessage -> getType() == CONT_DISCHARGE)
            {
                cout << "BAT: I got TCP message, Type=" << controlmessage -> getType() << endl;

                var = controlmessage -> getVar();

                double kw = controlmessage -> getKw();

                if (kw > KWR)
                {
                    kw = KWR;
                }

                cout << "BAT: " << name << " I got TCP message kw=" << kw << endl;

                EditParameters(kw, var, DISCHARGING);
            }

            if (controlmessage -> getType() == CONT_CHARGE)
            {
                cout << "BAT: I got TCP message, Type=" << controlmessage -> getType() << endl;

                var = controlmessage -> getVar();

                double kw = controlmessage -> getKw();

                if (kw > KWR)
                {
                    kw = KWR;
                }

                cout << name << "BAT: I got TCP message kw=" << kw << endl;

                EditParameters1(kw, 0, CHARGING);
            }

            if (controlmessage -> getType() == CONT_IDLE)
            {
                cout << "BAT: I got TCP message, Type=" << controlmessage -> getType() << endl;

                var = controlmessage -> getVar();

                double kw = controlmessage -> getKw();

                if (kw > KWR)
                {
                    kw = KWR;
                }

                cout << name << "BAT: I got TCP message kw=" << kw << endl;

                EditParameters1(kw, 0, IDLING);
            }
        }

        delete msg;
    }
    else
    {
        cout << "BAT: deleting a message" << msg -> getKind() << endl;

        delete msg;
    }

    // delete msg;
}

BAT::~BAT()
{
}

void BAT::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
}

void BAT::EditParameters(double kw,
                         double kvar,
                         int    Control)
{
    char * name = (char *) (getParentModule() -> getFullName());

    string str;

    if (Control == IDLING)
    {
        str = std::string("Storage.") + name + ".state=IDLING";
    }
    else if (Control == CHARGING)
    {
        str = std::string("Storage.") + name + ".state=CHARGING";
    }
    else if (Control == DISCHARGING)
    {
        str = std::string("Storage.") + name + ".state=DISCHARGING";
    }

    char * cstr = new char[str.length() + 1];

    strcpy(cstr, str.c_str());

    cout << simTime() << "BAT mode:" << cstr << endl;
    ofeditbat1 << simTime() << " Battery mode:" << cstr << endl;

    sgsim->runCommand(cstr);
}

void BAT::EditParameters1(double kw,
                          double kvar,
                          int    Control)
{
    cout << simTime() << "BAT: I got TCP message kw=" << kw << endl;

    char * name;

    name = (char *) (getParentModule() -> getFullName());

    string str;
    float  FloatValue = (kw / KWR) * 100;

    std::ostringstream ss;

    ss << FloatValue;

    std::string s(ss.str());

    float FloatValue1 = kvar;

    std::ostringstream ss1;

    ss1 << FloatValue1;

    std::string s1(ss1.str());

    if (Control == IDLING)
    {
        str = std::string("Storage.") + name + ".state=IDLING" + " kw= " + s + " kvar= " + s1;;
    }

    if (Control == CHARGING)
    {
        str = std::string("Storage.") + name + ".state=CHARGING" + " %CHARGE= " + s + " kvar= " + s1;;
    }

    if (Control == DISCHARGING)
    {
        str = std::string("Storage.") + name + ".state=DISCHARGING" + " %DISCHARGE= " + s + " kvar= " + s1;;
    }

    char * cstr = new char[str.length() + 1];

    strcpy(cstr, str.c_str());

    cout << simTime() << "BAT mode:" << cstr << endl;
    ofeditbat1 << simTime() << "BAT CONT mode:" << cstr << endl;

    sgsim->runCommand(cstr);
}
