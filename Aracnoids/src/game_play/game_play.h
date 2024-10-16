#pragma once
#include "gameMenus.h"

void Aracnoids();

void Init(Player& player, Rectangle& gameArena, Mouse& gameMouse, SCENEMANAGMENT scene);

void Input(Player& player, SCENEMANAGMENT& scene);

void Update(Player& player, SCENEMANAGMENT& scene);

void Draw(Player& player, Rectangle& gameArena, SCENEMANAGMENT scene);
