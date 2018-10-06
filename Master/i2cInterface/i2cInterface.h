#ifndef   i2cInterface_h
#define   i2cInterface_h

#include "Arduino.h"
#include "../ledInterface/ledInterface.h"
#include <Wire.h>


void I2CSend(int data,byte address);

void I2CGetData(int command, int address,int dataSize);

#endif
