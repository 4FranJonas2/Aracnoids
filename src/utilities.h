#pragma once

#include "raylib.h"

namespace aracnoids
{
	struct Circle
	{
		Vector2 pos;
		float rad;
	};

	enum class SceneStatus
	{
		INITGAME = 1,
		FIRSTGAME,
		GAMEMENU,
		GAMERULES,
		GAMECREDITS,
		GAMEPLAY,
		GAMEPAUSE,
		RESETGAME,
		GAMEEND,
		SIMEND
	};

	struct GameStats
	{
		SceneStatus gameStatus;

		const int screenWidth = 750;
		const int screenHeight = 650;
		int fontSize = 25;

		bool isResetMatch = false;
		bool goMenu = false;
	};
}