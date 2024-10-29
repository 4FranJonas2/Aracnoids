#include "enemyObject.h"
#include <iostream>

namespace gameEnemy
{
	float countDown = 0.0f;
	float spawnRate = 5.0f;

	void InitNeufar(Neufar neufar[], gamePlayer::Player& player)
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

		//neufar type counter
		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isBigNeufar)
			{
				bigNeufarCounter++;
			}
			if (neufar[i].isSmallNeufar)
			{
				smallNeufarCounter++;
			}
		}

		//neufar spawns
		for (int i = 0; i < maxNeufares; i++)
		{
			player.elapsedTime += player.spawnTime;

#ifdef _DEBUG
			std::cout << "time: " << player.elapsedTime << std::endl;
#endif // _DEBUG

			player.elapsedTime = player.currentTime - static_cast<float> (player.neufarTimeSpawn);

			//countDown -= (GetFrameTime() < countDown) ? GetFrameTime() : countDown;


				if (player.elapsedTime >= spawnRate && !neufar[i].isNeufarAlive && bigNeufarCounter < maxBigNeufares)
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
					neufar[i].isNeufarAlive = true;
					neufar[i].isBigNeufar = true;

					player.elapsedTime = 0;

					// player.spawnTime =GetTime();
					break;
				}
		}
	}
	void UpdateNeufar(Neufar neufar[])
	{
		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isNeufarAlive)
			{
				neufar[i].neufarPos = Vector2Add(neufar[i].neufarPos, Vector2Scale(neufar[i].velocity, GetFrameTime()));

				//future sprite updated pos
				neufar[i].neufarRec.x = neufar[i].neufarPos.x;
				neufar[i].neufarRec.y = neufar[i].neufarPos.y;

				neufar[i].neufarHitBox.circlePos.x = neufar[i].neufarPos.x;
				neufar[i].neufarHitBox.circlePos.y = neufar[i].neufarPos.y;
			}

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

	void DrawNeufar(Neufar neufar[])
	{
		for (int i = 0; i < maxNeufares; i++)
		{
			if (neufar[i].isNeufarAlive)
			{
				DrawCircleLines(static_cast<int> (neufar[i].neufarHitBox.circlePos.x),
					static_cast<int> (neufar[i].neufarHitBox.circlePos.y), neufar[i].neufarHitBox.radius, RED);
				DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);

				if (neufar[i].neufarPos.x < neufar[i].neufarHitBox.radius)
				{
					neufar[i].neufarPos.x = neufar[i].neufarPos.x + screenWidth;

					DrawCircleLines(static_cast<int> (neufar[i].neufarHitBox.circlePos.x), static_cast<int> (neufar[i].neufarHitBox.circlePos.y), neufar[i].neufarHitBox.radius, RED);
					DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
				}
				if (neufar[i].neufarPos.x > screenWidth)
				{
					neufar[i].neufarPos.x = neufar[i].neufarPos.x - screenWidth;
					DrawCircleLines(static_cast<int> (neufar[i].neufarHitBox.circlePos.x), static_cast<int> (neufar[i].neufarHitBox.circlePos.y), neufar[i].neufarHitBox.radius, RED);
					DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
				}
				if (neufar[i].neufarPos.y < neufar[i].neufarHitBox.radius)
				{
					neufar[i].neufarPos.y = neufar[i].neufarPos.y + screenHeight;
					DrawCircleLines(static_cast<int> (neufar[i].neufarHitBox.circlePos.x), static_cast<int> (neufar[i].neufarHitBox.circlePos.y), neufar[i].neufarHitBox.radius, RED);
					DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
				}
				if (neufar[i].neufarPos.y > screenHeight)
				{
					neufar[i].neufarPos.y = neufar[i].neufarPos.y - screenHeight;
					DrawCircleLines(static_cast<int> (neufar[i].neufarHitBox.circlePos.x), static_cast<int> (neufar[i].neufarHitBox.circlePos.y), neufar[i].neufarHitBox.radius, RED);
					DrawRectanglePro(neufar[i].neufarRec, neufar[i].pivot, neufar[i].rotation, WHITE);
				}
			}
		}
	}


}