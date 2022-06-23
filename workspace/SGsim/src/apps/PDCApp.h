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



// PDCApp.h

#ifndef _PDCAPP_H_
#define _PDCAPP_H_
/*
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <winsock2.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <windows.h>
#include "PMUValues_m.h"
#include "pmumessage_m.h"
#include "IPvXAddress.h"
#include "INETDefs.h"
#include "UDPSocket.h"
#include "UDPControlInfo_m.h"
#include "IPvXAddressResolver.h"
#include "InterfaceTableAccess.h"
#include "SmartData_m.h"
*/
#include "pmumessage_m.h"
#include "TCPSocket.h"
#include "UDPSocket.h"
#include "IPvXAddressResolver.h"
#include <fstream>
#include <winsock2.h>
//#include "ccdata.h"

class PDCApp
        : public cSimpleModule
{
    protected:

        // The following redefined virtual function holds the algorithm.
        virtual ~PDCApp();

        virtual void initialize(int stage);

        virtual int numInitStages() const
        {
            return 4;
        }

        virtual void finish();

        virtual void handleMessage(cMessage * msg);

    private:

        // parameters

        simtime_t          oldtime;
        double             var;
        float              stepSize;
        float              floatcurrentTime;
        cMessage *         event;
        const char *       outPutFilename;
        int                countValue;
        int                roundToSQL;
        cPacket *          tmsg;
        pmumessage *       PMUmsg;
        int                destPort;
        int                localPort;
        UDPSocket          socket;
        static simsignal_t sentPkSignal;
        static simsignal_t rcvdPkSignal;
        long               numSent;
        long               numReceived;
        cLongHistogram     hopCountStats;
        cOutVector         hopCountVector;
        cOutVector         timeVector;
        unsigned char      df_temp[2];
};
#endif // _SMARTDATA_M_H_

