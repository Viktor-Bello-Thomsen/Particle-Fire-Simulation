#include "Screen.h"

namespace vbt {



Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

}
bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	// dealing with error in building window
	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}


	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	//handling if renderer and texture are not correctly build
	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	//maybe catch error for unsuccesful memory allocation
	m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	
	//same as memset... slower. But we can change individual values
	// 0x(Red)(Green)(Blue)(Alpha) Alpha does not seem to work though
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_buffer[i] = 0xFFFF0000;
	}

	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	//Copying pixels to our texture from buffer
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	//Passing our texture to the renderer
	SDL_RenderPresent(m_renderer);
	//Presenting the renderer to window/screen

	return true;
}
bool Screen::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}
void Screen::close() {


	delete[] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}




}