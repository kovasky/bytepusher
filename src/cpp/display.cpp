#include "include/display.h"

Display::Display()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	this->myWindow = SDL_CreateWindow("BytePusher VM by Kovasky Buezo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->widthHeight  * this->pixelSize, this->widthHeight * this->pixelSize, SDL_WINDOW_SHOWN);
	this->myRenderer = SDL_CreateRenderer(this->myWindow, -1, SDL_RENDERER_ACCELERATED);
	this->myTexture = SDL_CreateTexture(this->myRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, this->widthHeight, this->widthHeight);
	SDL_RenderSetScale(this->myRenderer, this->pixelSize, this->pixelSize);
	uint8_t index = 0;

	for(size_t red = 0; red < 256; red = red + 0x33)
	{
		for(size_t green = 0; green < 256; green = green + 0x33)
		{
			for(size_t blue = 0; blue < 256; blue = blue + 0x33)
			{
				this->colorPalette[index].r = red;
				this->colorPalette[index].g = green;
				this->colorPalette[index].b = blue;
				this->colorPalette[index].a = 255;

				index++;
			}
		}
	}

	this->pixels.fill({0,0,0,255});
}

Display::~Display()
{
	SDL_DestroyWindow(this->myWindow);
	SDL_DestroyRenderer(this->myRenderer);
	SDL_DestroyTexture(this->myTexture);
	SDL_Quit();
}

void Display::drawImage(std::array<uint8_t,0x10000> displayMemory)
{
	this->pixels.fill({0,0,0,0});

	for(auto y=0; y < 256; y++)
	{
		for(auto x=0; x < 256; x++)
		{
			this->pixels[(y*256) + x] = this->colorPalette[displayMemory[(y*256) + x]];
		}
	}

	SDL_UpdateTexture(this->myTexture, NULL, this->pixels.data(),this->widthHeight * sizeof(uint32_t));
	SDL_RenderClear(this->myRenderer);
    SDL_RenderCopy(this->myRenderer, this->myTexture, NULL, NULL);
    SDL_RenderPresent(this->myRenderer);
}
