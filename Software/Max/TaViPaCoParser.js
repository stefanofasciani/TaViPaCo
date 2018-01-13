/*
TaViPaCoParser.js
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