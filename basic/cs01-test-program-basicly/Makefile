CC := clang
CFLAGS := -std=c11 -Wall

SRC := main.c
TARGET := main
OBJ := main.o


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ) 

.PHONY: clean
clean:
	rm -rf $(OBJ) $(TARGET)
