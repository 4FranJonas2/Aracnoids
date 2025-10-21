#include "enemyObj.h"

namespace aracnoids
{
	const int maxBigEnemy = 5;
	const int maxMidEnemy = 10;
	const int maxSmallEnemy = 40;
	EnemyObject bigEnemy[maxBigEnemy];
	EnemyObject midEnemy[maxMidEnemy];
	EnemyObject smallEnemy[maxSmallEnemy];

	int bigEnemyDecendant[maxBigEnemy];
	int nextId = 0;

	float spawnTimer = 0.0f;
	float spawnDelay = 1.5f;
	int bigCounter = 0;

	float RandomAngle();
	float RandomSpeed(float minSpeed, float maxSpeed);
	Vector2 RandomPos();

	void MoveEnemyObj(EnemyObject& neufar);
	void Bounce(EnemyObject& neufarA, EnemyObject& neufarB);
	void DeleteBigEnemy(int i);
	void DeleteMidEnemy(int i);
	void DeleteSmallEnemy(int i);
	void CheckCollisionEnemys();
	void CheckCollisionEnemysBullet(Bullet bullet[]);

	void CreateBigEnemy()
	{
		for (int i = 0; i < maxBigEnemy; i++)		
			if (!bigEnemy[i].isAlive)
			{
				bigEnemy[i].isAlive = true;
				bigEnemy[i].pos = RandomPos();
				bigEnemy[i].angle = RandomAngle();
				bigEnemy[i].speed = RandomSpeed(80, 150);
				bigEnemy[i].radius = 40;
				bigEnemy[i].type = 0;
				bigEnemy[i].parentId = -1;
				bigEnemy[i].id = nextId++;

				bigEnemyDecendant[i] = 0;
				bigCounter++;
				break;
			}		
	}

	void CreateMediumEnemy(int idBigEnemy, Vector2 pos, float baseAngle)
	{
		for (int i = 0; i < maxMidEnemy; i++)		
			if (!midEnemy[i].isAlive)
			{
				midEnemy[i].isAlive = true;
				midEnemy[i].pos = pos;
				midEnemy[i].angle = baseAngle + DEG2RAD * GetRandomValue(-20, 20);
				midEnemy[i].speed = RandomSpeed(80, 150);
				midEnemy[i].radius = 25;
				midEnemy[i].type = 1;
				midEnemy[i].parentId = idBigEnemy;
				midEnemy[i].id = nextId++;

				bigEnemyDecendant[idBigEnemy] += 1;
				if (bigEnemyDecendant[idBigEnemy] >= 2)
					break; // Solo dos medianos
			}	
	}
	void CreateSmallEnemy(int idBigEnemy, Vector2 pos, float baseAngle)
	{
		int smallCounter = 0;
		for (int i = 0; i < maxSmallEnemy; i++)		
			if (!smallEnemy[i].isAlive)
			{
				smallEnemy[i].isAlive = true;
				smallEnemy[i].pos = pos;
				smallEnemy[i].angle = baseAngle + DEG2RAD * GetRandomValue(-45, 45);
				smallEnemy[i].speed = RandomSpeed(80, 150);
				smallEnemy[i].radius = 10;
				smallEnemy[i].type = 2;
				smallEnemy[i].parentId = idBigEnemy;
				smallEnemy[i].id = nextId++;
				bigEnemyDecendant[idBigEnemy] += 1;
				smallCounter++;
				if (smallCounter == 4)
					break;
			}	
	}
	void UpdateEnemyObject(Bullet gameBullet[])
	{
		spawnTimer += GetFrameTime();

		if (spawnTimer >= spawnDelay && bigCounter < maxBigEnemy)
		{
			CreateBigEnemy();
			spawnTimer = 0;
		}

		for (int i = 0; i < maxBigEnemy; i++)
			if (bigEnemy[i].isAlive)
				MoveEnemyObj(bigEnemy[i]);

		for (int i = 0; i < maxMidEnemy; i++)
			if (midEnemy[i].isAlive)
				MoveEnemyObj(midEnemy[i]);

		for (int i = 0; i < maxSmallEnemy; i++)
			if (smallEnemy[i].isAlive)
				MoveEnemyObj(smallEnemy[i]);

		CheckCollisionEnemys();

		CheckCollisionEnemysBullet(gameBullet);
	}
	void DrawEnemyObject()
	{
		for (int i = 0; i < maxBigEnemy; i++)
			if (bigEnemy[i].isAlive)
				DrawCircleLines(static_cast <int>(bigEnemy[i].pos.x), static_cast <int>(bigEnemy[i].pos.y), bigEnemy[i].radius, RED);

		for (int i = 0; i < maxMidEnemy; i++)
			if (midEnemy[i].isAlive)
				DrawCircleLines(static_cast <int>(midEnemy[i].pos.x), static_cast <int>(midEnemy[i].pos.y), midEnemy[i].radius, ORANGE);

		for (int i = 0; i < maxSmallEnemy; i++)
			if (smallEnemy[i].isAlive)
				DrawCircleLines(static_cast <int>(smallEnemy[i].pos.x), static_cast <int>(smallEnemy[i].pos.y), smallEnemy[i].radius, YELLOW);
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
		return { static_cast <float> (GetRandomValue(0, GetScreenWidth())),
			static_cast <float> (GetRandomValue(0, GetScreenHeight())) };
	}

	void MoveEnemyObj(EnemyObject& neufar)
	{
		neufar.pos.x += cosf(neufar.angle) * neufar.speed * GetFrameTime();
		neufar.pos.y += sinf(neufar.angle) * neufar.speed * GetFrameTime();

		if (neufar.speed > 200)
			neufar.speed = 200;

		if (neufar.pos.x < 0)
			neufar.pos.x = static_cast <float>(GetScreenWidth());

		if (neufar.pos.x > GetScreenWidth())
			neufar.pos.x = 0;

		if (neufar.pos.y < 0)
			neufar.pos.y = static_cast <float>(GetScreenHeight());

		if (neufar.pos.y > GetScreenHeight())
			neufar.pos.y = 0;
	}
	void Bounce(EnemyObject& neufarA, EnemyObject& neufarB)
	{
		Vector2 delta = Vector2Subtract(neufarB.pos, neufarA.pos);
		float dist = Vector2Length(delta);
		if (dist == 0)
			return;

		float overlap = (neufarA.radius + neufarB.radius) - dist;
		if (overlap > 0)
		{
			Vector2 normal = Vector2Normalize(delta);
			neufarA.pos = Vector2Subtract(neufarA.pos, Vector2Scale(normal, overlap / 2));
			neufarB.pos = Vector2Add(neufarB.pos, Vector2Scale(normal, overlap / 2));

			Vector2 velA = { cosf(neufarA.angle) * neufarA.speed, sinf(neufarA.angle) * neufarA.speed };
			Vector2 velB = { cosf(neufarB.angle) * neufarB.speed, sinf(neufarB.angle) * neufarB.speed };

			float velANorm = Vector2DotProduct(velA, normal);
			float velBNorm = Vector2DotProduct(velB, normal);


			float aux = velANorm;
			velANorm = velBNorm;
			velBNorm = aux;

			Vector2 vaT = Vector2Subtract(velA, Vector2Scale(normal, velANorm)); // tangencial
			Vector2 vbT = Vector2Subtract(velB, Vector2Scale(normal, velBNorm));

			velA = Vector2Add(vaT, Vector2Scale(normal, velANorm));
			velB = Vector2Add(vbT, Vector2Scale(normal, velBNorm));

			neufarA.speed = Vector2Length(velA);
			neufarB.speed = Vector2Length(velB);
			neufarA.angle = atan2f(velA.y, velA.x);
			neufarB.angle = atan2f(velB.y, velB.x);
		}
	}

	void DeleteBigEnemy(int i)
	{
		if (!bigEnemy[i].isAlive) return;
		Vector2 pos = bigEnemy[i].pos;
		float angle = bigEnemy[i].angle;
		bigEnemy[i].isAlive = false;

		// 2 medianos
		CreateMediumEnemy(i, pos, angle);
	}
	void DeleteMidEnemy(int i)
	{
		if (!midEnemy[i].isAlive) return;
		int idGrande = midEnemy[i].parentId;
		Vector2 pos = midEnemy[i].pos;
		float angle = midEnemy[i].angle;
		midEnemy[i].isAlive = false;

		CreateSmallEnemy(idGrande, pos, angle);
	}
	void DeleteSmallEnemy(int i)
	{
		if (!smallEnemy[i].isAlive) return;
		int idGrande = smallEnemy[i].parentId;
		smallEnemy[i].isAlive = false;

		if (idGrande >= 0 && idGrande < maxBigEnemy)		
			bigEnemyDecendant[idGrande]--;
	}

	void CheckCollisionEnemys()
	{
		//grande grande
		for (int i = 0; i < maxBigEnemy; i++)
		{
			if (!bigEnemy[i].isAlive)
				continue;
			for (int j = 0; j < maxBigEnemy; j++)
				if (bigEnemy[j].isAlive)
					Bounce(bigEnemy[i], bigEnemy[j]);
		}

		//mediano mediano
		for (int i = 0; i < maxMidEnemy; i++)
		{
			if (!midEnemy[i].isAlive)
				continue;
			for (int j = 0; j < maxMidEnemy; j++)			
				if (midEnemy[j].isAlive)
					Bounce(midEnemy[i], midEnemy[j]);			
		}


		//chicos chicos
		for (int i = 0; i < maxSmallEnemy; i++)
		{
			if (!smallEnemy[i].isAlive)
				continue;
			for (int j = 0; j < maxSmallEnemy; j++)			
				if (smallEnemy[j].isAlive)
					Bounce(smallEnemy[i], smallEnemy[j]);			
		}

		//grandes con medianos y chicos
		for (int i = 0; i < maxBigEnemy; i++)
		{
			if (!bigEnemy[i].isAlive)
				continue;
			for (int j = 0; j < maxMidEnemy; j++)			
				if (midEnemy[j].isAlive)
					Bounce(bigEnemy[i], midEnemy[j]);
			
			for (int k = 0; k < maxSmallEnemy; k++)			
				if (smallEnemy[k].isAlive)
					Bounce(bigEnemy[i], smallEnemy[k]);			
		}

		//medianos con chicos
		for (int i = 0; i < maxMidEnemy; i++)
		{
			if (!midEnemy[i].isAlive)
				continue;
			for (int j = 0; j < maxSmallEnemy; j++)			
				if (smallEnemy[j].isAlive)
					Bounce(midEnemy[i], smallEnemy[j]);
		}
	}
	void CheckCollisionEnemysBullet(Bullet bullet[])
	{
		const int maxBullets = 20;

		for (int i = 0; i < maxBullets; i++)
		{
			if (!bullet[i].isBulletAlive) continue;
			//grande 
			for (int j = 0; j < maxBigEnemy; j++)			
				if (bigEnemy[j].isAlive && Vector2Distance(bullet[i].bulletHitBox.pos, bigEnemy[j].pos) < bullet[i].bulletHitBox.rad + bigEnemy[j].radius)
				{
					bullet[i].isBulletAlive = false;
					DeleteBigEnemy(j);
					break;
				}

			//mediano 
			for (int j = 0; j < maxMidEnemy; j++)			
				if (midEnemy[j].isAlive && Vector2Distance(bullet[i].bulletHitBox.pos, midEnemy[j].pos) < bullet[i].bulletHitBox.rad + midEnemy[j].radius)
				{
					bullet[i].isBulletAlive = false;
					DeleteMidEnemy(j);
					break;
				}			

			//chicos 
			for (int j = 0; j < maxSmallEnemy; j++)			
				if (smallEnemy[j].isAlive && Vector2Distance(bullet[i].bulletHitBox.pos, smallEnemy[j].pos) < bullet[i].bulletHitBox.rad + smallEnemy[j].radius)
				{
					bullet[i].isBulletAlive = false;
					DeleteSmallEnemy(j);
					break;
				}		
		}
	}
}