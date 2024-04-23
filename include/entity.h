#ifndef ENTITY_H_
#define ENTITY_H_

#include <raylib/raylib.h>

#include <sprite.h>

#include <vector>

#ifndef UTIL_IMPLEMENTATION
#define UTIL_IMPLEMENTATION
#endif

#include <util/types.h>

#define ENTITY_TYPE_PLAYER (1 << 0)

typedef struct entity_handler entity_handler_t;
typedef struct entity entity_t;

struct entity_handler {
    entity_t *start;
    u16 capacity;
    // I feel like having two vectors here is stupid
    // but this code is stupid.

    // This vector contains a list of indices
    // that are free for a new entity
    std::vector<u16> free;
    std::vector<u16> entities;

    // This simply increments, and we use this 
    // IF AND ONLY IF there are no indices stored
    // in free.

    // This value does not increment if an index in
    // free is used instead.
    u16 next_free;
};

struct entity {
    u16 id;
    sprite_t sprite;
    Vector2 pos;
    u8 type_flags;
};

entity_handler_t entity_handler_init(u16 capacity);
u16 entity_handler_next_id(entity_handler_t *handler);

entity_t *get_entity_by_id(entity_handler_t *handler, u16 id);

u16 entity_init(entity_handler_t *handler, sprite_t sprite, Vector2 pos, u8 type_flags);

void entity_render(entity_t *entity);

#endif // ENTITY_H_