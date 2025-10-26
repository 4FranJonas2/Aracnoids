#pragma once

#include "raylib.h"

#include "../utilities.h"

#include <string>

using namespace std;

namespace aracnoids
{
	struct MenuButtons
	{
		Rectangle backButton;
		Rectangle linkButton;
		Rectangle playButton;
		Rectangle rulesButton;
		Rectangle creditsButton;
	};

	void InitButtons(MenuButtons& buttons);
	void UpdateSceneMenus(GameStats& gamestats, MenuButtons buttons);
	void DrawMainMenu(GameStats gameStats);
	void DrawRulesMenu(GameStats gameStats);
	void DrawCreditsMenu(GameStats gameStats);
	void DrawPause(GameStats gameStats);
	//void DrawButtonRec(Rectangle button);
}