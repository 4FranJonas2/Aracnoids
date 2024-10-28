#include "gamePlay.h"

namespace Game
{
	void RunGame()
	{
		SCENEMANAGMENT scene = SCENEMANAGMENT::NONE;
		Rectangle gameArena;
		gamePlayer::Player player;
		mouse::Mouse gameMouse;
		gameMenu::Menu mainAndPauseMenu;
		gameMenu::Menu credits;
		gameMenu::Menu winLoseScreen;
		gameMenu::Menu exitScreen;
		gameBullet::Bullet bullet{};
		gameBullet::Magazine playerMagazine{};

		Init(player, gameArena, gameMouse, scene, mainAndPauseMenu, winLoseScreen, exitScreen, bullet, playerMagazine);

		while (!WindowShouldClose())
		{
			Input(player, scene, gameMouse, mainAndPauseMenu, winLoseScreen, exitScreen);
			Update(player, scene, gameMouse, bullet, playerMagazine);
			Draw(player, gameArena, scene, mainAndPauseMenu, credits, winLoseScreen, exitScreen, gameMouse, playerMagazine);
		}

		Close();
	}

	void Init(gamePlayer::Player& player, Rectangle& gameArena, mouse::Mouse& gameMouse, SCENEMANAGMENT& scene, gameMenu::Menu& mainAndPauseMenu,
		gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen, gameBullet::Bullet bullet, gameBullet::Magazine playerMagazine)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::NONE:
			InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), " RunGame by Francisco Jonas ");
			player = gamePlayer::CreatePlayer(player);
			gameArena = arena::createGameArena(gameArena);
			gameMouse = mouse::CreateMouse(gameMouse);
			mainAndPauseMenu = gameMenu::CreateMainMenu(mainAndPauseMenu);
			winLoseScreen = gameMenu::CreateWinLoseScreen(winLoseScreen);
			exitScreen = gameMenu::CreateExitScreen(exitScreen);
			bullet = gameBullet::CreateBullet(bullet, player);
			gameBullet::InitBullets(playerMagazine, bullet, player);

			scene = SCENEMANAGMENT::MAINMENU;
		default:
			break;
		}
	}
	void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse gameMouse, gameMenu::Menu& mainAndPauseMenu,
		gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen)
	{
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:
			gameMenu::InputMainMenu(mainAndPauseMenu, gameMouse, scene);
			break;

		case SCENEMANAGMENT::CREDITS:
			gameMenu::InputCredits(scene);
			break;

		case SCENEMANAGMENT::GAME:
			gamePlayer::InputPlayer(player);
			break;

		case SCENEMANAGMENT::WINLOSESCRREN:
			gameMenu::InputWinLoseScreen(winLoseScreen, gameMouse, scene);
			break;

		case SCENEMANAGMENT::PAUSE:
			gameMenu::InputPauseMenu(mainAndPauseMenu, gameMouse, scene);
			break;

		case SCENEMANAGMENT::EXIT:
			gameMenu::InputExitScreen(exitScreen, gameMouse, scene);
			break;
		default:
			break;
		}
	}
	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse& gameMouse, gameBullet::Bullet bullet, gameBullet::Magazine playerMAgazine)
	{
		mouse::UpdateMousePos(gameMouse);

		switch (scene)
		{
		case SCENEMANAGMENT::GAME:
			gamePlayer::UpdatePlayer(player, gameMouse);
			gameBullet::UpdateBullet(playerMAgazine, bullet, player);
			break;
		case SCENEMANAGMENT::RESETGAME:

			break;
		case SCENEMANAGMENT::WINLOSESCRREN:
			break;

		default:
			break;
		}
	}
	void Draw(gamePlayer::Player& player, Rectangle& gameArena, SCENEMANAGMENT scene, gameMenu::Menu mainAndPauseMenu,
		gameMenu::Menu credits, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen, mouse::Mouse gameMouse,
		gameBullet::Magazine playerMAgazine)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (scene)
		{
		case SCENEMANAGMENT::MAINMENU:
			gameMenu::DrawMainMenuorPause(mainAndPauseMenu, scene, gameMouse);
			break;
		case SCENEMANAGMENT::CREDITS:
			gameMenu::DrawCredits(credits);
			break;
		case SCENEMANAGMENT::GAME:
			gamePlayer::DrawPlayer(player);
			arena::drawArena(gameArena);
			gameBullet::DrawBullet(playerMAgazine);
			break;
		case SCENEMANAGMENT::WINLOSESCRREN:
			gameMenu::DrawWinLoseScreen(winLoseScreen);
			break;
		case SCENEMANAGMENT::PAUSE:
			gameMenu::DrawMainMenuorPause(mainAndPauseMenu, scene, gameMouse);
			break;
		case SCENEMANAGMENT::EXIT:
			gameMenu::DrawExitMenu(exitScreen);
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
