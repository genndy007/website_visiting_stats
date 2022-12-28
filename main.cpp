#include <iostream>

// Own code
// #include "helper.h"
// #include "stats.h"
// #include "browser.h"
// #include "freqip.h"
// #include "referrals.h"
#include <src/utils/helper.h>
#include <src/utils/stats.h>

using namespace std;


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("static/data/stats.txt");
    // printTopReferrals(stats);
    for (auto stat : stats) {
        cout << stat.toString() << endl;
    }

    // vector<string> lol = splitString("lololo lolollo lololkoko hhbh", ' ');
    // printVector(lol);


    return 0;
}