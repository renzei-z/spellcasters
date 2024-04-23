#include <player.h>

#include <raylib/raylib.h>

#include <cstdlib>

player_t *player_init(entity_t *entity) {
    player_t *player = (player_t*) calloc(1, sizeof(player_t));
    player->entity = entity;
    return player;
}

void player_update(player_t *player) {
    Vector2 dir = { 
        (float) (IsKeyDown(KEY_A) * -1 + IsKeyDown(KEY_D)), 
        (float) (IsKeyDown(KEY_W) * -1 + IsKeyDown(KEY_S)) 
    };

    if (dir.x > 0) player->entity->sprite.idx.y = 3;
    else if (dir.x < 0) player->entity->sprite.idx.y = 2;
    else if (dir.y > 0) player->entity->sprite.idx.y = 0;
    else if (dir.y < 0) player->entity->sprite.idx.y = 1;

    player->entity->pos.x += 100 * GetFrameTime() * dir.x;
    player->entity->pos.y += 100 * GetFrameTime() * dir.y;
}