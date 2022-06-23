//
// Copyright (C) 2014 Abdalkarim Awad <abdalkarim.awad@cs.fau.de>
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
//
//package inet.examples.SGsim;
package SGsim.simulations.example;
import inet.nodes.ethernet.Eth100M;
import inet.nodes.ethernet.EtherSwitch;
import inet.nodes.inet.Router;
import inet.nodes.inet.WirelessHost;
import inet.nodes.internetcloud.InternetCloud;
import inet.nodes.wireless.AccessPoint;
import inet.world.radio.ChannelControl;
import SGsim.nodes.SmartPMU;
import inet.nodes.inet.StandardHost;
import ned.IdealChannel;
import ned.DatarateChannel;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;

import SGsim.nodes.SmartHouse;
import SGsim.apps.Mainsolver;
import SGsim.nodes.SmartPDC;
import SGsim.nodes.SmartController;
import SGsim.nodes.SmartDER;
import SGsim.nodes.SmartBAT;
network Smartgridnet
{
    @display("bgb=808,522;bgl=6");
    types:
        channel ethernet extends DatarateChannel
        {
            delay = normal(0.00015s, 0.00005s);
            datarate = 10Mbps;
        }
        channel fiberrouterline extends DatarateChannel
        {
            ber = 0.0;
            delay = normal(0.000001s, 0.0000001s);
            datarate = 512Mbps;
        }
        channel Unnamed
        {
        }

        channel Unnamed1
        {
        }

    submodules:
        solver: Mainsolver {
            parameters:
                // assignDisjunctSubnetAddresses = false;
                @display("p=206,21");
        }
        configurator: IPv4NetworkConfigurator {
            parameters:
                // assignDisjunctSubnetAddresses = false;
                @display("p=144,21");
        }

        PDC: SmartPDC {
            parameters:
                @display("p=83,109;i=block/app2_l;is=s");
            gates:
                ethg[1];
        }

        router: Router {
            @display("p=194,220");
        }
        PMU1: SmartPMU {
            @display("p=441,31;i=misc/square;is=s");
        }
        CVRController: SmartController {
            @display("p=89,260;i=misc/controller");
        }
        LD3: SmartHouse {
            @display("p=152,452;i=misc/house;is=l");
        }

        router1: Router {
            @display("p=368,69");
        }
        router3: Router {
            @display("p=152,113");
        }

        router5: Router {
            @display("p=425,212");
        }

        LD2: SmartHouse {
            @display("p=104,434;i=misc/house;is=l");
        }

        LD1: SmartHouse {
            @display("p=45,407;i=misc/house;is=l");
        }

        LD4: SmartHouse {
            @display("p=232,469;i=misc/house;is=l");
        }

        PV1: SmartDER {
            @display("p=45,383;i=misc/Solar");
        }
        internet: InternetCloud {
            @display("p=299,156;is=vl");
        }
        LD5: SmartHouse {
            @display("p=319,489;i=misc/house;is=l");
        }

        LD6: SmartHouse {
            @display("p=425,481;i=misc/house;is=l");
        }

        LD7: SmartHouse {
            @display("p=505,469;i=misc/house;is=l");
        }

        LD8: SmartHouse {
            @display("p=573,469;i=misc/house;is=l");
        }

        LD9: SmartHouse {
            @display("p=626,452;i=misc/house;is=l");
        }

        LD10: SmartHouse {
            @display("p=692,452;i=misc/house;is=l");
        }

        PV2: SmartDER {
            @display("p=160,434;i=misc/Solar");
        }
        PV3: SmartDER {
            @display("p=313,458;i=misc/Solar");
        }
        PV4: SmartDER {
            @display("p=573,440;i=misc/Solar");
        }
        RPMU2: SmartPMU {
            @display("p=464,82;i=misc/square;is=s");
        }


        BAT1: SmartBAT {
            @display("p=759,458;i=misc/bat_s");
        }


    connections:
        router.pppg++ <--> fiberrouterline <--> CVRController.pppg++;

        router1.pppg++ <--> ethernet <--> RPMU2.pppg++;

        router1.pppg++ <--> ethernet <--> PMU1.pppg++;
        internet.pppg++ <--> fiberrouterline <--> router3.pppg++;
        PDC.ethg[0] <--> ethernet <--> router3.ethg++;

        LD1.pppg++ <--> ethernet <--> router5.pppg++;
        LD3.pppg++ <--> ethernet <--> router5.pppg++;
        LD2.pppg++ <--> ethernet <--> router5.pppg++;
        LD4.pppg++ <--> ethernet <--> router5.pppg++;

        LD5.pppg++ <--> ethernet <--> router5.pppg++;
        LD6.pppg++ <--> ethernet <--> router5.pppg++;
        LD7.pppg++ <--> ethernet <--> router5.pppg++;
        LD8.pppg++ <--> ethernet <--> router5.pppg++;

        LD9.pppg++ <--> ethernet <--> router5.pppg++;
        LD10.pppg++ <--> ethernet <--> router5.pppg++;

        BAT1.pppg++ <--> ethernet <--> router5.pppg++;
        PV1.pppg++ <--> ethernet <--> router5.pppg++;
        PV2.pppg++ <--> ethernet <--> router5.pppg++;
        PV3.pppg++ <--> ethernet <--> router5.pppg++;
        PV4.pppg++ <--> ethernet <--> router5.pppg++;
        router5.pppg++ <--> fiberrouterline <--> internet.pppg++;
        router1.pppg++ <--> fiberrouterline <--> internet.pppg++;
        internet.pppg++ <--> fiberrouterline <--> router.pppg++;
}
