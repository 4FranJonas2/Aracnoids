#pragma once
#include "player.h"
#include "game_settings/constants.h"
namespace gamePlayer
{
	//PLAYER settings
	const float playerSpeed = 450.0f;
	const float playerPosX = screenWidth / 2.0f;
	const float playerPosY = screenHeight / 2.0f;

	Player CreatePlayer(Player player)
	{
		player.playerDir = PLAYERDIRECTION::STOP;
		player.playerColor = RED;

		player.playerPos.x = playerPosX;
		player.playerPos.y = playerPosY;
		player.playerRec.x = screenWidth/2;
		player.playerRec.y = screenHeight/2;
		player.playerRec.width = 20.0f;
		player.playerRec.height = 10.0f;

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
		DrawRectangle(static_cast<int> (player.playerPos.x), static_cast<int> (player.playerPos.y), static_cast<int> (player.playerRec.width), static_cast<int> (player.playerRec.height), player.playerColor);
	}

	void StopMovement(Player& player)
	{
		if (IsKeyUp(KEY_W))
		{
			player.playerDir = PLAYERDIRECTION::STOP;
		}
	}
}