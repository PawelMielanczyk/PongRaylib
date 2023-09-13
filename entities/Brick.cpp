#include <raylib.h>

#include "Brick.hpp"


Brick::Brick(int x, int y)
{
	position = Vector2{ (float)x, (float)y };
}

Brick::~Brick()
{

}

void Brick::draw()
{
	DrawRectangle(position.x, position.y, brickWidth, brickHeight, GREEN);
}

void Brick::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

Vector2 Brick::getPosition()
{
	return position;
}


void Brick::doOnCollision()
{
}
