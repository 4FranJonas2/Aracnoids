#pragma once

#include "../utilities.h"

namespace aracnoids
{
	enum class PLAYERMOVSTAT
	{
		STOP = 1,
		MOVING,
		DERIVA
	};

	struct Player
	{
		PLAYERMOVSTAT movStatus;

		Circle playerCir;
		Vector2 vecDir;
		Vector2 velocity;
		Vector2 acceleration;
		
		bool isAlive;
		bool isAcelerating;
		bool isShotting;
		int lives;

		float speed;
		float maxSpeed;
		float rotation;
		float rotationSpeed;

		float countDown;
		float resetCountDown;
	};

	void InitPlayer(Player& player);
	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player player);
}