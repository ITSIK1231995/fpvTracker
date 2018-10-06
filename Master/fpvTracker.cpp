#include <Arduino.h>


#include <Wire.h>

#include "comConsts.h"
#include "functions/funcArry/funcArry.h"
#include "ledInterface/ledInterface.h"
#include "comBuffer/comBuffer.h"

ComBuffer comBuffer;

void setup() {
    Serial.begin(115200); // Start serial for output/debugging

    pinMode(LED_BUILTIN, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
    Wire.begin(); // join i2c bus (address optional for master)
}



void loop() {
    int comNum;
    if(comBuffer.hasNext()){
    	//comBuffer.printBuffer(); // for debuging
        comNum = comBuffer.read8();
        if(comNum < MAC_COM_NUM)
            functions[comNum](&comBuffer);
        else{
        	Serial.println("Error - no such command");
        }
    }
}


void serialEvent() {
    while (Serial.available()) {
    	delay(1000);
        char input = (char)Serial.read();
        if(input != '\n')
        	comBuffer.write8(input -48);
    }
    Serial.flush();
}
