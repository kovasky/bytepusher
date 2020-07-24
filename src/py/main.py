import sys
import pygame
from bytepusher import BytePusher

vm = BytePusher()

vm.loadRom(sys.argv[1])

vm.run()