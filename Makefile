CFLAGS = -Wall -Werror -pedantic -g

TARGET = $(BIN_DIR)/Lab6

BIN_DIR = bin
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = lib
SRC_DIR = src

$(TARGET) : $(OBJ_DIR)/Lab6.o
	mkdir -p $(BIN_DIR)
	gcc $(CFLAGS) $(OBJ_DIR)/Lab6.o -o $(TARGET)

$(OBJ_DIR)/Lab6.o : $(SRC_DIR)/Lab6.c $(INC_DIR)/Lab6.h
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $(SRC_DIR)/Lab6.c -o $(OBJ_DIR)/Lab6.o

.PHONY: clean
clean:
	rm -f -r $(OBJ_DIR)
	rm -f -r $(BIN_DIR)
	rm -f -r $(LIB_DIR)