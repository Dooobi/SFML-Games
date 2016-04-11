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
	std::multimap<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

void GameObjectManager::remove(VisibleGameObject* object)
{

}

void GameObjectManager::removeDestroyingObjects()
{
	std::multimap<std::string, VisibleGameObject*> buffer(_gameObjects);
	std::multimap<std::string, VisibleGameObject*>::iterator itr = buffer.begin();

	while (itr != buffer.end())
	{
		if (itr->second->isDestroying())
		{
			remove(itr->second);
		}
		itr++;
	}
}

std::vector<VisibleGameObject*> GameObjectManager::get(std::string name) const
{
	std::vector<VisibleGameObject*> vec;

	std::multimap<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	while (results != _gameObjects.end())
		vec.push_back(results->second);

	return vec;
}

int GameObjectManager::getObjectCount() const
{
	return _gameObjects.size();
}

void GameObjectManager::drawAll(sf::RenderWindow& renderWindow)
{
	std::multimap<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->draw(renderWindow);
		itr++;
	}
}

void GameObjectManager::updateAll(float elapsedTime)
{
	std::multimap<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	
	while (itr != _gameObjects.end())
	{
		itr->second->update(elapsedTime);
		itr++;
	}
}