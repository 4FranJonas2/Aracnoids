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


		Vector2 vecDir;
		Vector2 velocity;
		Vector2 acceleration;

		float rotation;
		float impulse;
		float angle;

		double maxTimeAlive;
		bool isBulletAlive;
	};

	//Bullet CreateBullet( gamePlayer::Player player);
	//void InitBullets(Bullet bullet[], gamePlayer::Player player);
	
	void InputBullet(bool& shoot);
	void CreateBullet(Bullet bullet[], Player player, bool& shoot);
	void UpdateBullet(Bullet bullet[]);
	void DrawBullet(Bullet bullet[]);
}