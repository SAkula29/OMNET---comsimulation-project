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



#include "createPMUFrames.h"

#define MAX_STRING_SIZE 1024

/*
 * the data will be encoded in a standard (IEEE c37.118)
 */
createPMUFrames::createPMUFrames()
{
    // TODO Auto-generated constructor stub
}

createPMUFrames::~createPMUFrames()
{
    // TODO Auto-generated destructor stub
}

int createPMUFrames::createconfigframe(unsigned char Config_Frame[MAX_STRING_SIZE],
        char *                                       name,
        int                                          id)
{
    // Configuration Frame
    int ConfigIndex = 0;

    Config_Frame[ConfigIndex++] = 0xAA;       // sync high byte
    Config_Frame[ConfigIndex++] = 0x32;       // sync low byte
    Config_Frame[ConfigIndex++] = 0;          // size high byte
    Config_Frame[ConfigIndex++] = 0;          // size low byte
    Config_Frame[ConfigIndex++] = 0;          // ID high byte
    Config_Frame[ConfigIndex++] = 1;          // ID low byte
    Config_Frame[ConfigIndex++] = 81;         // time
    Config_Frame[ConfigIndex++] = 163;        // time
    Config_Frame[ConfigIndex++] = 114;        // time
    Config_Frame[ConfigIndex++] = 72;         // time
    Config_Frame[ConfigIndex++] = 0;          // frac sec
    Config_Frame[ConfigIndex++] = 0;          // frac sec
    Config_Frame[ConfigIndex++] = 4;          // frac sec
    Config_Frame[ConfigIndex++] = 200;        // frac sec
    Config_Frame[ConfigIndex++] = 0;          // time base
    Config_Frame[ConfigIndex++] = 200;        // time base
    Config_Frame[ConfigIndex++] = 255;        // time base
    Config_Frame[ConfigIndex++] = 255;        // time base
    Config_Frame[ConfigIndex++] = 0;          // number of PMUs
    Config_Frame[ConfigIndex++] = 1;          // number of PMUs
    Config_Frame[ConfigIndex++] = name[0];    // start the name of the pmu
    Config_Frame[ConfigIndex++] = 'R';
    Config_Frame[ConfigIndex++] = 'L';
    Config_Frame[ConfigIndex++] = 32;
    Config_Frame[ConfigIndex++] = 'P';
    Config_Frame[ConfigIndex++] = 'M';
    Config_Frame[ConfigIndex++] = 'U';
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         // ;//end of the name of PMU
    Config_Frame[ConfigIndex++] = 0;          // ID
    Config_Frame[ConfigIndex++] = id;         // ID
    Config_Frame[ConfigIndex++] = 0;          // format
    Config_Frame[ConfigIndex++] = 2;          // 10//format
    Config_Frame[ConfigIndex++] = 0;          //
    Config_Frame[ConfigIndex++] = 6;          // number of phasor
    Config_Frame[ConfigIndex++] = 0;
    Config_Frame[ConfigIndex++] = 0;          // number of analog values
    Config_Frame[ConfigIndex++] = 0;
    Config_Frame[ConfigIndex++] = 0;          // number of digital status words
    Config_Frame[ConfigIndex++] = 'v';        // start Name of the phasor
    Config_Frame[ConfigIndex++] = 'o';
    Config_Frame[ConfigIndex++] = 'l';        //
    Config_Frame[ConfigIndex++] = 't';        //
    Config_Frame[ConfigIndex++] = '1';        //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         // ;//end of name Phasor
    Config_Frame[ConfigIndex++] = 'v';        // start Name of the phasor
    Config_Frame[ConfigIndex++] = 'o';
    Config_Frame[ConfigIndex++] = 'l';        //
    Config_Frame[ConfigIndex++] = 't';        //
    Config_Frame[ConfigIndex++] = '2';        //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         // ;//end of name Phasor
    Config_Frame[ConfigIndex++] = 'v';        // start Name of the phasor
    Config_Frame[ConfigIndex++] = 'o';
    Config_Frame[ConfigIndex++] = 'l';        //
    Config_Frame[ConfigIndex++] = 't';        //
    Config_Frame[ConfigIndex++] = '3';        //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         // ;//end of name Phasor
    Config_Frame[ConfigIndex++] = 'c';        // start Name of the phasor
    Config_Frame[ConfigIndex++] = 'u';
    Config_Frame[ConfigIndex++] = 'r';        //
    Config_Frame[ConfigIndex++] = 'r';        //
    Config_Frame[ConfigIndex++] = 'e';        //
    Config_Frame[ConfigIndex++] = 'n';        //
    Config_Frame[ConfigIndex++] = 't';        //
    Config_Frame[ConfigIndex++] = '1';        //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         // ;//end of name
    Config_Frame[ConfigIndex++] = 'c';        // start Name of the phasor
    Config_Frame[ConfigIndex++] = 'u';
    Config_Frame[ConfigIndex++] = 'r';        //
    Config_Frame[ConfigIndex++] = 'r';        //
    Config_Frame[ConfigIndex++] = 'e';        //
    Config_Frame[ConfigIndex++] = 'n';        //
    Config_Frame[ConfigIndex++] = 't';        //
    Config_Frame[ConfigIndex++] = '2';        //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         // ;//end of name
    Config_Frame[ConfigIndex++] = 'c';        // start Name of the phasor
    Config_Frame[ConfigIndex++] = 'u';
    Config_Frame[ConfigIndex++] = 'r';        //
    Config_Frame[ConfigIndex++] = 'r';        //
    Config_Frame[ConfigIndex++] = 'e';        //
    Config_Frame[ConfigIndex++] = 'n';        //
    Config_Frame[ConfigIndex++] = 't';        //
    Config_Frame[ConfigIndex++] = '3';        //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         //
    Config_Frame[ConfigIndex++] = 32;         // ;//end of name
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT1 high byte
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT1
    Config_Frame[ConfigIndex++] = 50;         // PHAUNIT1
    Config_Frame[ConfigIndex++] = 150;        // PHAUNIT1
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT2 high byte
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT2
    Config_Frame[ConfigIndex++] = 50;         // PHAUNIT2
    Config_Frame[ConfigIndex++] = 150;        // PHAUNIT2
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT3 high byte
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT3
    Config_Frame[ConfigIndex++] = 50;         // PHAUNIT3
    Config_Frame[ConfigIndex++] = 150;        // PHAUNIT3
    Config_Frame[ConfigIndex++] = 8;          // PHAUNIT4 high byte
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT4
    Config_Frame[ConfigIndex++] = 50;         // PHAUNIT4
    Config_Frame[ConfigIndex++] = 150;        // PHAUNIT4
    Config_Frame[ConfigIndex++] = 8;          // PHAUNIT5 high byte
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT5
    Config_Frame[ConfigIndex++] = 50;         // PHAUNIT5
    Config_Frame[ConfigIndex++] = 150;        // PHAUNIT5
    Config_Frame[ConfigIndex++] = 8;          // PHAUNIT6 high byte
    Config_Frame[ConfigIndex++] = 0;          // PHAUNIT6
    Config_Frame[ConfigIndex++] = 50;         // PHAUNIT6
    Config_Frame[ConfigIndex++] = 150;        // PHAUNIT6
    Config_Frame[ConfigIndex++] = 0;          // freq high byte
    Config_Frame[ConfigIndex++] = 1;          // freq
    Config_Frame[ConfigIndex++] = 0;          // changes high byte
    Config_Frame[ConfigIndex++] = 0;          // changes
    Config_Frame[ConfigIndex++] = 0;          // frame rate high byte
    Config_Frame[ConfigIndex++] = 25;         // frame rate

    // overwrite frm size after we know the exact size
    Config_Frame[2] = (ConfigIndex + 2) >> 8;    // frame size
    Config_Frame[3] = (ConfigIndex + 2);         // frame size

    uint16_t df_chk;

    df_chk                      = compute_CRC(Config_Frame, ConfigIndex);    // compute the CRC of the configuration frame
    Config_Frame[ConfigIndex++] = df_chk >> 8;    // CRC high byte
    Config_Frame[ConfigIndex++] = df_chk;         // CRC low byte

    // std::cout<<"inside create conf confframe="<<Config_Frame[0]<<std::endl;
    return ConfigIndex;
}

int createPMUFrames::createdataframe(unsigned char data_frame[MAX_STRING_SIZE],
        AllValues                                  allvalues,
        int                                        id)
{
    // **********************DATA FRAME*********************//
    int Dindex = 0;

    data_frame[Dindex++] = 0xAA;    // synch
    data_frame[Dindex++] = 0x01;    // data frame with version 1
    data_frame[Dindex++] = 0x0;     // frame size
    data_frame[Dindex++] = 0x0;     // frame size
    data_frame[Dindex++] = 0x0;     // ID Code
    data_frame[Dindex++] = id;      // ID Code

    time_t t;

    t                    = time(NULL);
    data_frame[Dindex++] = (t + 2 * 3600) >> 24;    // SOC
    data_frame[Dindex++] = (t + 2 * 3600) >> 16;    // SOC
    data_frame[Dindex++] = (t + 2 * 3600) >> 8;     // SOC
    data_frame[Dindex++] = (t + 2 * 3600);          // SOC
    data_frame[Dindex++] = 0x0;                     // FRASEC
    data_frame[Dindex++] = 0x0;                     // FRASEC
    data_frame[Dindex++] = 0x0;                     // FRASEC
    data_frame[Dindex++] = 0x0;                     // FRASEC
    data_frame[Dindex++] = 0x0;                     // STAT
    data_frame[Dindex++] = 0x0;                     // STAT

    std::cout << "data starts hear" << Dindex << std::endl;

    /** *****************phasor1******************* */
    float         Vr = allvalues.V1r;
    float         Vi = allvalues.V1i;
    unsigned char phasorDataR[4];
    unsigned char phasorDataI[4];

    memcpy(phasorDataR, &Vr, 4);
    memcpy(phasorDataI, &Vi, 4);

    data_frame[Dindex++] = phasorDataR[3];
    data_frame[Dindex++] = phasorDataR[2];
    data_frame[Dindex++] = phasorDataR[1];
    data_frame[Dindex++] = phasorDataR[0];
    data_frame[Dindex++] = phasorDataI[3];
    data_frame[Dindex++] = phasorDataI[2];
    data_frame[Dindex++] = phasorDataI[1];
    data_frame[Dindex++] = phasorDataI[0];

    /** *****************phasor2******************* */
    Vr = allvalues.V2r;
    Vi = allvalues.V2i;

    memcpy(phasorDataR, &Vr, 4);
    memcpy(phasorDataI, &Vi, 4);

    data_frame[Dindex++] = phasorDataR[3];
    data_frame[Dindex++] = phasorDataR[2];
    data_frame[Dindex++] = phasorDataR[1];
    data_frame[Dindex++] = phasorDataR[0];
    data_frame[Dindex++] = phasorDataI[3];
    data_frame[Dindex++] = phasorDataI[2];
    data_frame[Dindex++] = phasorDataI[1];
    data_frame[Dindex++] = phasorDataI[0];

    /** *****************phasor3******************* */
    Vr = allvalues.V3r;
    Vi = allvalues.V3i;

    memcpy(phasorDataR, &Vr, 4);
    memcpy(phasorDataI, &Vi, 4);

    data_frame[Dindex++] = phasorDataR[3];
    data_frame[Dindex++] = phasorDataR[2];
    data_frame[Dindex++] = phasorDataR[1];
    data_frame[Dindex++] = phasorDataR[0];
    data_frame[Dindex++] = phasorDataI[3];
    data_frame[Dindex++] = phasorDataI[2];
    data_frame[Dindex++] = phasorDataI[1];
    data_frame[Dindex++] = phasorDataI[0];

    /** *****************phasor4******************* */
    Vr = allvalues.I1r;
    Vi = allvalues.I1i;

    memcpy(phasorDataR, &Vr, 4);
    memcpy(phasorDataI, &Vi, 4);

    data_frame[Dindex++] = phasorDataR[3];
    data_frame[Dindex++] = phasorDataR[2];
    data_frame[Dindex++] = phasorDataR[1];
    data_frame[Dindex++] = phasorDataR[0];
    data_frame[Dindex++] = phasorDataI[3];
    data_frame[Dindex++] = phasorDataI[2];
    data_frame[Dindex++] = phasorDataI[1];
    data_frame[Dindex++] = phasorDataI[0];

    /** *****************phasor5******************* */
    Vr = allvalues.I2r;
    Vi = allvalues.I2i;

    memcpy(phasorDataR, &Vr, 4);
    memcpy(phasorDataI, &Vi, 4);

    data_frame[Dindex++] = phasorDataR[3];
    data_frame[Dindex++] = phasorDataR[2];
    data_frame[Dindex++] = phasorDataR[1];
    data_frame[Dindex++] = phasorDataR[0];
    data_frame[Dindex++] = phasorDataI[3];
    data_frame[Dindex++] = phasorDataI[2];
    data_frame[Dindex++] = phasorDataI[1];
    data_frame[Dindex++] = phasorDataI[0];

    /** *****************phasor6******************* */
    Vr = allvalues.I3r;
    Vi = allvalues.I3i;

    memcpy(phasorDataR, &Vr, 4);
    memcpy(phasorDataI, &Vi, 4);

    data_frame[Dindex++] = phasorDataR[3];
    data_frame[Dindex++] = phasorDataR[2];
    data_frame[Dindex++] = phasorDataR[1];
    data_frame[Dindex++] = phasorDataR[0];
    data_frame[Dindex++] = phasorDataI[3];
    data_frame[Dindex++] = phasorDataI[2];
    data_frame[Dindex++] = phasorDataI[1];
    data_frame[Dindex++] = phasorDataI[0];

    /// /in order to send  50.020

    // int freq=20;
    // in order to send  49.990
    int freq = -10;

    srand(time(NULL));

    freq = rand() % 20 - 10;

    // float freq=50.1;
    // unsigned char F[4];
    // memcpy(F, &freq,4);
    data_frame[Dindex++] = freq >> 8;    // FREQ
    data_frame[Dindex++] = freq;         // FREQ
    data_frame[Dindex++] = 0x0;          // devFrequency
    data_frame[Dindex++] = 0x0;          // devFrequency

    // overwrite frm size after we know the exact size
    data_frame[2] = (Dindex + 2) >> 8;    // frame size
    data_frame[3] = (Dindex + 2);         // frame size

    uint16_t df_chk;

    df_chk               = compute_CRC(data_frame, Dindex);    // compute the CRC of the data frame
    data_frame[Dindex++] = df_chk >> 8;                        // CRC high byte
    data_frame[Dindex++] = df_chk;                             // CRC low byte

    std::cout << "inside create datad ataframe Time=" << simTime() << "Vr=" << Vr << " Vi=" << Vi << std::endl;

    return Dindex;
}

uint16_t createPMUFrames::compute_CRC(unsigned char * message,
        int                                           length)
{
    uint16_t crc = 0x0ffff, temp, quick;
    int      i;

    for (i = 0; i < length; i++)
    {
        temp  = (crc >> 8) ^ message[i];
        crc   <<= 8;
        quick = temp ^ (temp >> 4);
        crc   ^= quick;
        quick <<= 5;
        crc   ^= quick;
        quick <<= 7;
        crc   ^= quick;
    }

    return crc;
}

