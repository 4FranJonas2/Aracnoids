#include "game.h"

#include <iostream>

#include "utilities.h"

using namespace std;

namespace aracnoids
{
	void Init();
	void Input();
	void Update();
	void Draw();

	void RunGame()
	{

		srand(time(nullptr));

		Init();

		while (!WindowShouldClose())
		{
			Input();
			Update();

			BeginDrawing();

			ClearBackground(BLACK);
			Draw();

			EndDrawing();
		}

		CloseWindow();
	}

	void Init()
	{
		InitWindow(200, 200, "Aracnoids");
	}

	void Input()
	{

	}

	void Update()
	{

	}

	void Draw()
	{

	}
}
