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
// Reference:
//Abdalkarim Awad, Peter Bazan and Reinhard German, "SGsim: a Simulation Framework for Smart Grid Applications," Proceedings of the IEEE International Energy Conference, Dubrovnik, Croatia, pp. 730-736, May 2014



/*
 * this module obtains the data from opendss and send it to PDC
 */
#undef UNICODE

#include "PMUApp.h"

std::ofstream ofs1("allvalues1-PMU.out", std::ofstream::out);

// std::ofstream ofs2("allvalues2.txt", std::ofstream::out);
// std::ofstream ofsc;

Define_Module(PMUApp);

using namespace std;

PMUApp::~PMUApp()
{
}

void PMUApp::initialize(int stage)
{
    if (stage != 3)
    {
        return;
    }

    sgsim = check_and_cast<SGSimInterface*>(getParentModule()->getParentModule()->getSubmodule("SGSimInterface"));

    firsttime   = true;
    numSent     = 0;
    numReceived = 0;
    stopTime    = 0;

    WATCH(numSent);
    WATCH(numReceived);

    localPort = par("localPort");
    destPort  = par("destPort");

    socket.setOutputGate(gate("udpOut"));
    socket.bind(localPort);

    cMessage * timerMsg = new cMessage("Solve");

    scheduleAt(SimTime() + 0.7, timerMsg);
}

void PMUApp::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
}

void PMUApp::runDSS()
{
    bubble("Solving OpenDSS!");

    // cout<<"run OpenDSS"<<endl;

    AllValues allvalues;

    std::string Element      = par("Element");
    char *      activeobject = new char[Element.length() + 1];

    strcpy(activeobject, Element.c_str());

    // Return the electricity measurements of activeobject (Element = line.Line01)
    allvalues = sgsim->getValuesActiveObject(activeobject);

    cout << "PMUApp:  allvalues: " << endl;
    cout << allvalues.V1r << endl;
    cout << allvalues.V1i << endl;
    cout << allvalues.V2r << endl;
    cout << allvalues.V2i << endl;
    cout << allvalues.V3r << endl;
    cout << allvalues.V3i << endl;
    cout << allvalues.I1r << endl;
    cout << allvalues.I1i << endl;
    cout << allvalues.I2r << endl;
    cout << allvalues.I2i << endl;
    cout << allvalues.I3r << endl;
    cout << allvalues.I3i << endl;
    cout << allvalues.P1 << endl;
    cout << allvalues.Q1 << endl;
    cout << allvalues.P2 << endl;
    cout << allvalues.Q2 << endl;
    cout << allvalues.P3 << endl;
    cout << allvalues.Q3 << endl;
    ofs1 << simTime() << "\t" << allvalues.P1 + allvalues.P2 + allvalues.P3 << "\t" << allvalues.P1 << "\t"
         << allvalues.P2 << "\t" << allvalues.P3 << "\t" << allvalues.Q1 << "\t" << allvalues.Q2 << "\t"
         << allvalues.Q3 << "\t" << allvalues.V1r << "\t" << allvalues.V1i << "\t" << allvalues.I1r << "\t"
         << allvalues.I1i << "\t" << sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i) << endl;
    cout << "Voltage at: " << activeobject << "\t" << "Power: " << allvalues.P1 + allvalues.P2 + allvalues.P3
         << "Voltage: " << sqrt(allvalues.V1r * allvalues.V1r + allvalues.V1i * allvalues.V1i) << endl;

    unsigned char   config_frm[MAX_STRING_SIZE];
    unsigned char   data_frame[MAX_STRING_SIZE];
    createPMUFrames createpmu;

    // if runDSS is called for the first time, a conf self message is scheduled with the module name and the module id
    if (firsttime)
    {
        confmsg = new pmumessage("confmsg");

        int CFindx = createpmu.createconfigframe(config_frm, (char *) getParentModule() -> getFullName(),
                         par("id"));

        for (int i = 0; i < CFindx; i++)
        {
            confmsg -> setData_frm(i, config_frm[i]);
        }

        confmsg -> setCtime(simTime());
        confmsg -> setPmusize(CFindx);
        scheduleAt(simTime(), confmsg);    // send configuration

        firsttime = false;
    }

    // in each case a data msg is scheduled that contains the values retrieved by the system paramaters from the text file
    datamsg = new pmumessage("datamsg");

    int Dindex = createpmu.createdataframe(data_frame, allvalues, par("id"));

    for (int i = 0; i < Dindex; i++)
    {
        datamsg -> setData_frm(i, data_frame[i]);
    }

    datamsg -> setCtime(simTime());
    datamsg -> setPmusize(Dindex);
    scheduleAt(simTime(), datamsg);    // send data frame
}

void PMUApp::handleMessage(cMessage * msg)
{
    ev << "PMUApp: I got a message Name=" << msg -> getName() << endl;

    if (msg -> isSelfMessage())
    {
        if (strcmp(msg -> getName(), "Solve") == 0)           // self message =  solve
        {
            runDSS();

            simtime_t d = simTime() + par("Interval");

            if ((stopTime == 0) || (d < stopTime))
            {
                scheduleAt(d, msg);
            }
            else
            {
                delete msg;
            }
        }
        else if (strcmp(msg -> getName(), "confmsg") == 0)    // self message =  confmsg, then forward tmsg
        {
            // cout << "sensor received conf" << endl;
            pmumessage * tmsg = check_and_cast<pmumessage *>(msg);

            forwardmessage(tmsg);
        }
        else if (strcmp(msg -> getName(), "datamsg") == 0)    // self message = datamsg, then also forward tmsg
        {
            // cout << "sensor received data" << endl;
            pmumessage * tmsg = check_and_cast<pmumessage *>(msg);

            forwardmessage(tmsg);
        }
    }
    else if (msg -> getKind() == UDP_I_DATA)     // if message is udp-data do nothing?!
    {
    }
    else if (msg -> getKind() == UDP_I_ERROR)    // if message is udp-error ignore it and delete
    {
        EV << "Ignoring UDP error report\n";

        delete msg;
    }
    else
    {
        error("Unrecognized message (%s)%s", msg -> getClassName(), msg -> getName());
    }

    if (ev.isGUI())
    {
        char buf[40];

        sprintf(buf, "rcvd: %d pks\nsent: %d pks", numReceived, numSent);
        getDisplayString().setTagArg("t", 0, buf);
    }
}

void PMUApp::forwardmessage(pmumessage * msg)
{
    // cout<<"Forwarding"<<endl;
    numSent++;
    msg -> setHops(msg -> getHops() + 1);

    cPacket * data = new cPacket("data");

    data -> setByteLength(1024);
    data -> encapsulate(msg);

    ev << data -> getByteLength() << endl;

    IPvXAddress destAddr;
    char        msgName[32];
    int         counter = 0;

    sprintf(msgName, "UDPBasicAppData-%d", counter++);
    std::vector<IPvXAddress> destAddresses;

    cPacket *    payload   = new cPacket(msgName);
    const char * destAddrs = par("PMUdestAddress");

    // cout<<"destAddrs"<<destAddrs<<"end"<<endl;
    cStringTokenizer tokenizer(destAddrs);
    const char *     token;

    while ((token = tokenizer.nextToken()) != NULL)
    {
        destAddresses.push_back(IPvXAddressResolver().resolve(token));
    }

    destAddr = destAddresses[0];

    cout << "PMUAPP: destAddr " << destAddr << endl;

    socket.sendTo(data, destAddr, destPort);

    delete payload;
}
