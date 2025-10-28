#pragma once

#include "ctime"

#include "player.h"
#include "../utilities.h"
#include "../gameSetings/audioManager.h"

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
	
	void InputBullet();
	void CreateBullet(Bullet bullet[], Player player, AudioManager audio);
	void UpdateBullet(Bullet bullet[]);
	void DrawBullet(Bullet bullet[]);
}