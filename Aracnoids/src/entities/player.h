#pragma once

#include "mouse.h"

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
		Vector2 pivot;
		Vector2 direction;
		Vector2 dirNormalizado;
		Color playerColor;
		float rotation;
		float rotationSpeed;
		float radius;
		float speed;
		float angle;
	};

	Player CreatePlayer(Player player);

	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player, mouse::Mouse gameMouse);
	void DrawPlayer(Player player);

	void StopMovement(Player& player);
	float GetMousePosRespectFromPlayer(Player player, Vector2 mouse);
}