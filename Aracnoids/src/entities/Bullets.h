#pragma once

#include "raylib.h"
#include "raymath.h"
#include "ctime"


#include "mouse.h"
#include "player.h"
#include "game_settings/constants.h"

namespace gameBullet
{
	struct Bullet
	{
		clock_t bulletTimeAlive;
		Rectangle bulletRec;
		Circle bulletHitBox;
		Color bulletColor;
		Vector2 bulletPos;
		Vector2 pivot;
		Vector2 direction;
		Vector2 dirNormalizado;
		float rotation;
		float rotationSpeed;
		float radius;
		float impulse;
		Vector2 velocity;
		float angle;
		Vector2 aceleration;
		double maxTimeAlive;
		bool isBulletAlive;
	};

	//Bullet CreateBullet( gamePlayer::Player player);

	//void InitBullets(Bullet bullet[], gamePlayer::Player player);
	void InputBullets(Bullet bullet[], gamePlayer::Player player, mouse::Mouse gameMouse);
	void UpdateBullet(Bullet bullet[]);
	void DrawBullet(Bullet bullet[]);
	float GetMousePosRespectFromPlayer(Bullet bullet[], Vector2 mouse, int index);
}