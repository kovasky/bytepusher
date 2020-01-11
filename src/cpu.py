import numpy

class Cpu:
    def __init__(self):
        self.memory = numpy.array([0] * 0x100000, dtype='uint8') #vm has acess to 16MiB ram

        self.programCounter = numpy.uint32(self.read(2) << 0x10 | self.read(3) << 0x08 | self.read(4)) #supposed to be a 24 bit pc, start at address 2

    def loadRom(self,romLocation):
        temp = open(romLocation, "rb").read()
        
        if len(temp) <= len(self.memory):
            for i in range(len(temp)):
                self.memory[i] = numpy.fromstring(temp[i], dtype='uint8')
        
    def read(self,location):
        return self.memory[location]

    def write(self,location,data): #write to memory
        self.memory[location] = data

    def copyDisplayMem(self,location):
        displayMem = numpy.array([0] * (256*256), dtype='uint8')

        for i in range((256*256)):
            displayMem[i] = self.memory[location + i]

        return displayMem

    def resetProgramCounter(self):
        self.programCounter = numpy.uint32(self.read(2) << 0x10 | self.read(3) << 0x08 | self.read(4))

    def step(self):
        AAA = self.read(self.programCounter) << 0x10 | self.read(self.programCounter + 0x01) << 0x08 | self.read(self.programCounter + 0x02)
        BBB = self.read(self.programCounter + 0x03) << 0x10 | self.read(self.programCounter + 0x04) << 0x08 | self.read(self.programCounter + 0x05)
        CCC = self.read(self.programCounter + 0x06) << 0x10 | self.read(self.programCounter + 0x07) << 0x08 | self.read(self.programCounter + 0x08)

        self.write(BBB,self.read(AAA))
        self.programCounter = CCC
