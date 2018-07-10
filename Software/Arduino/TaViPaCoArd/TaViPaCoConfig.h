/*
* This file is part of the TaViPaCo (Tangible Virtual Patch Cords)
* 
* The TaViPaCo can be obtained at http://stefanofasciani.com/tavipaco.html
* TaViPaCo Copyright (C) 2018 Stefano Fasciani, University of Wollongong in Dubai
* Inquiries: stefanofasciani@stefanofasciani.com
* 
* The TaViPaCo is free software: you can redistribute it and/or modify it under the 
* terms of the GNU Lesser General Public License as published by the Free Software 
* Foundation, either version 3 of the License, or (at your option) any later version.
* 
* The TaViPaCo is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
* See the GNU Less General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public License along with TaViPaCo. 
* If not, see <http://www.gnu.org/licenses/>.
* 
* If you use the TaViPaCo or any part of it in any system or publication, please acknowledge 
* its authors by adding a reference to this pubblication:
* 
* S. Fasciani, H. Rahman, 2018, "Tangible Virtual Patch Cords" in proceedings of
* International Computer Music Conference 2018, Daegu, Korea.
*/

#define DebugEnabled 0

#if (DebugEnabled == 1)
  #define BaudRate 9600
#else
  //#define BaudRate 76800 // use with MAX only
  #define BaudRate 57600 // use with PD and MAX
#endif

#define MaxSourcePinCount   22
#define MaxSinkPinCount     22
#define MaxPotCount         23
#define MaxSwitches         1

#define EnableSwitch        12
#define ModeSwitch          11

#define AnalogMuxInputPin   15
#define AnMuxChSelPinsDef   {4,3,2} //[LSB:MSB]

#define SourcePinsDef       {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53} //SrcId[0:]
#define SinkPinsDef         {5,6,7,8,9,10,22,14,15,16,17,18,19,20,21,23,24,25,26,27,28,29} //SinkId[0:]
#define SwitchesPinsDef     { ModeSwitch } //SwitchId [0:]


#define LedPin              {13}


