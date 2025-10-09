CC := clang
CFLAGS := -std=c11 -Wall -Wextra
LDFLAGS := -lm

BUILD_DIR := build
SRC := $(wildcard *.c)
TARGET := $(BUILD_DIR)/main

all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(TARGET) $(SRC) 
	mkdir -p build

run: $(TARGET)
	./$(TARGET)

.PHONY:clean
clean:
	rm $(TARGET)