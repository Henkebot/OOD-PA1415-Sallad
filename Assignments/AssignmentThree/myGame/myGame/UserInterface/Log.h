#ifndef LOG_H
#define LOG_H
#include <string>
#include <SFML/Graphics.hpp>
class Log : public sf::Drawable
{
public:
	static const int SIZE = 20;

	Log();
	~Log();
	void addMessage(const std::string & message);
	void setPosition(float x, float y);
	void setPosition(const sf::Vector2f & newPos);
private:
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	void initiate();
	void popUp();
	void fixPosition();
private:
	sf::Text messages[SIZE];
	sf::Font aFont;
	sf::Vector2f pos;
};

#endif