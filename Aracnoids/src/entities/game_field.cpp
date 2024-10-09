#include "game_field.h"

namespace arena
{
	Rectangle createGameArena(Rectangle& gameArena)
	{
		gameArena.pos.x = 0.0f;
		gameArena.pos.y = 0.0f;
		gameArena.size.x = screenWidth;
		gameArena.size.y = screenHeight;
	}

	void drawArena(Rectangle gameArena)
	{
		//DrawRectangle(gameArena.pos.x, gameArena.pos.y, gameArena.size.x, gameArena.size.y, RED);
		DrawRectangleLines(gameArena.pos.x, gameArena.pos.y, gameArena.size.x, gameArena.size.y, RED);
	}
}