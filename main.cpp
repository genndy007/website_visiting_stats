#include <iostream>

// Own code
#include <src/utils/helper.h>
#include <src/utils/stats.h>

#include <src/subtasks/browser.h>
#include <src/subtasks/referrals.h>
#include <src/subtasks/freqip.h>

using namespace std;
// Mean page popularity


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats/stats.txt");
    printTopReferrals(stats);

    return 0;
}