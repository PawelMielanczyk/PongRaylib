#pragma once

class Entity
{
public:
	virtual void update(float dt) = 0;
	virtual void draw() = 0;

	virtual void setPosition(float x, float y) = 0;
	virtual struct Vector2 getPosition() = 0;
	virtual void doOnCollision() {};
protected:
	struct Vector2 position;
};