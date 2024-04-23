#ifndef SPRITE_H_
#define SPRITE_H_

#include <raylib/raylib.h>

typedef struct spritesheet {
    Texture2D texture;
    Vector2 size;
    Vector2 cell_size;
} spritesheet_t;

typedef struct sprite {
    spritesheet_t *spritesheet;
    Vector2 idx;
} sprite_t;

spritesheet_t spritesheet_from_src(const char *path, Vector2 size, Vector2 cell_size);

sprite_t sprite_from_sheet(spritesheet_t *spritesheet, Vector2 idx);

void sprite_render(sprite_t *sprite, Vector2 pos);

#endif // SPRITE_H_