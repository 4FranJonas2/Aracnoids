#include "game.h"

#include <iostream>

#include "utilities.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/enemyObj.h"

using namespace std;

namespace aracnoids
{
	bool isShoot = false;
	const int maxBullets = 20;

	Player player;
	Bullet bullets[maxBullets];
	GameStats gameStats;

	void Init(GameStats gameVars, Player& player);
	void Input(Player& player, Bullet bullets[]);
	void Update(Player& player, Bullet bullets[]);
	void Draw(Player player, Bullet bullets[]);

	void RunGame()
	{
		srand(time(nullptr));

		GameStats gameVars;

		Init(gameVars,player);

		while (!WindowShouldClose())
		{
			Input(player, bullets);
			Update(player, bullets);
			Draw(player, bullets);
		}
		CloseWindow();
	}

	void Init(GameStats gameVars, Player& player)
	{
		InitWindow(gameVars.screenWidth, gameVars.screenHeight, "Aracnoids");

		InitPlayer(player);

		CreateBigEnemy();
	}

	void Input(Player& player, Bullet bullets[])
	{
		InputPlayer(player);
		InputBullet(isShoot);
	}

	void Update(Player& player, Bullet bullets[])
	{
		UpdatePlayer(player);
		CreateBullet(bullets, player, isShoot);
		UpdateBullet(bullets);
		UpdateEnemyObject(bullets);
	}

	void Draw(Player player, Bullet bullets[])
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawPlayer(player);
		DrawBullet(bullets);
		DrawEnemyObject();

		EndDrawing();
	}
}
