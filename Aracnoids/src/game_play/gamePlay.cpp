#include "GamePlay.h"

#include "entities/GameField.h"
#include "GameMenus.h"
#include "entities/Mouse.h"
#include "game_settings/SceneManage.h"
#include "game_settings/Constants.h"
#include "game_play/ColisionManager.h"


namespace Game
{
	SCENEMANAGMENT scene = SCENEMANAGMENT::NONE;
	Rectangle gameArena;

	gamePlayer::Player player;
	mouse::Mouse gameMouse;
	gameEnemy::Neufar neufar[maxNeufares];
	gameBullet::Bullet bullet[maxBullets];

	void RunGame()
	{

		Init();

		while (!WindowShouldClose())
		{
			Input();
			Update();
			Draw();
		}

		Close();
	}

	void Init()
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " RunGame by Francisco Jonas ");
			gamePlayer::CreatePlayer(player);
			gameArena = arena::createGameArena(gameArena);
			gameEnemy::InitNeufar(neufar);
			mouse::CreateMouse(gameMouse);
			gameMenu::CreateMainMenu();
			gameMenu::CreateWinLoseScreen();
			gameMenu::CreateExitScreen();
			//gameBullet::InitBullets(bullet, player);
		
			scene = SCENEMANAGMENT::MAINMENU;

		case SCENEMANAGMENT::GAME:
			
				break;
		default:
			break;
		}
	}
	void Input()
	{
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:
			gameMenu::InputMainMenu( gameMouse, scene);
			break;

		case SCENEMANAGMENT::CREDITS:
			gameMenu::InputCredits(scene);
			break;

		case SCENEMANAGMENT::GAME:
			gamePlayer::InputPlayer(player);
			gameBullet::InputBullets(bullet, player,gameMouse);
			//gameEnemy::InitNeufar();
			break;

		case SCENEMANAGMENT::WINLOSESCRREN:
			gameMenu::InputWinLoseScreen( gameMouse, scene);
			break;

		case SCENEMANAGMENT::PAUSE:
			gameMenu::InputPauseMenu( gameMouse, scene);
			break;

		case SCENEMANAGMENT::EXIT:
			gameMenu::InputExitScreen( gameMouse, scene);
			break;
		default:
			break;
		}
	}
	void Update()
	{
		mouse::UpdateMousePos(gameMouse.mousePos);

		switch (scene)
		{
		case SCENEMANAGMENT::GAME:
			gamePlayer::UpdatePlayer(player, gameMouse);
			gameBullet::UpdateBullet(bullet);
			gameEnemy::UpdateNeufar(neufar);
			colisionManager::BulletNeufarColision(bullet, neufar);

			break;
		case SCENEMANAGMENT::RESETGAME:

			break;
		case SCENEMANAGMENT::WINLOSESCRREN:
			break;

		default:
			break;
		}
	}
	void Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:
			gameMenu::DrawMainMenuorPause( scene, gameMouse);
			break;
		case SCENEMANAGMENT::CREDITS:
			gameMenu::DrawCredits();
			break;
		case SCENEMANAGMENT::GAME:
			arena::drawArena(gameArena);
			gamePlayer::DrawPlayer(player);
			gameBullet::DrawBullet(bullet);
			gameEnemy::DrawNeufar(neufar);
			break;
		case SCENEMANAGMENT::WINLOSESCRREN:
			gameMenu::DrawWinLoseScreen();
			break;
		case SCENEMANAGMENT::PAUSE:
			gameMenu::DrawMainMenuorPause( scene, gameMouse);
			break;
		case SCENEMANAGMENT::EXIT:
			gameMenu::DrawExitMenu();
			break;
		default:
			break;
		}

		EndDrawing();
	}

	void Close()
	{
		CloseWindow();
	}
}
