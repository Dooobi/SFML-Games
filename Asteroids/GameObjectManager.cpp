#include "stdafx.h"
#include "GameObjectManager.h"
#include "Asteroid_Big.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(std::string name, VisibleGameObject* gameObject)
{
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
	std::cout << "Deleting Object" << std::endl;
	std::cout << "New Object Count: " << getObjectCount() << std::endl;
}

void GameObjectManager::removeDestroyingObjects()
{
	std::map<std::string, VisibleGameObject*> buffer(_gameObjects);
	std::map<std::string, VisibleGameObject*>::iterator itr = buffer.begin();

	while (itr != buffer.end())
	{
		if (itr->second->isDestroying())
		{
			remove(itr->first);
		}
		itr++;
	}
}

VisibleGameObject* GameObjectManager::get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
		return NULL;
	return results->second;
}

int GameObjectManager::getObjectCount() const
{
	return _gameObjects.size();
}

void GameObjectManager::drawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->draw(renderWindow);
		itr++;
	}
}

void GameObjectManager::updateAll(float elapsedTime)
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	
	while (itr != _gameObjects.end())
	{
		itr->second->update(elapsedTime);
		itr++;
	}
}