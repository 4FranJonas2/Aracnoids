#include "game.h"

#include <iostream>

#include "utilities.h"
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/enemyObj.h"
#include "entities/menu.h"
#include "gameSetings/backGround.h"
#include "gameSetings/audioManager.h"

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
	static AudioManager audio;
	static MusicType music;

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
		UnloadParallax(backGRound);
		UnloadNeufars();
		UnloadPlayer(player);
		UnloadAudio(audio);
		
		CloseWindow();
	}

	void Init()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;

		InitWindow(screenWidth, screenHeight, "Aracnoids");
		InitAudioDevice();

		InitPlayer(player);

		InitEnemys();
		InitButtons(menu);
		InitParallax(backGRound);
		InitAudio(audio);
		SetMusicVolume(audio.menuMusic, 0.5f);
		SetMusicVolume(audio.gameplayMusic, 0.5f);
		SetSoundVolume(audio.enemyDestroySound, 0.3f);
		SetSoundVolume(audio.shootSound, 0.2f);

		gameStats.gameStatus = SceneStatus::GAMEMENU;
	}

	void Input()
	{
		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEPLAY:

			InputPlayer(player);
			InputBullet();
#ifdef _DEBUG
			if (IsKeyPressed(KEY_R))
				gameStats.gameStatus = SceneStatus::RESETGAME;		
#endif // _DEBUG
			break;

		default:
			break;
		}
	}

	void Update()
	{
		if (gameStats.gameStatus == SceneStatus::GAMEPLAY)
		{
			SwitchMusic(audio, MusicType::GAMPLAY);
		}
		else
			SwitchMusic(audio, MusicType::MENU);

		switch ((SceneStatus)gameStats.gameStatus)
		{
		case SceneStatus::GAMEMENU:

			UpdateSceneMenus(gameStats, menu, audio);
			UpdateParallaxMenu(backGRound);
			UpdateAudio(audio);
			break;

		case SceneStatus::GAMERULES:

			UpdateSceneMenus(gameStats, menu, audio);
			UpdateParallaxMenu(backGRound);
			UpdateAudio(audio);

			break;

		case SceneStatus::GAMECREDITS:

			UpdateSceneMenus(gameStats, menu, audio);
			UpdateParallaxMenu(backGRound);
			UpdateAudio(audio);

			break;

		case SceneStatus::FIRSTGAME:

			UpdateSceneMenus(gameStats, menu, audio);
			UpdateAudio(audio);

			break;

		case SceneStatus::GAMEPLAY:

			UpdatePlayer(player);
			CreateBullet(bullets, player, audio);
			UpdateBullet(bullets);
			UpdateEnemyObject(bullets, player, audio);
			UpdateParallaxGameplay(backGRound, player.velocity);
			UpdateAudio(audio);

			if (player.lives == 0)
			{
				gameStats.gameStatus = SceneStatus::GAMEEND;
			}
			UpdateSceneMenus(gameStats, menu, audio);
			break;

		case SceneStatus::GAMEPAUSE:

			UpdateSceneMenus(gameStats, menu, audio);
			UpdateAudio(audio);

			break;

		case SceneStatus::RESETGAME:

			InitPlayer(player);
			InitEnemys();
			gameStats.gameStatus = SceneStatus::FIRSTGAME;
			UpdateAudio(audio);

			break;

		case SceneStatus::GAMEEND:
 
			UpdateSceneMenus(gameStats, menu, audio);
			UpdateAudio(audio);

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

			DrawParallax(backGRound);
			DrawPlayer(player);
			DrawPause(gameStats,menu);
			break;

		case SceneStatus::GAMEPLAY:
			
			DrawParallax(backGRound);
			DrawBullet(bullets);
			DrawEnemyObject();		
			DrawPlayer(player);
			break;

		case SceneStatus::GAMEPAUSE:
			
			DrawParallax(backGRound);
			DrawBullet(bullets);
			DrawEnemyObject();
			DrawPlayer(player);
			DrawPause(gameStats,menu);
			break;

		case SceneStatus::GAMEEND:
			
			DrawParallax(backGRound);
			DrawBullet(bullets);
			DrawEnemyObject();
			DrawPlayer(player);
			DrawPause(gameStats,menu);
			break;

		default:
			break;
		}
		EndDrawing();
	}
}