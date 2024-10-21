#pragma once
#include <iostream>

#include "game_play.h"
#include "entities/mouse.h"
#include "game_settings/utils.h"

void Aracnoids()
{
	SCENEMANAGMENT scene;
	RectangleGame gameArena;
	Player player;
	Mouse gameMouse;
	Menu mainMenu;
	Menu credits;
	Menu pauseMenu;
	Menu winLoseScreen;
	Menu exitScreen;

	Init(player, gameArena, gameMouse, scene);

	while (!WindowShouldClose() && scene == SCENEMANAGMENT::LEAVESIM)
	{
		Input(player, scene, gameMouse, mainMenu, pauseMenu, winLoseScreen, exitScreen);
		Update(player, scene, gameMouse, mainMenu, credits, pauseMenu, winLoseScreen, exitScreen);
		Draw(player, gameArena, scene, gameMouse, mainMenu, credits, pauseMenu, winLoseScreen, exitScreen);
	}

	Close();
}

void Init(Player& player, RectangleGame& gameArena, Mouse& gameMouse, SCENEMANAGMENT& scene)
{
	switch (scene)
	{
	case SCENEMANAGMENT::NONE:
		//srand(time(0));
		InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " Aracnoids by Francisco Jonas ");
		player = gamePlayer::CreatePlayer(player);
		gameArena = arena::createGameArena(gameArena);
		gameMouse = mouse::CreateMouse(gameMouse);
		scene = SCENEMANAGMENT::MAINMENU;
	default:
		break;
	}

}
void Input(Player& player, SCENEMANAGMENT& scene,Mouse gameMouse, Menu mainMenu, 
				Menu pauseMenu, Menu winLoseScreen, Menu exitScreen)
{
	switch (scene)
	{
	case SCENEMANAGMENT::MAINMENU:
		gameMenu::InputMainMenu(mainMenu,gameMouse,scene);
		break;

	case SCENEMANAGMENT::CREDITS:
		gameMenu::InputCredits(scene);
		break;

	case SCENEMANAGMENT::GAME:
		gamePlayer::InputPlayer(player);
		break;

	case SCENEMANAGMENT::WINLOSESCRREN:
		gameMenu::InputWinLoseScreen(winLoseScreen, gameMouse, scene);
		break;

	case SCENEMANAGMENT::PAUSE:
		gameMenu::InputPauseMenu(pauseMenu, gameMouse, scene);
		break;

	case SCENEMANAGMENT::EXIT:
		gameMenu::InputExitScreen(exitScreen, gameMouse, scene);
		break;
	default:
		break;
	}
}
void Update(Player& player, SCENEMANAGMENT& scene, Mouse gameMouse, Menu mainMenu,
	Menu credits, Menu pauseMenu, Menu winLoseScreen, Menu exitScreen)
{
	switch (scene)
	{
	case SCENEMANAGMENT::GAME:
		gamePlayer::UpdatePlayer(player);
		break;
	case SCENEMANAGMENT::RESETGAME:

		break;
	case SCENEMANAGMENT::WINLOSESCRREN:
		break;

	default:
		break;
	}
}
void Draw(Player& player, RectangleGame& gameArena, SCENEMANAGMENT scene, 
	Mouse gameMouse, Menu mainMenu, Menu credits, Menu pauseMenu, Menu winLoseScreen, Menu exitScreen)
{
	switch (scene)
	{
	case SCENEMANAGMENT::INITSIM:
		break;
	case SCENEMANAGMENT::MAINMENU:
		gameMenu::DrawMainMenuorPause(mainMenu,scene);
		break;
	case SCENEMANAGMENT::CREDITS:
		break;
	case SCENEMANAGMENT::GAME:
		gamePlayer::DrawPlayer(player);
		arena::drawArena(gameArena);

		break;
	case SCENEMANAGMENT::RESETGAME:
		break;
	case SCENEMANAGMENT::WINLOSESCRREN:
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