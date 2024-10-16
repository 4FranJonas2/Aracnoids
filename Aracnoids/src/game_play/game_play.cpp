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

	Init(player, gameArena, gameMouse, scene);

	while (!WindowShouldClose() && scene == SCENEMANAGMENT::LEAVESIM)
	{
		Input(player, scene);
		Update(player, scene);
		Draw(player, gameArena, scene);
	}

	Close();
}

void Init(Player& player, Rectangle& gameArena, Mouse& gameMouse, SCENEMANAGMENT scene)
{
	switch (scene)
	{
	case SCENEMANAGMENT::NONE:
		srand(time(NULL));
		InitWindow(screenWidth, screenHeight, " Aracnoids by Francisco Jonas ");
		player = gamePlayer::CreatePlayer(player);
		gameArena = arena::createGameArena(gameArena);
		gameMouse = mouse::CreateMouse(gameMouse);

		break;
	case SCENEMANAGMENT::INITSIM:	
		break;
	case SCENEMANAGMENT::MAINMENU:	
		break;
	case SCENEMANAGMENT::CREDITS:	
		break;
	case SCENEMANAGMENT::GAME:	
		break;
	case SCENEMANAGMENT::RESETGAME:	
		break;
	case SCENEMANAGMENT::WINSCRREN:	
		break;
	case SCENEMANAGMENT::LOSESCREEN:	
		break;
	case SCENEMANAGMENT::BACK:	
		break;
	case SCENEMANAGMENT::EXIT:	
		break;
	case SCENEMANAGMENT::LEAVESIM:	
		break;
	default:
		break;
	}

}

void Input(Player& player, SCENEMANAGMENT& scene)
{
	switch (scene)
	{
	case SCENEMANAGMENT::INITSIM:
		break;
	case SCENEMANAGMENT::MAINMENU:
		break;
	case SCENEMANAGMENT::CREDITS:
		break;
	case SCENEMANAGMENT::GAME:
		break;
	case SCENEMANAGMENT::RESETGAME:
		break;
	case SCENEMANAGMENT::WINSCRREN:
		break;
	case SCENEMANAGMENT::LOSESCREEN:
		break;
	case SCENEMANAGMENT::BACK:
		break;
	case SCENEMANAGMENT::EXIT:
		break;
	case SCENEMANAGMENT::LEAVESIM:
		break;
	default:
		break;
	}
}

void Update(Player& player, SCENEMANAGMENT& scene)
{
	switch (scene)
	{
	case SCENEMANAGMENT::INITSIM:
		break;
	case SCENEMANAGMENT::MAINMENU:
		break;
	case SCENEMANAGMENT::CREDITS:
		break;
	case SCENEMANAGMENT::GAME:
		break;
	case SCENEMANAGMENT::RESETGAME:
		break;
	case SCENEMANAGMENT::WINSCRREN:
		break;
	case SCENEMANAGMENT::LOSESCREEN:
		break;
	case SCENEMANAGMENT::BACK:
		break;
	case SCENEMANAGMENT::EXIT:
		break;
	case SCENEMANAGMENT::LEAVESIM:
		break;
	default:
		break;
	}
}

void Draw(Player& player, Rectangle& gameArena, SCENEMANAGMENT scene)
{
	switch (scene)
	{
	case SCENEMANAGMENT::INITSIM:
		break;
	case SCENEMANAGMENT::MAINMENU:
		break;
	case SCENEMANAGMENT::CREDITS:
		break;
	case SCENEMANAGMENT::GAME:
		gamePlayer::DrawPlayer(player);
		arena::drawArena(gameArena);

		break;
	case SCENEMANAGMENT::RESETGAME:
		break;
	case SCENEMANAGMENT::WINSCRREN:
		break;
	case SCENEMANAGMENT::LOSESCREEN:
		break;
	case SCENEMANAGMENT::BACK:
		break;
	case SCENEMANAGMENT::EXIT:
		break;
	case SCENEMANAGMENT::LEAVESIM:
		break;
	default:
		break;
	}
}

static void Close()
{
	CloseWindow();
}