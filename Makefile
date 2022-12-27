SOURCES = main.cpp helper.cpp

run:
	g++ -o bin/exe $(SOURCES)
	./bin/exe