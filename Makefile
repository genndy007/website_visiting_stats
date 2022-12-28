SOURCES = main.cpp helper.cpp stats.cpp browser.cpp freqip.cpp referrals.cpp

run:
	g++ -o bin/exe $(SOURCES)
	./bin/exe