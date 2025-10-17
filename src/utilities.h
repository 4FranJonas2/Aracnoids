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
		SceneStatus gameStatus = SceneStatus::INITGAME;

		int fontSize = 25;

		bool isResetMatch = false;
		bool goMenu = false;
	};


}