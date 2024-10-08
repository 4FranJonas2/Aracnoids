#pragma once
#include "../game_settings/utils.h"

namespace gamePlayer
{

	enum class DIRECTION
	{
		STOP = 1,
		MOVING,
		DERIVA
	};

	struct Player
	{
		DIRECTION playerDir;
		Vector2 playerRec;
		Vector2 playerPos;
		Color color;
		
	};

	void InitPlayer();
	void InitArena();

	Player CreatePlayer(Player& player);
	Player GetPlayer();

	void Input();
	void Update();
	void DrawPlayer();

	void InputPlayer(Player& player);
	void StopMovement(Player& player);
	void UpdatePlayer(Player& player);
}