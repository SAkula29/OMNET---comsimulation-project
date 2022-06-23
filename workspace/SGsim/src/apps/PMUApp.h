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



#ifndef _PMUAPP_H_
#define _PMUAPP_H_

// #ifndef _PDCAPP_H_
// #define _PDCAPP_H_

#include "pmumessage_m.h"
#include "TCPSocket.h"
#include "UDPSocket.h"
#include "IPvXAddressResolver.h"
#include <fstream>
#include "ccdata.h"
#include "UDPControlInfo_m.h"
#include "createPMUFrames.h"
#include "SGSimInterface.h"


/**
 * UDP application. See NED for more info.
 */
class PMUApp
        : public cSimpleModule
{
    public:
        BOOLEAN      firsttime;
        pmumessage * confmsg;
        pmumessage * datamsg;

    protected:
        SGSimInterface*          sgsim;
        UDPSocket                socket;
        int                      localPort, destPort;
        std::vector<IPvXAddress> destAddresses;
        IPvXAddress              PMUdestAddresses;
        simtime_t                stopTime;
        int                      numSent;
        int                      numReceived;

        virtual ~PMUApp();

        virtual void runDSS();

        virtual void forwardmessage(pmumessage * msg);

    protected:
        virtual int numInitStages() const
        {
            return 4;
        }

        virtual void initialize(int stage);

        virtual void handleMessage(cMessage * msg);

        virtual void finish();
};
#endif

