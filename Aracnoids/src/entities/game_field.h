#pragma once

#include "raylib.h"

namespace arena
{
	Rectangle createGameArena(Rectangle& gameArena);
	void drawArena(Rectangle gameArena);
}