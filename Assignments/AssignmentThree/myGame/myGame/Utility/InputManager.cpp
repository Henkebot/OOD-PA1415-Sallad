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

int InputManager::getIndexOfKeyPressed()
{
	int key = -1;
	bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
	bool altPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt);
	bool foundKey = false;
	//Letters
	for (int i = sf::Keyboard::A; i <= sf::Keyboard::Z && !foundKey; i++)
	{
		foundKey = InputManager::keyPressed(sf::Keyboard::Key(i));
		if (foundKey)
		{
			key = sf::Keyboard::Key(i);
			if (shiftPressed)
			{
				key += 65;
			}
			else
			{
				key += 97;
			}
		}
	}
	//Numbers
	for (int i = sf::Keyboard::Num0; i <= sf::Keyboard::Num9 && !foundKey; i++)
	{
		foundKey = InputManager::keyPressed(sf::Keyboard::Key(i));
		if (foundKey)
		{
			key = sf::Keyboard::Key(i);
			std::cout << "look at this: " << key << std::endl;
			if (shiftPressed)
			{
				if (i == 26)
					key += 35;
				else
					key += 6;
			}
			else
			{
				key += 22;
			}
			
		}
	}
	//Keypad
	for (int i = sf::Keyboard::Numpad0; i <= sf::Keyboard::Numpad9 && !foundKey; i++)
	{
		foundKey = InputManager::keyPressed(sf::Keyboard::Key(i));
		if (foundKey)
		{
			key = sf::Keyboard::Key(i);
			std::cout << "look at this: " << key << std::endl;
			key -= 27;
		}
	}




	return key;

}
