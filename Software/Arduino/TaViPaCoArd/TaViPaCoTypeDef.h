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

#define ReportStartBit (1<<7)
#define ReportType_bp (5)
#define ReportType_bm (0x03<<ReportType_bp)

#define ReportAnalogId_bp 0
#define ReportAnalogId_bm 0x1F
#define ReportAnalogHVal_bp 7
#define ReportAnalogHVal_bm 0x07
#define ReportAnalogLVal_bp 0
#define ReportAnalogLVal_bm 0x7F



/** Enum definition for the command type
 *  Common structure to report all type of updates.
 */
typedef enum{
  ReportType_IOMatrix = 0x02, /**< The command sends updates for IO Matrix change */
  ReportType_Mode = 0x00,   /**< The command sends updates when the mode value changes */
  ReportType_PotVal = 0x03, /**< The command sends updates when the Potentiometer value changes */
  
}ReportType_t;

/** IO Matrix change reporting structure
 *  Structure containing the information of the IOMatrix data change that has to be sent
 */
typedef struct{
  bool connection;  /**< The value being low when connected and high when disconnected */
  uint8_t srcId;    /**< The Source Id of the pin*/
  uint8_t sinkId;   /**< The Sink Id of the pin*/
}ReportIOMatrix_t;

/** Potentiometer Value change reporting structure
 *  Structure containing the information of the Potentiometer data change that has to be sent
 */
typedef struct{
  uint8_t potId;    /**< Id of the potentiometer that has a change in value */
  uint16_t potValue;  /**< The new ADC value of the potentiometer */
}ReportPotVal;

/** Arithmetic Mode change reporting structure
 *  Structure containing the information of the Arithmetic mode change that has to be sent
 */
typedef struct{
  bool arthmMode;   /**< The arithmetic mode being low addition and high for multiplication*/
}ReportArthmMode_t;

/** Reporting Structure 
 *  Common structure to report all type of updates.
 */
typedef struct{
  ReportType_t Type;      /**< the type of report to be sent */
  ReportIOMatrix_t IOMatrix;  /**< The IO Matrix report */
  ReportPotVal PotVal;    /**< The Potentiometer Value Change Report */
  ReportArthmMode_t Mode;   /**< The Mode Change Report */
}Report_t;
