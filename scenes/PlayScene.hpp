#pragma once

#include "BaseScene.hpp"

class PlayScene : public BaseScene
{
public:
	PlayScene(SceneManager* sceneManager);
	~PlayScene();

	void draw() override;
	void update(float dt) override;
private:
	void checkForCollision();
	void decreaseLives();
	void increaseScore();
	class Ball* ball;
	class Paddle* paddle;
	bool isPaused;
	int score;
	int highScore;
	int lives;
};