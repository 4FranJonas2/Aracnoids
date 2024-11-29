#include "Mouse.h"

namespace mouse
{
	Mouse gameMouse;

	Mouse CreateMouse(Mouse& gameMouse)
	{
		gameMouse.mousePos = GetMousePosition();
	
		return gameMouse;
	}

	Vector2 UpdateMousePos(Vector2& mousePos)
	{
		gameMouse.mousePos = GetMousePosition();

		return gameMouse.mousePos;
	}

	float GetMouseXPos(float& mousePosX)
	{
		float mouseXPos = gameMouse.mousePos.x;
		return mouseXPos;
	}

	float GetMouseYPos(float& mousePosY)
	{
		float mouseYPos = gameMouse.mousePos.y;
		return mouseYPos;
	}
}