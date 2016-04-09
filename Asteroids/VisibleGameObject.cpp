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

void VisibleGameObject::setSize(int width, int height)
{
	sf::Vector2u textureSize = _sprite.getTexture()->getSize();
	_sprite.setScale(float(width) / textureSize.x, float(height) / textureSize.y);
}

void VisibleGameObject::setScale(float widthScale, float heightScale)
{
	_sprite.setScale(widthScale, heightScale);
}

sf::Sprite& VisibleGameObject::getSprite()
{
	return _sprite;
}

bool VisibleGameObject::isLoaded() const
{
	return _isLoaded;
}