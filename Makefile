SOURCES = main.cpp helper.cpp stats.cpp

run:
	g++ -o bin/exe $(SOURCES)
	./bin/exe