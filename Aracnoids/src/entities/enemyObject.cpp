#include "EnemyObject.h"

#include <iostream>

namespace gameEnemy
{
	float countDown = 0.0f;
	float spawnRate = 5.0f;
	float timer = 0.0f;
	float resetTimer = 4.0f;

	void InitNeufar(Neufar neufar[])
	{
		int bigNeufarCounter = 0;
		int smallNeufarCounter = 0;
		int maxRangeNeufarRotation = 360;

		int neufarSpawnRangeOnY = static_cast<int>(screenWidth + (screenWidth / 3));
		int neufarSpawnRangeOnX = static_cast<int>(screenHeight + (screenHeight / 3));

		int randSpawnZone = GetRandomValue(1, 2);

		Vector2 randSpawnPos = { 0.0f,0.0f };

		if (randSpawnZone == 1)
		{
			Vector2 neufarSpawnPosRight_Down;
			neufarSpawnPosRight_Down.x = static_cast<float>(GetRandomValue(static_cast<int>(screenWidth), neufarSpawnRangeOnX));
			neufarSpawnPosRight_Down.y = static_cast<float>(GetRandomValue(static_cast<int>(screenHeight), neufarSpawnRangeOnY));
			randSpawnPos = neufarSpawnPosRight_Down;
		}
		else
		{
			Vector2 neufarSpawnPosTop_Left;
			neufarSpawnPosTop_Left.x = static_cast<float>(GetRandomValue(0, 0 - neufarSpawnRangeOnX));
			neufarSpawnPosTop_Left.y = static_cast<float>(GetRandomValue(0, 0 - neufarSpawnRangeOnY));
			randSpawnPos = neufarSpawnPosTop_Left;
		}

		////neufar type counter
		//for (int i = 0; i < maxNeufares; i++)
		//{
		//	if (neufar[i].isBigNeufar)
		//	{
		//		bigNeufarCounter++;
		//	}
		//	if (neufar[i].isSmallNeufar)
		//	{
		//		smallNeufarCounter++;
		//	}
		//}

		for (int i = 0; i < maxNeufares; i++)
		{

			if (bigNeufarCounter < maxBigNeufares)
			{
				neufar[i].neufarPos.x = randSpawnPos.x;
				neufar[i].neufarPos.y = randSpawnPos.y;

				neufar[i].neufarHitBox.circlePos.x = neufar[i].neufarPos.x;
				neufar[i].neufarHitBox.circlePos.y = neufar[i].neufarPos.y;
				neufar[i].neufarHitBox.radius = 60.0f;

				neufar[i].neufarRec.x = neufar[i].neufarPos.x;
				neufar[i].neufarRec.y = neufar[i].neufarPos.y;
				neufar[i].neufarRec.width = 80.0f;
				neufar[i].neufarRec.height = 80.0f;
				neufar[i].pivot.x = neufar[i].neufarRec.width / 2;
				neufar[i].pivot.y = neufar[i].neufarRec.height / 2;

				//direccion random hacia el centro 
				Vector2 randDirectionNeufar;
				randDirectionNeufar.x = static_cast<float>(GetRandomValue(0, static_cast<int>(screenWidth)));
				randDirectionNeufar.y = static_cast<float>(GetRandomValue(0, static_cast<int>(screenHeight)));

				float velocity = 50.0f;
				Vector2 direction = Vector2Subtract(randDirectionNeufar, neufar[i].neufarPos);
				neufar[i].direction = Vector2Normalize(direction);
				neufar[i].velocity = Vector2Scale(neufar[i].direction, velocity);

				neufar[i].rotation = static_cast<float>(GetRandomValue(0, maxRangeNeufarRotation));
				neufar[i].impulse = 0.2f;
				neufar[i].aceleration = { 100.0f,100.0f };
				neufar[i].isNeufarAlive = false;
				neufar[i].isBigNeufar = true;

				bigNeufarCounter++;
			}
			else
			{
				neufar[i].neufarPos.x = randSpawnPos.x;
				neufar[i].neufarPos.y = randSpawnPos.y;

				neufar[i].neufarHitBox.circlePos.x = neufar[i].neufarPos.x;
				neufar[i].neufarHitBox.circlePos.y = neufar[i].neufarPos.y;
				neufar[i].neufarHitBox.radius = 20.0f;

				neufar[i].neufarRec.x = neufar[i].neufarPos.x;
				neufar[i].neufarRec.y = neufar[i].neufarPos.y;
				neufar[i].neufarRec.width = 30.0f;
				neufar[i].neufarRec.height = 30.0f;
				neufar[i].pivot.x = neufar[i].neufarRec.width / 2;
				neufar[i].pivot.y = neufar[i].neufarRec.height / 2;

				//direccion random hacia el centro 
				Vector2 randDirectionNeufar;
				randDirectionNeufar.x = static_cast<float>(GetRandomValue(0, static_cast<int>(screenWidth)));
				randDirectionNeufar.y = static_cast<float>(GetRandomValue(0, static_cast<int>(screenHeight)));

				float velocity = 50.0f;
				Vector2 direction = Vector2Subtract(randDirectionNeufar, neufar[i].neufarPos);
				neufar[i].direction = Vector2Normalize(direction);
				neufar[i].velocity = Vector2Scale(neufar[i].direction, velocity);

				neufar[i].rotation = static_cast<float>(GetRandomValue(0, maxRangeNeufarRotation));
				neufar[i].impulse = 0.2f;
				neufar[i].aceleration = { 100.0f,100.0f };
				neufar[i].isNeufarAlive = false;
				neufar[i].isBigNeufar = false;

				smallNeufarCounter++;
			}
		}

	}
	void UpdateNeufar(Neufar neufar[])
	{
		timer -= GetFrameTime();

		if (timer <= 0)
		{
			for (int i = 0; i < maxNeufares; i++)
			{
				if (!neufar[i].isNeufarAlive)
				{
					neufar[i].isNeufarAlive = true;
					timer = resetTimer;
					break;
				}
			}
		}

		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isNeufarAlive && neufar[i].isBigNeufar)
			{
				neufar[i].neufarPos = Vector2Add(neufar[i].neufarPos, Vector2Scale(neufar[i].velocity, GetFrameTime()));

				//future sprite updated pos
				neufar[i].neufarRec.x = neufar[i].neufarPos.x;
				neufar[i].neufarRec.y = neufar[i].neufarPos.y;

				neufar[i].neufarHitBox.circlePos.x = neufar[i].neufarPos.x;
				neufar[i].neufarHitBox.circlePos.y = neufar[i].neufarPos.y;


				neufar[i].neufarPos = Vector2Add(neufar[i].neufarPos, Vector2Scale(neufar[i].velocity, GetFrameTime()));

				//chekeo de limites horizontales
				if (neufar[i].neufarPos.x < -neufar[i].neufarHitBox.radius)
					neufar[i].neufarPos.x = screenWidth + neufar[i].neufarHitBox.radius;
				if (neufar[i].neufarPos.x > screenWidth + neufar[i].neufarHitBox.radius)
					neufar[i].neufarPos.x = -neufar[i].neufarHitBox.radius;
				//chekeo de limites verticales
				if (neufar[i].neufarPos.y < -neufar[i].neufarHitBox.radius)
					neufar[i].neufarPos.y = screenWidth + neufar[i].neufarHitBox.radius;
				if (neufar[i].neufarPos.y > screenHeight + neufar[i].neufarHitBox.radius)
					neufar[i].neufarPos.y = -neufar[i].neufarHitBox.radius;
			}

		}
	}

	void DrawNeufar(Neufar neufar[])
	{
		if (matchStart == true)
		{
			for (int i = 0; i < maxNeufares; i++)
			{
				if (neufar[i].isNeufarAlive)
				{
					DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
	#ifdef _DEBUG
					DrawCircleLines(static_cast<int> (neufar[i].neufarHitBox.circlePos.x), static_cast<int> (neufar[i].neufarHitBox.circlePos.y), neufar[i].neufarHitBox.radius, RED);
	#endif //_DEBUG

					if (neufar[i].neufarPos.x < neufar[i].neufarHitBox.radius)
					{
						neufar[i].neufarPos.x = neufar[i].neufarPos.x + screenWidth;
						DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
					}
					if (neufar[i].neufarPos.x > screenWidth)
					{
						neufar[i].neufarPos.x = neufar[i].neufarPos.x - screenWidth;
						DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
					}
					if (neufar[i].neufarPos.y < neufar[i].neufarHitBox.radius)
					{
						neufar[i].neufarPos.y = neufar[i].neufarPos.y + screenHeight;
						DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
					}
					if (neufar[i].neufarPos.y > screenHeight)
					{
						neufar[i].neufarPos.y = neufar[i].neufarPos.y - screenHeight;
						DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
					}
				}
			}

		}
	}
}