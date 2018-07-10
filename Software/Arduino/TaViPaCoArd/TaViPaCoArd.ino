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
 * File:   TaViPaCoArd.cpp
 * Created on November 12, 2017, 7:10 PM
 */

// Note on Terminology
// Sources in Arduino code are Signal Outlets in the interface (red connector) and Inlets n the Max/Pd svstraction
// Sinks in Arduino code are Signal Inlets in the interface (black connector) and Outlets n the Max/Pd svstraction


#include <Arduino.h>

#include "TaViPaCoConfig.h"
#include "TaViPaCoTypeDef.h"

char TotalSourcePins; /**< The total number of source pins. This is initialized at startup and left unchanged */
char TotalSinkPins;  /**< The total number of sink pins. This is initialized at startup and left unchanged */
char TotalSwitchs; /**< The total number of Switchs. This is initialized at startup and left unchanged */

char SourcePins[] = SourcePinsDef ;    /**< Array of Source Pins with the corresponding Arduino pin number as its elements */
char SinkPins[] = SinkPinsDef ;      /**< Array of Sink Pins with the corresponding Arduino pin number as its elements */
char ExtAdcPins[] = AnMuxChSelPinsDef ;  /**< Array of  corresponding Arduino Pins pins used for controlling the External analog multiplexer */
char SwitchPins[] = SwitchesPinsDef;   /**< Array of Switch Pins with the corresponding Arduino pin number as its elements */


char Status_SrcSinkConn [MaxSourcePinCount][MaxSinkPinCount ];  /**< The IO Matrix stored globally*/
char Status_Switchs[MaxSwitches];               /**< Switch Values Status stored globally*/
int Status_PotVal[MaxPotCount];                 /**< Potentiometer ADC values stored globally*/

char SystemEn;
char SwitchEn;
char LedStatus;

class AnalogMuxDemux4HC4051{
  public:

  AnalogMuxDemux4HC4051(){
    
  }
  
  AnalogMuxDemux4HC4051(int signalPin, int dPin2,int dPin1,int dPin0){
    setup(signalPin, dPin2,dPin1,dPin0);
  }
  
  AnalogMuxDemux4HC4051(int signalPin, int dPin2,int dPin1,int dPin0, int enPin){
    setup(signalPin, dPin2,dPin1,dPin0, enPin);
  }
  
  
  void setup(int signalPin, int dPin2,int dPin1,int dPin0, int enPin){
    this->signalPin = signalPin;
    this->dPin0 = dPin0;
    this->dPin1 = dPin1;
    this->dPin2 = dPin2;
    this->enPin = enPin;
  }

  void setup(int signalPin, int dPin2,int dPin1,int dPin0){
    this->signalPin = signalPin;
    this->dPin0 = dPin0;
    this->dPin1 = dPin1;
    this->dPin2 = dPin2;
  }

  
  void setChannel(int channel){
    digitalWrite(dPin0, bitRead(channel,0));
    digitalWrite(dPin1, bitRead(channel,1));
    digitalWrite(dPin2, bitRead(channel,2));
  }
  
  
  int readAdc(int channel){
    setChannel(channel);
    return analogRead(signalPin);
  }
  
  private:
  
  
  protected:
  
  int signalPin;
  int dPin2,dPin1,dPin0;
  int enPin;
  
  
};




AnalogMuxDemux4HC4051 AnMux(AnalogMuxInputPin, ExtAdcPins[0],ExtAdcPins[1],ExtAdcPins[2]);

/** 
 * Initializes the Source and Sink Pins
 */
void InitHardware_SourceSinkPins();
/** 
 * Initializes the Switchs and LED Pins
 */
void InitHardware_SwitchesLED();
/** 
 * Initializes the Control for the Analog Mux 
 */
void InitHardware_AnalogMuxCtrl();

/** Read Switch Value
 * Reads the Switch value
 * @param SwitchId the Id of the Switch to be read
 * @return returs the value of the Switch read
 */
bool Read_Switch(int SwitchId);

/** Read Potentiometer ADC value
 * Read the ADC value of the potentiometer
 * This includes both the internal channels as well as the external multiplexed channels
 * @param potId the Id of the potentiometer channel. 
 * @return the ADC sampled value
 */
int Read_Pot(int potId);

/** 
 * Initializes to -1 the status of the IO Matrix in global variable 'Status_SrcSinkConn' . 
 */
void InitAllSrcSinkConn();
/** 
 * Initializes to -1 the status of the Switchs in the global variable 'Status_Switchs'. 
 */
void InitAllSwitchStat();
/** 
 * Initializes to -1 the status Potentiometer ADC in the global variable 'Status_PotVal'. 
 */
void InitAllPotVal();

/** 
 * Scans for any changes in the IO Matrix and sends update to the client. 
 */
void scanAndReportChange_SrcSinkConn();
/** 
 * Scans for any changes in the Switchs and sends update to the client. 
 * This function also includes the Switch to change the arithmetic mode. See function SendReport_SwitchStatChange
 */
void scanAndReportChange_Switchs();
/** 
 * Scans for any changes in the Potentiometer ADC values and sends update to the client. 
 */
void scanAndReportChange_PotVal();

/** 
 * Sends report to the client about the new connection status between the source and sink 
 * @param srcId the id of the source that has been connected/disconnected
 * @param sinkId the id of the sink that has been connected/disconnected
 * @param connStat Low means connected wheras High means disconnected
 */
void SendReport_SrcSinkConnChange(int srcId, int sinkId, int connStat);

/** 
 * Sends report to the client for change in a SwitchId
 * @param SwitchId the Switch id whose value has changed
 * @param val the new value of the Switch
 */

void SendReport_SwitchStatChange(int SwitchId, bool val);

/** 
 * Sends report to the client for change in a Potentiometer value
 * @param potId the Potentiometer id whose value has changed
 * @param potVal the new value of the Potentiometer ADC 
 */
void SendReport_PotValChange(int potId, int potVal);

/** 
 * Sends the packaged report. 
 * @param report the structure of the report containing the updated information that has to be sent to the client
 */
void sendReport(Report_t *report);

/** 
 * HAL function to send the command over serial/uart
 * @param data pointer to the data buffer
 * @size the number of bytes that has to be transmitted
 */
void sendReportViaUart(uint8_t *data, unsigned int size);

/** 
 * Receives commands via uart
 */
void receiveCmdViaUart();

/** 
 * Toggles the status fo the LED
 */
void ToggleLEDStatus();

/** 
 * Reads the starus of the enable switch returnin FALSE if disabled or TRUE if enabled
 */
bool GetEnableSwitch();






int Read_Pot(int potId){
  if(potId <15) return analogRead(potId);
  //else return Read_ExternalAdc(potId-15);
  else return AnMux.readAdc(potId-15);
}

bool Read_Switch(int SwitchId){
  return digitalRead(SwitchPins[SwitchId]);
  
}

void InitHardware_SwitchesLED(){
  int i;
  for(i=0;i<TotalSwitchs;i++){
    pinMode(SwitchPins[i], INPUT_PULLUP);
  }
  pinMode(EnableSwitch, INPUT_PULLUP);
  pinMode(LedPin, OUTPUT);
}

void InitHardware_SourceSinkPins(){
  int i;
  
  for(i=0;i<TotalSourcePins;i++){
    pinMode(SourcePins[i], INPUT_PULLUP);
  }
  
  for(i=0;i<TotalSinkPins;i++){
    pinMode(SinkPins[i], INPUT_PULLUP);
  }
}

void InitHardware_AnalogMuxCtrl(){
  int i;
  for(i=0;i<3;i++){
    pinMode(ExtAdcPins[i], OUTPUT);
  }
}

void InitAllPotVal(){
  int i;
  for(i=0;i<MaxPotCount;i++){
    Status_PotVal[i] = -1;//Read_Pot(i);
  }
  
}

void InitAllSrcSinkConn(){
  int i,j;
  
  for(i=0;i<TotalSourcePins;i++){
    for(j=0;j<TotalSinkPins;j++){
      Status_SrcSinkConn[i][j] = -1;      
    }
  }
}

void InitAllSwitchStat(){
  int i;
  for(i=0;i<TotalSwitchs;i++){
    Status_Switchs[i] = -1;
    
  }
}

void scanAndReportChange_PotVal(){
  int i;
  ReportPotVal report;
  for(i=0;i<MaxPotCount;i++){
    int potVal = Read_Pot(i);
    
    if( abs(Status_PotVal[i] -  potVal ) >= 2   ){
      
      SendReport_PotValChange(i,potVal);
      Status_PotVal[i] = potVal;
    }
  }
}


void scanAndReportChange_SrcSinkConn(){
  int i,j;
  ReportIOMatrix_t report;
  for(i=0;i<TotalSourcePins;i++){
    pinMode(SourcePins[i], OUTPUT);
    digitalWrite(SourcePins[i], LOW);
    for(j=0;j<TotalSinkPins;j++){
      int pinVal = digitalRead(SinkPins[j]);
      if(pinVal != Status_SrcSinkConn[i][j]){
        SendReport_SrcSinkConnChange(i,j,pinVal);
        Status_SrcSinkConn[i][j] = pinVal;
      }
    }
    pinMode(SourcePins[i], INPUT_PULLUP);
  }
}

void scanAndReportChange_Switchs(){
  int i;
  for(i=0;i<TotalSwitchs;i++){
    bool pinVal = Read_Switch(i);
    if(pinVal != Status_Switchs[i] ){
      SendReport_SwitchStatChange(i, pinVal);
      Status_Switchs[i] = pinVal;
    }
  }
}

void SendReport_PotValChange(int potId, int potVal){

  Report_t Report;
  Report.Type = ReportType_PotVal;
  Report.PotVal.potId =potId;
  Report.PotVal.potValue = potVal;
  
  
  sendReport(&Report);
}

void SendReport_SrcSinkConnChange(int srcId, int sinkId, int connStat){

  Report_t Report;
  Report.Type = ReportType_IOMatrix;
  Report.IOMatrix.srcId = srcId;
  Report.IOMatrix.sinkId = sinkId;
  Report.IOMatrix.connection = connStat;
  
  sendReport(&Report); 
}

void SendReport_SwitchStatChange(int SwitchId, bool val){
  Report_t Report;
  if(SwitchId == 0){
    Report.Type = ReportType_Mode;
    Report.Mode.arthmMode = !val;
  }
  
  sendReport(&Report);
  
}




void sendReport(Report_t *report){
  uint8_t data[3];
  unsigned int reportSize = 0;
  switch(report->Type){
    case ReportType_IOMatrix:{
      data[0] = ReportStartBit | (ReportType_IOMatrix<<ReportType_bp) | (!(report->IOMatrix.connection)<<0);
      data[1] = (report->IOMatrix.srcId)&0xFF;
      data[2] = (report->IOMatrix.sinkId)&0xFF;
      reportSize = 3;
      
      //For debug Only
      /////////////////////////
      #if (DebugEnabled == 1)
      Serial.print("IOMatrix ");
      Serial.print(SourcePins[report->IOMatrix.srcId],DEC);
      Serial.print(" ");
      Serial.print(SinkPins[report->IOMatrix.sinkId],DEC);
      Serial.print(" ");

      if(report->IOMatrix.connection){
        Serial.println("disconnected");
      }
      else{
        Serial.println("connnected");
      }
      #endif
      /////////////////////////
      
      break;
    }
    case ReportType_Mode:{
      data[0] = ReportStartBit | (ReportType_Mode<<ReportType_bp) | ( (report->Mode.arthmMode));
      reportSize = 1;
      
      //For debug Only
      /////////////////////////
      #if (DebugEnabled == 1)
      Serial.print("Mode Change ");
      
      if(report->Mode.arthmMode){
        Serial.println("multiplication");
      }
      else{
        Serial.println("addition");
      }
      #endif
      /////////////////////////

      break;
    }
    case ReportType_PotVal:{
      data[0] = ReportStartBit | (ReportType_PotVal<<ReportType_bp) | ( (report->PotVal.potId) &ReportAnalogId_bm);
      data[1] = (report->PotVal.potValue>>ReportAnalogHVal_bp)& ReportAnalogHVal_bm;
      data[2] = (report->PotVal.potValue)& ReportAnalogLVal_bm;
      reportSize = 3;
      
      //For debug Only
      /////////////////////////
      #if (DebugEnabled == 1)
      Serial.print("potentiometer ");
      Serial.print(report->PotVal.potId,DEC);
      Serial.print(" ");
      Serial.println(report->PotVal.potValue,DEC);
      #endif
      /////////////////////////
      
      break;
    }

  }
  
  sendReportViaUart(data,reportSize);
  
}

void sendReportViaUart(uint8_t *data, unsigned int size){
  
  int i;
  for(i=0;i<size;i++){
    #if (DebugEnabled == 0)
    Serial.write(data[i]);
    #endif
  }
}


void receiveCmdViaUart(){
  if (Serial.available() > 0) {
      SystemEn = Serial.read();
    }
}

void ToggleLEDStatus(){
  LedStatus = LedStatus ^ 1;
  digitalWrite(LedPin, LedStatus);
}

bool GetEnableSwitch(){
  return !(bool)digitalRead(EnableSwitch);
}


void setup() {
  SystemEn = 0;
  LedStatus = 0;
  
  Serial.begin(BaudRate);

  //For debug Only
  /////////////////////////
  #if (DebugEnabled == 1)
        Serial.println("setup begins");
  #endif
  /////////////////////////

  //runtime variable used for flexibility. Add and remove pins in Config.h file
  TotalSourcePins = sizeof(SourcePins)/sizeof(SourcePins[0]);
  TotalSinkPins = sizeof(SinkPins)/sizeof(SinkPins[0]);
  TotalSwitchs = sizeof(SwitchPins)/sizeof(SwitchPins[0]);

  //initializes the pins for the Srouce, Sink, Switches, LED, Mux Control
  InitHardware_SwitchesLED();
  InitHardware_SourceSinkPins();
  InitHardware_AnalogMuxCtrl();

  //sets the global data to impossible values (- 1)
  InitAllSrcSinkConn();
  InitAllPotVal();
  InitAllSwitchStat();

  //For debug Only
  /////////////////////////
  #if (DebugEnabled == 1)
        SystemEn = 1;
        Serial.println("setup ends");
  #endif
  /////////////////////////

}


void loop() {

  //For debug Only
  /////////////////////////
  #if (DebugEnabled == 1)
        Serial.println("main loop");
  #endif
  /////////////////////////

  if(GetEnableSwitch()){

    //For debug Only
    /////////////////////////
    #if (DebugEnabled == 1)
          Serial.println("enabled");
          delay(200);
    #endif
    /////////////////////////
  
    receiveCmdViaUart();
    while((SystemEn==0) ){
      receiveCmdViaUart();
      InitAllSrcSinkConn();
      InitAllPotVal();
      InitAllSwitchStat();
    }
  
    scanAndReportChange_SrcSinkConn();
    scanAndReportChange_PotVal();
    scanAndReportChange_Switchs();
  
    ToggleLEDStatus();

  }
  
}


