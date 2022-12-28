

// Own code
#include "helper.h"
#include "stats.h"
#include "browser.h"
#include "freqip.h"
#include "referrals.h"

using namespace std;


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("static/data/stats.txt");
    printTopReferrals(stats);
    return 0;
}