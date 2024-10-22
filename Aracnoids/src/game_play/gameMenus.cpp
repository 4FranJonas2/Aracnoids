#pragma once
#include "gameMenus.h"

namespace gameMenu
{
	//BUTTON SIZE
	const float buttonWidth = 60.0f;
	const float buttonHeiht = 30.0f;
	const int fontSize = 5;
	//BUTTON CENTER
	const float buttonCenterX = buttonWidth / 2.0f;
	const float buttonCenterY = buttonHeiht / 2.0f;

	//MAINMENU settings---------------------------------
	//PAUSE MENU settings------------------------------------------
	//button default pos
	const float auxButtonPosX = static_cast<float>(screenWidth) / 2.0f;
	const float auxButtonPosY_1 = ((screenHeight / 5.0f) * 2.0f);
	const float auxButtonPosY_2 = ((screenHeight / 5.0f) * 3.0f);
	const float auxButtonPosY_3 = ((screenHeight / 5.0f) * 4.0f);
	const float auxButtonPosY_4 = ((screenHeight / 5.0f) * 5.0f);
	//text main menu
	const float titleTextPosX = auxButtonPosX;
	const float titleTextPosY = auxButtonPosY_1;
	const float playTextPosX = auxButtonPosX;
	const float playTextPosY = auxButtonPosY_2;
	const float creditsTextButtonPosX = auxButtonPosX;
	const float creditsTextButtonPosY = auxButtonPosY_3;
	const float exitTextButtonPosX = auxButtonPosX;
	const float exitTextButtonPosY = auxButtonPosY_4;

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

	const float restartButtonPosY_3 = (screenHeight / 5) * 4;
	const float toMenuButtonPosY_4 = (screenHeight / 5) * 5;

	Menu CreateMainMenu(Menu mainAndPauseMenu)
	{
		//PLAY BUTTON
		mainAndPauseMenu.firstButton.buttonPos.x = auxButtonPosX;
		mainAndPauseMenu.firstButton.buttonPos.y = auxButtonPosY_1;

		mainAndPauseMenu.firstButton.buttonSize.x = buttonWidth;
		mainAndPauseMenu.firstButton.buttonSize.y = buttonHeiht;
		
		mainAndPauseMenu.firstButton.buttonCenterPos.x = buttonCenterX;
		mainAndPauseMenu.firstButton.buttonCenterPos.y = buttonCenterY;
		
		//CREDITS BUTTON
		mainAndPauseMenu.secondButton.buttonPos.x = auxButtonPosX;
		mainAndPauseMenu.secondButton.buttonPos.y = auxButtonPosY_1;

		mainAndPauseMenu.secondButton.buttonSize.x = buttonWidth;
		mainAndPauseMenu.secondButton.buttonSize.y = buttonHeiht;

		mainAndPauseMenu.secondButton.buttonCenterPos.x = buttonCenterX;
		mainAndPauseMenu.secondButton.buttonCenterPos.y = buttonCenterY;

		//EXIT BUTTON
		mainAndPauseMenu.thirdButton.buttonPos.x = auxButtonPosX;
		mainAndPauseMenu.thirdButton.buttonPos.y = auxButtonPosY_1;

		mainAndPauseMenu.thirdButton.buttonSize.x = buttonWidth;
		mainAndPauseMenu.thirdButton.buttonSize.y = buttonHeiht;

		mainAndPauseMenu.thirdButton.buttonCenterPos.x = buttonCenterX;
		mainAndPauseMenu.thirdButton.buttonCenterPos.y = buttonCenterY;

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
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.firstButton.buttonPos, mainAndPauseMenu.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::GAME;
		}
		// CREDITS BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::CREDITS;
		}
		// EXIT BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize))
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
	void InputPauseMenu(Menu pauseMenu, mouse::Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// RESUME BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, pauseMenu.firstButton.buttonPos, pauseMenu.firstButton.buttonSize))
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
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, pauseMenu.secondButton.buttonPos, pauseMenu.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::CREDITS;
		}
		// BACKMENU BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, pauseMenu.thirdButton.buttonPos, pauseMenu.thirdButton.buttonSize))
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

	void DrawMainMenuorPause(Menu mainAndPauseMenu, SCENEMANAGMENT scene)
	{
		
		DrawButton(mainAndPauseMenu.firstButton.buttonPos, mainAndPauseMenu.firstButton.buttonSize, WHITE);
		DrawButton(mainAndPauseMenu.secondButton.buttonPos, mainAndPauseMenu.secondButton.buttonSize, WHITE);
		DrawButton(mainAndPauseMenu.thirdButton.buttonPos, mainAndPauseMenu.thirdButton.buttonSize, WHITE);

		if (scene == SCENEMANAGMENT::MAINMENU)
		{
			PrintText("ARACNOIDS", titleTextPosX, titleTextPosY, RED);
			PrintText("PLAY", playTextPosX, playTextPosY, RED);
			PrintText("CREDITS", creditsTextButtonPosX, creditsTextButtonPosY, RED);
			PrintText("EXIT", exitTextButtonPosX, exitTextButtonPosY, RED);
		}

		else
		{
			PrintText("PAUSE", titleTextPosX, titleTextPosY, RED);
			PrintText("RESUME", mainAndPauseMenu.firstButton.buttonPos.x, mainAndPauseMenu.firstButton.buttonPos.y, RED);
			PrintText("RESTART", mainAndPauseMenu.secondButton.buttonPos.x, mainAndPauseMenu.secondButton.buttonPos.y, RED);
			PrintText("MENU", mainAndPauseMenu.thirdButton.buttonPos.x, mainAndPauseMenu.thirdButton.buttonPos.y, RED);
		}

	}

	void PrintText(const char *text, float posX, float posY, Color color)
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