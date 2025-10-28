#include "player.h"

namespace aracnoids
{
	static Rectangle auxRec;
	//static Animation playerAnims;
	int loadTextures = 0;

	bool playerIsMoving = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

	void PrintPlayer(Player& player);
	void UpdateAnim(Animation& anim);

	void InitPlayer(Player& player)
	{
		if (loadTextures == 0)
		{
			player.idleAnim.texture = LoadTexture("res/Arania/Spider.png");
			player.runAnim.texture = LoadTexture("res/Arania/Spider_Move.png");
			player.shotAnim.texture = LoadTexture("res/Arania/Spider_Attack.png");

			loadTextures = 1;
		}

		player.playerCir.pos = { static_cast <float> (GetScreenWidth() / 2), static_cast <float> (GetScreenHeight() / 2) };
		player.playerCir.rad = 20;

		player.vecDir = { 0, 0 };
		player.velocity = { 0, 0 };
		player.acceleration = { 0, 0 };
		player.points = 0;

		player.speed = 0;
		player.maxSpeed = 400.0f;
		player.rotation = 0.0f;
		player.rotationSpeed = 5.0f;
		player.isAcelerating = false;
		player.movStatus = PLAYERMOVSTAT::STOP;
		player.lives = 3;

		player.playerHit = false;
		player.isShooting = false;
		player.immunityTimer = 0.0f;
		player.inmmunityDelay = 4.0f;

		auxRec = { 0, 0, 40, 20 };

		player.idleAnim.frameCounter = 1;
		player.idleAnim.frameWidth = player.idleAnim.texture.width;
		player.idleAnim.frameHeight = player.idleAnim.texture.height;
		player.idleAnim.frameTime = 0.2f;
		player.idleAnim.time = 0.0f;
		player.idleAnim.currentFrame = 0;

		player.runAnim.frameCounter = 4;
		player.runAnim.frameWidth = player.runAnim.texture.width / static_cast <int>(player.runAnim.frameCounter);
		player.runAnim.frameHeight = player.runAnim.texture.height;
		player.runAnim.frameTime = 0.12f;
		player.runAnim.time = 0.0f;
		player.runAnim.currentFrame = 0;

		player.shotAnim.frameCounter = 5;
		player.shotAnim.frameWidth = player.shotAnim.texture.width / static_cast <int>(player.shotAnim.frameCounter);
		player.shotAnim.frameHeight = player.shotAnim.texture.height;
		player.shotAnim.frameTime = 0.08f;
		player.shotAnim.time = 0.0f;
		player.shotAnim.currentFrame = 0;

	}

	void InputPlayer(Player& player)
	{
		player.isAcelerating = IsMouseButtonDown(MOUSE_RIGHT_BUTTON);
		player.isShooting = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
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
		else player.movStatus = PLAYERMOVSTAT::STOP;

		if (player.isShooting)
			UpdateAnim(player.shotAnim);
		else if (player.movStatus == PLAYERMOVSTAT::MOVING)
			UpdateAnim(player.runAnim);
		else 
			UpdateAnim(player.idleAnim);

		player.playerCir.pos = Vector2Add(player.playerCir.pos, Vector2Scale(player.velocity, GetFrameTime()));
		//chekeo de limites horizontales
		if (player.playerCir.pos.x < -player.playerCir.rad)  player.playerCir.pos.x = GetScreenWidth() + player.playerCir.rad;
		if (player.playerCir.pos.x > GetScreenWidth() + player.playerCir.rad)  player.playerCir.pos.x = -player.playerCir.rad;
		//chekeo de limites verticales
		if (player.playerCir.pos.y < -player.playerCir.rad)  player.playerCir.pos.y = GetScreenHeight() + player.playerCir.rad;
		if (player.playerCir.pos.y > GetScreenHeight() + player.playerCir.rad)  player.playerCir.pos.y = -player.playerCir.rad;
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
	void PrintPlayer(Player& player)
	{
#ifdef _DEBUG
		DrawCircleLines(static_cast<int>(player.playerCir.pos.x), static_cast<int>(player.playerCir.pos.y), player.playerCir.rad, RED);

		DrawRectanglePro({ player.playerCir.pos.x, player.playerCir.pos.y, auxRec.width, auxRec.height },
			{ auxRec.width / 2, auxRec.height / 2 }, player.rotation, RED);
#endif // DEBUG
		DrawText(TextFormat("LIVES: %i", player.lives), 50, 30, 20, BLACK);
		DrawText(TextFormat("POINTS: %i", player.points), 450, 30, 20, RED);
		
		Animation& actualAnim = player.idleAnim;

		if (player.isShooting)
			actualAnim = player.shotAnim;
		else if (player.movStatus == PLAYERMOVSTAT::MOVING)
			actualAnim = player.runAnim;
		else
			actualAnim = player.idleAnim;

		Rectangle frame = { static_cast <float> (actualAnim.currentFrame) *
			static_cast <float> (actualAnim.frameWidth),0.0f,
			static_cast <float> (actualAnim.frameWidth),
			static_cast <float> (actualAnim.frameHeight) };

		Rectangle dest = { player.playerCir.pos.x,player.playerCir.pos.y,
			static_cast <float> (actualAnim.frameWidth) *0.5f,
			static_cast <float> (actualAnim.frameHeight) *0.5f};

		Vector2 origin = { (actualAnim.frameWidth * 0.5f) / 2.0f,(actualAnim.frameHeight*0.5f) / 2.0f };

		if (player.playerHit)
			DrawTexturePro(actualAnim.texture, frame, dest, origin, player.rotation +90.0f, GRAY);
		else
			DrawTexturePro(actualAnim.texture, frame, dest, origin, player.rotation +90.0f, WHITE);
	}
	void UpdateAnim(Animation& anim)
	{
		TraceLog(LOG_INFO, "Entró a UpdateAnim()");

		anim.time += GetFrameTime();

		if (anim.time >= anim.frameTime)
		{
			anim.time = 0.0f;
			anim.currentFrame++;
			if (anim.currentFrame >= anim.frameCounter)
			{
				anim.currentFrame = 0;
			}
		}
	}
	void UnloadPlayer(Player& player)
	{
		UnloadTexture(player.idleAnim.texture);
		UnloadTexture(player.runAnim.texture);
		UnloadTexture(player.shotAnim.texture);
	}
}