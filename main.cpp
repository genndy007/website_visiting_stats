#include <iostream>

// Own code
#include <src/utils/helper.h>
#include <src/utils/stats.h>

#include <src/subtasks/browser.h>
#include <src/subtasks/referrals.h>
#include <src/subtasks/freqip.h>

using namespace std;


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats/stats.txt");
    printTopNMostFreqIp(stats, 4);

    return 0;
}