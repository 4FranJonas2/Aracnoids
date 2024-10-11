#pragma once
#include "gameMenus.h"

void Aracnoids();

void Init(Player& player, Rectangle& gameArena, Mouse& gameMouse);

void Input(Player& player);

void Update(Player& player);

void Draw(Player& player, Rectangle& gameArena);
