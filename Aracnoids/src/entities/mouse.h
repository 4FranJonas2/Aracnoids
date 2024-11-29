#pragma once
#include "raylib.h"

namespace mouse
{
	struct Mouse
	{
		Vector2 mousePos;
	};

	Mouse CreateMouse(Mouse& gameMouse);
	Vector2 UpdateMousePos(Vector2& nousePos);
	float GetMouseXPos(float& mousePosX);
	float GetMouseYPos(float& mousePosY);
}