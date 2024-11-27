#include "ColisionManager.h"

#include"entities/Player.h"
#include"entities/Bullets.h"
#include"entities/EnemyObject.h"

namespace ColisionManager
{
	gamePlayer::Player player{};
	gameEnemy::Neufar neufar[maxNeufares];
	gameEnemy::Neufar neufar2[maxNeufares];
	gameBullet::Bullet bullet[maxBullets];


	bool CircleCircle(Circle circle1, Circle circle2)
	{
		float distX = circle1.circlePos.x - circle2.circlePos.x;
		float distY = circle1.circlePos.y - circle2.circlePos.y;
		float distance = sqrt((distX * distX) + (distY * distY));

		if (distance <= circle1.radius + circle2.radius)
		{
			return true;
		}
		return false;
	}

	bool PlayerNeufarColision()
	{
		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isNeufarAlive)
			{
				if (CircleCircle(player.playerHitBox, neufar[i].neufarHitBox))
				{
					return true;
				}
				
			}
		}
		return false;
	}

	bool NeufarNeufarColision()
	{
		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isNeufarAlive)
			{
				for (int j = 0; j < maxNeufares; j++)
				{
					if (neufar2[j].isNeufarAlive)
					{
						if (CircleCircle(neufar[j].neufarHitBox, neufar2[j].neufarHitBox))
						{
							return true;
						}
						
					}
				}
			}
		}
		return false;

	}

	bool BulletNeufarColision()
	{
		for (int i = 0; i < maxBullets; i++)
		{
			if (bullet[i].isBulletAlive)
			{
				for (int j = 0; j < maxNeufares; j++)
				{
					if (neufar[j].isNeufarAlive)
					{
						if (CircleCircle(bullet[j].bulletHitBox, neufar[j].neufarHitBox))
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
}
