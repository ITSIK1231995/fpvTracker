#include "ledInterface.h"

byte comIndecatorLED = LOW;

void blinkComLed(){
    digitalWrite(LED_BUILTIN, comIndecatorLED = !comIndecatorLED);
}
