#include "Bullets.h"


namespace playerBullet
{
	Bullet CreateBullet(Bullet bullet, gamePlayer::Player player)
	{	
		//bullets
		bullet.bulletPos.x = player.playerPos.x - player.radius;
		bullet.bulletPos.y = player.playerPos.y - player.radius;
		//hitbox
		bullet.bulletHitBox.circlePos.x = bullet.bulletPos.x;
		bullet.bulletHitBox.circlePos.y = bullet.bulletPos.y;
		bullet.bulletHitBox.radius = 5.0f;
		//sprite
		bullet.bulletRec.x = bullet.bulletPos.x;
		bullet.bulletRec.y = bullet.bulletPos.y;
		bullet.bulletRec.width = 10.0f;
		bullet.bulletRec.height = 5.0f;

		bullet.pivot.x = player.pivot.x;
		bullet.pivot.y = player.pivot.y;
		bullet.rotation = player.rotation;
		bullet.radius = 10.0f;
		bullet.velocity = 200.0f;
		bullet.impulse = 0.2f;
		bullet.aceleration = player.aceleration;

		bullet.maxTimeAlive = 3.0;
		bullet.bulletTimeAlive = 0.0;
		bullet.isBulletAlive = false;

		return Bullet();
	}

	void InitBullets(Magazine& playerBullets, Bullet bullet, gamePlayer::Player player)
	{
		playerBullets.maxBullets = 100;

		for (int i = 0; i < playerBullets.maxBullets; i++)
		{
			playerBullets.magazine[i] = CreateBullet(bullet, player);
		}
	}

	void UpdateBullet(Magazine& playerBullets, mouse::Mouse gameMouse, Bullet bullet, gamePlayer::Player player)
	{
		//disparo bala si se da la orden
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			for (int i = 0; i < playerBullets.maxBullets; i++)
			{
				if (!playerBullets.magazine[i].isBulletAlive)
				{
					playerBullets.magazine[i] = CreateBullet(bullet,player);
					playerBullets.magazine[i].isBulletAlive = true;
					playerBullets.magazine[i].bulletTimeAlive = clock();

					break;
				}
			}
		}
		//si no disparo reviso estado actual del cargador
		else if (IsMouseButtonUp(MOUSE_BUTTON_RIGHT))
		{
			for (int i = 0; i < playerBullets.maxBullets; i++)
			{
				if (playerBullets.magazine[i].isBulletAlive)
				{
					playerBullets.magazine[i].bulletTimeAlive = clock() - playerBullets.magazine[i].bulletTimeAlive;

					if (playerBullets.magazine[i].bulletTimeAlive = clock() == playerBullets.magazine[i].maxTimeAlive)
					{
						playerBullets.magazine[i].isBulletAlive = false;
					}
				}
			}
		}
	}

	void DrawBullet(Magazine playerBullets)
	{
		for (int i = 0; i < playerBullets.maxBullets; i++)
		{
			if (playerBullets.magazine[i].isBulletAlive)
			{
				DrawCircleLines(static_cast<int> (playerBullets.magazine[i].bulletHitBox.circlePos.x),
					static_cast<int> (playerBullets.magazine[i].bulletHitBox.circlePos.y), playerBullets.magazine[i].bulletHitBox.radius, RED);
				DrawRectanglePro(playerBullets.magazine[i].bulletRec, playerBullets.magazine[i].pivot, playerBullets.magazine[i].rotation, WHITE);
			}
		}
	}
}

