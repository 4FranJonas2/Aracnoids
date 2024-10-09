#pragma once
#include "game_field.h"

namespace gamePlayer
{
	Player CreatePlayer(Player& player);

	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player player);
	
	void StopMovement(Player& player);
}