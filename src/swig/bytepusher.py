from display import Display 
from spu import Spu
from keyboard import Keyboard
import pygame
import numpy
import cpu

class BytePusher:
    def __init__(self):
        self.cpu = cpu.CPU()

        self.keyboard = Keyboard()

        self.display = Display()

        self.keyData = numpy.array([0] * 0x02, dtype='uint8')

    def loadRom(self,romLocation):
        self.cpu.loadRom(romLocation)

    def run(self):
        while True:
            keys = self.keyboard.getKeys()
            self.display.renderFrame(self.cpu.run(self.cpu.readByte(0x05) << 0x10))
