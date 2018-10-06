#include "writeFuncs.h"


void writeFrequency(ComBuffer* comBuffer){
    //I2CSend (0,20);
    Serial.println("writeFrequency");
    I2CGetData (0,20,2);
}
void func2(ComBuffer* comBuffer){
    //I2CSend (0,20);
    Serial.println("func2");
    comBuffer->printBuffer();
    comBuffer->read8();
    I2CGetData (0,20,2);
}
