#include "turtle.h"
namespace aracnoids
{
	float RandomAngle();
	float RandomSpeed(float minSpeed, float maxSpeed);
	Vector2 RandomPos();
	EnemyTurtle turtle;

	void aracnoids::InitTurtle()
	{
		turtle.turtleTexture = LoadTexture("res/PowerUps/Turtle.png");

		for (int i = 0; i < maxBigEnemy; i++)
		{
			bigEnemyDecendant[i] = 0;
			bigEnemy[i].isAlive = false;
		}

		for (int i = 0; i < maxMidEnemy; i++)
		{
			midEnemy[i].isAlive = false;
		}
		for (int i = 0; i < maxSmallEnemy; i++)
		{
			smallEnemy[i].isAlive = false;
		}

		nextId = 0;
		spawnTimer = 0.0f;
		spawnDelay = 1.5f;
		bigCounter = 0;
	}

	void aracnoids::UpdateTurtle(Bullet gameBullet[], Player& player, EnemyObject neufar[])
	{

	}

	void aracnoids::DrawTurtle()
	{
	}

	void aracnoids::UnloadTurtle()
	{
	}

	float RandomAngle()
	{
		return DEG2RAD * GetRandomValue(0, 359);
	}
	float RandomSpeed(float minSpeed, float maxSpeed)
	{
		return GetRandomValue(static_cast <int>((minSpeed * 100.0f)), static_cast <int>((maxSpeed * 100.0f))) / 100.0f;
	}
	Vector2 RandomPos()
	{
		int limit = GetRandomValue(0, 3);
		float xPos = 0;
		float yPos = 0;

		switch (limit)
		{
		case 0: // izquierda
			xPos = -100.0f;
			yPos = static_cast <float>(GetRandomValue(0, GetScreenHeight()));
			break;

		case 1: // derecha
			xPos = GetScreenWidth() + 100.0f;
			yPos = static_cast <float>(GetRandomValue(0, GetScreenHeight()));
			break;

		case 2: // arriba
			xPos = static_cast <float>(GetRandomValue(0, GetScreenWidth()));
			yPos = -100.0f;
			break;

		case 3: // abajo
			xPos = static_cast <float>(GetRandomValue(0, GetScreenWidth()));
			yPos = GetScreenHeight() + 100.0f;
			break;

		default:
			break;
		}
		return { xPos, yPos };
	}
}
