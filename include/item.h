#ifndef ITEM_H_
#define ITEM_H_

#include <raylib/raylib.h>

#include <sprite.h>

typedef struct item {
    const char *name;
    sprite_t sprite;
} item_t;


#endif // ITEM_H_