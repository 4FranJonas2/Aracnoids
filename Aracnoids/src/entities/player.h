#pragma once
#include"raylib.h"
//#include "mouse.h"

namespace gamePlayer
{
	enum class PLAYERDIRECTION
	{
		STOP = 1,
		MOVING,
		DERIVA
	};

	struct Player
	{
		PLAYERDIRECTION playerDir;
		Rectangle playerRec;
		Vector2 playerPos;
		Color playerColor;
	};

	Player CreatePlayer(Player player);

	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player player);
	
	void StopMovement(Player& player);
}