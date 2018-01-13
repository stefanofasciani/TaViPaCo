
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
