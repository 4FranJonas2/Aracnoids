#pragma once

#include "raylib.h"

//ARENA settings
extern bool matchStart;

const float screenWidth = 1024.0f;
const float screenHeight = 768.0f;
const float midScreenWidth = screenWidth / 2;
const float midScreenHeight = screenHeight / 2;
const float screenHeightDiv6 = screenHeight / 6;
const float auxFloat = 100.0f;
const float arenaMarkBoard = 100.0f;

const int maxBullets = 40;
const int maxNeufares = 50;
const int maxBigNeufares = 10;
const int maxSmallNeufares = 40;

struct Circle
{
	Vector2 circlePos;
	float radius;
};