#pragma once
#include "Constants.h"

enum class SCENEMANAGMENT
{
	NONE,
	INITSIM,
	MAINMENU,
	CREDITS,
	GAME,
	RESETGAME,
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

struct Text
{
	Vector2 textPos;
	int fontSize;
};

struct Button
{
	Vector2 buttonPos;
	Vector2 buttonSize;
	Vector2 buttonCenterPos;
};

struct Menu
{
	Button firstButton;
	Button secondButton;
	Button thirdButton;
	Button backButton;
	Text buttonText;
};
