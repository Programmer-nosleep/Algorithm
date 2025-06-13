CC := clang
CFLAGS := -std=c11 -Wall -O2 -Iinclude

BUILD := build
OUTDIR := Debug

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, $(BUILD)/%.o, $(notdir $(SRC)))
TARGET := $(OUTDIR)/main

$(TARGET): $(OBJ)
	@mkdir -p $(OUTDIR)
	$(CC) $(OBJ) -o $(TARGET)

$(BUILD)/%.o: %.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(BUILD) $(OUTDIR)
