#include "game.h"

#include <iostream>

#include "utilities.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/enemyObj.h"

using namespace std;

namespace aracnoids
{
	const int maxBullets = 20;
	
	static Player player;
	static GameStats gameStats;
	static Bullet bullets[maxBullets];

	void Init();
	void Input();
	void Update();
	void Draw();

	void RunGame()
	{
		Init();

		while (!WindowShouldClose())
		{
			Input();
			Update();
			Draw();
		}
		CloseWindow();
	}

	void Init()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;

		InitWindow(screenWidth, screenHeight, "Aracnoids");

		InitPlayer(player);

		CreateBigEnemy();
	}

	void Input()
	{
		InputPlayer(player);
		InputBullet();
	}

	void Update()
	{
		UpdatePlayer(player);
		CreateBullet(bullets, player);
		UpdateBullet(bullets);
		UpdateEnemyObject(bullets);
	}

	void Draw()
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawPlayer(player);
		DrawBullet(bullets);
		DrawEnemyObject();

		EndDrawing();
	}
}
