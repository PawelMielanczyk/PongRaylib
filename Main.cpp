// RaylibSetup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <raylib.h>

#include "scenes/SceneManager.hpp"
#include "Constants.hpp"

int main()
{

    InitWindow(ScreenWidth, ScreenHeight, "Pong Raylib");
    SetTargetFPS(60);

    SceneManager sceneManager;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        BeginDrawing();
        sceneManager.draw();
        sceneManager.update(dt);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}