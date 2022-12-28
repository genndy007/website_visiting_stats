SOURCES = main.cpp helper.cpp stats.cpp browser.cpp

run:
	g++ -o bin/exe $(SOURCES)
	./bin/exe