CC=g++
CFLAGS=-c -std=c++11
EXEC=lutin
SRC= $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
HEADER=$(wildcard src/*h src/*/*.h src/*/*/*.h)
BUILD_DIR=object
OBJ= $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.cpp=.o)))
EXEC_TEST=lut

all: $(EXEC)
		cp $(EXEC) $(EXEC_TEST)

lutin: $(OBJ)
		$(CC) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cpp 
		$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: src/*/%.cpp src/*/%.h
		$(CC) $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: src/*/*/%.cpp src/*/*/%.h
		$(CC) $(CFLAGS) -o $@ $<

PHONY: clean test

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC) $(EXEC_TEST)