#pragma once

#include "Entity.hpp"

class Paddle : public Entity
{
public:
	Paddle(int x, int y);
	~Paddle();

	void update(float dt) override;

	void draw() override;

	void setPosition(float x, float y) {};

	Vector2 getPosition() override;

	Rectangle getRectangle();

private:
	int paddleWidth = 150;
	int paddleHight = 25;
	int speed;
};