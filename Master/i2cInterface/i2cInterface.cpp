#include "i2cInterface.h"

void I2CSend(int data,byte address){
    Wire.beginTransmission(address); // transmit to device 
    Wire.write(data);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    blinkComLed();
}

void I2CGetData(int command, int address,int dataSize){
   I2CSend(command,address);
    Wire.requestFrom(address,dataSize);
    while (Wire.available()) {
         Serial.println(Wire.read(),HEX);
    } 
    blinkComLed();
}
