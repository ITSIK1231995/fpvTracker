#include "comBuffer.h"

ComBuffer::ComBuffer() {}

ComBuffer::~ComBuffer() {}

uint8_t ComBuffer::read8() {
	return buffer[comBufferStartIndex++ % comBufferSize];
}

uint16_t ComBuffer::read16() {
	uint16_t result;
	result = buffer[comBufferStartIndex++ % comBufferSize];
	result = (result << 8) | buffer[comBufferStartIndex++ % comBufferSize];
	return result;
}

void ComBuffer::write8(uint8_t data) {
	buffer[comBufferEndIndex++ % comBufferSize] = data;
}

void ComBuffer::write16(uint16_t data) {
	buffer[comBufferEndIndex++ % comBufferSize] = (uint16_t)(data >> 8);
	buffer[comBufferEndIndex++ % comBufferSize] = (uint16_t)(data & 0xFF);
}

void ComBuffer::write32(uint32_t data) {
	buffer[comBufferEndIndex++ % comBufferSize] = (uint16_t)(data >> 24);
	buffer[comBufferEndIndex++ % comBufferSize] = (uint16_t)(data >> 16);
	buffer[comBufferEndIndex++ % comBufferSize] = (uint16_t)(data >> 8);
	buffer[comBufferEndIndex++ % comBufferSize] = (uint16_t)(data & 0xFF);
}

void ComBuffer::printBuffer(){ // for debug
    int i;
    for(i = comBufferStartIndex; i < comBufferEndIndex; i++)
        Serial.println(buffer[(i)%comBufferSize]);
}






