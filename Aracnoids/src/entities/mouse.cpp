#include "Mouse.h"

namespace mouse
{
	Mouse CreateMouse(Mouse& gameMouse)
	{
		gameMouse.mousePos = GetMousePosition();
	
		return gameMouse;
	}

	Vector2 UpdateMousePos(Vector2& gameMouse)
	{
		gameMouse = GetMousePosition();

		return gameMouse;
	}

	float GetMouseXPos(float& mousePosX)
	{
		float mouseXPos = mousePosX;
		return mouseXPos;
	}

	float GetMouseYPos(float& mousePosY)
	{
		float mouseYPos = mousePosY;
		return mouseYPos;
	}
}