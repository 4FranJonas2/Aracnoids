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
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:

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
			break;

		case SceneStatus::GAMERULES:
			
			if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backButton))
			{
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
			break;

		case SceneStatus::GAMECREDITS:

			/*if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.linkButton))
			{
				system("start https://4franjonas2.itch.io/");
			}*/

			if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonUp(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backButton))
			{
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
			break;

		case SceneStatus::FIRSTGAME:
			
			if (!IsKeyPressed(KEY_SPACE)&& IsKeyReleased(KEY_SPACE))
			{
				gameStats.gameStatus = SceneStatus::GAMEPLAY;
			}

			break;

		case SceneStatus::GAMEPLAY:

			if (!IsKeyPressed(KEY_SPACE) && IsKeyReleased(KEY_SPACE))
			{
				gameStats.gameStatus = SceneStatus::GAMEPAUSE;
			}
			break;

		case SceneStatus::GAMEPAUSE:

			if (!IsKeyPressed(KEY_SPACE) && IsKeyReleased(KEY_SPACE))
			{
				gameStats.gameStatus = SceneStatus::GAMEPLAY;
			}
			break;

		default:
			break;
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

	void DrawRulesMenu(GameStats gameStats)
	{
		if (gameStats.gameStatus == SceneStatus::GAMERULES)
		{
			int titleFontSize = 50;
			int defaultFontSize = 20;
			int exitFontSize = 20;

			int LineText1PosX = GetScreenWidth() / 2 - 100;
			int LineText1PosY = 100;

			int LineText2PosX = 100;
			int LineText2PosY = 230;

			int LineText3PosX = 100;
			int LineText3PosY = 280;

			int LineText4PosX = 100;
			int LineText4PosY = 310;

			int LineText5PosX = 100;
			int LineText5PosY = 380;

			int LineText6PosX = 100;
			int LineText6PosY = 450;

			int LineText7PosX = 100;
			int LineText7PosY = 480;

			int LineText8PosX = 100;
			int LineText8PosY = 510;

			int LineText9PosX = 100;
			int LineText9PosY = 650;

			int LineText0PosX = 100;
			int LineText0PosY = 720;

			string titleText = "RULES";
			string howToMoveText = "-To MOVE use LEFT Mouse Button and to SHOT use RIGHT mouse buton";
			string winConditionText = "-In normal mode Destroy all Neufars to win.";
			string winConditionText2 = "-In endless mode survive as long as you can.";
			string loseConditionText2 = "-You will have 3 lives. If you get touch by a neufar, you lose 1 life.";
			string turtleText = "Take care of the TURTLE, they can change neufar direction !!";
			string frogText = "FROGS loves water but we cant explain why their smell slows you down if they touch you.";
			string petalsText = "The PINK PETALS can reestore 1 life, if you are not full healt.";
			string pauseText = "-Use spacebar to pause game at any moment.";
			string exitText = "Back";

			DrawText("RULES", LineText1PosX, LineText1PosY, titleFontSize, WHITE);

			DrawText("-To MOVE use LEFT Mouse Button and to SHOT use RIGHT mouse buton",
				LineText2PosX, LineText2PosY, defaultFontSize, WHITE);
			DrawText("-In normal mode Destroy all Neufars to win.",
				LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
			DrawText("-In endless mode survive as long as you can.",
				LineText4PosX, LineText4PosY, defaultFontSize, WHITE);
			DrawText("-You will have 3 lives. If you get touch by a neufar, you lose 1 life.",
				LineText5PosX, LineText5PosY, defaultFontSize, WHITE);
			DrawText("TURTLE dont care about anything. But take care, they can change neufar direction !!",
				LineText6PosX, LineText6PosY, defaultFontSize, WHITE);
			DrawText("FROGS loves water but we cant explain why their smell slows you down if they touch you.",
				LineText7PosX, LineText7PosY, defaultFontSize, WHITE);
			DrawText("The PINK PETALS can reestore 1 life, if you are not full healt.",
				LineText8PosX, LineText8PosY, defaultFontSize, WHITE);
			DrawText("-Use spacebar to pause game at any moment.",
				LineText9PosX, LineText9PosY, defaultFontSize, WHITE);
			DrawText("Back", LineText0PosX, LineText0PosY, exitFontSize, WHITE);

			/*slSprite(gameStats.redCoconut, 120.0, 245.0, 16, 16);
			slSprite(gameStats.yellowCoconut, 120.0, 215.0, 16, 16);
			slSprite(gameStats.greenCoconut, 120.0, 185.0, 16, 16);*/


			/*slSprite(gameStats.backButton, buttons.backButton.recPos.x, buttons.backButton.recPos.y,
				buttons.backButton.recSize.x, buttons.backButton.recSize.y);
			PrintMenuText(LineText6PosX - auxXPos, LineText6PosY, exitText);*/
		}
	}

	void DrawCreditsMenu(GameStats gameStats)
	{
		if (gameStats.gameStatus == SceneStatus::GAMECREDITS)
		{
			int titleFontSize = 50;
			int defaultFontSize = 20;
			int exitFontSize = 20;

			int LineText1PosX = GetScreenWidth() / 2 - 100;
			int LineText1PosY = 100;

			int LineText2PosX = 100;
			int LineText2PosY = 230;

			int LineText3PosX = 100;
			int LineText3PosY = 280;

			int LineText4PosX = 100;
			int LineText4PosY = 330;

			int LineText0PosX = 100;
			int LineText0PosY = 720;

			string titleText = "CREDITS";

			string howToMoveText = "-Game made by me Francisco Jonas: https://4franjonas2.itch.io/.";
			string creditText1 = "-Game assests made by Guadalupe Ferreira Le Roi";
			string creditText2 = "-Special thanks to, Stefano Juan Cvitanich and Sergio Baretto";
			string exitText = "Back";

			DrawText("CREDITS", LineText1PosX, LineText1PosY, titleFontSize, WHITE);

			DrawText("-Game made by me Francisco Jonas: https://4franjonas2.itch.io/.",
				LineText2PosX, LineText2PosY, defaultFontSize, WHITE);
			DrawText("-Game assests made by Guadalupe Ferreira Le Roi",
				LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
			DrawText("-Special thanks to, Stefano Juan Cvitanich and Sergio Baretto",
				LineText4PosX, LineText4PosY, defaultFontSize, WHITE);

			DrawText("Back", LineText0PosX, LineText0PosY, exitFontSize, WHITE);

			/*slSprite(gameStats.redCoconut, 120.0, 245.0, 16, 16);
			slSprite(gameStats.yellowCoconut, 120.0, 215.0, 16, 16);
			slSprite(gameStats.greenCoconut, 120.0, 185.0, 16, 16);*/


			/*slSprite(gameStats.backButton, buttons.backButton.recPos.x, buttons.backButton.recPos.y,
				buttons.backButton.recSize.x, buttons.backButton.recSize.y);
			PrintMenuText(LineText6PosX - auxXPos, LineText6PosY, exitText);*/
		}
	}

	void DrawPause(GameStats gameStats)
	{
		if (gameStats.gameStatus == SceneStatus::GAMEPAUSE || gameStats.gameStatus == SceneStatus::FIRSTGAME)
		{
			int titleFontSize = 50;
			int defaultFontSize = 20;
			//int exitFontSize = 20;

			int LineText1PosX = GetScreenWidth() / 2 - 100;
			int LineText1PosY = 100;

			int LineText2PosX = 100;
			int LineText2PosY = 230;

			int LineText3PosX = 100;
			int LineText3PosY = 280;

			int LineText4PosX = 100;
			int LineText4PosY = 310;

			int LineText5PosX = 100;
			int LineText5PosY = 380;

			string pauseText = "GAME PAUSE";
			string keyInstructionText = "Press SPACEBAR key";
			string continueText = "To RESUME";
			string startText = "To START Game";
			string resetText = "RESET game";
			string menuText = "Go to MENU";
			string endText = "GAME OVER";

			DrawText("Press SPACEBAR key", LineText2PosX, LineText2PosY, defaultFontSize, WHITE);

			if (gameStats.gameStatus == SceneStatus::GAMEPAUSE)
			{
				DrawText("GAME PAUSE", LineText1PosX, LineText1PosY, titleFontSize, WHITE);
				DrawText("To RESUME", LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
				DrawText("RESET game", LineText4PosX, LineText4PosY, defaultFontSize, WHITE);
				DrawText("Go to MENU", LineText5PosX, LineText5PosY, defaultFontSize, WHITE);
			}

			if (gameStats.gameStatus == SceneStatus::FIRSTGAME)
			{
				DrawText("GAME PAUSE", LineText1PosX, LineText1PosY, titleFontSize, WHITE);

				DrawText("To START Game", LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
				DrawText("Go to MENU", LineText5PosX, LineText5PosY, defaultFontSize, WHITE);
			}

			if (gameStats.gameStatus == SceneStatus::GAMEEND)
			{
				DrawText("GAME OVER", LineText1PosX, LineText1PosY, titleFontSize, WHITE);
				DrawText("RESET game", LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
				DrawText("Go to MENU", LineText5PosX, LineText5PosY, defaultFontSize, WHITE);
			}
		}
	}

	//void DrawButtonRec(Rectangle button)
	//{
	//	Colors white = { 1.0f,1.0f,1.0f,1.0f };

	//	slSetForeColor(white.r, white.g, white.b, white.a);

	//	slRectangleOutline(button.recPos.x, button.recPos.y,
	//		button.recSize.x, button.recSize.y);
	//	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	//}
}