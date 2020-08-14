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

		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}
