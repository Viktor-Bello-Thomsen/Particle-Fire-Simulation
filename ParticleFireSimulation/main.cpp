#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "SDL.h"
#include "Screen.h"
#include "Swarm.h"
using namespace std;
using namespace vbt;
int main(int argc, char* argv[]) {

	// makeing sure that a new seed is used everytime 
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error creating screen" << endl;
	}
	
	Swarm swarm;
	

	while (true) {
		//update particles
		//draw particles
		//check for message/events
		//screen.clear();
		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		Particle* pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = particle.m_x * Screen::SCREEN_WIDTH + Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH + Screen::SCREEN_HEIGHT/2;
			screen.setPixel(x, y, red, green, blue);
		}

		
		
		screen.boxBlur();
		screen.update();
		if (screen.processEvents() == false) {
			break;
		}
	}
	screen.close();
	return 0;
}
