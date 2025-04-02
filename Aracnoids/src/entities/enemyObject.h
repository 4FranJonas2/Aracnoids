#pragma once

#include "raylib.h"
#include "raymath.h"
#include "ctime"

#include "game_settings/Constants.h"

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
		Vector2 aceleration{0,0};

		bool isNeufarAlive = false;
		bool isBigNeufar = false;
		bool isSmallNeufar = false;
		bool isInitSet = false;

		int bigNeufarCounter;
		int smallNeufarCounter;
	};

	void InitNeufar(Neufar neufar[]);
	void UpdateNeufar(Neufar neufar[]);
	//Vector2 GetRandSpawnPos();
	void DrawNeufar(Neufar neufar[]);
	//float GetMousePosRespectFromPlayer(Neufar neufar[], Vector2 mouse, int index);
}