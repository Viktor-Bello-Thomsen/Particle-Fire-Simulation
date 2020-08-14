#include<iostream>
#include "SDL.h"
#include "Screen.h"
using namespace std;
using namespace vbt;
int main(int argc, char* argv[]) {

	
	
	Screen screen;

	if (screen.init() == false) {
		cout << "Error creating screen" << endl;
	}

	while (true) {
		//update particles
		//draw particles
		//check for message/events


		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++){
				screen.setPixel(x, y, 255, 255, 0);
			}
		}

		//screen.setPixel(400, 300, 255, 255, 255);

		screen.update();
		
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}
