#pragma once
#include <iostream>

#include "raylib.h"

#include "game_settings/Constants.h"
#include "game_settings/SceneManage.h"
#include "entities/Mouse.h"

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

	Menu CreateMainMenu();
	Menu CreateWinLoseScreen();
	Menu CreateExitScreen();
	
	void InputMainMenu( mouse::Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputCredits( SCENEMANAGMENT& scene);
	void InputPauseMenu( mouse::Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputWinLoseScreen( mouse::Mouse gameMouse, SCENEMANAGMENT& scene);
	void InputExitScreen( mouse::Mouse gameMouse, SCENEMANAGMENT& scene);

	void DrawMainMenuorPause( SCENEMANAGMENT scene, mouse::Mouse gameMouse);
	void DrawCredits();
	void DrawExitMenu();
	void DrawWinLoseScreen();

	void PrintText(const char* text, float posX, float posY, int fontSize, Color color);
	void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color);
	bool isOverButon(mouse::Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension);
}