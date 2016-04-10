#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "VisibleGameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void add(std::string name, VisibleGameObject* gameObject);
	void remove(std::string name);
	void removeDestroyingObjects();
	int getObjectCount() const;
	VisibleGameObject* get(std::string name) const;

	void drawAll(sf::RenderWindow& renderWindow);
	void updateAll(float elapsedTime);

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*>& p) const
		{
			delete p.second;
		}
	};
};

#endif