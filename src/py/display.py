import pygame
from pygame import gfxdraw

class Display:
    def __init__(self):
        pygame.init()

        pygame.display.set_caption('BytePusher by Kovasky Buezo')
        
        self.screen = pygame.display.set_mode((512,512))

        self.surface = pygame.Surface((256,256))

        self.pixelArray = pygame.PixelArray(self.surface)

        self.palette = [pygame.Color(0,0,0)] * 256

        index = 0

        for red in range(0,256,0x33):
            for green in range(0,256,0x33):
                for blue in range(0,256,0x33):
                    self.palette[index] = pygame.Color(red,green,blue)
                    
                    index += 1
        
    def renderFrame(self, data):     
        for y in range(256):
            for x in range(256):
                self.pixelArray[x][y] = self.palette[data[(y * 256) + x]]
                
        pygame.transform.scale2x(self.surface, self.screen)
        pygame.display.update()
