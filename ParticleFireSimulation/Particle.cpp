#include "Particle.h"
#include<stdlib.h>
namespace vbt {



	Particle::Particle(){
		m_x = (double) rand() / RAND_MAX;
		m_y = (double) rand() / RAND_MAX;
	}

	Particle::~Particle() {



	}


}