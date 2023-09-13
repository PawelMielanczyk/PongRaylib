#include "SceneManager.hpp"
#include "TitleScene.hpp"
#include "PlayScene.hpp"

SceneManager::SceneManager()
{
	currentScene = new TitleScene(this);
}

SceneManager::~SceneManager()
{
	if (currentScene != nullptr)
		delete currentScene;
}

void SceneManager::switchScene(GameScenes gameScene)
{
	if (currentScene != nullptr)
		delete currentScene;

	switch (gameScene)
	{
	case TITLE_SCREEN:
		currentScene = new TitleScene(this);
		break;
	case PLAY:
		currentScene = new PlayScene(this);
		break;
	default:
		break;
	}
}

void SceneManager::draw()
{
	if (currentScene != nullptr)
		currentScene->draw();
}

void SceneManager::update(float dt)
{
	if (currentScene != nullptr)
		currentScene->update(dt);
}
