import numpy

class Cpu:
    def __init__(self):
        self.memory = numpy.array([0] * 0x100000, dtype='uint8') #vm has acess to 16MiB ram

        self.programCounter = numpy.uint32(self.read(2) << 0x10 | self.read(3) << 0x08 | self.read(4)) #supposed to be a 24 bit pc, start at address 2

    def loadRom(self,romLocation):
        temp = open(romLocation, "rb").read()
        
        if len(temp) <= len(self.memory):
            for i in range(len(temp)):
                self.memory[i] = temp[i]
        
    def read(self,location):
        return self.memory[location]

    def write(self,location,data): #write to memory
        if location < len(self.memory):
            self.memory[location] = data 

    def copyDisplayMem(self,location):
        return self.memory[location:]

    def resetProgramCounter(self):
        self.programCounter = numpy.uint32(self.read(2) << 0x10 | self.read(3) << 0x08 | self.read(4))

    def step(self):
        AAA = self.read(self.programCounter) << 0x10 | self.read(self.programCounter + 0x01) << 0x08 | self.read(self.programCounter + 0x02)
        
        BBB = self.read(self.programCounter + 0x03) << 0x10 | self.read(self.programCounter + 0x04) << 0x08 | self.read(self.programCounter + 0x05)
        
        CCC = self.read(self.programCounter + 0x06) << 0x10 | self.read(self.programCounter + 0x07) << 0x08 | self.read(self.programCounter + 0x08)

        self.write(BBB,self.read(AAA))
        
        self.programCounter = CCC
