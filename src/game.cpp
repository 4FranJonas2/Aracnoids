#include "game.h"

#include <iostream>

#include "utilities.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/enemyObj.h"
#include "entities/menu.h"

using namespace std;

namespace aracnoids
{
	const int maxBullets = 20;
	
	static Player player;
	static GameStats gameStats;
	static Bullet bullets[maxBullets];
	static MenuButtons menu;

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
		InitButtons(menu);

		gameStats.gameStatus = SceneStatus::FIRSTGAME;
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
		case SceneStatus::GAMEMENU:

			UpdateSceneMenus(gameStats, menu);
			break;

		case SceneStatus::GAMERULES:

			UpdateSceneMenus(gameStats, menu);
			break;

		case SceneStatus::GAMECREDITS:

			UpdateSceneMenus(gameStats, menu);
			break;

		case SceneStatus::FIRSTGAME:

			UpdateSceneMenus(gameStats, menu);
			break;

		case SceneStatus::GAMEPLAY:

			UpdatePlayer(player);
			CreateBullet(bullets, player);
			UpdateBullet(bullets);
			UpdateEnemyObject(bullets, player);
			if (player.lives == 0)
			{
				gameStats.gameStatus = SceneStatus::RESETGAME;
			}
			UpdateSceneMenus(gameStats, menu);
			break;

		case SceneStatus::GAMEPAUSE:

			UpdateSceneMenus(gameStats, menu);
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

			DrawMainMenu(gameStats);
			break;

		case SceneStatus::GAMERULES:

			DrawRulesMenu(gameStats);
			break;

		case SceneStatus::GAMECREDITS:

			DrawCreditsMenu(gameStats);
			break;

		case SceneStatus::FIRSTGAME:

			DrawPlayer(player);
			
			DrawPause(gameStats);
			break;

		case SceneStatus::GAMEPLAY:

			DrawPlayer(player);
			DrawBullet(bullets);
			DrawEnemyObject();		
			break;

		case SceneStatus::GAMEPAUSE:
			
			DrawPlayer(player);
			DrawBullet(bullets);
			DrawEnemyObject();
			DrawPause(gameStats);
			break;

		case SceneStatus::GAMEEND:

			break;

		default:
			break;
		}
		EndDrawing();
	}
}
