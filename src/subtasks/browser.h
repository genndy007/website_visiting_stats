#ifndef SRC_SUBTASKS_BROWSER_H
#define SRC_SUBTASKS_BROWSER_H

#include <string>
#include <map>
#include <vector>

#include <src/utils/stats.h>

// web browser popularity
struct BrowserToAmount{
    std::string browser;
    int amount;

    std::string toString() {
        return "Browser: " + browser + "; amount=" + std::to_string(amount);
    }
};

void printMap(std::map<std::string, int> m);
void btoaListBubbleSort(std::vector<BrowserToAmount>& btoaList);
std::vector<BrowserToAmount> getSortedBrowserToAmount(std::vector<VisitStat> stats);
void printBrowserByPopularity(std::vector<VisitStat> stats);

#endif 