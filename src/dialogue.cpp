#include <dialogue.h>

#include <raylib/raylib.h>

#include <util/types.h>

static int padding = 20;

void render_dialogue(std::string text, u8 count, Font font) {
    Rectangle dialogue_box = Rectangle {
        (float) padding, 
        (float) (GetScreenHeight() / 2), 
        (float) (GetScreenWidth() - (2 * padding)), 
        (float) (GetScreenHeight() / 2 - padding),
    };

    DrawRectangleRec(dialogue_box, BROWN);
    DrawTextPro(
        font,
        text.substr(0, count).c_str(),
        Vector2 { dialogue_box.x + padding, dialogue_box.y + padding },
        Vector2 { 0.0f, 0.0f },
        0.0f,
        48.0f,
        -2.0f,
        RAYWHITE
    );
}