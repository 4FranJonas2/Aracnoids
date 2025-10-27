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
		backGrOund[1].speed = 10.0;
		
		backGrOund[2].texture = LoadTexture("res/Agua/Water_Sparkles.png");
		backGrOund[2].speed = 20.0;

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

			if (backGrOund[i].position.x <= -backGrOund[i].texture.width)
			{
				backGrOund[i].position.x += backGrOund[i].texture.width;
			}
		}
	}

	void UpdateParallaxGameplay(Parallax backGrOund[], Vector2 playerVel)
	{
		for (int i = 0; i < maxLayers; i++)
		{
			backGrOund[i].position.x += -playerVel.x * (backGrOund[i].speed * 0.02f) * GetFrameTime();
			backGrOund[i].position.y += -playerVel.y * (backGrOund[i].speed * 0.02f) * GetFrameTime();

			backGrOund[i].position.x = fmodf(backGrOund[i].position.x, static_cast <float>(backGrOund[i].texture.width));
			backGrOund[i].position.y = fmodf(backGrOund[i].position.y, static_cast <float>(backGrOund[i].texture.height));
		}
	}

	/*void DrawParallax(Parallax backGrOund[])
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
	}*/

	void DrawParallax(Parallax backGrOund[])
	{
		for (int i = 0; i < maxLayers; i++)
		{
			Texture2D auxTex = backGrOund[i].texture;
			Vector2 pos = backGrOund[i].position;
			
			for (int y = -1; y < 1; y++)
			{
				for (int x = -1; x < 1; x++)
				{
					DrawTexture(auxTex, static_cast<int>(pos.x + auxTex.width * x),
										static_cast<int>(pos.y + auxTex.height * y), WHITE);
				}
			}
		}
	}

	void UnloadParallax(Parallax backGrOund[])
	{
		for (int i = 0; i < maxLayers; i++)
		{
			UnloadTexture(backGrOund[i].texture);
		}
	}
}