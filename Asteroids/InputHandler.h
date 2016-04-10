#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler
{
public:
	InputHandler();

	bool isKeyPressed(sf::Keyboard::Key key);
	bool isKeyDown(sf::Keyboard::Key key);
	bool isKeyReleased(sf::Keyboard::Key key);

	void update();
	void printState();

private:
	std::map<sf::Keyboard::Key, bool> _previousKeys;
	std::map<sf::Keyboard::Key, bool> _currentKeys;

};

#endif