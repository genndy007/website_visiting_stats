#include <iostream>
#include "browser.h"


void printMap(std::map<std::string, int> m){
    for (auto kv : m) {
        std::cout << kv.first << " : " << kv.second << std::endl;
    }
}

void btoaListBubbleSort(std::vector<BrowserToAmount>& btoaList) {
    int n = btoaList.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (btoaList[j].amount < btoaList[j + 1].amount)
                std::swap(btoaList[j], btoaList[j + 1]);     
}

std::vector<BrowserToAmount> getSortedBrowserToAmount(std::vector<VisitStat> stats) {
    // create map browser -> amount
    std::map<std::string, int> browserToAmount;
    std::string browserName;
    for (auto stat : stats){
        browserName = stat.browser;
        if (!browserToAmount.count(browserName)) browserToAmount[browserName] = 1;
        else browserToAmount[browserName]++;
    }
    // convert map into a sortable vector
    std::vector<BrowserToAmount> btoaList;
    for (auto kv : browserToAmount) {
        BrowserToAmount btoa = {kv.first, kv.second};
        btoaList.push_back(btoa);
    }
    // sort with primitive bubble sort
    btoaListBubbleSort(btoaList);
    return btoaList;
}

void printBrowserByPopularity(std::vector<VisitStat> stats) {
    std::vector<BrowserToAmount> btoaList = getSortedBrowserToAmount(stats);
    for (auto btoa : btoaList) {
        std::cout << btoa.toString() << std::endl;
    }
}