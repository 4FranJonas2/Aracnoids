#include <iostream>
#include "game_play.h"
#include "raylib.h"

void Aracnoids()
{
	Init();

	while (!WindowShouldClose())
	{

	}

	Close();
}

void Init()
{
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, " PONG by Francisco Jonas ");
}

void Input()
{

}

void Update()
{

}

void Draw()
{

}

static void Close()
{
	CloseWindow();
}