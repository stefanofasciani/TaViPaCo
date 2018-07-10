
# TaViPaCo
## Tangible Virtual Patch Cords

The TaViPaCo (Tangible Virtual Patch Cords) is a system to tangibly manipulate the virtual patching cords in graphical programming environments, such as Max and Pure Data. The system includes a physical interface, a communication protocol, and a software library, providing physical extension of the graphical programming paradigm. The repository includes the related software for MAX and Pure Data, the interface schematics and Arduino code.

The TaViPaCo can be obtained at http://stefanofasciani.com/tavipaco.html
TaViPaCo Copyright (C) 2018 Stefano Fasciani, University of Wollongong in Dubai
Inquiries: stefanofasciani@stefanofasciani.com

##Description

The TaViPaCo has been developed using:

MAX 7.3.5
Pure Data 1.6.5
Arduino IDE 1.6.5
Proteus 8.6

Proteus has been used only to design the schematic of the interface and it is not necessary to replicate the system.

Arduino IDE is required to compile the Firmware for the ATMEGA2560 on the Arduino Mega 2560 Rev3 board. No additional libraries are required.

The interface can be used in both Max and Pure data using the external TaViPaCoMax.maxpat or TaViPaCoPd.pd. For more details on usage, refer to the related help files and demo.

The Max version uses only native objects.

The Pure Data version require do download and install the following externals:
- comport https://puredata.info/downloads/comport/?searchterm=comport 
- counter (in markex https://puredata.info/downloads/markex/?searchterm=markex)

The folder ‘Documentation’ includes the schematic and details on the serial communication protocol between Max or Pd and the ATMEGA2560.

The folder ‘Hardware’ includes the Proteus file related to the hardware design.

The folder ‘Software/Arduino’ includes the Arduino IDE project for the Arduino Mega 2560 Rev3 board (not that the current hardware design requires an external 9-12V power adaptor, the power provided via USB is not sufficient).

The folder ‘Software/Max’ includes the TaViPaCoMax.maxpat, the helpfile, a simple demo, and all required sub-patches. Include this folder in your Max path or save your Max patch using TaViPaCoMax in ‘Software/Max’.

The folder ‘Software/Pd’ includes the TaViPaCoPd.pd, the helpfile, a simple demo, and all required sub-patches. Include this folder in your Pd path or save your Pd patch using TaViPaCoPd in ‘Software/Pd’.

###USB Serial Baud Rate
The current version uses a Serial USB baud rate of 57600 bps, which is supported by both Max and Pure Data. The ‘serial’ object in Max support also 76800 bps baud rate.

To change the baud rate in Arduino, comment/uncomment lines 31-32 of ‘Software/Arduino/TaViPaCoArd/ TaViPaCoConfig.h’.

To change the baud rate in Max change the parameter of the ‘serial’ object in TaViPaCoMax.maxpat.

To change the baud rate in Pd change the message ‘baud’ sent to the ‘comport’ object in TaViPaCoPd.pd.

The baud rates in Arduino and Max or Pd must be identical.




For more technical details refer to:
S. Fasciani, H. Rahman, 2018, "Tangible Virtual Patch Cords" in proceedings of International Computer Music Conference 2018, Daegu, Korea.



