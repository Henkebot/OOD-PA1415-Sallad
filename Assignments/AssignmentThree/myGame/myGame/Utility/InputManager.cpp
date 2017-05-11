#include "InputManager.h"

bool InputManager::buttons[200] = { false };

bool InputManager::keyPressed(sf::Keyboard::Key key)
{
	bool keyIsPressed = false;
	bool isButtonPressed = sf::Keyboard::isKeyPressed(key);
	if (isButtonPressed && !InputManager::buttons[key])
	{
		std::cout << key << " Pressed!" << std::endl;
		keyIsPressed = true;
	}
	InputManager::buttons[key] = isButtonPressed;
	return keyIsPressed;
}
