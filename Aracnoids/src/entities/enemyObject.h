#pragma once

#include "raylib.h"
#include "raymath.h"
#include "ctime"

#include "mouse.h"
#include "player.h"
//#include "game_settings/constants.h"

namespace gameEnemy
{
	struct Neufar
	{
		Rectangle neufarRec;

		Circle neufarHitBox;

		Vector2 neufarPos;
		Vector2 pivot;
		Vector2 direction;
		Vector2 dirNormalizado;

		float rotation;
		float rotationSpeed;
		float impulse;
		float angle;

		Vector2 velocity;
		Vector2 aceleration;

		bool isNeufarAlive = false;
		bool isBigNeufar = false;
		bool isSmallNeufar = false;

		int bigNeufarCounter;
		int smallNeufarCounter;
	};

	//Neufar CreateNeufar(gamePlayer::Player player);

	void InitNeufar(Neufar neufar[]);
	void UpdateNeufar(Neufar neufar[]);
	//Vector2 GetRandSpawnPos();
	void DrawNeufar(Neufar neufar[]);
	//float GetMousePosRespectFromPlayer(Neufar neufar[], Vector2 mouse, int index);
}