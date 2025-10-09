CC := clang++
CFLAGS := -std=c++11 -Wall -Werror 

TARGET := main

all:main
main: main.cpp
	$(CC) main.cpp $(CFLAGS) -o $(TARGET)

.PHONY:clean
clean:
	rm main
