#include <Arduino.h>


#include <Wire.h>

#include "comConsts.h"
#include "functions/funcArry/funcArry.h"
#include "ledInterface/ledInterface.h"

#define comBufferSize 512
byte comBuffer[comBufferSize] = {0};
int comBufferStartIndex = 0;
int comBufferEndIndex = 0;

void setup() {
        Serial.begin(115200); // Start serial for output/debugging

    pinMode(LED_BUILTIN, OUTPUT);// initialize digital pin LED_BUILTIN as an output.
    Wire.begin(); // join i2c bus (address optional for master)
}

void printComBuffer(){ // for debug
    int i;
    for(i = comBufferStartIndex; i < comBufferEndIndex; i++)
        Serial.println(comBuffer[(i)%comBufferSize]);
}

void loop() {
    int comNum;
    if(comBufferStartIndex < comBufferEndIndex){
        printComBuffer();

        comNum = comBuffer[(comBufferStartIndex++)%comBufferSize];
        if(comNum < MAC_COM_NUM)
            functions[comNum]();


    }
}


void serialEvent() {
    while (Serial.available()) {
        char input = (char)Serial.read();
        if(input != '\n')
            comBuffer[(comBufferEndIndex++)%comBufferSize] = input -48;
    }
    Serial.flush();
}
