#pragma once

#include "../utilities.h"
#include "player.h"
#include "ctime"

namespace aracnoids
{
	struct Bullet
	{
		clock_t bulletTimeAlive;

		Rectangle bulletRec;
		Circle bulletHitBox;

		Color bulletColor;

		Vector2 pivot;
		Vector2 direction;
		Vector2 dirNormalizado;
		Vector2 velocity;
		Vector2 aceleration;

		float rotation;
		float rotationSpeed;
		float radius;
		float impulse;
		float angle;

		double maxTimeAlive;
		bool isBulletAlive;
	};

	//Bullet CreateBullet( gamePlayer::Player player);
	//void InitBullets(Bullet bullet[], gamePlayer::Player player);

	void InputBullets(Bullet bullet[], Player player);
	void UpdateBullet(Bullet bullet[]);
	void DrawBullet(Bullet bullet[]);
	float GetMousePosRespectFromPlayer(Bullet bullet[], Vector2 mouse, int index);
}