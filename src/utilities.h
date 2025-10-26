#pragma once

#include "raylib.h"
#include "raymath.h"

namespace aracnoids
{
	struct Circle
	{
		Vector2 pos;
		float rad;
	};

	enum class SceneStatus
	{
		GAMEMENU = 1,
		GAMERULES,
		GAMECREDITS,
		FIRSTGAME,
		GAMEPLAY,
		GAMEPAUSE,
		RESETGAME,
		GAMEEND,
		SIMEND
	};

	struct GameStats
	{
		SceneStatus gameStatus;

		int fontSize = 25;

		bool isResetMatch = false;
		bool goMenu = false;
	};
}