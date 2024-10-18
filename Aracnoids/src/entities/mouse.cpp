#include "mouse.h"

namespace mouse
{
	Mouse CreateMouse(Mouse gameMouse)
	{
		gameMouse.mousePos.x = static_cast<float>(GetMouseX());
		gameMouse.mousePos.y = static_cast<float>(GetMouseY());

		return gameMouse;
	}
}