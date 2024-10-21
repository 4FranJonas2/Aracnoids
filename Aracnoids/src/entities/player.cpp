#pragma once
#include "player.h"

namespace gamePlayer
{
	Player CreatePlayer(Player player)
	{
		player.playerDir = DIRECTION::STOP;
		player.playerColor = RED;

		player.playerPos.x = playerPosX;
		player.playerPos.y = playerPosY;
		player.playerRec.pos.x = screenWidth/2;
		player.playerRec.pos.y = screenHeight/2;
		player.playerRec.size.x = 20.0f;
		player.playerRec.size.y = 10.0f;

		return player;
	}

	//PLAYER PLAY

	void InputPlayer(Player& player)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			///shoot
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			///trusterON
		}

		StopMovement(player);
	}

	void UpdatePlayer(Player& player)
	{
		player.playerColor = WHITE;
	}

	void DrawPlayer(Player player)
	{
		DrawRectangleV(player.playerPos, player.playerRec.size, player.playerColor);
	}

	void StopMovement(Player& player)
	{
		if (IsKeyUp(KEY_W))
		{
			player.playerDir = DIRECTION::STOP;
		}
	}
}