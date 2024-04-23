#include <sprite.h>

spritesheet_t spritesheet_from_src(const char *path, Vector2 size, Vector2 cell_size) {
    Texture2D texture = LoadTexture(path);
    return spritesheet_t {
        .texture = texture,
        .size = size,
        .cell_size = cell_size
    };
}

sprite_t sprite_from_sheet(spritesheet_t *spritesheet, Vector2 idx) {
    return sprite_t {
        .spritesheet = spritesheet,
        .idx = idx,
    }; 
}

void sprite_render(sprite_t *sprite, Vector2 pos) {
    Rectangle source = {
        .x = sprite->idx.x * sprite->spritesheet->cell_size.x,
        .y = sprite->idx.y * sprite->spritesheet->cell_size.y,
        .width = sprite->spritesheet->cell_size.x,
        .height = sprite->spritesheet->cell_size.y
    };

    DrawTexturePro(sprite->spritesheet->texture, source, Rectangle { pos.x, pos.y, 100.f, 100.f }, Vector2 { 0.0f, 0.0f }, 0.0f, RAYWHITE);
}