#include "Log.h"

Log::Log()
{
	this->aFont.loadFromFile("font/D3Stonism.ttf");
	this->initiate();
}

Log::~Log()
{

}

void Log::addMessage(const std::string & message)
{
	this->popUp();
	this->messages[SIZE - 1].setString(message);
	this->fixPosition();
}

void Log::setPosition(float x, float y)
{
	this->pos.x = x;
	this->pos.y = y;
	this->fixPosition();
}

void Log::setPosition(const sf::Vector2f & newPos)
{
	this->pos = newPos;
	this->fixPosition();
}

void Log::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < SIZE; i++)
	{
		target.draw(this->messages[i]);
	}
}

void Log::initiate()
{
	for (int i = 0; i < SIZE; i++)
	{
		this->messages[i].setCharacterSize(16);
		this->messages[i].setFont(aFont);
		this->messages[i].setString("");
		this->messages[i].setFillColor(sf::Color(255, 255, 255, (255 / SIZE)* (i + 1)));
	}
	this->pos = sf::Vector2f(0, 0);

	this->fixPosition();
}

void Log::popUp()
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		this->messages[i].setString(this->messages[i + 1].getString());
	}
}

void Log::fixPosition()
{
	for (int i = SIZE - 1; i >= 0; i--)
	{
		this->messages[i].setPosition(this->pos.x, this->pos.y + (i * 17));
	}
}
