#include "gameMenus.h"

namespace gameMenu
{
	Menu CreateMainMenu(Menu mainMenu)
	{
		//PLAY BUTTON
		mainMenu.firstButton.buttonPos.x = auxButtonPosX;
		mainMenu.firstButton.buttonPos.y = auxButtonPosY_1;

		mainMenu.firstButton.buttonSize.x = buttonWidth;
		mainMenu.firstButton.buttonSize.y = buttonHeiht;
		
		mainMenu.firstButton.buttonCenterPos.x = buttonCenterX;
		mainMenu.firstButton.buttonCenterPos.y = buttonCenterY;
		
		//CREDITS BUTTON
		mainMenu.secondButton.buttonPos.x = auxButtonPosX;
		mainMenu.secondButton.buttonPos.y = auxButtonPosY_1;

		mainMenu.secondButton.buttonSize.x = buttonWidth;
		mainMenu.secondButton.buttonSize.y = buttonHeiht;

		mainMenu.secondButton.buttonCenterPos.x = buttonCenterX;
		mainMenu.secondButton.buttonCenterPos.y = buttonCenterY;

		//EXIT BUTTON
		mainMenu.thirdButton.buttonPos.x = auxButtonPosX;
		mainMenu.thirdButton.buttonPos.y = auxButtonPosY_1;

		mainMenu.thirdButton.buttonSize.x = buttonWidth;
		mainMenu.thirdButton.buttonSize.y = buttonHeiht;

		mainMenu.thirdButton.buttonCenterPos.x = buttonCenterX;
		mainMenu.thirdButton.buttonCenterPos.y = buttonCenterY;

		return mainMenu;
	}
	Menu CreateWinLoseScreen(Menu winScreen)
	{
		return winScreen;
	}
	Menu CreateExitScreen(Menu exitScreen)
	{
		return exitScreen;
	}

	void InputMainMenu(Menu mainMenu, Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// PLAY BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainMenu.firstButton.buttonPos, mainMenu.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::GAME;
		}
		// CREDITS BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainMenu.secondButton.buttonPos, mainMenu.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::CREDITS;
		}
		// EXIT BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, mainMenu.thirdButton.buttonPos, mainMenu.thirdButton.buttonSize))
		{
			scene = SCENEMANAGMENT::EXIT;
		}
	}
	void InputCredits(Menu credits, Mouse gameMouse, SCENEMANAGMENT& scene)
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
	void InputPauseMenu(Menu pauseMenu, Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// RESUME BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, pauseMenu.firstButton.buttonPos, pauseMenu.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::GAME;
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
	void InputWinLoseScreen(Menu winScreen, Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// RESUME BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, winScreen.firstButton.buttonPos, winScreen.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::RESETGAME;
		}
		// RESET BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, winScreen.secondButton.buttonPos, winScreen.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::MAINMENU;
		}
	}
	void InputExitScreen(Menu exitScreen, Mouse gameMouse, SCENEMANAGMENT& scene)
	{
		// EXIT BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, exitScreen.firstButton.buttonPos, exitScreen.firstButton.buttonSize))
		{
			//end simulation
		}
		// GOBACK BUTTON
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, exitScreen.secondButton.buttonPos, exitScreen.secondButton.buttonSize))
		{
			scene = SCENEMANAGMENT::MAINMENU;
		}
	}

	void DrawMainMenuorPause(Menu mainMenu, SCENEMANAGMENT scene)
	{
		
		DrawButton(mainMenu.firstButton.buttonPos, mainMenu.firstButton.buttonSize, WHITE);
		DrawButton(mainMenu.secondButton.buttonPos, mainMenu.secondButton.buttonSize, WHITE);
		DrawButton(mainMenu.thirdButton.buttonPos, mainMenu.thirdButton.buttonSize, WHITE);

		if (scene == SCENEMANAGMENT::MAINMENU)
		{
			DrawText("ARACNOIDS", titleTextPosX, titleTextPosY, fontSize, RED);
			DrawText("PLAY", playTextPosX, playTextPosY, fontSize, RED);
			DrawText("CREDITS",creditsTextButtonPosX, creditsTextButtonPosY, fontSize, RED);
			DrawText("EXIT", exitTextButtonPosX, exitTextButtonPosY, fontSize, RED);
		}
		else
		{
			DrawText("PAUSE", titleTextPosX, titleTextPosY, fontSize, RED);
			DrawText("RESUME", mainMenu.firstButton.buttonPos.x, mainMenu.firstButton.buttonPos.y, fontSize, RED);
			DrawText("RESTART", mainMenu.secondButton.buttonPos.x, mainMenu.secondButton.buttonPos.y, fontSize, RED);
			DrawText("MENU", mainMenu.thirdButton.buttonPos.x, mainMenu.thirdButton.buttonPos.y, fontSize, RED);
		}

	}

	void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color)
	{
		DrawRectangle(buttonPos.x, buttonPos.y, buttonSize.x, buttonSize.y, color);
	}

	bool isOverButon(Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension)
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