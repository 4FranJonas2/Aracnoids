#include "bullet.h"

namespace aracnoids
{
	int maxBullets = 15;

	void InputBullets(Bullet bullet[], Player player)
	{
		//disparo bala si se da la orden
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			for (int i = 0; i < maxBullets; i++)
			{
				if (!bullet[i].isBulletAlive)
				{
					bullet[i].bulletHitBox.pos.x = player.playerCir.pos.x;
					bullet[i].bulletHitBox.pos.y = player.playerCir.pos.y;
					bullet[i].bulletHitBox.rad = 5.0f;

					bullet[i].bulletRec.x = bullet[i].bulletHitBox.pos.x;
					bullet[i].bulletRec.y = bullet[i].bulletHitBox.pos.y;
					bullet[i].bulletRec.width = 10.0f;
					bullet[i].bulletRec.height = 5.0f;
					bullet[i].rotation = player.rotation;

					//bullet[i].velocity = Vector2Scale(bullet[i].direction, player.velocity);
					bullet[i].impulse = player.speed;

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
			if (bullet[i].isBulletAlive)
			{
				bullet[i].bulletHitBox.pos = Vector2Add(bullet[i].bulletHitBox.pos, Vector2Scale(bullet[i].velocity, GetFrameTime()));

				//future sprite updated pos
				bullet[i].bulletRec.x = bullet[i].bulletHitBox.pos.x;
				bullet[i].bulletRec.y = bullet[i].bulletHitBox.pos.y;
			}

			bullet[i].bulletHitBox.pos = Vector2Add(bullet[i].bulletHitBox.pos, Vector2Scale(bullet[i].velocity, GetFrameTime()));

			//chekeo de limites horizontales
			if (bullet[i].bulletHitBox.pos.x < -bullet[i].bulletHitBox.rad)
				bullet[i].bulletHitBox.pos.x = GetScreenWidth() + bullet[i].bulletHitBox.rad;
			if (bullet[i].bulletHitBox.pos.x > GetScreenWidth() + bullet[i].bulletHitBox.rad)
				bullet[i].bulletHitBox.pos.x = -bullet[i].bulletHitBox.rad;
			//chekeo de limites verticales
			if (bullet[i].bulletHitBox.pos.y < -bullet[i].bulletHitBox.rad)
				bullet[i].bulletHitBox.pos.y = GetScreenWidth() + bullet[i].bulletHitBox.rad;
			if (bullet[i].bulletHitBox.pos.y > GetScreenHeight() + bullet[i].bulletHitBox.rad)
				bullet[i].bulletHitBox.pos.y = -bullet[i].bulletHitBox.rad;
		}
	}

	void DrawBullet(Bullet bullet[])
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullet[i].isBulletAlive)
			{

				DrawRectanglePro({ bullet[i].bulletHitBox.pos.x,bullet[i].bulletHitBox.pos.y }, { bullet[i].bulletRec.width,bullet[i].bulletRec.height }, bullet[i].rotation, WHITE);
#ifdef _DEBUG
				DrawCircleLines(static_cast<int>(bullet[i].bulletHitBox.pos.x), static_cast<int>(bullet[i].bulletHitBox.pos.y), bullet[i].bulletHitBox.rad, RED);
#endif //_DEBUG

				if (bullet[i].bulletHitBox.pos.x < bullet[i].bulletHitBox.rad)
				{
					bullet[i].bulletHitBox.pos.x = bullet[i].bulletHitBox.pos.x + GetScreenWidth();
					DrawRectanglePro({ bullet[i].bulletHitBox.pos.x,bullet[i].bulletHitBox.pos.y }, { bullet[i].bulletRec.width,bullet[i].bulletRec.height }, bullet[i].rotation, WHITE);
				}
				if (bullet[i].bulletHitBox.pos.x > GetScreenWidth())
				{
					bullet[i].bulletHitBox.pos.x = bullet[i].bulletHitBox.pos.x - GetScreenWidth();
					DrawRectanglePro({ bullet[i].bulletHitBox.pos.x,bullet[i].bulletHitBox.pos.y }, { bullet[i].bulletRec.width,bullet[i].bulletRec.height }, bullet[i].rotation, WHITE);
				}
				if (bullet[i].bulletHitBox.pos.y < bullet[i].bulletHitBox.rad)
				{
					bullet[i].bulletHitBox.pos.y = bullet[i].bulletHitBox.pos.y + GetScreenHeight();
					DrawRectanglePro({ bullet[i].bulletHitBox.pos.x,bullet[i].bulletHitBox.pos.y }, { bullet[i].bulletRec.width,bullet[i].bulletRec.height }, bullet[i].rotation, WHITE);
				}
				if (bullet[i].bulletHitBox.pos.y > GetScreenHeight())
				{
					bullet[i].bulletHitBox.pos.y = bullet[i].bulletHitBox.pos.y - GetScreenHeight();
					DrawRectanglePro({ bullet[i].bulletHitBox.pos.x,bullet[i].bulletHitBox.pos.y }, { bullet[i].bulletRec.width,bullet[i].bulletRec.height }, bullet[i].rotation, WHITE);
				}

			}
		}
	}
}