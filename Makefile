PROJECTNAME = project

OUTPUT_DIR = .

INCLUDE_DIRS = -Iinclude -Iheaders

LIB_DIRS = -Llib_windows

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)

windows:
	g++ $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)

mac:
	clang++ -std=c++2b -stdlib=libc++ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -Llib_mac -lraylib -Iinclude -Iheaders $(SRC) -o $(OUTPUT_DIR)/$(PROJECTNAME)