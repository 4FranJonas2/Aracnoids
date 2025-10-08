#pragma once
namespace aracnoids
{
	struct Vector2
	{
		float x;
		float y;
	};

	struct Circle
	{
		Vector2 pos;
		float rad;
	};

	struct Colors
	{
		float r;
		float g;
		float b;
		float a;
	};

	struct Rectangle
	{
		Vector2 recPos;
		Vector2 recSize;
	};

	enum class SceneStatus
	{
		INITGAME = 1,
		FIRSTGAME,
		GAMEMENU,
		GAMERULES,
		GAMECREDITS,
		GAMEPLAY,
		GAMEPAUSE,
		RESETGAME,
		GAMEEND,
		SIMEND
	};

	struct GameStats
	{
		SceneStatus gameStatus;
		const int screenWidth = 750;
		const int screenHeight = 650;
		int fontSize = 25;
		bool enterIsPressed = false;
		bool enterWasPressed = false;
		bool isResetMatch = false;
		bool goMenu = false;
		int backGroundImage;
		int coconut;
		int redCoconut;
		int yellowCoconut;
		int greenCoconut;
		int coconutTree;
		int backButton;
		int crabNormalWalk;
		int bottle1;
		int bottle2;
		int bottle3;
	};
}