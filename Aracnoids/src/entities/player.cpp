#include "player.h"

namespace gamePlayer
{
	Player player;

	void InitPlayer()
	{
		player = CreatePlayer(player);
	}

	Player CreatePlayer(Player& player)
	{
		player.playerDir = DIRECTION::STOP;
		player.color = RED;

		player.playerPos.x = playerPosX;
		player.playerPos.y = playerPosY;
		player.playerRec.x = 30;
		player.playerRec.y = 20;

		return player;
	}

	Player GetPlayer()
	{
		return player;
	}

	//PLAYER LOGIC

	void Input()
	{
		InputPlayer(player);
	}
	void Update()
	{
		UpdatePlayer(player);
	}
	void DrawPlayer()
	{
		DrawRectangle(player.playerPos.x, player.playerPos.y, player.playerRec.x, player.playerRec.y, player.color);
	}

	//PLAYER PLAY

	void InputPlayer(Player& player)
	{
		if (IsKeyPressed(KEY_W))
		{
			///trusterON
		}

		StopMovement(player);
	}
	void StopMovement(Player& player)
	{
		if (IsKeyUp(KEY_W))
		{
			player.playerDir = DIRECTION::STOP;
		}
	}
	void UpdatePlayer(Player& player)
	{
		bool IsRightSideScreen = (player.rec.pos.x + player.rec.size.x / 2) >= (arenaPaletteWidth - minDistanceFromBorder);
		bool IsLeftSideScreen = (player.rec.pos.x - player.rec.size.x / 2) <= 0 + minDistanceFromBorder;

		if (player.playerDir == DIRECTION::RIGHT)
		{
			if (!IsRightSideScreen)
			{
				player.rec.pos.x += playerSpeed * slGetDeltaTime();
			}
		}
		if (player.playerDir == DIRECTION::LEFT)
		{
			if (!IsLeftSideScreen)
			{
				player.rec.pos.x -= playerSpeed * slGetDeltaTime();
			}
		}
	}
}