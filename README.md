
Based on code from purgedsoul, published here:

http://forum.arduino.cc/index.php?topic=227435.msg2466463#msg2466463

For Arduino Esplora, use the following pinout:

Esplora|     | WT588D |
-----|+-----+|+--+|--
*Name* | *Header* | *ICSP*| *pin*
MISO | 9     | 1  | 6 DO
SCLK | 8     | 3  | 7 CLK
MOSI | 7     | 4  | 5 DI
CS/D7| 6     | -  | 9 CS
VDD  | 2     | 2  |16 VDD
GND  | 1     | 6  | 8 GND

Reference:

https://www.arduino.cc/en/Guide/ArduinoEsploraExamples
