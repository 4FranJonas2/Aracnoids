#include "bullet.h"

namespace aracnoids
{
	int bullets = 15;
	bool isShoot = false;

	static void PrintBullet(Bullet bullet[], int i);
#ifdef _DEBUG
	static void DrawHitBox(Bullet bullet[], int i);
#endif // _DEBUG

	void InputBullet()
	{
		//disparo bala si se da la orden
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			isShoot = true;
	}

	void CreateBullet(Bullet bullet[], Player player)
	{
		//disparo bala si se da la orden
		if (isShoot)
			for (int i = 0; i < bullets; i++)
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

					Vector2 direction = Vector2Subtract(GetMousePosition(), player.playerCir.pos);
					bullet[i].vecDir = Vector2Normalize(direction);
					bullet[i].impulse = 500.0;
					bullet[i].velocity = Vector2Scale(bullet[i].vecDir, bullet[i].impulse);

					bullet[i].maxTimeAlive = 2.0;
					bullet[i].isBulletAlive = true;
					bullet[i].bulletTimeAlive = clock();

					isShoot = false;

					break;
				}
	}

	void UpdateBullet(Bullet bullet[])
	{
		for (int i = 0; i < bullets; i++)
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

			if (IsMouseButtonUp(MOUSE_BUTTON_RIGHT))
				for (int j = 0; j < bullets; j++)
					if (bullet[j].isBulletAlive)
					{
						float elapsedTime = (float)(clock() - bullet[j].bulletTimeAlive) / CLOCKS_PER_SEC;
						if (elapsedTime >= bullet[j].maxTimeAlive)
							bullet[j].isBulletAlive = false;  // Desactivar la bala
					}
			bullet[i].bulletRec.x = bullet[i].bulletHitBox.pos.x;
			bullet[i].bulletRec.y = bullet[i].bulletHitBox.pos.y;
		}
	}

	void DrawBullet(Bullet bullet[])
	{
		for (int i = 0; i < bullets; i++)
			if (bullet[i].isBulletAlive)
			{
				PrintBullet(bullet, i);

				if (bullet[i].bulletHitBox.pos.x < bullet[i].bulletHitBox.rad)
				{
					bullet[i].bulletHitBox.pos.x = bullet[i].bulletHitBox.pos.x + GetScreenWidth();
					PrintBullet(bullet, i);
				}
				if (bullet[i].bulletHitBox.pos.x > GetScreenWidth())
				{
					bullet[i].bulletHitBox.pos.x = bullet[i].bulletHitBox.pos.x - GetScreenWidth();
					PrintBullet(bullet, i);
				}
				if (bullet[i].bulletHitBox.pos.y < bullet[i].bulletHitBox.rad)
				{
					bullet[i].bulletHitBox.pos.y = bullet[i].bulletHitBox.pos.y + GetScreenHeight();
					PrintBullet(bullet, i);
				}
				if (bullet[i].bulletHitBox.pos.y > GetScreenHeight())
				{
					bullet[i].bulletHitBox.pos.y = bullet[i].bulletHitBox.pos.y - GetScreenHeight();
					PrintBullet(bullet, i);
				}
			}
	}

	static void PrintBullet(Bullet bullet[], int i)
	{
		DrawRectanglePro(bullet[i].bulletRec, { bullet[i].bulletRec.width,bullet[i].bulletRec.height }, bullet[i].rotation, RED);
#ifdef _DEBUG
		DrawHitBox(bullet, i);
#endif // _DEBUG
	}

#ifdef _DEBUG
	static void DrawHitBox(Bullet bullet[], int i)
	{
		DrawCircleLines(static_cast<int>(bullet[i].bulletHitBox.pos.x), static_cast<int>(bullet[i].bulletHitBox.pos.y), bullet[i].bulletHitBox.rad, RED);
	}
#endif
}