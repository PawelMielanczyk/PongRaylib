#include <raylib.h>

#include "EntityManager.hpp"
#include "../Constants.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
	for (auto entity : entites)
	{
		delete entity;
	}
}

void EntityManager::addEntity(Entity* entity)
{
	entites.push_back(entity);
}

void EntityManager::drawEntites()
{
	for (const auto entity : entites)
	{
		entity->draw();
	}
}

void EntityManager::updateEntites(float dt)
{
	for (const auto entity : entites)
	{
		checkForCollision();
		entity->update(dt);
	}
}

void EntityManager::checkForCollision()
{
	for (int i = 0; i < entites.size(); i++)
	{
		for (int j = i + 1; j < entites.size(); j++)
		{
			if (checkCollisionBetweenEntites(entites.at(i), entites.at(j)))
			{
				entites.at(i)->doOnCollision();
			}
		}
		if (checkCollisionWithWorldEdges(entites.at(i)))
		{
			entites.at(i)->doOnCollision();
		}
	}
}

bool EntityManager::checkCollisionBetweenEntites(Entity* entity1, Entity* entity2)
{
	if (dynamic_cast<Ball*>(entity1) != nullptr && dynamic_cast<Paddle*>(entity2) != nullptr)
	{
		Ball* ballEntity = dynamic_cast<Ball*>(entity1);
		Paddle* paddleEntity = dynamic_cast<Paddle*>(entity2);
		return CheckCollisionCircleRec(ballEntity->getPosition(), ballEntity->getRadius() + 2, paddleEntity->getRectangle());
	}

	//if (dynamic_cast<Paddle*>(entity1) != nullptr && dynamic_cast<Ball*>(entity2) != nullptr)
	//{
	//	Paddle* paddleEntity = dynamic_cast<Paddle*>(entity1);
	//	Ball* ballEntity = dynamic_cast<Ball*>(entity2);
	//	return CheckCollisionCircleRec(ballEntity->getPosition(), ballEntity->getRadius(), paddleEntity->getRectangle());
	//}

	return false;
}

bool EntityManager::checkCollisionWithWorldEdges(Entity* entity)
{
	if (dynamic_cast<Ball*>(entity) != nullptr)
	{
		Ball* ballEntity = dynamic_cast<Ball*>(entity);
		Vector2 ballPosition = ballEntity->getPosition();
		float ballRadius = ballEntity->getRadius();
		if (ballPosition.x + ballRadius > ScreenWidth || ballPosition.x - ballRadius < 0)
		{
			return true;
		}
		if (ballPosition.y + ballRadius > ScreenHeight || ballPosition.y - ballRadius < 0)
		{
			return true;
		}
	}
	return false;
}