#include "State.h"

State::State(GameStateManager* gsm)
{
	this->gsm = gsm;
}

State::State(const State & other)
{
	this->gsm = other.gsm;
}

State & State::operator=(const State & other)
{
	if (this != &other)
	{
		this->gsm = other.gsm;
	}
	return *this;
}
