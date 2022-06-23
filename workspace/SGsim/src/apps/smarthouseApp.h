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
//
//



#ifndef _smarthouseApp_H
#define _smarthouseApp_H

#include "TCPSocket.h"
#include "UDPSocket.h"
#include "IPvXAddressResolver.h"
#include <fstream>
#include "ccdata.h"
#include "SmartData_m.h"
#include "SGSimInterface.h"

class smarthouseApp
        : public cSimpleModule
{
    public:
        double       Interval;
        int          numSent;
        int          numReceived;
        char *       fname;
        bool         firsttime;
        double       Demandkw[1440];
        double       Demandkvar[1440];
        pmumessage * confmsg;
        pmumessage * datamsg;
        int          NrPoints;
        double       DataPeriod;

    protected:
        SGSimInterface*          sgsim;
        UDPSocket                socket;
        int                      localPort, destPort;
        std::vector<IPvXAddress> destAddresses;
        IPvXAddress              PMUdestAddresses;
        simtime_t                stopTime;
        simtime_t                nextSendTime;

        virtual void EditParameters(double,
                                    double);

    protected:
        virtual int numInitStages() const
        {
            return 4;
        }

        virtual void initialize(int stage);

        virtual void handleMessage(cMessage * msg);

        virtual void finish();

        virtual ~smarthouseApp();
};
#endif
