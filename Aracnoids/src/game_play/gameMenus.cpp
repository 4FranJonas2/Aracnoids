#include "gameMenus.h"

namespace gameMenu
{
	Menu CreateMainMenu(Menu mainMenu)
	{
		return mainMenu;
	}
	Menu CreateCredits(Menu credits)
	{
		return credits;
	}
	Menu CreatePauseMenu(Menu pauseMenu)
	{
		return pauseMenu;
	}
	Menu CreateWinScreen(Menu winScreen)
	{
		return winScreen;
	}
	Menu CreateLoseScreen(Menu loseScreen)
	{
		return loseScreen;
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
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(gameMouse, credits.firstButton.buttonPos, credits.firstButton.buttonSize))
		{
			scene = SCENEMANAGMENT::MAINMENU;
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