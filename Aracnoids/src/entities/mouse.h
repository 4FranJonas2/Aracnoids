#pragma once
#include "raylib.h"

namespace mouse
{

	struct Mouse
	{
		Vector2 mousePos;
	};

	Mouse CreateMouse();
	Vector2 UpdateMousePos();
	float GetMouseXPos();
	float GetMouseYPos();
}