#pragma once

#include "entities/Player.h"
#include "entities/GameField.h"
#include "GameMenus.h"
#include "entities/Mouse.h"
#include "game_settings/SceneManage.h"
#include "game_settings/Constants.h"
#include "entities/Bullets.h"
#include "entities/EnemyObject.h"

namespace Game
{
	void RunGame();

	void Init(gamePlayer::Player& player, Rectangle& gameArena, mouse::Mouse& gameMouse, SCENEMANAGMENT& scene, gameMenu::Menu& mainAndPauseMenu,
		gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen, gameEnemy::Neufar neufar[]);

	void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse gameMouse, gameMenu::Menu& mainAndPauseMenu,
		 gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen, gameBullet::Bullet bullet[]);

	void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse& gameMouse, 
		gameBullet::Bullet bullet[], gameEnemy::Neufar neufar[]);

	void Draw(gamePlayer::Player& player, Rectangle& gameArena, SCENEMANAGMENT scene, gameMenu::Menu mainAndPauseMenu,
		gameMenu::Menu credits, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen, mouse::Mouse gameMouse,
		gameBullet::Bullet bullet[], gameEnemy::Neufar neufar[]);
	void Close();
}
