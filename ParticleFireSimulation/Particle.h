#pragma once

namespace vbt {

	
	
class Particle
{
private:
	double m_speed;
	double m_direction;
	void init();

public:
	// for the sake of speed these member variables are made public
	double m_x, m_y;

public:
	Particle();
	~Particle();
	void update(int interval);

};



}
