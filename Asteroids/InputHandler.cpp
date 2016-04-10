#include "stdafx.h"
#include "InputHandler.h"

InputHandler::InputHandler()
{
	_currentKeys.insert(std::pair<sf::Keyboard::Key, bool>(sf::Keyboard::Space, false));
	_currentKeys.insert(std::pair<sf::Keyboard::Key, bool>(sf::Keyboard::I, false));
	_previousKeys.insert(_currentKeys.begin(), _currentKeys.end());
}

bool InputHandler::isKeyPressed(sf::Keyboard::Key key)
{
	std::map<sf::Keyboard::Key, bool>::iterator it;

	it = _currentKeys.find(key);
	if (it != _currentKeys.end())
	{
		if (it->second == true)
		{
			it = _previousKeys.find(key);
			if (it != _previousKeys.end())
			{
				if (it->second == false) {
					return true;
				}
			}
		}
	}

	return false;
}

bool InputHandler::isKeyDown(sf::Keyboard::Key key)
{
	std::map<sf::Keyboard::Key, bool>::iterator it;

	it = _currentKeys.find(key);
	if (it != _currentKeys.end())
	{
		if (it->second == true)
		{
			return true;
		}
	}

	return false;
}

bool InputHandler::isKeyReleased(sf::Keyboard::Key key)
{
	std::map<sf::Keyboard::Key, bool>::iterator it;

	it = _currentKeys.find(key);
	if (it != _currentKeys.end())
	{
		if (it->second == false)
		{
			it = _previousKeys.find(key);
			if (it != _previousKeys.end())
			{
				if (it->second == true) {
					return true;
				}
			}
		}
	}

	return false;
}

void InputHandler::update()
{
	_previousKeys.clear();
	_previousKeys.insert(_currentKeys.begin(), _currentKeys.end());

	std::map<sf::Keyboard::Key, bool>::iterator it;

	it = _currentKeys.begin();
	if (it != _currentKeys.end())
	{
		it->second = sf::Keyboard::isKeyPressed(it->first);
		it++;
	}
}


void InputHandler::printState()
{
	std::map<sf::Keyboard::Key, bool>::iterator it, it2;

	it = _currentKeys.begin();
	it2 = _previousKeys.begin();
	while (it != _currentKeys.end() && it2 != _previousKeys.end())
	{
		std::cout << " " << it->first << ": " << it->second << " | " << it2->second << std::endl;
		it++;
		it2++;
	}
}
