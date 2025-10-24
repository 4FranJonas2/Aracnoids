#include "menu.h"

namespace aracnoids
{
	Vector2 recSize = { 90.0, 50.0 };

	bool IsMouseOverButton(Rectangle buttonRec);

	bool IsMouseOverButton(Rectangle buttonRec)
	{
		Vector2 mousePos = GetMousePosition();

		float left = buttonRec.x - buttonRec.x / 2;
		float right = buttonRec.x + buttonRec.x / 2;
		float top = buttonRec.y + buttonRec.y / 2;
		float bottom = buttonRec.y - buttonRec.y / 2;

		if (mousePos.x >= left && mousePos.x <= right && mousePos.y <= top && mousePos.y >= bottom)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void InitButtons(MenuButtons& buttons)
	{
		buttons.backButton.x = 80.0;
		buttons.backButton.y = 45.0;
		buttons.backButton.width = 100.0;
		buttons.backButton.height = 50.0;

		buttons.linkButton.x = 575.0;
		buttons.linkButton.y = 485.0;
		buttons.linkButton.width = 330.0;
		buttons.linkButton.height = 30.0;

		buttons.playButton.x = 395.0;
		buttons.playButton.y = 390.0;
		buttons.playButton.width = 100.0;
		buttons.playButton.height = 40.0;

		buttons.rulesButton.x = 395.0;
		buttons.rulesButton.y = 320.0;
		buttons.rulesButton.width = 130.0;
		buttons.rulesButton.height = 40.0;

		buttons.creditsButton.x = 395.0;
		buttons.creditsButton.y = 260.0;
		buttons.creditsButton.width = 150.0;
		buttons.creditsButton.height = 40.0;

		
	}

	void UpdateSceneMenus(GameStats& gameStats, MenuButtons buttons)
	{
		if (gameStats.gameStatus == SceneStatus::GAMEMENU)
		{
			if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.playButton))
			{
				gameStats.gameStatus = SceneStatus::GAMEPLAY;
			}
			else if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.rulesButton))
			{
				gameStats.gameStatus = SceneStatus::GAMERULES;
			}
			else if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.creditsButton))
			{
				gameStats.gameStatus = SceneStatus::GAMECREDITS;
			}
		}

		else if (gameStats.gameStatus == SceneStatus::GAMERULES)
		{
			if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backButton))
			{
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
		}

		else if (gameStats.gameStatus == SceneStatus::GAMECREDITS)
		{
			if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.linkButton))
			{
				system("start https://4franjonas2.itch.io/");
			}

			else if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backButton))
			{
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
		}
	}

	void DrawMainMenu(GameStats gameStats)
	{
		if (gameStats.gameStatus == SceneStatus::GAMEMENU)
		{
			int lineText1PosX = GetScreenWidth() / 2 - 140;
			int LineText1PosY = 150;
		
			int LineText2PosX = GetScreenWidth() / 2 - 25;
			int LineText2PosY = 280;
	
			int LineText3PosX = GetScreenWidth() / 2 - 35;
			int LineText3PosY = 340;
		
			int LineText4PosX = GetScreenWidth() / 2 - 45;
			int LineText4PosY = 400;
		
			int LineText5PosX = 360;
			int LineText5PosY = 750;

			//int auxXPos = 15;
			int titleFontSize = 50;
			int defaultFontSize = 30;
			int exitFontSize = 15;

			string titleText = "ARACNOIDS";
			string playText = "Play";
			string rulesext = "Rules";
			string creditsText = "Credits";
			string exitText = "Press ESC at ANY momment to CLOSE the game";

			DrawText("ARACNOIDS", lineText1PosX, LineText1PosY, titleFontSize, WHITE);
			DrawText("Play", LineText2PosX, LineText2PosY, defaultFontSize, WHITE);
			DrawText("Rules", LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
			DrawText("Credits", LineText4PosX, LineText4PosY, defaultFontSize, WHITE);

			DrawText("Press ESC at ANY momment to CLOSE the game", LineText5PosX, LineText5PosY, exitFontSize, WHITE);
		}
	}

	//void DrawRulesMenu(GameStats gameStats, MenuButtons buttons)
	//{
	//	float lineText1PosX = GetScreenWidth() / 2 - 50.0;
	//	float LineText1PosY = 600.0;

	//	float LineText2PosX = 100.0;
	//	float LineText2PosY = 480.0;

	//	float LineText3PosX = GetScreenWidth() / 2 - 150.0;
	//	float LineText3PosY = 410.0;

	//	float LineText4PosX = 100.0;
	//	float LineText4PosY = 330.0;

	//	float LineText5PosX = 170.0;
	//	float LineText5PosY = 300.0;

	//	float LineText6PosX = 50.0;
	//	float LineText6PosY = 35.0;

	//	float LineText7PosX = 170.0;
	//	float LineText7PosY = 240.0;

	//	float LineText8PosX = 170.0;
	//	float LineText8PosY = 210.0;

	//	float LineText9PosX = 170.0;
	//	float LineText9PosY = 180.0;

	//	if (gameStats.gameStatus == SceneStatus::GAMERULES)
	//	{
	//		int auxXPos = 15.0;
	//		int auxFontSize = 15;
	//		string titleText = "RULES";
	//		string howToMoveText = "-To move use A and D keys to move player horizontal.";
	//		string winConditionText = "-Break all the blocks to win";
	//		string loseConditionText1 = "-You will have 3 Lives, if the ball touch the bottom you ";
	//		string loseConditionText2 = "lose 1 live, lose them all and its game over.";
	//		string redCocoText = "RED coconut (PowerDown) slows you down.";
	//		string yellowCocoText = "YELLOW coconut (PowerDown) makes you smaller.";
	//		string greenCocoText = "GREEN coconut (PowerUp) makes you bigger.";
	//		string exitText = "Back";

	//		PrintMenuText(lineText1PosX, LineText1PosY, titleText);

	//		slSetFontSize(15);
	//		PrintMenuText(LineText2PosX, LineText2PosY, howToMoveText);
	//		PrintMenuText(LineText3PosX, LineText3PosY, winConditionText);
	//		PrintMenuText(LineText4PosX - auxXPos, LineText4PosY, loseConditionText1);
	//		PrintMenuText(LineText5PosX - auxXPos, LineText5PosY, loseConditionText2);

	//		PrintMenuText(LineText7PosX - auxXPos, LineText7PosY, redCocoText);
	//		PrintMenuText(LineText8PosX - auxXPos, LineText8PosY, yellowCocoText);
	//		PrintMenuText(LineText9PosX - auxXPos, LineText9PosY, greenCocoText);

	//		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	//		slSprite(gameStats.redCoconut, 120.0, 245.0, 16, 16);
	//		slSprite(gameStats.yellowCoconut, 120.0, 215.0, 16, 16);
	//		slSprite(gameStats.greenCoconut, 120.0, 185.0, 16, 16);

	//		slSetFontSize(gameStats.fontSize);

	//		slSprite(gameStats.backButton, buttons.backButton.recPos.x, buttons.backButton.recPos.y,
	//			buttons.backButton.recSize.x, buttons.backButton.recSize.y);
	//		PrintMenuText(LineText6PosX - auxXPos, LineText6PosY, exitText);
	//		slSetForeColor(1.0, 1.0, 1.0, 1.0);

	//		//DrawButtonRec(buttons.backButton);
	//	}

	//}

	//void DrawCreditsMenu(GameStats gameStats, MenuButtons buttons)
	//{
	//	float lineText1PosX = gameStats.screenWidth / 2 - 50.0;
	//	float LineText1PosY = 600.0;

	//	float LineText2PosX = 10.0;
	//	float LineText2PosY = 480.0;

	//	float LineText3PosX = 10.0;
	//	float LineText3PosY = 440.0;

	//	float LineText6PosX = 50.0;
	//	float LineText6PosY = 35.0;

	//	if (gameStats.gameStatus == SceneStatus::GAMECREDITS)
	//	{
	//		int auxXPos = 15.0;
	//		int auxFontSize = 15;
	//		string titleText = "CREDITS";

	//		string howToMoveText = "-Game made by me Francisco Jonas: https://4franjonas2.itch.io/.";
	//		string creditText1 = "-Game assests made by Francisco Jonas";
	//		string exitText = "Back";

	//		PrintMenuText(lineText1PosX, LineText1PosY, titleText);

	//		slSetFontSize(15);
	//		PrintMenuText(LineText2PosX, LineText2PosY, howToMoveText);
	//		PrintMenuText(LineText3PosX, LineText3PosY, creditText1);

	//		slSetFontSize(gameStats.fontSize);
	//		PrintMenuText(LineText6PosX - auxXPos, LineText6PosY, exitText);

	//		DrawButtonRec(buttons.linkButton);

	//		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	//		slSprite(gameStats.backButton, buttons.backButton.recPos.x, buttons.backButton.recPos.y,
	//			buttons.backButton.recSize.x, buttons.backButton.recSize.y);
	//		PrintMenuText(LineText6PosX - auxXPos, LineText6PosY, exitText);
	//		slSetForeColor(1.0, 1.0, 1.0, 1.0);

	//	}
	//	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	//}

	//void DrawPause(GameStats gameStats)
	//{
	//	if (gameStats.gameStatus == SceneStatus::GAMEPAUSE || gameStats.gameStatus == SceneStatus::FIRSTGAME)
	//	{
	//		float lineText1PosX = gameStats.screenWidth / 2 - 90.0;
	//		float LineText1PosY = 580.0;

	//		float LineText2PosX = gameStats.screenWidth / 2 - 135.0;
	//		float LineText2PosY = 310.0;

	//		float LineText3PosX = gameStats.screenWidth / 2 - 100.0;
	//		float LineText3PosY = 270.0;

	//		float LineText4PosX = 190;
	//		float LineText4PosY = 220.0;

	//		float LineText5PosX = 160;
	//		float LineText5PosY = 170.0;

	//		string pauseText = "GAME PAUSE";
	//		string keyInstructionText = "Press ENTER key";
	//		string continueText = "To Continue";
	//		string startText = "To Start Game";
	//		string resetText = "Press R to reset game";
	//		string menuText = "Press M to go to the MENU";

	//		PrintMenuText(lineText1PosX, LineText1PosY, pauseText);
	//		PrintMenuText(LineText2PosX, LineText2PosY, keyInstructionText);

	//		if (gameStats.gameStatus == SceneStatus::GAMEPAUSE)
	//		{
	//			PrintMenuText(LineText3PosX, LineText3PosY, continueText);
	//			PrintMenuText(LineText4PosX, LineText4PosY, resetText);
	//			PrintMenuText(LineText5PosX, LineText5PosY, menuText);
	//		}
	//		if (gameStats.gameStatus == SceneStatus::FIRSTGAME)
	//		{
	//			int auxXPos = 15.0;
	//			PrintMenuText(LineText3PosX - auxXPos, LineText3PosY, startText);
	//			PrintMenuText(LineText5PosX, LineText5PosY, menuText);
	//		}
	//	}

	//	if (gameStats.gameStatus == SceneStatus::GAMEEND)
	//	{
	//		float lineText1PosX = gameStats.screenWidth / 2 - 90.0;
	//		float LineText1PosY = 580.0;

	//		float LineText2PosX = gameStats.screenWidth / 2 - 225.0;
	//		float LineText2PosY = 310.0;

	//		float LineText3PosX = gameStats.screenWidth / 2 - 210.0;
	//		float LineText3PosY = 270.0;

	//		string endText = "GAME ENDED";
	//		string keyInstructionText = "Press ENTER to RESTART";
	//		string restartText = "or M to go to the MENU";

	//		PrintMenuText(lineText1PosX, LineText1PosY, endText);
	//		PrintMenuText(LineText2PosX, LineText2PosY, keyInstructionText);
	//		PrintMenuText(LineText3PosX, LineText3PosY, restartText);
	//	}
	//	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	//}

	//void DrawButtonRec(Rectangle button)
	//{
	//	Colors white = { 1.0f,1.0f,1.0f,1.0f };

	//	slSetForeColor(white.r, white.g, white.b, white.a);

	//	slRectangleOutline(button.recPos.x, button.recPos.y,
	//		button.recSize.x, button.recSize.y);
	//	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	//}
}