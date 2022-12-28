#include <iostream>
#include <map>

// Own code
#include "helper.h"
#include "stats.h"
#include "browser.h"

using namespace std;

// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    printBrowserByPopularity(stats);
    return 0;
}