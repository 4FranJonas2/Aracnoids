#include "player.h"

#include "cmath"

#include "game_settings/constants.h"
#include "raymath.h"

//para chequear coliciones ANOTACION
//saco la distancia entre ambos objetos
//comparo la distancia entre la suma del radio de objeto 1 y objeto 2 
//si es igual estan a punto de colisionar(colisionaron)
//si la distancis es menor a la suma de los radios entonces ya colisionaron

namespace gamePlayer
{
	//PLAYER settings
	const float playerSpeed = 450.0f;
	const float playerPosX = screenWidth / 2.0f;
	const float playerPosY = screenHeight / 2.0f;

	Player CreatePlayer(Player player)
	{
		player.playerDir = PLAYERDIRECTION::STOP;
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
		player.speed = 150.0f;
		player.aceleration = { 0.0f,0.0f };
		player.matchStart = false;

		player.playerHitBox.circlePos.x = player.playerPos.x;
		player.playerHitBox.circlePos.y = player.playerPos.y;
		player.playerHitBox.radius = player.radius;
		return player;
	}

	//PLAYER PLAY
	void InputPlayer(Player& player)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
		{
			player.matchStart = true;
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			///trusterON
		}

		StopMovement(player);
	}

	void UpdatePlayer(Player& player, mouse::Mouse& gameMouse)
	{
		if (player.matchStart == true)
		{
			float maxAceleracion = 1.0f;
			//float moduleVectorDir;
			//player set to thrust in direction to te mouse pos and normalize the vector
			//get angle
			player.rotation = GetMousePosRespectFromPlayer(player, gameMouse.mousePos);
			
			player.direction = Vector2Subtract(GetMousePosition(), player.playerPos);

			player.direction.x = gameMouse.mousePos.x - player.playerPos.x;
			player.direction.y = gameMouse.mousePos.y - player.playerPos.y;

			if ( IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			{
				player.dirNormalizado = Vector2Normalize(player.direction);

				player.aceleration = Vector2Add(player.aceleration, player.dirNormalizado);
				
				// Limitar la aceleración máxima
				float acelMagnitud = Vector2Length(player.aceleration);

				if (acelMagnitud > maxAceleracion)
				{
					// Ajustar la aceleración al máximo permitido
					player.aceleration = Vector2Scale(Vector2Normalize(player.aceleration), maxAceleracion);
				}
			}

			//movemment
			player.playerPos.x += player.aceleration.x * GetFrameTime() * player.speed;
			player.playerPos.y += player.aceleration.y * GetFrameTime() * player.speed;

			//future sprite updated pos
			player.playerRec.x = player.playerPos.x;
			player.playerRec.y = player.playerPos.y;

			player.playerHitBox.circlePos.x = player.playerPos.x;
			player.playerHitBox.circlePos.y = player.playerPos.y;
		}
	}

	void DrawPlayer(Player player)
	{
		DrawCircleLines(static_cast<int> (player.playerHitBox.circlePos.x), static_cast<int> (player.playerHitBox.circlePos.y), player.playerHitBox.radius, RED);
		DrawRectanglePro(player.playerRec, player.pivot, player.rotation, WHITE);
		if (player.matchStart == false)
		{
			DrawText("PRess middle mouse button to start", 250, 500, 30,LIGHTGRAY);
		}
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

		//Convierto el ángulo a grados
		float thetaGrados = theta * (180.0f / PI);

		return thetaGrados;
	}
}