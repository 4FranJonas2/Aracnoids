#pragma once
#include "game_field.h"

namespace arena
{
	RectangleGame createGameArena(RectangleGame& gameArena)
	{
		gameArena.pos.x = 0.0f;
		gameArena.pos.y = 0.0f;
		gameArena.size.x = screenWidth;
		gameArena.size.y = screenHeight;
	}

	void drawArena(RectangleGame gameArena)
	{
		//DrawRectangle(gameArena.pos.x, gameArena.pos.y, gameArena.size.x, gameArena.size.y, RED);
		//DrawRectangleLines(gameArena.pos.x, gameArena.pos.y, gameArena.size.x, gameArena.size.y, RED);
		Rectangle draw = { gameArena.pos.x,gameArena.pos.y,gameArena.size.x,gameArena.size.y};
		DrawRectangleLinesEx(draw, 2.0, RED);
	}
}