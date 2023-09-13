#include <raylib.h>

#include "Ball.hpp"

Ball::Ball(int x, int y)
{
	position = Vector2{ (float) x, (float) y };
	velocity = Vector2{ 200, 400 };
	radius = 20;
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;
}

void Ball::draw()
{
	DrawCircle(position.x, position.y, radius, BLACK);
}

void Ball::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

Vector2 Ball::getPosition()
{
	return position;
}

float Ball::getRadius()
{
	return radius;
}

void Ball::doOnCollision()
{
	velocity.x *= -1;
	//
	velocity.y *= -1;
}

void Ball::setVelocity(Vector2 newVelocity)
{
	velocity = newVelocity;
}

Vector2 Ball::getVelocity()
{
	return velocity;
}
