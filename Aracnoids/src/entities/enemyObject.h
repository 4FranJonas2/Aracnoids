#pragma once

#include "raylib.h"
#include "raymath.h"
#include "ctime"

#include "Mouse.h"
#include "Player.h"
#include "game_play/ColisionManager.h"

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

	void InitNeufar();
	void UpdateNeufar();
	//Vector2 GetRandSpawnPos();
	void DrawNeufar();
	//float GetMousePosRespectFromPlayer(Neufar neufar[], Vector2 mouse, int index);
}