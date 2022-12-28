

// Own code
#include "helper.h"
#include "stats.h"
#include "browser.h"
#include "freqip.h"

using namespace std;


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    printTopNMostFreqIp(stats, 3);
    return 0;
}