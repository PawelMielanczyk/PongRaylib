#include <raylib.h>

#include "Paddle.hpp"
#include "../Constants.hpp"

Paddle::Paddle(int x, int y)
{
	this->position = Vector2{ (float) x, (float) y };
	this->speed = 250;
}

Paddle::~Paddle()
{
}

void Paddle::update(float dt)
{
	if (position.x > 0)
	{
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
			position.x -= speed * dt;
	}

	if (position.x + paddleWidth < ScreenWidth)
	{
		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
			position.x += speed * dt;
	}
}

void Paddle::draw()
{
	DrawRectangle(position.x, position.y, paddleWidth, paddleHight, BLACK);
}

Vector2 Paddle::getPosition()
{
	return position;
}

Rectangle Paddle::getRectangle()
{
	return Rectangle{ position.x, position.y, (float) paddleWidth, (float) paddleHight };
}
