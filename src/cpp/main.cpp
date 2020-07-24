#include "include/cpu.h"
#include "include/display.h"
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
	CPU *cpu = new CPU();
	cpu->loadRom(argv[1]);
	Display *dis = new Display();
	bool quit = false;
	SDL_Event event;

	while (!quit)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			{
				quit = true;
			}
		}

		for (auto i = 0; i < 0x10000; i++)
		{
			cpu->step();
		}

		cpu->resetProgramCounter();
		dis->drawImage(cpu->readDisplayMemory(cpu->readByte(0x05) << 0x10));
	}

	delete cpu;
	delete dis;
	return 0;
}