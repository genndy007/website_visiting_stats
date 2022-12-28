SOURCES = main.cpp src/utils/*.cpp src/subtasks/*.cpp
INCLUDED_DIRS = -I . -I ./src

run:
	g++ -o bin/exe $(INCLUDED_DIRS) $(SOURCES)
	./bin/exe