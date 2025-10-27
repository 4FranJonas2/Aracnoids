#include "game.h"

#include <iostream>

#include "utilities.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/enemyObj.h"
#include "entities/menu.h"
#include "gameSetings/backGround.h"

using namespace std;

namespace aracnoids
{
	const int maxBullets = 20;
	const int maxLayers = 3;

	static Player player;
	static GameStats gameStats;
	static Bullet bullets[maxBullets];
	static MenuButtons menu;
	static Parallax backGRound[maxLayers];

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

		UnloadTexture(menu.buttonSprite);

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
		InitParallax(backGRound);

		gameStats.gameStatus = SceneStatus::GAMEMENU;
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

		/*case SceneStatus::GAMEPAUSE:

			
			break;

		case SceneStatus::GAMEEND:

			
			break;*/

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
			UpdateParallaxMenu(backGRound);
			break;

		case SceneStatus::GAMERULES:

			UpdateSceneMenus(gameStats, menu);
			UpdateParallaxMenu(backGRound);

			break;

		case SceneStatus::GAMECREDITS:

			UpdateSceneMenus(gameStats, menu);
			UpdateParallaxMenu(backGRound);

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
				gameStats.gameStatus = SceneStatus::GAMEEND;
			}
			UpdateSceneMenus(gameStats, menu);
			break;

		case SceneStatus::GAMEPAUSE:

			UpdateSceneMenus(gameStats, menu);
			break;

		case SceneStatus::RESETGAME:

			InitPlayer(player);
			InitEnemys();
			gameStats.gameStatus = SceneStatus::FIRSTGAME;
			break;

		case SceneStatus::GAMEEND:
 
			UpdateSceneMenus(gameStats, menu);
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
			
			DrawParallax(backGRound);
			DrawMainMenu(gameStats,menu);
			break;

		case SceneStatus::GAMERULES:
			
			DrawParallax(backGRound);
			DrawRulesMenu(gameStats, menu);
			break;

		case SceneStatus::GAMECREDITS:
			
			DrawParallax(backGRound);
			DrawCreditsMenu(gameStats, menu);
			break;

		case SceneStatus::FIRSTGAME:

			DrawPlayer(player);
			DrawPause(gameStats,menu);
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
			DrawPause(gameStats,menu);
			break;

		case SceneStatus::GAMEEND:

			DrawPlayer(player);
			DrawBullet(bullets);
			DrawEnemyObject();
			DrawPause(gameStats,menu);
			DrawParallax(backGRound);
			break;

		default:
			break;
		}
		EndDrawing();
	}
}
