#include "raylib.h"

#include "../utilities.h"
#include "ctime"
#include "bullet.h"

namespace aracnoids
{
    struct EnemyObject
    {
        Vector2 pos;
        float angle;
        float speed;
        float radius;
        bool isAlive;
        int type;       // 0 = grande, 1 = mediano, 2 = chico
        int parentId;   // id del grande original (o -1 si es inicial)
        int id;         // identificador único
    };

	//Bullet CreateBullet( gamePlayer::Player player);
	//void InitBullets(Bullet bullet[], gamePlayer::Player player);
    void InitEnemys();
    void CreateBigEnemy();
    void CreateMediumEnemy( int idBigEnemy, Vector2 pos, float baseAngle);
    void CreateSmallEnemy( int idBigEnemy, Vector2 pos, float baseAngle);
    void UpdateEnemyObject( Bullet gameBullet[], Player& player);
    void DrawEnemyObject();
}