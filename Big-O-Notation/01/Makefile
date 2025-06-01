CC = clang
CFLAGS = -std=c11 -Wall
SRC = main.c
OBJ = main.o
BIN = main

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# .PHONY clean
clean:
	rm -rf $(OBJ) $(BIN)
