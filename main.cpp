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

vector<IpToAmount> getSortedIpToAmount(vector<VisitStat> stats) {
    map<string, int> ipToAmount;
    string ip;
    for (auto stat : stats) {
        ip = stat.visitorIp;
        if (!ipToAmount.count(ip)) ipToAmount[ip] = 1;
        else ipToAmount[ip]++;      
    }

    vector<IpToAmount> ipToAmtList;
    for (auto kv : ipToAmount) {
        IpToAmount ipToAmt = {kv.first, kv.second};
        ipToAmtList.push_back(ipToAmt);
    }

    for (auto iptoa : ipToAmtList) {
        cout << iptoa.toString() << endl;
    }

    return ipToAmtList;
}

// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    getSortedIpToAmount(stats);
    return 0;
}