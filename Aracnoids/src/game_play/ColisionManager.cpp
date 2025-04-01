#include "ColisionManager.h"

namespace colisionManager
{

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

	void BulletNeufarColision(gameBullet::Bullet bullet[],gameEnemy::Neufar neufar[])
	{
		int maxSmallNeufarDeploy = 4;
		int smallNeufarDeploy = 0;

		for (int i = 0; i < maxBullets; i++)
		{
			if (bullet[i].isBulletAlive)
			{
				for (int j = 0; j < maxNeufares; j++)
				{
					if (neufar[j].isNeufarAlive)
					{
						if (CircleCircle(bullet[i].bulletHitBox, neufar[j].neufarHitBox))
						{
							bullet[i].isBulletAlive = false;

							neufar[j].isNeufarAlive = false;

							for (int l = 0; l < maxNeufares; l++)
							{
								if (smallNeufarDeploy < maxSmallNeufarDeploy && !neufar->isNeufarAlive && neufar->isSmallNeufar)
								{
									neufar[l].isNeufarAlive = true;
									neufar[l].neufarPos = neufar[i].neufarPos;
									smallNeufarDeploy++;

								}
								else if (smallNeufarDeploy == maxSmallNeufarDeploy)
								{
									smallNeufarDeploy = 0;
									break;
								}
							}
						}
					}
				}
			}
		}	

		/*for (int i = 0; i < maxNeufares; i++)
		{
			

			
		}*/
	}

	void PlayerNeufarColision(gamePlayer::Player& player, gameEnemy::Neufar neufar[])
	{
		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isNeufarAlive)
			{
				if (CircleCircle(player.playerHitBox, neufar[i].neufarHitBox))
				{
					player.playerLives--;
				}
			}
		}
		
	}

	void NeufarNeufarColision(gameEnemy::Neufar neufar[])
	{
		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isNeufarAlive)
			{
				for (int j = 0; j < maxNeufares; j++)
				{
					if (neufar[j].isNeufarAlive)
					{
						if (CircleCircle(neufar[i].neufarHitBox, neufar[j].neufarHitBox))
						{
							
						}
					}
				}
			}
		}
		
	}
}
