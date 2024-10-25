#include "player.h"
#include "game_settings/constants.h"
#include "raymath.h"

#include "cmath"
namespace gamePlayer
{
	//PLAYER settings
	const float playerSpeed = 450.0f;
	const float playerPosX = screenWidth / 2.0f;
	const float playerPosY = screenHeight / 2.0f;


	Player CreatePlayer(Player player)
	{
		player.playerDir = PLAYERDIRECTION::STOP;
		player.playerColor = RED;

		player.playerPos.x = playerPosX;
		player.playerPos.y = playerPosY;
		player.playerRec.x = playerPosX;
		player.playerRec.y = playerPosY;
		player.playerRec.width = 20.0f;
		player.playerRec.height = 10.0f;
		player.pivot.x = player.playerRec.width / 2;
		player.pivot.y = player.playerRec.height / 2;
		player.rotation = 0.0f;
		player.rotationSpeed = 100.0f;
		player.radius = 10.0f;
		player.speed = 100.0f;

		return player;
	}

	//PLAYER PLAY

	void InputPlayer(Player& player)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			///shoot
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			///trusterON
		}

		StopMovement(player);
	}

	void UpdatePlayer(Player& player,mouse::Mouse gameMouse)
	{


		//player set to thrust in direction to te mouse pos
		player.direction = Vector2Subtract(gameMouse.mousePos, player.playerPos);

		player.dirNormalizado = Vector2Normalize(player.direction);

		//get angle

		player.rotation = GetMousePosRespectFromPlayer(player, gameMouse.mousePos);

		player.playerPos.x += player.dirNormalizado.x * GetFrameTime() * player.speed;
		player.playerPos.y += player.dirNormalizado.y * GetFrameTime() * player.speed;

		player.playerRec.x = player.playerPos.x;
		player.playerRec.y = player.playerPos.y;
	}

	void DrawPlayer(Player player)
	{
		DrawCircleLines(static_cast<int> (player.playerPos.x), static_cast<int> (player.playerPos.y), player.radius, RED);
		DrawRectanglePro(player.playerRec, player.pivot, player.rotation, WHITE);
	}

	void StopMovement(Player& player)
	{
		if (IsKeyUp(KEY_W))
		{
			player.playerDir = PLAYERDIRECTION::STOP;
		}
	}

	float GetMousePosRespectFromPlayer(Player player, Vector2 mouse)
	{

		float dx = mouse.x - player.playerPos.x;
		float dy = mouse.y - player.playerPos.y;
		
		 //angulo(?) en radianes
			float theta = std::atan2(dy, dx);

		//Convertimos el ángulo a grados
			float thetaGrados = theta * (180.0f / PI);

		return thetaGrados;
	}
}