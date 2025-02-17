*Before you try this, you should know I could not get this to work.  
The Arduino sketch would fail when erasing the chip and print ERROR on the serial port.  
The voltage measured on VCC (pin 14) of the WT588D is suspiciously low (1.8V).  
And my time allotted for this project is expired.  If anyone out there gets this to work, 
I'd love to hear the details.*


Based on code from purgedsoul, published here:

http://forum.arduino.cc/index.php?topic=227435.msg2466463#msg2466463

For Arduino Esplora, use the following pinout:

Esplora |   |WT588D 
-----|:-----:|:--:
*Name* | *right exp. header* | *module pin*|
MISO | 9     |  6 DO 
SCLK | 8     |  7 CLK 
MOSI | 7     |  5 DI 
CS/D7| 6     |  9 CS
VDD  | 2     | 16 VDD 
GND  | 1     |  8 GND

Graphically:

![](https://raw.githubusercontent.com/jcard0na/arduino-audio-loader-WT588D/master/misc/Esplora-WT58DD-16-Programmer_bb.png)

Reference:

![](http://2.bp.blogspot.com/-vYeRQFA-YYw/Ui84488MEVI/AAAAAAAAANc/pOaiPYxMDlI/s1600/PINOUT+esplora+no+oficial.png)
