#pragma once

#include "raylib.h"
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
		float velocity;
		float angle;
		Vector2 aceleration;
		double maxTimeAlive;
		bool isBulletAlive;
	};

	struct Magazine
	{
		int maxBullets;
		Bullet magazine[100];
	};

	Bullet CreateBullet(Bullet bullet, gamePlayer::Player player);

	void InitBullets(Magazine& playerBullets, Bullet bullet, gamePlayer::Player player);
	void UpdateBullet(Magazine& playerBullets, Bullet bullet, gamePlayer::Player player);
	void DrawBullet(Magazine playerBullets);
}