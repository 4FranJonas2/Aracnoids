#include "mouse.h"

namespace mouse
{
	Mouse CreateMouse(Mouse gameMouse)
	{
		gameMouse.mousePos.x = GetMouseX();
		gameMouse.mousePos.y = GetMouseY();

		return gameMouse;
	}
}