#pragma once

#include "raylib.h"

#include "../utilities.h"

namespace aracnoids
{
	struct Parallax
	{
		Texture2D texture;
		Vector2 position;
		float speed;
	};

	void InitParallax(Parallax backGround[]);
	void UpdateParallaxMenu(Parallax backGround[]);
	void DrawParallax(Parallax backGround[]);
}