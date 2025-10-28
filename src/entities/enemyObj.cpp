#include "enemyObj.h"

namespace aracnoids
{
	const int maxBigEnemy = 5;
	const int maxMidEnemy = 10;
	const int maxSmallEnemy = 40;
	EnemyObject bigEnemy[maxBigEnemy];
	EnemyObject midEnemy[maxMidEnemy];
	EnemyObject smallEnemy[maxSmallEnemy];

	Texture2D bigNeufarText;
	Texture2D midNeufarText;
	Texture2D smallNeufarText;

	int bigEnemyDecendant[maxBigEnemy] = { 0 };
	int nextId = 0;
	float spawnTimer = 0.0f;
	float spawnDelay = 1.5f;
	int bigCounter = 0;

	float RandomAngle();
	float RandomSpeed(float minSpeed, float maxSpeed);
	Vector2 RandomPos();

	void MoveEnemyObj(EnemyObject& neufar);
	void Bounce(EnemyObject& neufarA, EnemyObject& neufarB);

	void DeleteBigEnemy(int i, AudioManager auxAudio);
	void DeleteMidEnemy(int i, AudioManager auxAudio);
	void DeleteSmallEnemy(int i, AudioManager auxAudio);

	void CheckCollisionEnemys();
	void CheckCollisionEnemysBullet(Bullet bullet[], AudioManager auxAudio, Player& player);
	void CheckCollisionEnemysPlayer(Player& player, AudioManager auxAudio);

	void PrintEnemy(bool isAlive, EnemyObject enemy[], int i);

	void InitEnemys()
	{
		bigNeufarText = LoadTexture("res/Neufares/WaterLily_Big.png");
		midNeufarText = LoadTexture("res/Neufares/WaterLily.png");
		smallNeufarText = LoadTexture("res/Neufares/WaterLily_small.png");

		for (int i = 0; i < maxBigEnemy; i++)
		{
			bigEnemyDecendant[i] = 0;
			bigEnemy[i].isAlive = false;
		}

		for (int i = 0; i < maxMidEnemy; i++)
			midEnemy[i].isAlive = false;
		
		for (int i = 0; i < maxSmallEnemy; i++)		
			smallEnemy[i].isAlive = false;		

		nextId = 0;
		spawnTimer = 0.0f;
		spawnDelay = 1.5f;
		bigCounter = 0;
	}
	void CreateBigEnemy()
	{
		for (int i = 0; i < maxBigEnemy; i++)
			if (!bigEnemy[i].isAlive && bigEnemyDecendant[i] == 0)
			{
				bigEnemy[i].neufarTexture = bigNeufarText;
				bigEnemy[i].isAlive = true;
				bigEnemy[i].pos = RandomPos();
				bigEnemy[i].angle = RandomAngle();
				bigEnemy[i].speed = RandomSpeed(80, 150);
				bigEnemy[i].radius = 116;
				bigEnemy[i].type = 0;
				bigEnemy[i].parentId = 1;
				bigEnemy[i].id = nextId++;

				bigEnemyDecendant[i] = 0;
				bigCounter++;
				break;
			}
	}
	void CreateMediumEnemy(int idBigEnemy, Vector2 pos, float baseAngle)
	{
		int auxCount = 0;
		for (int i = 0; i < maxMidEnemy; i++)
			if (!midEnemy[i].isAlive)
			{
				midEnemy[i].neufarTexture = midNeufarText;
				midEnemy[i].isAlive = true;
				midEnemy[i].pos = pos;
				midEnemy[i].angle = baseAngle + DEG2RAD * GetRandomValue(-20, 20);
				midEnemy[i].speed = RandomSpeed(80, 150);
				midEnemy[i].radius = 78;
				midEnemy[i].type = 1;
				midEnemy[i].parentId = idBigEnemy;
				midEnemy[i].id = nextId++;
				bigEnemyDecendant[idBigEnemy] += 1;
				auxCount++;
				if (auxCount >= 2)
					break; // Solo dos medianos
			}
	}
	void CreateSmallEnemy(int idBigEnemy, Vector2 pos, float baseAngle)
	{
		int auxCounter = 0;
		for (int i = 0; i < maxSmallEnemy; i++)
			if (!smallEnemy[i].isAlive)
			{
				smallEnemy[i].neufarTexture = smallNeufarText;
				smallEnemy[i].isAlive = true;
				smallEnemy[i].pos = pos;
				smallEnemy[i].angle = baseAngle + DEG2RAD * GetRandomValue(-45, 45);
				smallEnemy[i].speed = RandomSpeed(80, 150);
				smallEnemy[i].radius = 44;
				smallEnemy[i].type = 2;
				smallEnemy[i].parentId = idBigEnemy;
				smallEnemy[i].id = nextId++;
				bigEnemyDecendant[idBigEnemy] += 1;
				auxCounter++;

				if (auxCounter == 4)
					break;
			}
	}
	void UpdateEnemyObject(Bullet gameBullet[], Player& player, AudioManager auxAudio)
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

		CheckCollisionEnemysBullet(gameBullet, auxAudio, player);

		CheckCollisionEnemysPlayer(player, auxAudio);
	}
	void DrawEnemyObject()
	{
		for (int i = 0; i < maxBigEnemy; i++)
			PrintEnemy(bigEnemy[i].isAlive, bigEnemy, i);

		for (int i = 0; i < maxMidEnemy; i++)
			PrintEnemy(midEnemy[i].isAlive, midEnemy, i);

		for (int i = 0; i < maxSmallEnemy; i++)
			PrintEnemy(smallEnemy[i].isAlive, smallEnemy, i);
	}
	void PrintEnemy(bool Alive, EnemyObject enemy[], int i)
	{
		if (Alive)
		{
			float textureWidth = static_cast<float>(enemy[i].neufarTexture.width);
			float textureHeight = static_cast<float>(enemy[i].neufarTexture.height);

			Vector2 drawPos = {
				enemy[i].pos.x - textureWidth / 2.0f,
				enemy[i].pos.y - textureHeight / 2.0f
			};

			DrawTextureEx(enemy[i].neufarTexture, drawPos, 0.0f, 1.0f, WHITE);

#ifdef _DEBUG
			DrawCircleLines(static_cast<int>(enemy[i].pos.x), static_cast<int>(enemy[i].pos.y), enemy[i].radius, RED);
#endif // _DEBUG
		}
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
		case 0: 
			xPos = -100.0f;
			yPos = static_cast <float>(GetRandomValue(0, GetScreenHeight()));
			break;

		case 1: 
			xPos = GetScreenWidth() + 100.0f;
			yPos = static_cast <float>(GetRandomValue(0, GetScreenHeight()));
			break;

		case 2: 
			xPos = static_cast <float>(GetRandomValue(0, GetScreenWidth()));
			yPos = -100.0f;
			break;

		case 3:
			xPos = static_cast <float>(GetRandomValue(0, GetScreenWidth()));
			yPos = GetScreenHeight() + 100.0f;
			break;

		default:
			break;
		}
		return { xPos, yPos };
	}

	void MoveEnemyObj(EnemyObject& neufar)
	{
		neufar.pos.x += cosf(neufar.angle) * neufar.speed * GetFrameTime();
		neufar.pos.y += sinf(neufar.angle) * neufar.speed * GetFrameTime();

		if (neufar.speed > 200)
			neufar.speed = 200;

		if (neufar.pos.x < -neufar.radius)  neufar.pos.x = GetScreenWidth() + neufar.radius;
		if (neufar.pos.x > GetScreenWidth() + neufar.radius)  neufar.pos.x = -neufar.radius;
		//chekeo de limites verticales
		if (neufar.pos.y < -neufar.radius)  neufar.pos.y = GetScreenHeight() + neufar.radius;
		if (neufar.pos.y > GetScreenHeight() + neufar.radius)  neufar.pos.y = -neufar.radius;
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

	void DeleteBigEnemy(int i, AudioManager auxAudio)
	{
		if (!bigEnemy[i].isAlive) return;
		Vector2 pos = bigEnemy[i].pos;
		float angle = bigEnemy[i].angle;
		bigEnemy[i].isAlive = false;

		PlaySFX(auxAudio.enemyDestroySound);
		// 2 medianos
		CreateMediumEnemy(i, pos, angle);
	}
	void DeleteMidEnemy(int i, AudioManager auxAudio)
	{
		if (!midEnemy[i].isAlive) return;
		int idGrande = midEnemy[i].parentId;
		Vector2 pos = midEnemy[i].pos;
		float angle = midEnemy[i].angle;
		midEnemy[i].isAlive = false;
		bigEnemyDecendant[idGrande]--;
		PlaySFX(auxAudio.enemyDestroySound);

		CreateSmallEnemy(idGrande, pos, angle);
	}
	void DeleteSmallEnemy(int i, AudioManager auxAudio)
	{
		if (!smallEnemy[i].isAlive) return;
		int idGrande = smallEnemy[i].parentId;
		smallEnemy[i].isAlive = false;
		bigEnemyDecendant[idGrande]--;
		PlaySFX(auxAudio.enemyDestroySound);

		if (bigEnemyDecendant[idGrande] <= 0)
			bigEnemyDecendant[idGrande] = 0;
		bigCounter--;
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
	void CheckCollisionEnemysBullet(Bullet bullet[], AudioManager auxAudio, Player& player)
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
					player.points += 100;

					DeleteBigEnemy(j, auxAudio);
					break;
				}

			//mediano 
			for (int j = 0; j < maxMidEnemy; j++)
				if (midEnemy[j].isAlive && Vector2Distance(bullet[i].bulletHitBox.pos, midEnemy[j].pos) < bullet[i].bulletHitBox.rad + midEnemy[j].radius)
				{
					bullet[i].isBulletAlive = false;
					player.points += 100;

					DeleteMidEnemy(j, auxAudio);
					break;
				}

			//chicos 
			for (int j = 0; j < maxSmallEnemy; j++)
				if (smallEnemy[j].isAlive && Vector2Distance(bullet[i].bulletHitBox.pos, smallEnemy[j].pos) < bullet[i].bulletHitBox.rad + smallEnemy[j].radius)
				{
					bullet[i].isBulletAlive = false;
					player.points += 100;

					DeleteSmallEnemy(j, auxAudio);
					break;
				}
		}
	}
	void CheckCollisionEnemysPlayer(Player& player, AudioManager auxAudio)
	{
		player.immunityTimer += GetFrameTime();

		if (player.immunityTimer >= player.inmmunityDelay && player.playerHit)
		{
			player.playerHit = false;
		}

		if (!player.isAlive && !player.playerHit)
		{
			//grande 
			for (int j = 0; j < maxBigEnemy; j++)
				if (bigEnemy[j].isAlive && Vector2Distance(player.playerCir.pos, bigEnemy[j].pos) < player.playerCir.rad + bigEnemy[j].radius)
				{
					if (player.lives > 0)
					{
						player.lives--;
						player.playerHit = true;
						player.immunityTimer = 0;
						PlaySFX(auxAudio.loseLifeSound);
					}
					DeleteBigEnemy(j, auxAudio);
					break;
				}

			//mediano 
			for (int j = 0; j < maxMidEnemy; j++)
				if (midEnemy[j].isAlive && Vector2Distance(player.playerCir.pos, midEnemy[j].pos) < player.playerCir.rad + midEnemy[j].radius)
				{
					if (player.lives > 0)
					{
						player.lives--;
						player.playerHit = true;
						player.immunityTimer = 0;
						PlaySFX(auxAudio.loseLifeSound);
					}
					DeleteMidEnemy(j, auxAudio);
					break;
				}

			//chicos 
			for (int j = 0; j < maxSmallEnemy; j++)
				if (smallEnemy[j].isAlive && Vector2Distance(player.playerCir.pos, smallEnemy[j].pos) < player.playerCir.rad + smallEnemy[j].radius)
				{
					if (player.lives > 0)
					{
						player.lives--;
						player.playerHit = true;
						player.immunityTimer = 0;
						PlaySFX(auxAudio.loseLifeSound);
					}
					DeleteSmallEnemy(j, auxAudio);
					break;
				}
		}
	}

	void UnloadNeufars()
	{
		UnloadTexture(bigNeufarText);
		UnloadTexture(midNeufarText);
		UnloadTexture(smallNeufarText);
	}
}