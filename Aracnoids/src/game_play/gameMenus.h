#pragma once
#include "raylib.h"
#include "game_settings/scene_manage.h"
#include "entities/mouse.h"
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
		Button fourthButton;
		Text buttonText{ 0.0f,0.0f,5 };
	};

	Menu CreateMainMenu(Menu mainAndPauseMenu);
	Menu CreateWinLoseScreen(Menu winScreen);
	Menu CreateExitScreen(Menu exitScreen);
	
	void InputMainMenu(Menu mainAndPauseMenu, mouse::Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputCredits( SCENEMANAGMENT& scene);
	void InputPauseMenu(Menu mainAndPauseMenu, mouse::Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputWinLoseScreen(Menu winLoseScreen, mouse::Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputExitScreen(Menu exitScreen, mouse::Mouse gameMouse, SCENEMANAGMENT& scene);

	void DrawMainMenuorPause(Menu mainAndPauseMenu, SCENEMANAGMENT scene);
	void DrawCredits(Menu credits);
	void DrawExitMenu(Menu exitScreen);
	void DrawWinLoseScreen(Menu winLoseScreen);

	void PrintText(const char* text, float posX, float posY, int fontSize, Color color);
	void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color);
	bool isOverButon(mouse::Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension);
}