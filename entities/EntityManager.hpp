#pragma once

#include <vector>

#include "Entity.hpp"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();
	void addEntity(Entity* entity);
	void updateEntites(float dt);
	void drawEntites();
private:
	void checkForCollision();
	bool checkCollisionBetweenEntites(Entity* entity1, Entity* entity2);
	bool checkCollisionWithWorldEdges(Entity* entity);
	std::vector<Entity*> entites;
};