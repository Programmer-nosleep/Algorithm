CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Iinclude
LDFLAGS := -lm

BUILD_DIR := build
TARGET  := main

SRC := $(wildcard *.c) $(wildcard include/*.c)
OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all:$(TARGET)
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

.PHONY:clean
clean:
	rm -rf main build