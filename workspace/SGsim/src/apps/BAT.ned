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

package SGsim.apps;

simple BAT
{
    parameters:

        string localAddress = default(""); // may be left empty ("")
        int TCPlocalPort = default(1000); // port number to listen on
        string dataTransferMode @enum("bytecount","object","bytestream") = default("bytecount");

        int NrPersons = default(1);
        int localPort = default(-1);  // local port (-1: use ephemeral port)
        string destAddresses = default(""); // list of IP addresses, separated by spaces ("": don't send)
        string PMUdestAddress = default(""); // list of IP addresses, separated by spaces ("": don't send)
        bool VVC = default(false);
        string Demandkw = default("");
        string Demandkvar = default("");
        string Irrad = default("");
        string NH = default("NH1");
        double Interval @unit(s) = default(60s);
        double KVA = default(15);
        double KWR = default(15);
        int destPort;
        int NrPoints = default(24);
        int DataPeriod = default(1);
        double startcharge @unit(s) = default(1s);
        double stopcharge @unit(s) = default(1s);
        double startdischarge @unit(s) = default(1s);
        double stopdischarge @unit(s) = default(1s);

    gates:
        input udpIn @labels(UDPControlInfo/up);
        output udpOut @labels(UDPControlInfo/down);
        input tcpIn @labels(TCPCommand/up);
        output tcpOut @labels(TCPCommand/down);
}
