#include <raylib/raylib.h>

#include <algorithm>

#include <cerrno>
#include <cstdlib>
#include <cstring>

#include <entity.h>

entity_handler_t entity_handler_init(u16 capacity) {
    entity_t *entity_arena = (entity_t*)malloc(sizeof(entity_t) * capacity);

    if (!entity_arena) {
        TraceLog(LOG_ERROR, "Could not initialize entity handler: %s", strerror(errno));
    }

    std::vector<u16> free, taken;

    return entity_handler_t {
        .start = entity_arena,
        .capacity = capacity,
        .free = free,
        .entities = taken,
        .next_free = 0,
    };
}

bool id_in_use(entity_handler_t *handler, u16 id) {
    // TODO: This could probably be a macro but shut up
    return std::find(handler->entities.begin(), handler->entities.end(), id) != handler->entities.end();
}

u16 entity_handler_next_id(entity_handler_t *handler) {
    u16 id;
    if (handler->free.empty()) {
        id = handler->next_free;
        handler->next_free += 1;
    } else {
        id = *(handler->free.begin());
        handler->free.erase(handler->free.begin());
    }
    return id;
}

entity_t *get_entity_by_id(entity_handler_t *handler, u16 id) {
    if (!id_in_use(handler, id)) {
        return nullptr;
    }

    return (handler->start) + id;
}

u16 entity_init(entity_handler_t *handler, sprite_t sprite, Vector2 pos, u8 type_flags) {
    u16 id = entity_handler_next_id(handler);
    if (id >= handler->capacity) {
        // TODO: Handle this???
        TraceLog(LOG_ERROR, "Could not initialize entity: entity handler reached capacity.");
        return id;
    }

    *((handler->start) + id) = entity_t { id, sprite, pos, type_flags };
    handler->entities.push_back(id);

    return id;
}

void entity_render(entity_t *entity) {
    sprite_render(&entity->sprite, Vector2 { entity->pos.x, entity->pos.y });
}