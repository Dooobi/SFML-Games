#include "stdafx.h"
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject() : 
	_isLoaded(false)
{
}

VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::load(std::string filename) 
{
	if (!_texture.loadFromFile(filename)) {
		_filename = "";
		_isLoaded = false;
	}
	else {
		_filename = filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}

void VisibleGameObject::draw(sf::RenderWindow& renderWindow)
{
	if (_isLoaded) {
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::update(float elapsedTime)
{
}

void VisibleGameObject::setPosition(float x, float y)
{
	if (_isLoaded) {
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::getPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
}

sf::Sprite& VisibleGameObject::getSprite()
{
	return _sprite;
}

bool VisibleGameObject::isLoaded() const
{
	return _isLoaded;
}