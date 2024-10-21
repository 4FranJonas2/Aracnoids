#pragma once
//#include "gameMenus.h"

void Aracnoids();

void Init(Player& player, RectangleGame& gameArena, Mouse& gameMouse, SCENEMANAGMENT& scene);

void Input(Player& player, SCENEMANAGMENT& scene, Mouse gameMouse, Menu mainMenu,
	 Menu pauseMenu, Menu winLoseScreen, Menu exitScreen);

void Update(Player& player, SCENEMANAGMENT& scene, Mouse gameMouse, Menu mainMenu,
	Menu credits, Menu pauseMenu, Menu winLoseScreen, Menu exitScreen);

void Draw(Player& player, RectangleGame& gameArena, SCENEMANAGMENT scene, Mouse gameMouse, Menu mainMenu,
	Menu credits, Menu pauseMenu, Menu winLoseScreen, Menu exitScreen);
static void Close();