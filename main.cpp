#include <iostream>
#include <limits.h>


// Own code
#include <src/utils/helper.h>
#include <src/utils/stats.h>

#include <src/subtasks/browser.h>
#include <src/subtasks/referrals.h>
#include <src/subtasks/freqip.h>
// #include <src/subtasks/pagepop.h>

using namespace std;
// Mean page popularity

void printMenu() {
    cout << "Website Visiting CLI App" << endl;
    cout << "1. TOP popular web browsers" << endl;
    cout << "2. TOP referrals by visiting" << endl;
    cout << "3. TOP [n] IP addresses by visiting" << endl;
    cout << "4. Mean page popularity during last month by hours" << endl;
}

int getUserIntInput(){
    int input;
    bool valid = false;
    while(!valid) {
        cout << "Your choice: ";
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } else valid = true;
    }
    return input;
}

void cliApp() {
    bool running = true;
    while (running) {
        printMenu();
        getUserIntInput();
    }
}


// MAIN PROGRAM LOOP
int main() {
    // vector<VisitStat> stats = readVisitStatsFromFileName("data/stats/stats.txt");
    // printTopReferrals(stats);

    cliApp();
    return 0;
}