#pragma once
#include "raylib.h"
//#include "game_field.h"

namespace mouse
{
	struct Mouse
	{
		Vector2 mousePos;
	};

	Mouse CreateMouse(Mouse gameMouse);
	void UpdateMousePos(Mouse& gameMouse);
}