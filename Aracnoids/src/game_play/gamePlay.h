#pragma once

#include "entities/Player.h"
#include "entities/GameField.h"
#include "GameMenus.h"
#include "entities/Mouse.h"
#include "game_settings/SceneManage.h"
#include "game_settings/Constants.h"
#include "entities/Bullets.h"
#include "entities/EnemyObject.h"

namespace Game
{
	void RunGame();

	void Init();

	void Input();

	void Update();

	void Draw();

	void Close();
}
