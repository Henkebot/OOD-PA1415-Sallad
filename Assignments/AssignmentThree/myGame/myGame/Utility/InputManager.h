#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <iostream>
#include <SFML/Graphics.hpp>
class InputManager
{
public:
	static bool keyPressed(sf::Keyboard::Key key);
	static int getIndexOfKeyPressed();
private:
	static bool buttons[200];
	
	



};

#endif