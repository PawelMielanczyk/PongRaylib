#pragma once

#include "Entity.hpp"

class Brick : public Entity
{
public:
	Brick(int x, int y);
	~Brick();

	void update(float dt) override {};

	void draw() override;

	void setPosition(float x, float y) override;

	Vector2 getPosition() override;

	void doOnCollision() override;

private:
	int brickWidth = 50;
	int brickHeight = 25;
};