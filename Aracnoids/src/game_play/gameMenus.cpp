#pragma once
#include "gameMenus.h"
#include "game_settings/constants.h"

namespace gameMenu
{
	//BUTTON SIZE
	const float buttonWidth = 150.0f;
	const float buttonHeiht = 40.0f;
	const int textFontSize = 25;
	const int titleFontSize = 50;
	const float auxXCorrect = 75.0f;
	const float auxTitleXCorrect = 65.0f;
	//BUTTON CENTER
	const float buttonCenterX = (buttonWidth / 4.0f) + 10.0f;
	const float buttonCenterY = buttonHeiht / 4.0f;

	//MAINMENU settings---------------------------------
	//PAUSE MENU settings------------------------------------------
	//button default pos
	const float auxButtonPosX = midScreenWidth - auxXCorrect;
	const float auxButtonPosY_1 = screenHeightDiv6 * 1.0f;
	const float auxButtonPosY_2 = screenHeightDiv6 * 2.0f;
	const float auxButtonPosY_3 = screenHeightDiv6 * 3.0f;
	const float auxButtonPosY_4 = screenHeightDiv6 * 4.0f;
	//text main menu
	const float titleTextPosX = auxButtonPosX;
	const float titleTextPosY = auxButtonPosY_1;
	const float playTextPosX = auxButtonPosX + buttonCenterX;
	const float playTextPosY = auxButtonPosY_2 + buttonCenterY;
	const float creditsTextButtonPosX = auxButtonPosX + buttonCenterX / 2;
	const float creditsTextButtonPosY = auxButtonPosY_3 + buttonCenterY;
	const float exitTextButtonPosX = auxButtonPosX + buttonCenterX;
	const float exitTextButtonPosY = auxButtonPosY_4 + buttonCenterY;

	//CREDITS settings-----------------------------------
	const float auxCreditsTextPosX = screenWidth / 3;
	const float creditsText1PosY = (screenHeight / 7);
	const float creditsText2PosY = (screenHeight / 7) * 2;
	const float creditsText3PosY = (screenHeight / 7) * 3;
	const float creditsText4PosY = (screenHeight / 7) * 4;
	const float creditsText5PosY = (screenHeight / 7) * 5;
	const float creditsText6PosY = (screenHeight / 7) * 6;

	const float creditsText7PosY = (screenHeight / 7) * 7;
	const float backButtonPosX = screenWidth / 5;
	const float backButtonPosY = screenWidth / 5;

	//EXIT-----------------------------------------------
	//question text1
	const float auxExitTextPosX = screenWidth / 3;
	const float exitText1PosY = (screenHeight / 7);
	//button YES NO exit
	const float auxExitButtonPosY = (screenHeight / 5) * 4;
	const float auxExitButtonPosX_1 = (screenWidth / 5) * 2;
	const float auxExitButtonPosX_2 = (screenWidth / 5) * 4;
	//text YES NO exit
	const float auxExitText2PosY = (screenHeight / 7) * 2;
	const float exitText3PosX = auxExitButtonPosX_1;
	const float exitText1PosX = auxExitButtonPosX_2;

	//WIN/LOSE SCREEN------------------------------------------
	//TO MENU and RESTART button
	//WIN LOSE title
	const float auxWinLoseTextPosX = auxButtonPosX;
	const float winLoseTextPosY = auxButtonPosY_1;
	const float restartTextPosY = auxButtonPosY_2;
	const float toMenuTextPosY = auxButtonPosY_3;

	//use auxbuttonpos for X position
	const float restartButtonPosY_3 = screenHeightDiv6 * 4;
	const float toMenuButtonPosY_4 = screenHeightDiv6 * 5;

	Menu CreateMainMenu(Menu mainAndPauseMenu)
	{
		//PLAY BUTTON
		mainAndPauseMenu.secondButton.buttonPos.x = auxButtonPosX;
		mainAndPauseMenu.secondButton.buttonPos.y = auxButtonPosY_2;

		mainAndPauseMenu.secondButton.buttonSize.x = buttonWidth;
		mainAndPauseMenu.secondButton.buttonSize.y = buttonHeiht;

		mainAndPauseMenu.secondButton.buttonCenterPos.x = buttonCenterX;
		mainAndPauseMenu.secondButton.buttonCenterPos.y = buttonCenterY;

		//CREDITS BUTTON
		mainAndPauseMenu.thirdButton.buttonPos.x = auxButtonPosX;
		mainAndPauseMenu.thirdButton.buttonPos.y = auxButtonPosY_3;

		mainAndPauseMenu.thirdButton.buttonSize.x = buttonWidth;
		mainAndPauseMenu.thirdButton.buttonSize.y = buttonHeiht;

		mainAndPauseMenu.thirdButton.buttonCenterPos.x = buttonCenterX;
		mainAndPauseMenu.thirdButton.buttonCenterPos.y = buttonCenterY;

		//EXIT BUTTON
		mainAndPauseMenu.fourthButton.buttonPos.x = auxButtonPosX;
		mainAndPauseMenu.fourthButton.buttonPos.y = auxButtonPosY_4;

		mainAndPauseMenu.fourthButton.buttonSize.x = buttonWidth;
		mainAndPauseMenu.fourthButton.buttonSize.y = buttonHeiht;

		mainAndPauseMenu.fourthButton.buttonCenterPos.x = buttonCenterX;
		mainAndPauseMenu.fourthButton.buttonCenterPos.y = buttonCenterY;

		return mainAndPauseMenu;
	}
	Menu CreateWinLoseScreen(Menu winScreen)
	{
		return winScreen;
	}
	Menu CreateExitScreen(Menu exitScreen)
	{
		return exitScreen;
	}

	void InputMainMenu(Menu mainAndPauseMenu, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// PLAY BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, 
			mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::GAME;
		}
		// CREDITS BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, 
			mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize))
		{
			scene = SCENEMANAGMENT::CREDITS;
		}
		// EXIT BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, 
			mainAndPauseMenu.fourthButton.buttonPos, mainAndPauseMenu.fourthButton.buttonSize))
		{
			scene = SCENEMANAGMENT::EXIT;
		}
	}
	void InputCredits(SCENEMANAGMENT& scene)
	{
		// BACK BUTTON
		if (IsKeyPressed(KEY_ESCAPE))
		{
			if (IsKeyReleased(KEY_ESCAPE))
			{
				scene = SCENEMANAGMENT::MAINMENU;
			}
		}
	}
	void InputPauseMenu(Menu mainAndPauseMenu, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// RESUME BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.firstButton.buttonPos, mainAndPauseMenu.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::GAME;
		}
		if (IsKeyPressed(KEY_ESCAPE))
		{
			if (IsKeyReleased(KEY_ESCAPE))
			{
				scene = SCENEMANAGMENT::GAME;
			}
		}
		// RESET BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::CREDITS;
		}
		// BACKMENU BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize))
		{
			scene = SCENEMANAGMENT::EXIT;
		}
	}
	void InputWinLoseScreen(Menu winLoseScreen, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// RESUME BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, winLoseScreen.firstButton.buttonPos, winLoseScreen.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::RESETGAME;
		}
		// RESET BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, winLoseScreen.secondButton.buttonPos, winLoseScreen.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::MAINMENU;
		}
	}
	void InputExitScreen(Menu exitScreen, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// EXIT BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, exitScreen.firstButton.buttonPos, exitScreen.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::LEAVESIM;
		}
		// GOBACK BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, exitScreen.secondButton.buttonPos, exitScreen.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::MAINMENU;
		}
	}

	/*gameMenu::Menu mainAndPauseMenu;
	gameMenu::Menu credits;
	gameMenu::Menu winLoseScreen;
	gameMenu::Menu exitScreen;*/

	void DrawMainMenuorPause(Menu mainAndPauseMenu, SCENEMANAGMENT scene, mouse::Mouse gameMouse)
	{
		if (isOverButon(gameMouse,mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
			DrawButton(mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize, RAYWHITE);
		else
			DrawButton(mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize, WHITE);
		
		if (isOverButon(gameMouse, mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
			DrawButton(mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize, RAYWHITE);
		else
			DrawButton(mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize, WHITE);
		
		if (isOverButon(gameMouse, mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
			DrawButton(mainAndPauseMenu.fourthButton.buttonPos, mainAndPauseMenu.fourthButton.buttonSize, RAYWHITE);
		else
			DrawButton(mainAndPauseMenu.fourthButton.buttonPos, mainAndPauseMenu.fourthButton.buttonSize, WHITE);
		
		if (scene == SCENEMANAGMENT::MAINMENU)
		{
			PrintText("ARACNOIDS", (titleTextPosX - auxTitleXCorrect), titleTextPosY, titleFontSize, RED);
			PrintText("PLAY", playTextPosX, playTextPosY, textFontSize, RED);
			PrintText("CREDITS", creditsTextButtonPosX, creditsTextButtonPosY, textFontSize, RED);
			PrintText("EXIT", exitTextButtonPosX, exitTextButtonPosY, textFontSize, RED);
		}

		else
		{
			PrintText("PAUSE", titleTextPosX, titleTextPosY, textFontSize, RED);
			PrintText("RESUME", mainAndPauseMenu.firstButton.buttonPos.x, mainAndPauseMenu.firstButton.buttonPos.y, textFontSize, RED);
			PrintText("RESTART", mainAndPauseMenu.secondButton.buttonPos.x, mainAndPauseMenu.secondButton.buttonPos.y, textFontSize, RED);
			PrintText("MENU", mainAndPauseMenu.thirdButton.buttonPos.x, mainAndPauseMenu.thirdButton.buttonPos.y, textFontSize, RED);
		}

	}
	void DrawCredits(Menu credits)
	{
		credits.fourthButton.buttonPos.x = 0.0f;
	}
	void DrawExitMenu(Menu exitScreen)
	{
		exitScreen.firstButton.buttonPos.x = 0.0f;
	}
	void DrawWinLoseScreen(Menu winLoseScreen)
	{
		winLoseScreen.firstButton.buttonPos.x = 0.0f;
	}

	void PrintText(const char* text, float posX, float posY, int fontSize, Color color)
	{
		DrawText(text, static_cast<int>(posX), static_cast<int>(posY), fontSize, color);
	}

	void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color)
	{
		DrawRectangle(static_cast<int>(buttonPos.x), static_cast<int>(buttonPos.y), static_cast<int>(buttonSize.x), static_cast<int>(buttonSize.y), color);
	}
	bool isOverButon(mouse::Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension)
	{
		if (mouse.mousePos.x >= buttonPos.x &&
			mouse.mousePos.x <= buttonPos.x + buttonDimension.x &&
			mouse.mousePos.y >= buttonPos.y &&
			mouse.mousePos.y <= buttonPos.y + buttonDimension.y)
		{
			return true;
		}
		return false;
	}
}