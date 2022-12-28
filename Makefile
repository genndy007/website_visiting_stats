SOURCES = main.cpp src/utils/*.cpp src/subtasks/*.cpp
INCLUDED_DIRS = -I . -I ./src
BINARY_PATH = ./bin/exe

run:
	g++ -o $(BINARY_PATH) $(INCLUDED_DIRS) $(SOURCES)
	$(BINARY_PATH)