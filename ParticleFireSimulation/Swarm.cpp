#include "Swarm.h"
namespace vbt {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticles;
}

Particle* const Swarm::getParticles() {
	return m_pParticles;
}

void Swarm::update() {
	for (int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].update();
		
	}
}

}