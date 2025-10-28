#pragma once

#include <string>

#include "raylib.h"

#include "../utilities.h"
#include "../gameSetings/audioManager.h"

using namespace std;

namespace aracnoids
{
	struct MenuButtons
	{
		Texture2D buttonSprite;

		Rectangle backButton;
		Rectangle playButton;
		Rectangle rulesButton;
		Rectangle creditsButton;
		Rectangle backMenuButton;
		Rectangle resetButton;
		
		int backButtState;
		int playButtState;
		int rulesButtState;
		int creditsButtState;
		int backToMenuButtState;
		int resetButtState;
	};

	void InitButtons(MenuButtons& buttons);
	void UpdateSceneMenus(GameStats& gamestats, MenuButtons& buttons, AudioManager audio);
	void DrawMainMenu(GameStats gameStats, MenuButtons buttons);
	void DrawRulesMenu(GameStats gameStats, MenuButtons buttons);
	void DrawCreditsMenu(GameStats gameStats, MenuButtons buttons);
	void DrawPause(GameStats gameStats, MenuButtons buttons);
}