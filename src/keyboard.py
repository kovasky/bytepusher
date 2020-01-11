import pygame
import sys

class Keyboard:
    def __init__(self):
        self.keyMap = {
            pygame.K_1: 0x1,
            pygame.K_2: 0x2,
            pygame.K_3: 0x3,
            pygame.K_4: 0xC,
            pygame.K_q: 0x4,
            pygame.K_w: 0x5,
            pygame.K_e: 0x6,
            pygame.K_r: 0xD,
            pygame.K_a: 0x7,
            pygame.K_s: 0x8,
            pygame.K_d: 0x9,
            pygame.K_f: 0xE,
            pygame.K_z: 0xA,
            pygame.K_x: 0x0,
            pygame.K_c: 0xB,
            pygame.K_v: 0xF
        }

        self.keys = [False] * 0x10 #array of 16 keys

    def getKeys(self):
        events = pygame.event.get()
    
        for key in self.keys:
            key = False

        for event in events:
            if event.type == pygame.QUIT:
                sys.exit()

            if event.type == pygame.KEYDOWN:
                if self.keyMap.get(event.key) != None:
                    self.keys[self.keyMap.get(event.key)] = True
                
            if event.type == pygame.KEYUP:
                if self.keyMap.get(event.key) != None:
                    self.keys[self.keyMap.get(event.key)] = False
        return self.keys
