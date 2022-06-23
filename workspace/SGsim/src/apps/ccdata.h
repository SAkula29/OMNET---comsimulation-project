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
 * CCdata.h
 * common data
 *  Created on: 09.04.2015
 *      Author: akarim
 */

#ifndef CCDATA_H_
#define CCDATA_H_

#include "pmumessage_m.h"

#define MAX_STRING_SIZE 1024
typedef struct
{
    double Pv, Pw, L2, L3, L5;
} my_constraint_data;


typedef struct
{
    double V1r;
    double V1i;
    double V2r;
    double V2i;
    double V3r;
    double V3i;
    double I1r;
    double I1i;
    double I2r;
    double I2i;
    double I3r;
    double I3i;
    double P1;
    double Q1;
    double P2;
    double Q2;
    double P3;
    double Q3;
} AllValues;
#endif /* SOLOPT_H_ */
