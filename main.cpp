#include <iostream>
#include <string>
#include <map>

// Own code
#include "helper.h"
#include "stats.h"
#include "browser.h"
#include "freqip.h"

using namespace std;

// resource referral frequency
struct ResourceToAmount{
    string resource;
    int amount;

    string toString() {
        return "Resource: " + resource + "; times: " + to_string(amount);
    }
};

string getResourceNameFromUrl(string url) {
    // calculate offset from beginning
    int offset = 0;
    vector<string> protocols = {"http://", "https://"};
    for (auto protocol : protocols) {
        int prefixLength = protocol.length();
        // check if prefix is equal
        if (url.compare(0, prefixLength, protocol) == 0){
            offset = prefixLength;
            break;
        }
    }
    // take from url between http(s):// and next /
    string resourceName = "";
    for (int i = offset; i < url.length(); i++) {
        char ch = url[i];
        if (ch == '/') break;
        resourceName += ch;
    }

    return resourceName;
}

void rtoaListShellSort(vector<ResourceToAmount>& rtoaList) {
    int n = rtoaList.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            ResourceToAmount temp = rtoaList[i];
            int j;
            for (j = i; j >= gap && rtoaList[j - gap].amount < temp.amount; j -= gap)
                rtoaList[j] = rtoaList[j - gap];
            rtoaList[j] = temp;
        }
    } 
}

vector<ResourceToAmount> getSortedReferrals(vector<VisitStat> stats) {
    map<string, int> resourceToAmtMap;
    for (auto stat : stats) {
        string resource = getResourceNameFromUrl(stat.referral);
        if (!resourceToAmtMap.count(resource)) resourceToAmtMap[resource] = 1;
        else resourceToAmtMap[resource]++;  
    }
    // convert into vector
    vector<ResourceToAmount> rtoaList;
    for (auto kv : resourceToAmtMap) {
        ResourceToAmount rtoa = {kv.first, kv.second};
        rtoaList.push_back(rtoa);
    }
    // sort with progressive shell sort - upgrade of insertion sort
    rtoaListShellSort(rtoaList);
    return rtoaList;
}

void printTopReferrals(vector<VisitStat> stats) {
    vector<ResourceToAmount> rtoaList = getSortedReferrals(stats);
    cout << "Top referrals:" << endl;
    for (auto rtoa : rtoaList) {
        cout << rtoa.toString() << endl;
    }
}


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    printTopReferrals(stats);
    return 0;
}