#pragma once

#include "../utilities.h"
#include "../gameSetings/audioManager.h"

namespace aracnoids
{
	enum class PLAYERMOVSTAT
	{
		STOP = 1,
		MOVING,
		DERIVA
	};

	struct Animation
	{
		Texture2D texture;

		int frameWidth;
		int frameHeight;
		int currentFrame;
		float frameTime;
		float time;
		float frameCounter;
	};

	struct Player
	{
		Circle playerCir;
		Vector2 vecDir;
		Vector2 velocity;
		Vector2 acceleration;

		float speed;
		float maxSpeed;
		float rotation;
		float rotationSpeed;
		bool isAlive;
		bool isAcelerating;
		int lives;
		int points;

		bool playerHit;
		bool isShooting;
		float immunityTimer;
		float inmmunityDelay;

		PLAYERMOVSTAT movStatus;

		Animation idleAnim;
		Animation runAnim;
		Animation shotAnim;
	};


	void InitPlayer(Player& player);
	void InputPlayer(Player& player);
	void UpdatePlayer(Player& player);
	void DrawPlayer(Player player);
	void UnloadPlayer(Player& player);
}