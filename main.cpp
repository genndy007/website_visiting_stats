

#include <src/cli/app.h>

using namespace std;
// Mean page popularity



// MAIN PROGRAM LOOP
int main() {
    // vector<VisitStat> stats = readVisitStatsFromFileName("data/stats/stats.txt");
    // printTopReferrals(stats);

    cliApp("data/stats/stats.txt");
    return 0;
}