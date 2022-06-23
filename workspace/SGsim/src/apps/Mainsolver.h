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



#ifndef _Mainsolver_H
#define _Mainsolver_H

#include "SGSimInterface.h"

class Mainsolver
        : public cSimpleModule
{
    public:
        BOOLEAN firsttime;
        double  Interval;

    protected:
        SGSimInterface*     sgsim;
        simtime_t           stopTime;
        int                 numSent;
        int                 numReceived;

        virtual void runDSS();

    protected:
        virtual int numInitStages() const
        {
            return 4;
        }

        virtual void initialize(int stage);

        virtual void handleMessage(cMessage * msg);

        virtual void finish();

        virtual ~Mainsolver();
};
#endif
