#ifndef PLAYER_H_
#define PLAYER_H_

#include <entity.h>

typedef struct player {
    entity_t *entity;
} player_t;

player_t *player_init(entity_t *entity);

void player_update(player_t *player);

#endif // PLAYER_H_