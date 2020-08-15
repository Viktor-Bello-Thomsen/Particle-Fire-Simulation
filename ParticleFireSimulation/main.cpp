#include<iostream>
#include<math.h>
#include "SDL.h"
#include "Screen.h"
using namespace std;
using namespace vbt;
int main(int argc, char* argv[]) {

	
	
	Screen screen;

	if (screen.init() == false) {
		cout << "Error creating screen" << endl;
	}

	int max = 0;

	while (true) {
		//update particles
		//draw particles
		//check for message/events
		int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
		if (green > max) max = green;

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++){
				screen.setPixel(x, y, red, green, blue);
			}
		}

		//screen.setPixel(400, 300, 255, 255, 255);

		screen.update();
		
		if (screen.processEvents() == false) {
			break;
		}
	}
	cout <<"Max: "  << max << endl;
	screen.close();
	return 0;
}
