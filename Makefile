PROJECTNAME = pong

OUTPUT_DIR = ./bin

INCLUDE_DIRS = -Iinclude -Iheaders

LIB_DIRS = -Llib

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)

build:
	@g++ $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)

run:build
	./bin/pong.exe
