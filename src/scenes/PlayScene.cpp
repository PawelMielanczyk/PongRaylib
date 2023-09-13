#include <raylib.h>

#include "PlayScene.hpp"
#include "SceneManager.hpp"
#include "../entities/Ball.hpp"
#include "../entities/Paddle.hpp"
#include "../entities/Brick.hpp"
#include "../Constants.hpp"

PlayScene::PlayScene(SceneManager* sceneManager)
{
	this->sceneManager = sceneManager;
	this->ball = new Ball{ ScreenWidth / 2, ScreenHeight / 2 };
	this->paddle = new Paddle{ ScreenWidth / 2, ScreenHeight - 50 };
	this->score = 0;
	this->highScore = 0;
	this->lives = 3;
	this->isPaused = false;
}

PlayScene::~PlayScene()
{
	delete ball;
	delete paddle;
}

void PlayScene::update(float dt)
{
	if (!isPaused)
	{
		ball->update(dt);
		paddle->update(dt);
		checkForCollision();
	}
	else
	{
		if (IsKeyPressed(KEY_X))
			sceneManager->switchScene(TITLE_SCREEN);
	}
	
	
	if (IsKeyPressed(KEY_SPACE))
		isPaused = !isPaused;
}

void PlayScene::draw()
{
	ClearBackground(RAYWHITE);
	ball->draw();
	paddle->draw();
	DrawText(TextFormat("Lives: %d Score: %d High Score: %d", lives, score, highScore), 30, 40, 25, BLACK);
	
	if (isPaused)
	{

		DrawText("Paused", ScreenWidth / 2 - (MeasureText("Pasued", 50) / 2), ScreenHeight / 2 - 50, 50, RED);
		DrawText("Press \'X\' to return to menu", ScreenWidth / 2 - (MeasureText("Press \'X\' to return to menu", 25) / 2), ScreenHeight / 2 - 75, 25, RED);
	}
}

void PlayScene::checkForCollision()
{
	if (CheckCollisionCircleRec(ball->getPosition(), ball->getRadius() + 2, paddle->getRectangle()))
	{
		Vector2 currentBallVelocity = ball->getVelocity();
		ball->setVelocity(Vector2{ currentBallVelocity.x, currentBallVelocity.y * -1});
	}
	Vector2 currentBallPosition = ball->getPosition();
	if (currentBallPosition.x + ball->getRadius() > ScreenWidth || currentBallPosition.x - ball->getRadius() < 0)
	{
		Vector2 currentBallVelocity = ball->getVelocity();
		ball->setVelocity(Vector2{ currentBallVelocity.x * -1, currentBallVelocity.y});
		
	}
	if (currentBallPosition.y + ball->getRadius() > ScreenHeight || currentBallPosition.y - ball->getRadius() < 0)
	{
		Vector2 currentBallVelocity = ball->getVelocity();
		ball->setVelocity(Vector2{ currentBallVelocity.x, currentBallVelocity.y * -1 });
		if (currentBallPosition.y + ball->getRadius() > ScreenHeight)
		{
			decreaseLives();
		}
		if (currentBallPosition.y - ball->getRadius() < 0)
		{
			increaseScore();
		}
	}
}

void PlayScene::decreaseLives()
{
	lives--;
	if (lives == 0)
	{
		score = 0;
		lives = 3;
		ball->setPosition(ScreenWidth / 2, ScreenHeight / 2);
		paddle->setPosition(ScreenWidth / 2, ScreenHeight - 50);
		isPaused = true;
	}
}

void PlayScene::increaseScore()
{
	score++;
	if (score > highScore)
	{
		highScore = score;
	}
}