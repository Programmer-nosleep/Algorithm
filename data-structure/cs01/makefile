CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Iinclude
LDFLAGS := -lm

BUILD_DIR := build
TARGET  := main

# Tambahkan direktori sumber ke VPATH agar 'make' dapat menemukannya
VPATH := include

# Ambil semua file .c dari direktori root dan include
SRC := $(wildcard *.c) $(wildcard include/*.c)

# Buat daftar file objek (.o) yang "datar" di dalam BUILD_DIR
# Contoh: main.c -> build/main.o, include/array.c -> build/array.o
OBJ := $(addprefix $(BUILD_DIR)/, $(notdir $(patsubst %.c,%.o,$(SRC))))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# Aturan ini sekarang berfungsi untuk semua file sumber karena VPATH
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) $(BUILD_DIR)
