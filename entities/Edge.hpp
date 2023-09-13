#pragma once

#include "Entity.hpp"

class Edge : public Entity
{
public:
	Edge(int x, int y);
	~Edge();

	void update(float dt) override;

	void draw() override;

	void setPosition(float x, float y) override;

	Vector2 getPosition() override;

	float getRadius();
};