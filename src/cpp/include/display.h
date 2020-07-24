#ifndef DISPLAY_H
#define DISPLAY_H

#include <array>
#include <cstdint>
#include <memory>
#include <SDL2/SDL.h>

class Display
{
public:
	Display();
	~Display();
	void drawImage(std::array<uint8_t, 0x10000> displayMemory);

private:
	std::array<SDL_Color, 256> colorPalette;
	std::array<SDL_Color, 256 * 256> pixels;
	const uint16_t widthHeight = 0x100;
	const uint8_t pixelSize = 0x04;
	SDL_Window *myWindow;
	SDL_Renderer *myRenderer;
	SDL_Texture *myTexture;
};

#endif