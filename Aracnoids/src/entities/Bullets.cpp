#include "Bullets.h"


namespace gameBullet
{
	Bullet CreateBullet(gamePlayer::Player player)
	{
		Bullet bullet;
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
		bullet.impulse = 0.2f;
		bullet.aceleration = player.aceleration;

		bullet.maxTimeAlive = 3.0;
		bullet.bulletTimeAlive = 0;
		bullet.isBulletAlive = false;

		return Bullet();
	}

	void InitBullets(Bullet bullet[], gamePlayer::Player player)
	{
		for (int i = 0; i < maxBullets; i++)
		{
			bullet[i].bulletPos.x = player.playerPos.x;
			bullet[i].bulletPos.y = player.playerPos.y;

			bullet[i].bulletHitBox.circlePos.x = player.playerPos.x;
			bullet[i].bulletHitBox.circlePos.y = player.playerPos.y;
			bullet[i].bulletHitBox.radius = 20.0f;

			bullet[i].bulletRec.x = player.playerPos.x;
			bullet[i].bulletRec.y = player.playerPos.y;
			bullet[i].bulletRec.width = 10.0f;
			bullet[i].bulletRec.height = 5.0f;

			bullet[i].pivot.x = player.pivot.x;
			bullet[i].pivot.y = player.pivot.y;
			bullet[i].rotation = player.rotation;
			bullet[i].radius = 10.0f;
			bullet[i].impulse = 0.2f;
			bullet[i].aceleration = player.aceleration;

			bullet[i].maxTimeAlive = 3.0;
			bullet[i].bulletTimeAlive = 0;
			bullet[i].isBulletAlive = false;
		}
	}

	void InputBullets(Bullet bullet[], gamePlayer::Player player, mouse::Mouse gameMouse)
	{
		//disparo bala si se da la orden
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			for (int i = 0; i < maxBullets; i++)
			{
				if (!bullet[i].isBulletAlive)
				{
					bullet[i].bulletPos.x = player.playerPos.x;
					bullet[i].bulletPos.y = player.playerPos.y;

					bullet[i].bulletHitBox.circlePos.x = bullet[i].bulletPos.x;
					bullet[i].bulletHitBox.circlePos.y = bullet[i].bulletPos.y;
					bullet[i].bulletHitBox.radius = 5.0f;

					bullet[i].bulletRec.x = bullet[i].bulletPos.x;
					bullet[i].bulletRec.y = bullet[i].bulletPos.y;
					bullet[i].bulletRec.width = 10.0f;
					bullet[i].bulletRec.height = 5.0f;

					bullet[i].pivot.x = bullet[i].bulletRec.width / 2;
					bullet[i].pivot.y = bullet[i].bulletRec.height / 2;
					bullet[i].rotation = GetMousePosRespectFromPlayer(bullet, gameMouse.mousePos, i);
					bullet[i].direction = player.direction;

					Vector2 direction = Vector2Subtract(gameMouse.mousePos, player.playerPos);
					bullet[i].direction = Vector2Normalize(direction);
					bullet[i].velocity = Vector2Scale(bullet[i].direction, player.velocity);
					bullet[i].impulse = player.impulse;

					bullet[i].radius = 10.0f;
					bullet[i].impulse = player.impulse;
					bullet[i].maxTimeAlive = 2.0;
					bullet[i].isBulletAlive = true;
					bullet[i].bulletTimeAlive = clock();

					break;
				}
			}
		}
		//si no disparo reviso estado actual del cargador
		else if (IsMouseButtonUp(MOUSE_BUTTON_RIGHT))
		{
			for (int i = 0; i < maxBullets; i++)
			{
				if (bullet[i].isBulletAlive)
				{
					float elapsedTime = (float)(clock() - bullet[i].bulletTimeAlive) / CLOCKS_PER_SEC;
					if (elapsedTime >= bullet[i].maxTimeAlive)
					{
						bullet[i].isBulletAlive = false;  // Desactivar la bala
					}
				}
			}
		}
	}

	void UpdateBullet(Bullet bullet[])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullet[i].isBulletAlive == true)
			{
				bullet[i].bulletPos = Vector2Add(bullet[i].bulletPos,
					Vector2Scale(bullet[i].velocity, GetFrameTime()));

				//future sprite updated pos
				bullet[i].bulletRec.x = bullet[i].bulletPos.x;
				bullet[i].bulletRec.y = bullet[i].bulletPos.y;

				bullet[i].bulletHitBox.circlePos.x = bullet[i].bulletPos.x;
				bullet[i].bulletHitBox.circlePos.y = bullet[i].bulletPos.y;
			}

			bullet[i].bulletPos = Vector2Add(bullet[i].bulletPos, Vector2Scale(bullet[i].velocity, GetFrameTime()));

			//chekeo de limites horizontales
			if (bullet[i].bulletPos.x < -bullet[i].radius)
				bullet[i].bulletPos.x = screenWidth + bullet[i].radius;
			if (bullet[i].bulletPos.x > screenWidth +bullet[i].radius)
				bullet[i].bulletPos.x = -bullet[i].radius;
			//chekeo de limites verticales
			if (bullet[i].bulletPos.y < -bullet[i].radius)
				bullet[i].bulletPos.y = screenWidth + bullet[i].radius;
			if (bullet[i].bulletPos.y > screenHeight +bullet[i].radius)
				bullet[i].bulletPos.y = -bullet[i].radius;
		}
	}

	void DrawBullet(Bullet bullet[])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullet[i].isBulletAlive)
			{
				DrawCircleLines(static_cast<int> (bullet[i].bulletHitBox.circlePos.x),
					static_cast<int> (bullet[i].bulletHitBox.circlePos.y), bullet[i].bulletHitBox.radius, RED);
				DrawRectanglePro(bullet[i].bulletRec, bullet[i].pivot, bullet[i].rotation, WHITE);
								
				if (bullet[i].bulletPos.x < bullet[i].radius)
				{
					bullet[i].bulletPos.x = bullet[i].bulletPos.x + screenWidth;

					DrawCircleLines(static_cast<int> (bullet[i].bulletHitBox.circlePos.x), static_cast<int> (bullet[i].bulletHitBox.circlePos.y), bullet[i].bulletHitBox.radius, RED);
					DrawRectanglePro(bullet[i].bulletRec, bullet[i].pivot, bullet[i].rotation, WHITE);
				}
				if (bullet[i].bulletPos.x > screenWidth)
				{
					bullet[i].bulletPos.x = bullet[i].bulletPos.x - screenWidth;
					DrawCircleLines(static_cast<int> (bullet[i].bulletHitBox.circlePos.x), static_cast<int> (bullet[i].bulletHitBox.circlePos.y), bullet[i].bulletHitBox.radius, RED);
					DrawRectanglePro(bullet[i].bulletRec, bullet[i].pivot, bullet[i].rotation, WHITE);
				}
				if (bullet[i].bulletPos.y < bullet[i].radius)
				{
					bullet[i].bulletPos.y = bullet[i].bulletPos.y + screenHeight;
					DrawCircleLines(static_cast<int> (bullet[i].bulletHitBox.circlePos.x), static_cast<int> (bullet[i].bulletHitBox.circlePos.y), bullet[i].bulletHitBox.radius, RED);
					DrawRectanglePro(bullet[i].bulletRec, bullet[i].pivot, bullet[i].rotation, WHITE);
				}
				if (bullet[i].bulletPos.y > screenHeight)
				{
					bullet[i].bulletPos.y = bullet[i].bulletPos.y - screenHeight;
					DrawCircleLines(static_cast<int> (bullet[i].bulletHitBox.circlePos.x), static_cast<int> (bullet[i].bulletHitBox.circlePos.y), bullet[i].bulletHitBox.radius, RED);
					DrawRectanglePro(bullet[i].bulletRec, bullet[i].pivot, bullet[i].rotation, WHITE);
				}
			}
		}
	}

	float GetMousePosRespectFromPlayer(Bullet bullet[], Vector2 mouse, int index)
	{
		float dx = mouse.x - bullet[index].bulletPos.x;
		float dy = mouse.y - bullet[index].bulletPos.y;

		//angulo(?) en radianes
		float theta = static_cast <float>(atan2(dy, dx));

		//Convierto el ángulo a grados
		float thetaGrados = theta * (180.0f / PI);

		return thetaGrados;
	}
}