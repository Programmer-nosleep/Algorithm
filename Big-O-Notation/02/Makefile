CC := clang
CFLAGS := -std=c11 -Wall -Iinclude

SRC_DIR := src
LIB_DIR := include
BUILD_DIR := build

TARGET := $(BUILD_DIR)/main

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
LIB_FILES := $(wildcard $(LIB_DIR)/*.c)
SRCS := $(SRC_FILES) $(LIB_FILES)

OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

