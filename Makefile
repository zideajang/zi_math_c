CC=gcc

CFLAGS=-Wall
CFLAGS+=-Wno-unused-variable
TARGET=main

SRC_FILES := main.c src/vec.c src/utils.c
OBJ := $(SRC_FILES:.c=.o)

INC_DIRS=-Isrc

all:clean $(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS)  -o $(TARGET) $^

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INC_DIRS) 


clean:
	rm -f $(OBJ) $(TARGET)