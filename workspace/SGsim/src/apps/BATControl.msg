//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

enum MessageType1
{
    CONT_CHARGE = 1;
    CONT_DISCHARGE = 2;
    CONT_IDLE = 3;   
}


packet
BATControl
{
    int type @enum(MessageType1);
    string source;
    simtime_t time;
    double var ;
    double kw;
    double voltage;
}