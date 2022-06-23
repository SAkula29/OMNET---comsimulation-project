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



#ifndef _CREATEPMUFRAMES_H_
#define _CREATEPMUFRAMES_H_
#define MAX_STRING_SIZE 1024

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <winsock2.h>
#include <stdio.h>
#include<stdint.h>
#include <time.h>
#include <math.h>
#include "ccdata.h"

class createPMUFrames
{
    public:
        createPMUFrames();

        virtual uint16_t compute_CRC(unsigned char * message,
                                     int             length);

        virtual int createconfigframe(unsigned char config_frm[MAX_STRING_SIZE],
                                      char *,
                                      int);

        virtual int createdataframe(unsigned char data_frm[MAX_STRING_SIZE],
                                    AllValues     allvalues,
                                    int);

        virtual ~createPMUFrames();
};
#endif /* CREATEPMUFRAMES_H_ */

