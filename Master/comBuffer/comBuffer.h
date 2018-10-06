#ifndef COMBUFFER_COMBUFFER_H_
#define COMBUFFER_COMBUFFER_H_
#include <Arduino.h>
#include <inttypes.h>

class ComBuffer {

	static const int comBufferSize =  512;
	byte buffer[comBufferSize] = {0};
	int comBufferStartIndex = 0;
	int comBufferEndIndex = 0;

public:
	ComBuffer();
	virtual ~ComBuffer();

	uint8_t read8();
	uint16_t read16();
	void write8(uint8_t data);
	void write16(uint16_t data);
	void write32(uint32_t data);

	void printBuffer();



	bool isBufferEmpty(){return !hasNext();}
	bool hasNext(){return comBufferStartIndex < comBufferEndIndex;}

};

#endif /* COMBUFFER_COMBUFFER_H_ */
