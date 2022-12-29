#include <iostream>
#include <limits.h>

#include "./app.h"
#include <src/subtasks/browser.h>
#include <src/subtasks/referrals.h>
#include <src/subtasks/freqip.h>


void printMenu() {
    std::cout << "Website Visiting CLI App" << std::endl;
    std::cout << "1. TOP popular web browsers" << std::endl;
    std::cout << "2. TOP referrals by visiting" << std::endl;
    std::cout << "3. TOP [n] IP addresses by visiting" << std::endl;
    std::cout << "4. Mean page popularity during last month by hours" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int getUserIntInput(){
    int input;
    bool valid = false;
    while(!valid) {
        std::cout << "Your choice: ";
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        } else valid = true;
    }
    return input;
}

bool activateChoice(std::vector<VisitStat> stats, int input) {
    // return false - stop program, true - continue
    switch (input) {
        case 1:
            printBrowserByPopularity(stats);
            break;
        case 2:
            printTopReferrals(stats);
            break;
        case 3:
            printTopNMostFreqIp(stats, 3);
            break;
        case 0:
            return false;
        default:
            break;
    }
    return true;
}

void cliApp() {
    std::vector<VisitStat> stats = readVisitStatsFromFileName("data/stats/stats.txt");
    bool running = true;
    int input;
    while (running) {
        printMenu();
        input = getUserIntInput();
        running = activateChoice(stats, input);
        std::cout << std::endl;
    }
}