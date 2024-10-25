#include "mouse.h"

namespace mouse
{
	Mouse CreateMouse(Mouse gameMouse)
	{
		gameMouse.mousePos = GetMousePosition();
	
		return gameMouse;
	}

	void UpdateMousePos(Mouse& gameMouse)
	{
		gameMouse.mousePos = GetMousePosition();
	}
}