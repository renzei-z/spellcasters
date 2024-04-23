CC=g++
CFLAGS=-Wall -Wextra -Werror -g -std=c++20 -pedantic -Iinclude
LINK=-Llib -lraylib -lwinmm -lgdi32

TARGET=spellcasters.exe
BUILD=build
_OBJ=dialogue.o \
		entity.o \
		item.o \
		player.o \
		sprite.o \
		main.o
OBJ=$(patsubst %,$(BUILD)/%,$(_OBJ))

.PHONY: all run clean

all: $(TARGET)

run: all
	./$(TARGET)

clean:
	rm build/*
	rm $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LINK)

$(BUILD)/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(LINK)

$(BUILD)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^ $(LINK)