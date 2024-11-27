#include "Mouse.h"

namespace mouse
{
	Mouse gameMouse;

	Mouse CreateMouse()
	{
		gameMouse.mousePos = GetMousePosition();
	
		return gameMouse;
	}

	Vector2 UpdateMousePos()
	{
		gameMouse.mousePos = GetMousePosition();

		return gameMouse.mousePos;
	}

	float GetMouseXPos()
	{
		float mouseXPos = gameMouse.mousePos.x;
		return mouseXPos;
	}

	float GetMouseYPos()
	{
		float mouseYPos = gameMouse.mousePos.y;
		return mouseYPos;
	}
}