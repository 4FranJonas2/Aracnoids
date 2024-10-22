#pragma once
//#include "gameMenus.h"

void Aracnoids();

void Init(gamePlayer::Player& player, Rectangle& gameArena, mouse::Mouse& gameMouse, SCENEMANAGMENT& scene);

void Input(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse gameMouse, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu pauseMenu, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen);

void Update(gamePlayer::Player& player, SCENEMANAGMENT& scene, mouse::Mouse gameMouse, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu credits, gameMenu::Menu pauseMenu, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen);

void Draw(gamePlayer::Player& player, Rectangle& gameArena, SCENEMANAGMENT scene, mouse::Mouse gameMouse, gameMenu::Menu mainAndPauseMenu,
	gameMenu::Menu credits, gameMenu::Menu pauseMenu, gameMenu::Menu winLoseScreen, gameMenu::Menu exitScreen);
static void Close();