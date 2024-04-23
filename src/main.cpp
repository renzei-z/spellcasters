#include <raylib/raylib.h>

#include <cassert>

#include <iostream>
#include <vector>

#include <dialogue.h>
#include <entity.h>
#include <item.h>
#include <player.h>
#include <sprite.h>

#define UNUSED(x) (void)(x)

typedef enum game_state {
    PLACEHOLDER
} game_state_t;

static game_state_t state;
static entity_handler_t entity_handler;
static player_t *player;

spritesheet_t spr;

void init_game() {
    spr = spritesheet_from_src(
        "assets/sprout_lands/character/Basic Charakter Spritesheet.png",
        Vector2 { 192, 192 },
        Vector2 { 48, 48 }
        );

    state = game_state_t::PLACEHOLDER;
    entity_handler = entity_handler_init(100);

    u16 id = entity_init(
        &entity_handler, 
        sprite_from_sheet(&spr, Vector2 { 0, 3 }),
        Vector2 { 100.f, 100.f }, 
        ENTITY_TYPE_PLAYER
        );
    
    player = player_init(get_entity_by_id(&entity_handler, id));
}

int main() {
    InitWindow(1024, 600, "Spellcasters");

    InitAudioDevice();

    SetTargetFPS(144);

    init_game();

    Music music = LoadMusicStream("assets/music/rattlesnake.mp3");

    PlayMusicStream(music);
    
    int muted = 1;

    Font font = LoadFontEx("assets/font/zpix.ttf", 48, NULL, 0);
    UNUSED(font);

    int counter = 0;

    while (!WindowShouldClose()) {
        counter ++;

        if (!muted)
            UpdateMusicStream(music);

        player_update(player);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (u16 entity_id : entity_handler.entities) {
            //std::cout << id << std::endl;
            entity_render(get_entity_by_id(&entity_handler, entity_id));
        }

        //render_dialogue("Hello, world!", (counter / 20) % 16, font);

        EndDrawing();
    }    

    UnloadMusicStream(music);

    CloseWindow();
    return 0;
}