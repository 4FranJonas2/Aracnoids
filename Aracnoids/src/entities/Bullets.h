#pragma once

#include "raylib.h"

#include "mouse.h"
#include "player.h"
#include "game_settings/constants.h"

namespace Bullets
{

	struct Bullet
	{
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
		float speed;
		float angle;
		Vector2 aceleration;
		bool isBulletAlive;
	};

	struct Bullets
	{
		int maxBullets;
		Bullet magazine[100];

	};

	Bullet CreateBullet(Bullet bullet, gamePlayer::Player player);

	//void UpdateBullet(Bullet& bullet, mouse::Mouse gameMouse);
	void DrawBullet(Bullet bullet);

	//float GetMousePosRespectFromBullet(Bullet bullet, Vector2 mouse);
}