# SOURCES = main.cpp helper.cpp stats.cpp browser.cpp freqip.cpp referrals.cpp

SOURCES = main.cpp src/utils/*.cpp
INCLUDED_DIRS = -I . -I ./src

run:
	g++ -o bin/exe $(INCLUDED_DIRS) $(SOURCES)
	./bin/exe