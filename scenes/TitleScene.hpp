#pragma once

#include "BaseScene.hpp"

class TitleScene : public BaseScene
{
public:
	TitleScene(SceneManager* sceneManager);
	~TitleScene();

	void draw() override;
	void update(float dt) override;
};

