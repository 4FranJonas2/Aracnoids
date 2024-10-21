#pragma once
#include "raylib.h"
//#include "game_settings/utils.h"

namespace arena
{
	Rectangle createGameArena(Rectangle& gameArena);
	void drawArena(Rectangle gameArena);
}