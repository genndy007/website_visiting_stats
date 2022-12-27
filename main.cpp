#include <iostream>

// Own code
#include "helper.h"
#include "stats.h"

using namespace std;

// web browser popularity



// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    for (auto stat : stats) cout << stat.toString() << endl;
    return 0;
}