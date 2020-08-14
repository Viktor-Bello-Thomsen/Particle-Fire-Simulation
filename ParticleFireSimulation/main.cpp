#include<iostream>
#include "SDL.h"
using namespace std;
int main(int argc, char* argv[]) {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed" << endl;
		return 1;
	}
	
	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	// dealing with error in building window
	if (window == NULL) {
		cout << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	//handling if renderer and texture are not correctly build
	if (renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	if (texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	//maybe catch error for unsuccesful memory allocation

	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// 0xFF is just another way of writing 255, but in hexadecimal

	buffer[30000] = 0xFFFFFFFF;

	//same as memset... slower. But we can change individual values
	// 0x(Red)(Green)(Blue)(Alpha) Alpha does not seem to work though
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = 0x00808000;
	}
	

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	//Copying pixels to our texture from buffer
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	//Passing our texture to the renderer
	SDL_RenderPresent(renderer);
	//Presenting the renderer to window/screen

	bool quit = false;
	SDL_Event event;
	while (!quit) {
		//update particles
		//draw particles
		//check for message/events

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
	delete[] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
