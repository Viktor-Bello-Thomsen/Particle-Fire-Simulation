#pragma once
#include "Particle.h"
namespace vbt {
class Swarm
{

private:
	Particle* m_pParticles;
	int lastTime;

public:
	const static int NPARTICLES = 5000;


public:
	Particle* const getParticles();
	Swarm();
	~Swarm();
	void update(int elapsed);
};
}
