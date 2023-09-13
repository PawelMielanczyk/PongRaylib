#pragma once

#include "BaseScene.hpp"
#include "GameScenes.hpp"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void switchScene(GameScenes gameScene);

	void update(float dt);
	void draw();

private:
	BaseScene* currentScene;
};