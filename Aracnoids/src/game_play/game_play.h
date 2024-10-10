#pragma once
#include "../entities/player.h"

void Aracnoids();

void Init(Player player, Rectangle gameArena);

void Input(Player& player);

void Update(Player& player);

void Draw(Player& player, Rectangle& gameArena);
