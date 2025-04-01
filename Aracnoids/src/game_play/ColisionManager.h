#pragma once

#include <iostream>

#include "game_settings/Constants.h"
#include "entities/Player.h"
#include "entities/Bullets.h"
#include "entities/EnemyObject.h"

namespace colisionManager
{
	bool CircleCircle(Circle circle1, Circle cricle2);
	void BulletNeufarColision(gameBullet::Bullet bullet[], gameEnemy::Neufar neufar[]);
	void PlayerNeufarColision(gamePlayer::Player& player, gameEnemy::Neufar neufar[]);
	void NeufarNeufarColision(gameEnemy::Neufar neufar[]);
}