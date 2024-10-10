#include <iostream>
#include "game_play.h"


void Aracnoids()
{
	SCENEMANAGMENT scene;
	Rectangle gameArena;
	Player player;
	Mouse gameMouse;


	Init(player,gameArena);

	while (!WindowShouldClose())
	{
		Input(player);
		Update(player);
		Draw(player, gameArena);
	}

	Close();
}

void Init(Player player, Rectangle gameArena)
{
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, " Aracnoids by Francisco Jonas ");
	player = gamePlayer::CreatePlayer(player);
	arena::createGameArena(gameArena);

}

void Input(Player& player)
{

}

void Update(Player& player)
{
	/*switch (switch_on)
	{
	default:
		break;
	}*/
}

void Draw(Player& player, Rectangle& gameArena)
{
	gamePlayer::DrawPlayer(player);
	arena::drawArena(gameArena);
}

static void Close()
{
	CloseWindow();
}