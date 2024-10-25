#include <iostream>
#include "game_play.h"

void RunGame()
{
	SCENEMANAGMENT scene = SCENEMANAGMENT::NONE;
	Rectangle gameArena;
	gamePlayer:: Player player;
	mouse::Mouse gameMouse;
	gameMenu::Menu mainAndPauseMenu;
	gameMenu::Menu credits;
	gameMenu::Menu winLoseScreen;
	gameMenu::Menu exitScreen;

	Init(player, gameArena, gameMouse, scene, mainAndPauseMenu, winLoseScreen, exitScreen);

	while (!WindowShouldClose())
	{
		Input(player, scene, gameMouse, mainAndPauseMenu, winLoseScreen, exitScreen);
		Update(player, scene, gameMouse);
		Draw(player, gameArena, scene, mainAndPauseMenu, credits, winLoseScreen, exitScreen, gameMouse);
	}

	Close();
}

void Init(gamePlayer::Player& player, Rectangle& gameArena, mouse::Mouse& gameMouse, SCENEMANAGMENT& scene, gameMenu::Menu& mainAndPauseMenu,
	gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen)
{
	switch (scene)
	{
	case SCENEMANAGMENT::NONE:
		//srand(time(0));
		InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " RunGame by Francisco Jonas ");
		player = gamePlayer::CreatePlayer(player);
		gameArena = arena::createGameArena(gameArena);
		gameMouse = mouse::CreateMouse(gameMouse);
		mainAndPauseMenu = gameMenu::CreateMainMenu(mainAndPauseMenu);
		winLoseScreen = gameMenu::CreateWinLoseScreen(winLoseScreen);
		exitScreen = gameMenu::CreateExitScreen(exitScreen);

		scene = SCENEMANAGMENT::MAINMENU;
	default:
		break;
	}

}
void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene,mouse ::Mouse gameMouse, gameMenu::Menu& mainAndPauseMenu,
	gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen)
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
		gameMenu::InputPauseMenu(mainAndPauseMenu, gameMouse, scene);
		break;

	case SCENEMANAGMENT::EXIT:
		gameMenu::InputExitScreen(exitScreen, gameMouse, scene);
		break;
	default:
		break;
	}
}
void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse& gameMouse)
{
	mouse::UpdateMousePos(gameMouse);

	switch (scene)
	{
	case SCENEMANAGMENT::GAME:
		gamePlayer::UpdatePlayer(player, gameMouse);
		break;
	case SCENEMANAGMENT::RESETGAME:
		
		break;
	case SCENEMANAGMENT::WINLOSESCRREN:
		break;

	default:
		break;
	}
}
void Draw(gamePlayer::Player& player, Rectangle& gameArena, SCENEMANAGMENT scene, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu credits, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen, mouse::Mouse gameMouse)
{
	BeginDrawing();
	ClearBackground(BLACK);
	switch (scene)
	{
	case SCENEMANAGMENT::MAINMENU:
		gameMenu::DrawMainMenuorPause(mainAndPauseMenu,scene, gameMouse);
		break;
	case SCENEMANAGMENT::CREDITS:
		gameMenu::DrawCredits(credits);
		break;
	case SCENEMANAGMENT::GAME:
		gamePlayer::DrawPlayer(player);
		arena::drawArena(gameArena);
		break;
	case SCENEMANAGMENT::WINLOSESCRREN:
		gameMenu::DrawWinLoseScreen(winLoseScreen);
		break;
	case SCENEMANAGMENT::PAUSE:
		gameMenu::DrawMainMenuorPause(mainAndPauseMenu, scene, gameMouse);
		break;
	case SCENEMANAGMENT::EXIT:
		gameMenu::DrawExitMenu(exitScreen);
		break;
	default:
		break;
	}

	EndDrawing();
}

 void Close()
{
	CloseWindow();
}