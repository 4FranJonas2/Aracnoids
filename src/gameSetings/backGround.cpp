#include "backGround.h"

namespace aracnoids
{
	const int maxLayers = 3;
	Parallax backGround[maxLayers];

	void InitParallax(Parallax backGrOund[])
	{
		backGrOund[0].texture = LoadTexture("res/Agua/Water_Base.png");
		backGrOund[0].speed = 0.0;

		backGrOund[1].texture = LoadTexture("res/Agua/Water_Shadows.png");
		backGrOund[1].speed = 0.5;
		
		backGrOund[2].texture = LoadTexture("res/Agua/Water_Sparkles.png");
		backGrOund[2].speed = 1.0;

		for (int i = 0; i < maxLayers; i++)
		{
			backGrOund[i].position = { 0.0, 0.0 };
		}
	}

	void UpdateParallaxMenu(Parallax backGrOund[])
	{
		for (int i = 0; i < maxLayers; i++)
		{
			backGrOund[i].position.x -= backGrOund[i].speed * GetFrameTime();

			if (backGrOund[i].position.x <= backGrOund[i].texture.width)
			{
				backGrOund[i].position.x = 0;
			}
		}
	}

	void DrawParallax(Parallax backGrOund[])
	{
		for (int i = 0; i < maxLayers; i++)
		{
			Texture2D auxTex = backGrOund[i].texture;
			Vector2 pos = backGrOund[i].position;

			DrawTexture(auxTex, (int)pos.x, (int)pos.y, WHITE);
			DrawTexture(auxTex, (int)pos.x + auxTex.width, (int)pos.y, WHITE);
			DrawTexture(auxTex, (int)pos.x, (int)pos.y + auxTex.height, WHITE);
			DrawTexture(auxTex, (int)pos.x + auxTex.width, (int)pos.y + auxTex.height, WHITE);
		}
	}
}