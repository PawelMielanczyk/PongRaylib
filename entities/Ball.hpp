#pragma once

#include "Entity.hpp"

class Ball : public Entity
{
public:
	Ball(int x, int y);
	~Ball();

	void update(float dt) override;

	void draw() override;

	void setPosition(float x, float y) override;

	void setVelocity(Vector2 newVelocity);

	Vector2 getPosition() override;

	Vector2 getVelocity();

	void doOnCollision() override;

	float getRadius();

private:
	float radius;
	Vector2 velocity;
};