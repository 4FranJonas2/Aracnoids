#pragma once

#include "raylib.h"
#include "player.h"
#include "enemyObj.h"
#include "Bullet.h"

namespace aracnoids
{
    struct EnemyTurtle
    {
        Texture2D turtleTexture;
        Vector2 pos;
        float angle;
        float speed;
        float radius;
        bool isAlive;
    };

    void InitTurtle();
    void UpdateTurtle(Bullet gameBullet[], Player& player, EnemyObject neufar[]);
    void DrawTurtle();
    void UnloadTurtle();
}