#include "Bullets.h"


namespace Bullets
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
		bullet.speed = 150.0f;
		bullet.aceleration = player.aceleration;
		bullet.isBulletAlive = false;

		return Bullet();
	}

	void InitBullets(Bullets& playerBullets, Bullet bullet, gamePlayer::Player player)
	{
		playerBullets.maxBullets = 100;

		for (int i = 0; i < playerBullets.maxBullets; i++)
		{
			playerBullets.magazine[i] = CreateBullet(bullet, player);
		}
	}

	/*void UpdateBullet(Bullet& bullet, mouse::Mouse gameMouse)
	{


	}*/

	void DrawBullet(Bullet bullet)
	{
		DrawCircleLines(static_cast<int> (bullet.bulletHitBox.circlePos.x), static_cast<int> (bullet.bulletHitBox.circlePos.y), bullet.bulletHitBox.radius, RED);
		DrawRectanglePro(bullet.bulletRec, bullet.pivot, bullet.rotation, WHITE);
	}

	/*float GetMousePosRespectFromBullet(Bullet bullet, Vector2 mouse)
	{
		return 0.0f;
	}*/

	
}

