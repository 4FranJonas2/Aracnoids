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
		Vector2 pivot;
		Vector2 direction;
		Vector2 dirNormalizado;
		Vector2 aceleration;
		Vector2 size; //para sprite
		
		bool isAlive;
		bool isShotting;
		bool isAcelerating;
		int lives;

		float speed;
		float rotation;
		float rotationSpeed;
		float impulse;
		float angle;

		float countDown;
		float resetCountDown;
	};
}