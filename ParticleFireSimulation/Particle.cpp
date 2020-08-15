#include "Particle.h"
#include "Screen.h"
#include<stdlib.h>
namespace vbt {



	Particle::Particle(){
		m_x = (double) rand() / RAND_MAX;
		m_y = (double) rand() / RAND_MAX;
		xspeed = 0.002 * (((2.0 * rand()) / RAND_MAX) - 1);
		yspeed = 0.002 * (((2.0 * rand()) / RAND_MAX) - 1);
	}

	Particle::~Particle() {



	}

	void Particle::update() {
		if (m_x < 0 || m_x >= 1) xspeed *= -1;
		if (m_y < 0 || m_y >= 1) yspeed *= -1;
		m_x += xspeed;
		m_y += yspeed;


	}


}