#pragma once

#include "entities/player.h"
#include "entities/game_field.h"
#include "gameMenus.h"
#include "entities/mouse.h"
#include "game_settings/scene_manage.h"
#include "game_settings/constants.h"

void RunGame();

void Init(gamePlayer::Player& player, Rectangle& gameArena, mouse::Mouse& gameMouse, SCENEMANAGMENT& scene, gameMenu::Menu& mainAndPauseMenu,
	gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen);

void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse gameMouse, gameMenu::Menu& mainAndPauseMenu,
	 gameMenu::Menu& winLoseScreen, gameMenu::Menu& exitScreen);

void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse& gameMouse);

void Draw(gamePlayer::Player& player, Rectangle& gameArena, SCENEMANAGMENT scene, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu credits, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen, mouse::Mouse gameMouse);
void Close();