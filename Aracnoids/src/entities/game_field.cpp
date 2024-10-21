#pragma once
#include "game_field.h"
#include "game_settings/constants.h"

namespace arena
{
	Rectangle createGameArena(Rectangle& gameArena)
	{
		gameArena.x = 0.0f;
		gameArena.y = 0.0f;
		gameArena.width = screenWidth;
		gameArena.height = screenHeight;
	}

	void drawArena(Rectangle gameArena)
	{
		//DrawRectangle(gameArena.pos.x, gameArena.pos.y, gameArena.size.x, gameArena.size.y, RED);
		//DrawRectangleLines(gameArena.pos.x, gameArena.pos.y, gameArena.size.x, gameArena.size.y, RED);
		Rectangle draw = { gameArena.x,gameArena.y,gameArena.width,gameArena.height};
		DrawRectangleLinesEx(draw, 2.0, RED);
	}
}