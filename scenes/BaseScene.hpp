#pragma once

class BaseScene
{
public:
	virtual ~BaseScene() = default;
	virtual void draw() = 0;
	virtual void update(float dt) = 0;
protected:
	class SceneManager* sceneManager;
};