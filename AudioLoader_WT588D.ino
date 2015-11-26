// Winbond serial flash loader.  Runs on normal Arduino (e.g. Uno,
// NOT Trinket), works with 'AudioXfer' Processing code on host PC.
// Modified by purgedsoul for uploading bin file to WTD588-16P sound module.
// Use at your own risk!

#include <Esplora.h>
#include <Adafruit_TinyFlash.h>
#include <SPI.h>

#define CHIP_SELECT_PIN   7

void setup() {
  Serial.begin(9600);
}

void loop() {
  Adafruit_TinyFlash flash = Adafruit_TinyFlash(CHIP_SELECT_PIN);

  uint8_t            buffer[256];

  int                c, index      = 0,
         rmdr          = 0,
         numpages      = 0,
         page          = 0;

  uint32_t           capacity,
         address       = 0,
         bytesExpected = 0x7FFFFFFF,
         bytesReceived = 0,
         filesize=0;

  pinMode(CHIP_SELECT_PIN, OUTPUT);
  Serial.println("HELLO");      // ACK to host
  capacity = flash.begin();
  Serial.println(capacity);     // Chip size to host

  while(!Serial.find("ERASE")); // Wait for ERASE command from host
  if(!flash.eraseChip()) {
    Serial.println("ERROR");
  }

  while(!Serial.find("CAPACITY"));
  filesize = Serial.parseInt();

  numpages = filesize / 256;
  rmdr = filesize % 256;

  if(rmdr != 0) numpages = numpages + 1;

  Serial.println("READY");      // ACK to host

  for(;;) {
    // Buffer data until a full page is ready or last packet arrives.
    if((c = Serial.read()) >= 0) {
      buffer[index] = c;
      index=index+1;
      if((index >= sizeof(buffer))) {
        if(flash.writePage(address, buffer)) {

          Serial.print('.');
        } else {
          Serial.print('X');
        }

        if(page >= numpages) break; //(address >= capacity) ||
        index = 0;
        page = page + 1;
        address = address + sizeof(buffer);
      }
    }
  }
}
