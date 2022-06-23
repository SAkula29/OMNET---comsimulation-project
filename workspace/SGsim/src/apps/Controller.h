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



#ifndef _Controller_H
#define _Controller_H

#include "pmumessage_m.h"
#include "TCPSocket.h"
#include "UDPSocket.h"
#include "IPvXAddressResolver.h"
#include <fstream>
#include "ccdata.h"
#include "SmartData_m.h"
#include "UDPControlInfo_m.h"
#include "BATControl_m.h"
#include "SGSimInterface.h"


class Controller
        : public cSimpleModule
{
    public:
        simtime_t    Lvoltage_time;
        bool         LowVoltage;
        bool         VProt;
        bool         ROptCVR;
        BOOLEAN      firsttime;
        pmumessage * confmsg;
        pmumessage * datamsg;
        double       currentVoltage;
        double       Interval;
        int          emergency;
        int          NrPV;
        double       TotalLosses;
        double       TotalLineLosses;
        const char * connectAddress;
        int          connectPort;
        TCPSocket    tcpsocket[100];
        TCPSocket    BatSocket;
        double       QPV[1000][100];

    protected:
        SGSimInterface*          sgsim;
        UDPSocket                socket;
        int                      localPort, destPort;
        std::vector<IPvXAddress> destAddresses;
        IPvXAddress              PMUdestAddresses;
        simtime_t                stopTime;
        double                   aPower[10];
        double                   rPower[10];
        int                      aPowerI[10];
        int                      rPowerI[10];
        double                   Irrad[96];
        double                   Lvoltage[10];
        double                   V1, V2;
        int                      numSent;
        int                      numReceived;
        int                      NrPoints;
        double                   DataPeriod;
        double                   minvoltage;
        bool                     CVR;
        bool                     OptCVR;
        double                   energy;
        double                   Voltage[96];
        simtime_t                minSendTime;
        simtime_t                minGetTime;
        simtime_t                emergencyTime;

        virtual void processPacket(cPacket * pk);

        // void CallSolver();
        virtual void CallDSS();

        // virtual void ChangeVoltage(double setvoltage,int emergency);//emergency

    protected:
        virtual int numInitStages() const
        {
            return 4;
        }

        virtual void initialize(int stage);

        virtual void handleMessage(cMessage * msg);

        virtual void finish();

        virtual ~Controller();
};
#endif
