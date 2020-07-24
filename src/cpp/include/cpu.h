#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <string>
#include <array>

class CPU
{
public:
	CPU();
	bool loadRom(std::string romLocation);
	uint8_t readByte(uint32_t location);
	void resetProgramCounter();
	std::array<uint8_t, 0x10000> readDisplayMemory(uint32_t location);
	void step();

private:
	void write(uint32_t location, uint8_t data);
	std::array<uint8_t, 0x100000> memory;
	uint32_t programCounter; //24 bit program counter
};

#endif