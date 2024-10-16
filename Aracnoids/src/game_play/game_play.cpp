#include <iostream>
#include "game_play.h"


void Aracnoids()
{
	SCENEMANAGMENT scene;
	Rectangle gameArena;
	Player player;
	Mouse gameMouse;
	Menu mainMenu;
	Menu credits;
	Menu pauseMenu;
	Menu winScreen;
	Menu loseScreen;
	Menu exitScreen;

	Init(player, gameArena, gameMouse);

	while (!WindowShouldClose() && scene == SCENEMANAGMENT::LEAVESIM)
	{
		Input(player);
		Update(player);
		Draw(player, gameArena);
	}

	Close();
}

void Init(Player& player, Rectangle& gameArena, Mouse& gameMouse)
{
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, " Aracnoids by Francisco Jonas ");
	player = gamePlayer::CreatePlayer(player);
	gameArena = arena::createGameArena(gameArena);
	gameMouse = mouse::CreateMouse(gameMouse);

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