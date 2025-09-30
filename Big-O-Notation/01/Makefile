CC := clang
CFLAGS := -std=c11 -Wall

SRC_DIR := src
BUILD_DIR := build

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC)))
TARGET := $(BUILD_DIR)/main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(addprefix $(BUILD_DIR)/,$(OBJ)) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

