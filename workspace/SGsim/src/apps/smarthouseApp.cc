//
// Copyright (C) 2014 Abdalkarim Awad <abdalkarim.awad@cs.fau.de>
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
//



/*
 * this module controls a load (e.g., a house)
 */
#undef UNICODE

#include "smarthouseApp.h"

std::ofstream ofhouses("Voltage-All-Houses.out", std::ofstream::out);
std::ofstream ofedit("debug_edit_commands.txt", std::ofstream::out);

Define_Module(smarthouseApp);

using namespace std;

void smarthouseApp::initialize(int stage)
{
    if (stage != 3)
    {
        return;
    }

    sgsim = check_and_cast<SGSimInterface*>(getParentModule()->getParentModule()->getSubmodule("SGSimInterface"));

    numSent     = 0;
    numReceived = 0;

    WATCH(numSent);
    WATCH(numReceived);

    Interval   = par("Interval");
    NrPoints   = par("NrPoints");
    DataPeriod = par("DataPeriod");
    firsttime  = true;
    localPort  = par("localPort");
    destPort   = par("destPort");

    socket.setOutputGate(gate("udpOut"));
    socket.bind(localPort);

    cMessage * timerMsg = new cMessage("Solve");

    scheduleAt(simTime() + 0.8, timerMsg);

    nextSendTime = 0.8;

    // read load (kw)
    if (strcmp(par("Demandkw"), "") != 0)
    {
        std::ifstream file(par("Demandkw"));

        for (int i = 0; i < NrPoints; i++)
        {
            file >> Demandkw[i];
        }
    }

    // read load (kvar)
    if (strcmp(par("Demandkvar"), "") != 0)
    {
        std::ifstream file(par("Demandkvar"));

        for (int i = 0; i < NrPoints; i++)
        {
            file >> Demandkvar[i];
        }
    }

    if ((strcmp(par("Demandkw"), "") != 0) || (strcmp(par("Demandkvar"), "") != 0))
    {
        cMessage * timerMsg = new cMessage("setData");

        scheduleAt(SimTime() + 0.1, timerMsg);
    }
}

void smarthouseApp::handleMessage(cMessage * msg)
{
    ev << "I got a message Name=" << msg -> getName() << endl;

    if (msg -> isSelfMessage())
    {
        if (strcmp(msg -> getName(), "setData") == 0)
        {
            EditParameters(0, 0);
        }

        if (strcmp(msg -> getName(), "Solve") == 0)
        {
            AllValues allvalues;
            char *    activeobject;
            char *    name;

            name = (char *) (getParentModule() -> getFullName());

            std::string str  = std::string("Load.") + name;
            char *      cstr = new char[str.length() + 1];

            strcpy(cstr, str.c_str());

            activeobject = cstr;
            allvalues    = sgsim->getValuesActiveObject(activeobject);

            double aPower = allvalues.P1 + allvalues.P2 + allvalues.P3;
            double rPower = allvalues.Q1 + allvalues.Q2 + allvalues.Q3;

            cout<<"SmarthouseApp:  Voltage at: "<<activeobject<<"\t"<<"Power: "<<allvalues.P1+allvalues.P2+allvalues.P3<<"Voltage: "<<sqrt(allvalues.V1r*allvalues.V1r+allvalues.V1i*allvalues.V1i)<<endl;
            if (strcmp("NH1", par("NH")) == 0)
            {
                ofhouses << simTime() << "\t" << activeobject << "\t" << aPower << "\t"
                         << sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i) << endl;
            }

            double      power1  = allvalues.P1 + allvalues.P2 + allvalues.P3;
            double      voltage = sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i);
            SmartData * DataMessage;

            if (ev.isGUI())
            {
                char buf[40];

                sprintf(buf, "V: %04f\n P: %04f", voltage, power1);
                getParentModule() -> getDisplayString().setTagArg("t", 0, buf);
            }

            if ((voltage < 212))
            {
                DataMessage = new SmartData("LVWarning");      // low voltage Warning

                DataMessage -> setSource(getParentModule() -> getFullName());
                DataMessage -> setVoltage(voltage);
                DataMessage -> setTime(simTime());
                DataMessage -> setAPower(aPower);
                DataMessage -> setRPower(rPower);

                cPacket *   payload  = DataMessage;
                IPvXAddress destAddr = IPvXAddressResolver().resolve(par("destAddresses"));

                socket.sendTo(payload, destAddr, destPort);

                nextSendTime = nextSendTime + Interval * 4;    // update sending time
            }

            if ((simTime() >= nextSendTime))
            {
                DataMessage = new SmartData("Voltage");

                DataMessage -> setSource(getParentModule() -> getFullName());
                DataMessage -> setVoltage(voltage);
                DataMessage -> setTime(simTime());
                DataMessage -> setAPower(aPower);
                DataMessage -> setRPower(rPower);

                cPacket *   payload  = DataMessage;
                IPvXAddress destAddr = IPvXAddressResolver().resolve(par("destAddresses"));

                socket.sendTo(payload, destAddr, destPort);

                nextSendTime = nextSendTime + Interval * 4;
            }
        }

        simtime_t d = simTime() + Interval;                        // par("sendInterval").doubleValue();

        if ((stopTime == 0) || (d < stopTime))
        {
            scheduleAt(d, msg);
        }
        else
        {
            delete msg;
        }
    }

    // delete msg;
}

smarthouseApp::~smarthouseApp()
{
}

void smarthouseApp::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
}

void smarthouseApp::EditParameters(double kw,
                                   double kvar)
{
    int    i = 0;
    double x, y;

    x = SIMTIME_DBL(simTime());
    y = x / (DataPeriod);

    // y=x;
    i                   = (int) (y);
    kw                  = Demandkw[i];
    kvar                = Demandkvar[i];

    cout << "SmarthouseApp:   Demandkw[i]: " << Demandkw[i] << "i=" << i << "y=" << y << "DataPeriod=" << DataPeriod << endl;

    char * name;

    name = (char *) (getParentModule() -> getFullName());

    float FloatValue = kw;

    std::ostringstream ss;

    ss << FloatValue;

    std::string s(ss.str());

    float FloatValue1 = kvar;

    std::ostringstream ss1;

    ss1 << FloatValue1;

    std::string s1(ss1.str());

    std::string str  = std::string("edit load.") + name + " kw= " + s + " kvar= " + s1;
    char *      cstr = new char[str.length() + 1];

    strcpy(cstr, str.c_str());

    // cout<<simTime()<<"Change active and reactive power with command:"<<cstr<<endl;
    ofedit << simTime() << " House:Change active and reactive power with command:" << cstr << endl;

    sgsim->runCommand(cstr);
}

