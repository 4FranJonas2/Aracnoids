#include "player.h"

namespace gamePlayer
{
	Player CreatePlayer(Player& player)
	{
		player.playerDir = DIRECTION::STOP;
		player.color = RED;

		player.playerPos.x = playerPosX;
		player.playerPos.y = playerPosY;
		player.playerRec.pos.x = screenWidth/2;
		player.playerRec.pos.y = screenHeight/2;
		player.playerRec.size.x = screenWidth / 2;
		player.playerRec.size.y = screenHeight / 2;

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
		
	}
	void DrawPlayer(Player player)
	{
		DrawRectangle(player.playerPos.x, player.playerPos.y, player.playerRec.x, player.playerRec.y, player.color);
	}

	void StopMovement(Player& player)
	{
		if (IsKeyUp(KEY_W))
		{
			player.playerDir = DIRECTION::STOP;
		}
	}
}