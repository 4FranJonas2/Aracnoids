#include "mouse.h"

namespace mouse
{
	Mouse CreateMouse(Mouse gameMouse)
	{
		gameMouse.mousePos.x =(float) GetMouseX();
		gameMouse.mousePos.y = GetMouseY();

		return gameMouse;
	}
}