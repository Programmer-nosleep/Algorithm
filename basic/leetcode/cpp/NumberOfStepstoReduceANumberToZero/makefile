CC := clang++
CFLAGS := -std=c++14 -Wall

all: main.exe
main.exe: main.cpp
	$(CC) main.cpp $(CFLAGS) -o main.exe

.PHONY: clean
clean:
	powershell -Command "Remove-Item -Recurse main.exe"
