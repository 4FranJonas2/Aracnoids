#include "player.h"

namespace aracnoids
{
	Rectangle auxRec;

	bool playerIsMoving = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

	void PrintPlayer(Player player);

	void InitPlayer(Player& player)
	{
		player.playerCir.pos = { 500, 500 };
		player.playerCir.rad = 20;

		player.vecDir = { 0, 0 };
		player.velocity = { 0, 0 };
		player.acceleration = { 0, 0 };

		player.speed = 0;
		player.maxSpeed = 400.0f;
		player.rotation = 0.0f;
		player.rotationSpeed = 5.0f;
		player.isAcelerating = false;
		player.movStatus = PLAYERMOVSTAT::STOP;
		player.lives = 3;

		player.playerHit = false;
		player.immunityTimer = 0.0f;
		player.inmmunityDelay = 4.0f;

		auxRec = { 0, 0, 40, 20 };
	}

	void InputPlayer(Player& player)
	{
		player.isAcelerating = IsMouseButtonDown(MOUSE_RIGHT_BUTTON);
	}

	void UpdatePlayer(Player& player)
	{
		Vector2 posMouse = GetMousePosition();
		player.rotation = atan2f(player.vecDir.y, player.vecDir.x) * RAD2DEG;

		player.vecDir = Vector2Subtract(posMouse, player.playerCir.pos);

		if (player.isAcelerating)
		{
			player.vecDir = Vector2Normalize(player.vecDir);

			Vector2 impulse = Vector2Scale(player.vecDir, 200.0f * GetFrameTime());
			player.velocity = Vector2Add(player.velocity, impulse);

			// limitar velocidad máxima
			if (Vector2Length(player.velocity) > player.maxSpeed)
				player.velocity = Vector2Scale(Vector2Normalize(player.velocity), player.maxSpeed);

			player.movStatus = PLAYERMOVSTAT::MOVING;
		}

		//chekeo de limites horizontales
		if (player.playerCir.pos.x < player.playerCir.rad)
			player.playerCir.pos.x = GetScreenWidth() + player.playerCir.rad;

		if (player.playerCir.pos.x > GetScreenWidth() + player.playerCir.rad)
			player.playerCir.pos.x = -player.playerCir.rad;

		//chekeo de limites verticales
		if (player.playerCir.pos.y < -player.playerCir.rad)
			player.playerCir.pos.y = GetScreenHeight() + player.playerCir.rad;

		if (player.playerCir.pos.y > GetScreenHeight() + player.playerCir.rad)
			player.playerCir.pos.y = -player.playerCir.rad;

		player.playerCir.pos = Vector2Add(player.playerCir.pos, Vector2Scale(player.velocity, GetFrameTime()));
		player.movStatus = PLAYERMOVSTAT::STOP;
	}

	void DrawPlayer(Player player)
	{
		PrintPlayer(player);

		if (player.playerCir.pos.x < player.playerCir.rad)
		{
			player.playerCir.pos.x = player.playerCir.pos.x + GetScreenWidth();
			PrintPlayer(player);
		}
		if (player.playerCir.pos.x > GetScreenWidth())
		{
			player.playerCir.pos.x = player.playerCir.pos.x - GetScreenWidth();
			PrintPlayer(player);
		}
		if (player.playerCir.pos.y < player.playerCir.rad)
		{
			player.playerCir.pos.y = player.playerCir.pos.y + GetScreenHeight() + player.playerCir.rad;
			PrintPlayer(player);
		}
		if (player.playerCir.pos.y > GetScreenHeight() + player.playerCir.rad)
		{
			player.playerCir.pos.y = player.playerCir.pos.y - GetScreenHeight();
			PrintPlayer(player);
		}
	}

	void PrintPlayer(Player player)
	{
#ifdef _DEBUG
		DrawCircleLines(static_cast<int>(player.playerCir.pos.x), static_cast<int>(player.playerCir.pos.y), player.playerCir.rad, RED);
		DrawText(TextFormat("%i", player.lives), 50, 50, 60, GRAY);
#endif // DEBUG
		DrawRectanglePro({ player.playerCir.pos.x, player.playerCir.pos.y, auxRec.width, auxRec.height },
			{ auxRec.width / 2, auxRec.height / 2 }, player.rotation, RED);
	}
}