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
 * this module solves the circuit and increment the time such that the opendss and omnet are synchronized
 */
#undef UNICODE

#include "Mainsolver.h"

Define_Module(Mainsolver);

using namespace std;

void Mainsolver::initialize(int stage)
{
    if (stage != 3)
    {
        return;
    }

    cerr << getParentModule()->getSubmodule("SGSimInterface")->getName() << endl;

    sgsim = check_and_cast<SGSimInterface*>(getParentModule()->getSubmodule("SGSimInterface"));

    firsttime   = true;
    numSent     = 0;
    numReceived = 0;

    WATCH(numSent);
    WATCH(numReceived);

    Interval = par("Interval");

    std::string filename = par("File");    // retrieve the OpenDSS file (example_5nodes.dss)
    std::string str      = std::string("compile ") + filename;
    char *      cstr     = new char[str.length() + 1];

    strcpy(cstr, str.c_str());
    sgsim->runCommand(cstr);             // compiles the OpenDSS file

    float FloatValue = Interval;

    std::ostringstream ss;                 // output stream for strings

    ss << FloatValue;                      // push the communication interval into the stream

    std::string s(ss.str());

    std::string str1 = std::string("Set Mode=Time Stepsize=") + s
                       + "s Loadshapeclass=Daily";    // create command for open dss (Set Mode=Time Stepsize=0.04s ...)
    char * cstr1 = new char[str1.length() + 1];

    strcpy(cstr1, str1.c_str());

    sgsim->runCommand(cstr1);               // run command

    FloatValue = 30.0 + Interval;

    std::ostringstream ss1;

    ss1 << FloatValue;

    std::string s1(ss1.str());

    str  = std::string("set sec=") + s1;      // create 2nd command (set sec=30.04)
    cstr = new char[str.length() + 1];

    strcpy(cstr, str.c_str());

    sgsim->runCommand(cstr);                // run command

    cMessage * timerMsg = new cMessage("Solve");

    scheduleAt(SimTime() + 0.6, timerMsg);    // scheduling self message
}

Mainsolver::~Mainsolver()
{
}

void Mainsolver::finish()
{
    recordScalar("packets sent", numSent);
    recordScalar("packets received", numReceived);
}

void Mainsolver::runDSS()
{
    bubble("Solving OpenDSS!");

    sgsim->runCommand("solve");
}

void Mainsolver::handleMessage(cMessage * msg)
{
    ev << "Mainsolver: I got a message Name=" << msg -> getName() << endl;

    if (msg -> isSelfMessage())
    {
        if (strcmp(msg -> getName(), "Solve") == 0)
        {
            runDSS();

            simtime_t d = simTime() + Interval;    // par("Interval").doubleValue();

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
}

