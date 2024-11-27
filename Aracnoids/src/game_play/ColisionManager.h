#pragma once

#include <iostream>

#include "game_settings/Constants.h"

namespace ColisionManager
{
	bool CircleCircle(Circle circle1, Circle cricle2);
	bool PlayerNeufarColision();
	bool NeufarNeufarColision();
	bool BulletNeufarColision();
}