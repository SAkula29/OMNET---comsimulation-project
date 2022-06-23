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
 * this module is used to send packets in a standard (IEEE 37.118) to a PDC , you can test this module
 * by running PMU connection tester
 */

#include "PDCApp.h"

#define MAX_STRING_SIZE 1024
using namespace std;

Define_Module(PDCApp);

simsignal_t PDCApp::sentPkSignal = SIMSIGNAL_NULL;

PDCApp::~PDCApp()
{
}

void PDCApp::initialize(int stage)
{
    if (stage != 3)
    {
        return;
    }

    numSent     = 0;
    numReceived = 0;

    WATCH(numSent);
    WATCH(numReceived);

    destPort  = par("destPort");
    localPort = par("localPort");

    socket.setOutputGate(gate("udpOut"));    // create Socket
    socket.bind(localPort);

    oldtime = 0;
}

void PDCApp::handleMessage(cMessage * msg)
{
    EV << " PDCApp received message " << msg << "\n";

    if (msg -> arrivedOn("udpIn"))
    {
        ev << "i got a message from udp" << endl;

        tmsg = check_and_cast<cPacket *>(msg);

        cPacket * payload = tmsg -> decapsulate();

        PMUmsg = check_and_cast<pmumessage *>(payload);

        // cout << "Delay to last message= " << simTime()-oldtime << "]\n";
        oldtime = simTime();

        unsigned char data_frm2[1024];

        for (int i = 0; i < PMUmsg -> getPmusize(); i++)
        {
            data_frm2[i] = PMUmsg -> getData_frm(i);
        }

        // Strange Tests ?!


         int index1 = 16;
          float V1r;
          int i, j;
          unsigned char test[4];
          test[0]=data_frm2[index1++];
          test[1]=data_frm2[index1++];
          test[2]=data_frm2[index1++];
          test[3]=data_frm2[index1++];
          for (i = 0, j = sizeof(float) - 1; i < j; ++i, --j)
          {
            char temp = test[i];
            test[i] = test[j];
            test[j] = temp;
          }
          memcpy(&V1r, test, sizeof(float));
          float V1i;
          test[0]=data_frm2[index1++];
          test[1]=data_frm2[index1++];
          test[2]=data_frm2[index1++];
          test[3]=data_frm2[index1++];
          for (i = 0, j = sizeof(float) - 1; i < j; ++i, --j)
          {
            char temp = test[i];
            test[i] = test[j];
            test[j] = temp;
          }
          memcpy(&V1i, test, sizeof(float));
          float I1r;
          test[0]=data_frm2[8*2+index1++];
          test[1]=data_frm2[8*2+index1++];
          test[2]=data_frm2[8*2+index1++];
          test[3]=data_frm2[8*2+index1++];
          for (i = 0, j = sizeof(float) - 1; i < j; ++i, --j)
          {
            char temp = test[i];
            test[i] = test[j];
            test[j] = temp;
          }
          memcpy(&I1r, test, sizeof(float));
         float I1i;
          test[0]=data_frm2[8*2+index1++];
          test[1]=data_frm2[8*2+index1++];
          test[2]=data_frm2[8*2+index1++];
          test[3]=data_frm2[8*2+index1++];
          for (i = 0, j = sizeof(float) - 1; i < j; ++i, --j)
          {
            char temp = test[i];
            test[i] = test[j];
            test[j] = temp;
          }
          memcpy(&I1i, test, sizeof(float));

        int            iResult;
        WSADATA        wsaData;    // Jedesmal wenn eine UDP Nachricht kommt wird ein neuer Socket aufgebaut?!
        SOCKET         SendSocket = INVALID_SOCKET;
        sockaddr_in    RecvAddr;
        unsigned short Port = par("Port");

        // ----------------------
        // Initialize Winsock
        iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (iResult != NO_ERROR)
        {
            wprintf(L"WSAStartup failed with error: %d\n", iResult);

            // return ;
        }

        // ---------------------------------------------
        // Create a socket for sending data
        SendSocket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

        if (SendSocket == INVALID_SOCKET)
        {
            wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();

            // return 1;
        }

        // ---------------------------------------------
        // Set up the RecvAddr structure with the IP address of
        // the PMU Connection Tester (in this example case "127.0.0.1")
        // and the specified port number.
        RecvAddr.sin_family      = AF_INET;
        RecvAddr.sin_port        = htons(Port);
        RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        // wprintf(L"Sending a datagram to the PMU tester...\n");
        iResult = sendto(SendSocket, (const char *) data_frm2, PMUmsg -> getPmusize(), 0, (SOCKADDR *) &RecvAddr,
                         sizeof(RecvAddr));

        delete msg;
        delete payload;
    }
}

void PDCApp::finish()
{
    ev << "done!" << endl;
}

