#include <vector>
#include <map>
#include <iostream>

// Own code
#include "helper.h"
#include "stats.h"
#include "browser.h"

using namespace std;

// sort by most frequent ip addresses
struct IpToAmount{
    string ip;
    int amount;

    string toString() {
        return "IP: " + ip + "; times: " + to_string(amount);
    }
};

void ipToAmtListInsertionSort(vector<IpToAmount>& ipToAmtList) {
    int n = ipToAmtList.size();
    for (int i = 1; i < n; i++){
        IpToAmount key = ipToAmtList[i];
        int j = i - 1;
        while(j >= 0 && ipToAmtList[j].amount < key.amount) {
            ipToAmtList[j + 1] = ipToAmtList[j];
            j -= 1;
        }
        ipToAmtList[j + 1] = key;
    }
}

vector<IpToAmount> getSortedIpToAmount(vector<VisitStat> stats) {
    // create map ip -> amount
    map<string, int> ipToAmount;
    string ip;
    for (auto stat : stats) {
        ip = stat.visitorIp;
        if (!ipToAmount.count(ip)) ipToAmount[ip] = 1;
        else ipToAmount[ip]++;      
    }
    // convert map to vector for sorting
    vector<IpToAmount> ipToAmtList;
    for (auto kv : ipToAmount) {
        IpToAmount ipToAmt = {kv.first, kv.second};
        ipToAmtList.push_back(ipToAmt);
    }
    // sort with not so primitive insertion sort
    ipToAmtListInsertionSort(ipToAmtList);
    return ipToAmtList;
}

void printTopNMostFreqIp(vector<VisitStat> stats, int n) {
    vector<IpToAmount> iptoaList = getSortedIpToAmount(stats);
    int length = iptoaList.size();
    if (length < n) n = length;
    cout << "Top " << n << " Most Frequent IPs of " << length << endl;
    for (int i = 0; i < n; i++) {
        cout << iptoaList[i].toString() << endl;
    }
}


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    printTopNMostFreqIp(stats, 4);
    return 0;
}