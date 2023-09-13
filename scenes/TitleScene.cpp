#include <raylib.h>

#include "TitleScene.hpp"
#include "SceneManager.hpp"

TitleScene::TitleScene(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
}

TitleScene::~TitleScene()
{

}

void TitleScene::update(float dt)
{
	if (IsKeyPressed(KEY_C))
		sceneManager->switchScene(PLAY);
}

void TitleScene::draw()
{
	ClearBackground(RAYWHITE);
	DrawText("Press C to play", 10, 10, 30, BLACK);
}