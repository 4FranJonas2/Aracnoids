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
