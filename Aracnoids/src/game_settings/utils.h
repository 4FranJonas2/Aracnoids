#pragma once
//#include "Constants.h"

enum class SCENEMANAGMENT
{
	NONE,
	INITSIM,
	MAINMENU,
	CREDITS,
	GAME,
	RESETGAME,
	WINLOSESCRREN,
	PAUSE,
	BACK,
	EXIT,
	LEAVESIM
};

struct RectangleGame
{
	Vector2 size;
	Vector2 pos;
};

struct Text
{
	Vector2 textPos;
	int fontSize;
};

struct Button
{
	Vector2 buttonPos{ 0.0f,0.0f };
	Vector2 buttonSize{ 0.0f,0.0f };
	Vector2 buttonCenterPos{ 0.0f,0.0f };
};

struct Menu
{
	Button firstButton;
	Button secondButton;
	Button thirdButton;
	Button backButton;
	Text buttonText;
};
