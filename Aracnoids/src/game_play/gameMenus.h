#pragma once
#include "raylib.h"
#include "game_settings/scene_manage.h"
//#include "../entities/player.h"



namespace gameMenu
{
	struct Text
	{
		Vector2 textPos;
		int fontSize;
	};

	struct Button
	{
		Vector2 buttonPos{ 0.0f,0.0f };
		Vector2 buttonSize{ 0.0f,0.0f };
		Vector2 buttonCenterPos{ 0.0f,0.0f };
	};

	struct Menu
	{
		Button firstButton;
		Button secondButton;
		Button thirdButton;
		Button backButton;
		Text buttonText;
	};

	Menu CreateMainMenu(Menu mainMenu);
	Menu CreateWinLoseScreen(Menu winScreen);
	Menu CreateExitScreen(Menu exitScreen);
	
	void InputMainMenu(Menu mainMenu, Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputCredits( SCENEMANAGMENT& scene);
	void InputPauseMenu(Menu pauseMenu, Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputWinLoseScreen(Menu winLoseScreen, Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputExitScreen(Menu exitScreen, Mouse gameMouse, SCENEMANAGMENT& scene);

	void DrawMainMenuorPause(Menu mainMenu, SCENEMANAGMENT scene);

	void PrintText(const char* text, float posX, float posY, Color color);
	void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color);
	bool isOverButon(Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension);
}