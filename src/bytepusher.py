from cpu import Cpu
from display import Display 
from spu import Spu
from keyboard import Keyboard
import pygame
import numpy

class BytePusher:
    def __init__(self):
        self.cpu = Cpu()

        self.keyboard = Keyboard()

        self.display = Display()

        self.keyData = numpy.array([0] * 0x02, dtype='uint8')

    def loadRom(self,romLocation):
        self.cpu.loadRom(romLocation)

    def run(self):
        while True:
                keys = self.keyboard.getKeys()
                self.keyData[0],self.keyData[1] = 0,0

                for dataIndex in range(1):
                    for keyIndex in range(7):
                        if keys[keyIndex + (0x8 * dataIndex)] == True:
                            self.keyData[dataIndex] = self.keyData[dataIndex] | (0x1 << (keyIndex))

                self.cpu.write(0x00,self.keyData[0x1])

                self.cpu.write(0x01,self.keyData[0x0])

                self.cpu.resetProgramCounter()

                for steps in range(0x10000):
                    self.cpu.step()

                self.display.renderFrame(self.cpu.copyDisplayMem(self.cpu.read(0x05) << 0x10))
