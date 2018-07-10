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

/*
* TaViPaCoParser.js
*/

inlets = 1;
outlets = 3;

var buffer = [0, 0, 0];
var pointer = 0;


function processBuffer(){
	if(buffer[0]&0x20){//analog
		//post("PotId " + (buffer[0]&0x1F) + " Adc : " + ((buffer[1]<<7) | buffer[2]) + "\n");
		var outBuffer = [(buffer[0]&0x1F) , ((buffer[1]<<7) | buffer[2]) ];
		outlet(2,outBuffer);
		
	}else{//IoMatrix
		//post("conn: " + (buffer[0]&0x01) + " srcId : " + buffer[1] + " sinkId : " + buffer[2]+ "\n"); 
		var outBuffer = [buffer[1] ,buffer[2], (buffer[0]&0x01)  ];
		outlet(1,outBuffer);
	}
	
}

function msg_int(received)
{
	
	if(received & 0x80){ // MSB of head is 1
		//post("received int " + received + "\n");
		if((received & 0x40) == 0){
			outlet(0,(received&1));
			return;
		}
		else{
			buffer[0] = received;
			pointer = 1;
		}
	}
	else{
		if(pointer < 3){ // check if buffer full
			buffer[pointer] = received;
			pointer++;
			if(pointer == 3){ // check if buffer is still filling or full
				processBuffer();
			}
		}
		return;
	}
}