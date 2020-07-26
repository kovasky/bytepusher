#include "include/cpu.h"
#include <fstream>
#include <algorithm>

CPU::CPU()
{
	this->memory.fill(0);
	this->programCounter = (this->readByte(0x02) << 0x10) | (this->readByte(0x03) <<0x08) | (this->readByte(0x04)); //program execution starts at 0x02
}

bool CPU::loadRom(std::string romLocation)
{
	std::ifstream someRom(romLocation.c_str(), std::ios::in | std::ios::binary);
	someRom.unsetf(std::ios::skipws);

	if(someRom)
	{
		someRom.seekg(0, std::ios::end);
		std::streampos fileSize = someRom.tellg();
		someRom.seekg(0, std::ios::beg);

		if(fileSize < 0x100000)
		{
			someRom.read((char*)((this->memory.data())),fileSize);
			someRom.close();
			return true;
		}
	}

	return false;
}

uint8_t CPU::readByte(uint32_t location)
{
	return location < (0x100000 - 1) ? this->memory[location] : 0x00; 
}

std::vector<uint8_t> CPU::run(uint32_t location)
{
	for (auto i = 0; i < 0x10000; i++)
    {
		this->step();
    }

    this->resetProgramCounter();

	std::vector<uint8_t> tempArray(0x10000,0);

	if (location + 0x10000 < 0x100000)
	{
		std::copy(this->memory.begin() + location, this->memory.begin() + location + 0x10000, tempArray.begin());
	}

	return tempArray;
}

void CPU::step()
{
	uint32_t AAA = this->readByte(this->programCounter) << 0x10 | this->readByte(this->programCounter + 0x01) << 0x08 | this->readByte(this->programCounter + 0x02);
    uint32_t BBB = this->readByte(this->programCounter + 0x03) << 0x10 | this->readByte(this->programCounter + 0x04) << 0x08 | this->readByte(this->programCounter + 0x05);
    uint32_t CCC = this->readByte(this->programCounter + 0x06) << 0x10 | this->readByte(this->programCounter + 0x07) << 0x08 | this->readByte(this->programCounter + 0x08);
    this->write(BBB,this->readByte(AAA));
    this->programCounter = CCC;
}

void CPU::resetProgramCounter()
{
    this->programCounter = (this->readByte(0x02) << 0x10) | (this->readByte(0x03) <<0x08) | (this->readByte(0x04));
}

void CPU::write(uint32_t location, uint8_t data)
{
	if(location < 0x100000)
	{
		this->memory[location] = data;
	}
}
