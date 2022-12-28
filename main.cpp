#include <iostream>

// Own code
#include "helper.h"
#include "stats.h"
#include "browser.h"
#include "freqip.h"

using namespace std;

// resource referral frequency

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

void getSortedReferrals(vector<VisitStat> stats) {
    for (auto stat : stats) {
        cout << getResourceNameFromUrl(stat.referral) << endl;
    }
}


// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("data/stats.txt");
    // getSortedReferrals(stats);
    // getResourceNameFromUrl("https://ololo.ua/popit/lookfor");
    getSortedReferrals(stats);
    return 0;
}