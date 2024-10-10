#pragma once
#include "Constants.h"

enum class SCENEMANAGMENT
{
	NONE,
	INITSIM,
	MAINMENU,
	CREDITS,
	GAME,
	WINSCRREN,
	LOSESCREEN,
	PAUSE,
	BACK,
	EXIT
};

struct Rectangle
{
	Vector2 size;
	Vector2 pos;
};

enum class DIRECTION
{
	STOP = 1,
	MOVING,
	DERIVA
};

struct Player
{
	DIRECTION playerDir;
	Rectangle playerRec;
	Vector2 playerPos;
	Color color;
};

struct Mouse
{
	Vector2 mousePos;
};
