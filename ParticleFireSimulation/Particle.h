#pragma once

namespace vbt {

	
	
class Particle
{
private:
	double xspeed;
	double yspeed;

public:
	// for the sake of speed these member variables are made public
	double m_x, m_y;

public:
	Particle();
	~Particle();
	void update();

};



}
