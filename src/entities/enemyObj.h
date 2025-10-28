#include "ctime"

#include "raylib.h"

#include "bullet.h"
#include "../utilities.h"
#include "../gameSetings/audioManager.h"

namespace aracnoids
{
    struct EnemyObject
    {
        Texture2D neufarTexture;
        Vector2 pos;
        float angle;
        float speed;
        float radius;
        bool isAlive;
        int type;       // 0 = grande, 1 = mediano, 2 = chico
        int parentId;   // id del grande original (o -1 si es inicial)
        int id;         // identificador único
    };

    void InitEnemys();
    void CreateBigEnemy();
    void CreateMediumEnemy( int idBigEnemy, Vector2 pos, float baseAngle);
    void CreateSmallEnemy( int idBigEnemy, Vector2 pos, float baseAngle);
    void UpdateEnemyObject( Bullet gameBullet[], Player& player, AudioManager auxAudio);
    void DrawEnemyObject();
    void UnloadNeufars();
}