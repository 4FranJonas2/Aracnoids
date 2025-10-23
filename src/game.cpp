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
		InitEnemys();
		
		gameStats.gameStatus = SceneStatus::GAMEPLAY;
	}

	void Input()
	{
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEPLAY:

			InputPlayer(player);
			InputBullet();
			if (IsKeyPressed(KEY_R))
				gameStats.gameStatus = SceneStatus::RESETGAME;		
			break;

		case SceneStatus::GAMEPAUSE:

			
			break;

		case SceneStatus::GAMEEND:

			
			break;

		default:
			break;
		}
	}

	void Update()
	{
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEPLAY:

			UpdatePlayer(player);
			CreateBullet(bullets, player);
			UpdateBullet(bullets);
			UpdateEnemyObject(bullets, player);
			if (player.lives == 0)
			{
				gameStats.gameStatus = SceneStatus::RESETGAME;
			}
			break;

		case SceneStatus::GAMEPAUSE:


			break;

		case SceneStatus::RESETGAME:

			InitPlayer(player);
			InitEnemys();
			gameStats.gameStatus = SceneStatus::GAMEPLAY;
			break;

		case SceneStatus::GAMEEND:


			break;

		default:
			break;
		}
	}

	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:

			break;

		case SceneStatus::GAMERULES:

			break;

		case SceneStatus::GAMECREDITS:

			break;

		case SceneStatus::GAMEPLAY:

			DrawPlayer(player);
			DrawBullet(bullets);
			DrawEnemyObject();		
			break;

		case SceneStatus::GAMEPAUSE:

			break;

		case SceneStatus::GAMEEND:

			break;

		default:
			break;
		}
		EndDrawing();
	}
}
