#pragma once
#include <iostream>
#include "game_play.h"



void Aracnoids()
{
	SCENEMANAGMENT scene;
	Rectangle gameArena;
	gamePlayer:: Player player;
	mouse::Mouse gameMouse;
	gameMenu::Menu mainAndPauseMenu;
	gameMenu::Menu credits;
	gameMenu::Menu pauseMenu;
	gameMenu::Menu winLoseScreen;
	gameMenu::Menu exitScreen;

	Init(player, gameArena, gameMouse, scene);

	while (!WindowShouldClose() && scene == SCENEMANAGMENT::LEAVESIM)
	{
		Input(player, scene, gameMouse, mainAndPauseMenu, pauseMenu, winLoseScreen, exitScreen);
		Update(player, scene, gameMouse, mainAndPauseMenu, credits, pauseMenu, winLoseScreen, exitScreen);
		Draw(player, gameArena, scene, gameMouse, mainAndPauseMenu, credits, pauseMenu, winLoseScreen, exitScreen);
	}

	Close();
}

void Init(gamePlayer::Player& player, Rectangle& gameArena, mouse::Mouse& gameMouse, SCENEMANAGMENT& scene)
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
void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene,mouse ::Mouse gameMouse, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu pauseMenu,gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen)
{
	switch (scene)
	{
	case SCENEMANAGMENT::MAINMENU:
		gameMenu::InputMainMenu(mainAndPauseMenu,gameMouse,scene);
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
void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse gameMouse, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu credits, gameMenu::Menu pauseMenu, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen)
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
void Draw(gamePlayer::Player& player, Rectangle& gameArena, SCENEMANAGMENT scene, mouse::Mouse gameMouse, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu credits, gameMenu::Menu pauseMenu, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen)
{
	switch (scene)
	{
	case SCENEMANAGMENT::INITSIM:
		break;
	case SCENEMANAGMENT::MAINMENU:
		gameMenu::DrawMainMenuorPause(mainAndPauseMenu,scene);
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