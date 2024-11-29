#include "GameField.h"

#include "game_settings/Constants.h"

namespace arena
{
	Rectangle createGameArena(Rectangle& gameArena)
	{
		gameArena.x = 0.0f;
		gameArena.y = 0.0f;
		gameArena.width = screenWidth;
		gameArena.height = screenHeight;

		return gameArena;
	}

	void drawArena(Rectangle gameArena)
	{
		Rectangle draw = { gameArena.x,gameArena.y,gameArena.width,gameArena.height};
#ifdef _DEBUG
		DrawRectangleLinesEx(draw, 2.0, RED);
#endif // _DEBUG
	}
}