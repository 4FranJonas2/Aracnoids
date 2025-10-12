#include "game.h"

#include <iostream>

#include "utilities.h"
#include "entities/player.h"

using namespace std;

namespace aracnoids
{
	Player player;

	void Init(GameStats gameVars, Player& player);
	void Input(Player& player);
	void Update(Player& player);
	void Draw(Player player);

	void RunGame()
	{
		srand(time(nullptr));

		GameStats gameVars;

		Init(gameVars,player);

		while (!WindowShouldClose())
		{
			Input(player);
			Update(player);
			Draw(player);
		}
		CloseWindow();
	}

	void Init(GameStats gameVars, Player& player)
	{
		InitWindow(gameVars.screenWidth, gameVars.screenHeight, "Aracnoids");

		InitPlayer(player);
	}

	void Input(Player& player)
	{
		InputPlayer(player);
	}

	void Update(Player& player)
	{
		UpdatePlayer(player);
	}

	void Draw(Player player)
	{
		BeginDrawing();

		ClearBackground(BLACK);

		DrawPlayer(player);

		EndDrawing();
	}
}
