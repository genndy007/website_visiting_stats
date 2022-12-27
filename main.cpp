#include <iostream>
#include <map>

// Own code
#include "helper.h"
#include "stats.h"

using namespace std;

// web browser popularity
struct BrowserToAmount{
    string browser;
    int amount;

    string toString() {
        return "Browser: " + browser + "; amount=" + to_string(amount);
    }
};

void printMap(map<string, int> m){
    for (auto kv : m) {
        cout << kv.first << " : " << kv.second << endl;
    }
}

void btoaListBubbleSort(vector<BrowserToAmount>& btoaList) {
    int n = btoaList.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (btoaList[j].amount < btoaList[j + 1].amount)
                swap(btoaList[j], btoaList[j + 1]);     
}

vector<BrowserToAmount> getSortedBrowserToAmount(vector<VisitStat> stats) {
    // create map browser -> amount
    map<string, int> browserToAmount;
    string browserName;
    for (auto stat : stats){
        browserName = stat.browser;
        if (!browserToAmount.count(browserName)) browserToAmount[browserName] = 1;
        else browserToAmount[browserName]++;
    }
    // convert map into a sortable vector
    vector<BrowserToAmount> btoaList;
    for (auto kv : browserToAmount) {
        BrowserToAmount btoa = {kv.first, kv.second};
        btoaList.push_back(btoa);
    }
    // use primitive bubble sort
    btoaListBubbleSort(btoaList);
    return btoaList;
}

void printBrowserByPopularity(vector<VisitStat> stats) {
    vector<BrowserToAmount> btoaList = getSortedBrowserToAmount(stats);
    for (auto btoa : btoaList) {
        cout << btoa.toString() << endl;
    }
}

// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    printBrowserByPopularity(stats);
    return 0;
}