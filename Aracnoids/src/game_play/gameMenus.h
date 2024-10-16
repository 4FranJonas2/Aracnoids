#pragma once
#include "../entities/player.h"

namespace gameMenu
{
	Menu CreateMainMenu(Menu mainMenu);
	Menu CreateWinLoseScreen(Menu winScreen);
	Menu CreateExitScreen(Menu exitScreen);
	
	void InputMainMenu(Menu mainMenu, Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputCredits(Menu credits, Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputPauseMenu(Menu pauseMenu, Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputWinLoseScreen(Menu winScreen, Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputExitScreen(Menu exitScreen, Mouse gameMouse, SCENEMANAGMENT& scene);

	void DrawMainMenuorPause(Menu mainMenu, SCENEMANAGMENT scene);

	void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color);
	bool isOverButon(Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension);
}