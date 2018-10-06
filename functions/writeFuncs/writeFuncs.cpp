#include "writeFuncs.h"


void writeFrequency(){
    //I2CSend (0,20);
    Serial.println("writeFrequency");
    I2CGetData (0,20,2);
}
void func2(){
    //I2CSend (0,20);
    Serial.println("func2");
    I2CGetData (0,20,2);
}
