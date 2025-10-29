#include "menu.h"

namespace aracnoids
{
	Vector2 recSize = { 90.0f, 50.0f };
	bool isOnButton = false;

	bool IsMouseOverButton(Rectangle buttonRec);
	int GetButtonState(Rectangle button, AudioManager audio);
	void DrawButton(Texture2D sprite, Rectangle button, int state);

	bool IsMouseOverButton(Rectangle buttonRec)
	{
		Vector2 mousePos = GetMousePosition();

		float left = buttonRec.x - buttonRec.width / 2;
		float right = buttonRec.x + buttonRec.width / 2;
		float top = buttonRec.y + buttonRec.height / 2;
		float bottom = buttonRec.y - buttonRec.height / 2;

		if (mousePos.x >= left && mousePos.x <= right && mousePos.y <= top && mousePos.y >= bottom)
			return true;

		return false;
	}
	void InitButtons(MenuButtons& buttons)
	{
		buttons.buttonSprite = LoadTexture("res/Botones/DefaultButtonSprite.png");

		float menuButtonsPosX = 505.0f;
		float backButtonPosX = 100.0f;
		float backButtonPosY = 720.0f;

		float resetButtonPosX = 335.0f;
		float resetButtonPosY = 660.0f;
		float goMenuButtonPosX = 697.0f;
		float goMenuButtonPosY = 660.0f;

		buttons.playButtState = 0;
		buttons.rulesButtState = 0;
		buttons.creditsButtState = 0;
		buttons.backButtState = 0;
		buttons.backToMenuButtState = 0;
		buttons.resetButtState = 0;

		float buttonWidth = 110.0f;
		float buttonHeight = 72.0f;

		float playButtonPosy = 290.0f;
		float rulesButtonPosy = 370.0f;
		float creditButtonPosy = 450.0f;

		//posiciones de botones y tamanio de hitbox
		buttons.playButton = { menuButtonsPosX,playButtonPosy,buttonWidth,buttonHeight };
		buttons.rulesButton = { menuButtonsPosX,rulesButtonPosy,buttonWidth,buttonHeight };
		buttons.creditsButton = { menuButtonsPosX,creditButtonPosy,buttonWidth,buttonHeight };

		buttons.backButton = { backButtonPosX,backButtonPosY,buttonWidth,buttonHeight };

		buttons.resetButton = { resetButtonPosX,resetButtonPosY,buttonWidth,buttonHeight };
		buttons.backMenuButton = { goMenuButtonPosX,goMenuButtonPosY,buttonWidth,buttonHeight };
	}
	void UpdateSceneMenus(GameStats& gameStats, MenuButtons& buttons, AudioManager audio)
	{
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:

			buttons.playButtState = GetButtonState(buttons.playButton, audio);
			buttons.rulesButtState = GetButtonState(buttons.rulesButton, audio);
			buttons.creditsButtState = GetButtonState(buttons.creditsButton, audio);

			if (!IsMouseOverButton(buttons.playButton) && !IsMouseOverButton(buttons.rulesButton) && !IsMouseOverButton(buttons.creditsButton))
			{
				isOnButton = false;
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.playButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::RESETGAME;
			}
			else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.rulesButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMERULES;
			}
			else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.creditsButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMECREDITS;
			}
			break;

		case SceneStatus::GAMERULES:

			buttons.backButtState = GetButtonState(buttons.backButton, audio);

			if (!IsMouseOverButton(buttons.backButton))
				isOnButton = false;

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
			break;

		case SceneStatus::GAMECREDITS:

			buttons.backButtState = GetButtonState(buttons.backButton, audio);

			if (!IsMouseOverButton(buttons.backButton))
				isOnButton = false;

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
			break;

		case SceneStatus::FIRSTGAME:

			buttons.backToMenuButtState = GetButtonState(buttons.backMenuButton, audio);

			if (!IsMouseOverButton(buttons.backMenuButton))
				isOnButton = false;

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backMenuButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
			if (!IsKeyPressed(KEY_SPACE) && IsKeyReleased(KEY_SPACE))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEPLAY;
			}
			break;

		case SceneStatus::GAMEPLAY:

			if (!IsKeyPressed(KEY_SPACE) && IsKeyReleased(KEY_SPACE))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEPAUSE;
			}
			break;

		case SceneStatus::GAMEPAUSE:

			buttons.backToMenuButtState = GetButtonState(buttons.backMenuButton, audio);
			buttons.resetButtState = GetButtonState(buttons.resetButton, audio);

			if (!IsMouseOverButton(buttons.backMenuButton) && !IsMouseOverButton(buttons.resetButton))
				isOnButton = false;

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backMenuButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.resetButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::RESETGAME;
			}
			if (!IsKeyPressed(KEY_SPACE) && IsKeyReleased(KEY_SPACE))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEPLAY;
			}
			break;

		case SceneStatus::GAMEEND:

			buttons.backToMenuButtState = GetButtonState(buttons.backMenuButton, audio);
			buttons.resetButtState = GetButtonState(buttons.resetButton, audio);

			if (!IsMouseOverButton(buttons.backMenuButton) && !IsMouseOverButton(buttons.resetButton))
				isOnButton = false;

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.backMenuButton))
			{
				PlaySFX(audio.clickSound);
				isOnButton = false;
				gameStats.gameStatus = SceneStatus::GAMEMENU;
			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && IsMouseOverButton(buttons.resetButton))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::RESETGAME;
			}
			if (!IsKeyPressed(KEY_SPACE) && IsKeyReleased(KEY_SPACE))
			{
				PlaySFX(audio.clickSound);
				gameStats.gameStatus = SceneStatus::GAMEPLAY;
			}
			break;

		default:
			break;
		}
	}
	void DrawMainMenu(GameStats gameStats, MenuButtons buttons)
	{
		if (gameStats.gameStatus == SceneStatus::GAMEMENU)
		{
			int lineText1PosX = GetScreenWidth() / 2 - 150;
			int LineText1PosY = 150;

			int LineText2PosX = GetScreenWidth() / 2 - 30;
			int LineText2PosY = 280;

			int LineText3PosX = GetScreenWidth() / 2 - 35;
			int LineText3PosY = 357;

			int LineText4PosX = GetScreenWidth() / 2 - 47;
			int LineText4PosY = 437;

			int LineText5PosX = 360;
			int LineText5PosY = 750;

			int titleFontSize = 50;
			int defaultFontSize = 20;
			int exitFontSize = 15;

			string titleText = "ARACNOIDS";
			string playText = "Play";
			string rulesext = "Rules";
			string creditsText = "Credits";
			string exitText = "Press ESC at ANY momment to CLOSE the game";

			DrawButton(buttons.buttonSprite, buttons.playButton, buttons.playButtState);
			DrawButton(buttons.buttonSprite, buttons.rulesButton, buttons.rulesButtState);
			DrawButton(buttons.buttonSprite, buttons.creditsButton, buttons.creditsButtState);

			DrawText("ARACNOIDS", lineText1PosX, LineText1PosY, titleFontSize, WHITE);
			DrawText("Play", LineText2PosX, LineText2PosY, defaultFontSize, WHITE);
			DrawText("Rules", LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
			DrawText("Credits", LineText4PosX, LineText4PosY, defaultFontSize, WHITE);

			DrawText("Press ESC at ANY momment to CLOSE the game", LineText5PosX, LineText5PosY, exitFontSize, WHITE);
		}
	}
	void DrawRulesMenu(GameStats gameStats, MenuButtons buttons)
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

			int LineText0PosX = 75;
			int LineText0PosY = 705;

			string titleText = "RULES";
			string howToMoveText = "-To MOVE use RIGHT Mouse Button and to SHOT use LEFT mouse buton";
			string winConditionText = "-In normal mode Destroy all Neufars to win.";
			string winConditionText2 = "-In endless mode survive as long as you can.";
			string loseConditionText2 = "-You will have 3 lives. If you get touch by a neufar, you lose 1 life.";
			string turtleText = "Take care of the TURTLE, they can change neufar direction !!";
			string frogText = "FROGS loves water but we cant explain why their smell slows you down if they touch you.";
			string petalsText = "The PINK PETALS can reestore 1 life, if you are not full healt.";
			string pauseText = "-Use spacebar to pause game at any moment.";
			string exitText = "Back";

			DrawButton(buttons.buttonSprite, buttons.backButton, buttons.backButtState);

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
		}
	}
	void DrawCreditsMenu(GameStats gameStats, MenuButtons buttons)
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

			int LineText0PosX = 75;
			int LineText0PosY = 705;

			string titleText = "CREDITS";

			string howToMoveText = "-Game made by me Francisco Jonas: https://4franjonas2.itch.io/.";
			string creditText1 = "-Game assests made by Guadalupe Ferreira Le Roi";
			string creditText2 = "-Special thanks to, Stefano Juan Cvitanich and Sergio Baretto";
			string exitText = "Back";

			DrawButton(buttons.buttonSprite, buttons.backButton, buttons.backButtState);

			DrawText("CREDITS", LineText1PosX, LineText1PosY, titleFontSize, WHITE);

			DrawText("-Game made by me Francisco Jonas: https://4franjonas2.itch.io/.",
				LineText2PosX, LineText2PosY, defaultFontSize, WHITE);
			DrawText("-Game assests made by Guadalupe Ferreira Le Roi",
				LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
			DrawText("-Special thanks to, Stefano Juan Cvitanich and Sergio Baretto",
				LineText4PosX, LineText4PosY, defaultFontSize, WHITE);

			DrawText("Back", LineText0PosX, LineText0PosY, exitFontSize, WHITE);
		}
	}
	void DrawPause(GameStats gameStats, MenuButtons buttons)
	{
		if (gameStats.gameStatus == SceneStatus::GAMEPAUSE
			|| gameStats.gameStatus == SceneStatus::FIRSTGAME
			|| gameStats.gameStatus == SceneStatus::GAMEEND)
		{
			int titleFontSize = 50;
			int defaultFontSize = 20;

			int LineText1PosX = 350;
			int LineText1PosY = 100;

			int LineText2PosX = 400;
			int LineText2PosY = 230;

			int LineText3PosX = 450;
			int LineText3PosY = 280;

			int LineText4PosX = 300;
			int LineText4PosY = 650;

			int LineText5PosX = 650;
			int LineText5PosY = 650;

			int LineText6PosX = 430;
			int LineText6PosY = 280;

			string pauseText = "GAME PAUSE";
			string keyInstructionText = "Press SPACEBAR key";
			string continueText = "To RESUME";
			string startText = "To START Game";
			string resetText = "RESET";
			string menuText = "Go MENU";
			string endText = "GAME OVER";

			DrawText("Press SPACEBAR key", LineText2PosX, LineText2PosY, defaultFontSize, WHITE);

			if (gameStats.gameStatus == SceneStatus::GAMEPAUSE)
			{
				DrawButton(buttons.buttonSprite, buttons.resetButton, buttons.resetButtState);
				DrawButton(buttons.buttonSprite, buttons.backMenuButton, buttons.backToMenuButtState);

				DrawText("GAME PAUSE", LineText1PosX, LineText1PosY, titleFontSize, WHITE);
				DrawText("To RESUME", LineText3PosX, LineText3PosY, defaultFontSize, WHITE);
				DrawText("RESET", LineText4PosX, LineText4PosY, defaultFontSize, WHITE);
				DrawText("Go MENU", LineText5PosX, LineText5PosY, defaultFontSize, WHITE);
			}

			if (gameStats.gameStatus == SceneStatus::FIRSTGAME)
			{
				DrawButton(buttons.buttonSprite, buttons.backMenuButton, buttons.backToMenuButtState);

				DrawText("GAME PAUSE", LineText1PosX, LineText1PosY, titleFontSize, WHITE);

				DrawText("To START Game", LineText6PosX, LineText6PosY, defaultFontSize, WHITE);
				DrawText("Go MENU", LineText5PosX, LineText5PosY, defaultFontSize, WHITE);
			}

			if (gameStats.gameStatus == SceneStatus::GAMEEND)
			{
				DrawButton(buttons.buttonSprite, buttons.resetButton, buttons.resetButtState);
				DrawButton(buttons.buttonSprite, buttons.backMenuButton, buttons.backToMenuButtState);

				DrawText("GAME OVER", LineText1PosX, LineText1PosY, titleFontSize, WHITE);
				DrawText("RESET", LineText4PosX, LineText4PosY, defaultFontSize, WHITE);
				DrawText("Go MENU", LineText5PosX, LineText5PosY, defaultFontSize, WHITE);
			}
		}
	}

	int GetButtonState(Rectangle button, AudioManager audio)
	{
		Vector2 mouse = GetMousePosition();

		if (IsMouseOverButton(button))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			{
				return 2;
			}
			else
			{
				if (!isOnButton)
				{
					PlaySFX(audio.overSound);
					isOnButton = true;
				}
				return 1;
			}
		}
		return 0;
	}
	void DrawButton(Texture2D sprite, Rectangle button, int state)
	{
		// dibujado de sprite y escalado
		float  scale = 2.5;
		float frameWidth = static_cast<float>(sprite.width) / 3.0f;
		float frameHeight = static_cast<float>(sprite.height);

		Rectangle spriteRec = { state * frameWidth, 0, frameWidth,frameHeight };
		Vector2 position = { button.x,button.y };

		Rectangle destRec = { button.x,button.y,frameWidth * scale,frameHeight * scale };
		Vector2 origin = { destRec.width / 2, destRec.height / 2 };

		DrawTexturePro(sprite, spriteRec, destRec, origin, 0.0, WHITE);
	}
}