#pragma once

#include <ctime>

#include "Mouse.h"
#include "game_settings/Constants.h"

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
		Circle playerHitBox;

		Vector2 playerPos;
		Vector2 pivot;
		Vector2 direction;
		Vector2 dirNormalizado;
		Vector2 aceleration;

		Color playerColor;

		double spawnTime;
		double neufarTimeSpawn;
		double elapsedTime;
		double currentTime;

		float rotation;
		float rotationSpeed;
		float radius;
		float impulse;
		float velocity;
		float angle;
		float countDown;
		float resetCountDown;

		int playerLives;
	};

	Player CreatePlayer(Player& player);

	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player, mouse::Mouse gameMouse);
	void DrawPlayer(Player player);

	void StopMovement(Player& player);
	float GetMousePosRespectFromPlayer(Player player, Vector2 mouse);
}