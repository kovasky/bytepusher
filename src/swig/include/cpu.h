#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include <string>
#include <array>
#include <vector>

class CPU
{
	public:
		CPU();
		bool loadRom(std::string romLocation);
		uint8_t readByte(uint32_t location);
        void resetProgramCounter();
		std::vector<uint8_t> run(uint32_t location);
	private:
		void step();
		void write(uint32_t location, uint8_t data);
		std::array<uint8_t,0x100000> memory;
		uint32_t programCounter; //24 bit program counter
};

#endif
