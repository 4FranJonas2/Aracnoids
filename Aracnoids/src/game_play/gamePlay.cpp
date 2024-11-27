#include "GamePlay.h"

namespace Game
{
	void RunGame()
	{
		SCENEMANAGMENT scene = SCENEMANAGMENT::NONE;
		Rectangle gameArena;
		gamePlayer::Player player;
		mouse::Mouse gameMouse;
		gameBullet::Bullet bullet[maxBullets];

		Init(player, gameArena, gameMouse, scene);

		while (!WindowShouldClose())
		{
			Input(player, scene, gameMouse, bullet);
			Update(player, scene, gameMouse, bullet);
			Draw(player, gameArena, scene, gameMouse, bullet);
		}

		Close();
	}

	void Init(gamePlayer::Player& player, Rectangle& gameArena, mouse::Mouse& gameMouse, SCENEMANAGMENT& scene)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " RunGame by Francisco Jonas ");
			player = gamePlayer::CreatePlayer(player);
			gameArena = arena::createGameArena(gameArena);
			gameMouse = mouse::CreateMouse();
			gameMenu::CreateMainMenu();
			gameMenu::CreateWinLoseScreen();
			gameMenu::CreateExitScreen();
			gameEnemy::InitNeufar();
			//gameBullet::InitBullets(bullet, player);
		
			scene = SCENEMANAGMENT::MAINMENU;

		case SCENEMANAGMENT::GAME:
			
				break;
		default:
			break;
		}
	}
	void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse gameMouse, gameBullet::Bullet bullet[])
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
	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse& gameMouse, gameBullet::Bullet bullet[])
	{
		gameMouse.mousePos = mouse::UpdateMousePos();

		switch (scene)
		{
		case SCENEMANAGMENT::GAME:
			gamePlayer::UpdatePlayer(player, gameMouse);
			gameBullet::UpdateBullet(bullet);
			gameEnemy::UpdateNeufar();
			break;
		case SCENEMANAGMENT::RESETGAME:

			break;
		case SCENEMANAGMENT::WINLOSESCRREN:
			break;

		default:
			break;
		}
	}
	void Draw(gamePlayer::Player& player, Rectangle& gameArena, SCENEMANAGMENT scene, mouse::Mouse gameMouse,
		gameBullet::Bullet bullet[])
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
			gameEnemy::DrawNeufar();
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
