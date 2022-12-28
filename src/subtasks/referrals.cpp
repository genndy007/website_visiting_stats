#include <map>
#include <iostream>

#include "./referrals.h"

bool startsWith(std::string target, std::string prefix) {
    int prefixLength = prefix.length();
    // horrifying comparison of prefix of string
    return target.compare(0, prefixLength, prefix) == 0;
}

std::string getResourceNameFromUrl(std::string url) {
    // calculate offset from beginning
    int offset = 0;
    std::vector<std::string> protocols = {"http://", "https://"};
    for (auto protocol : protocols) {
        if (startsWith(url, protocol)) {
            offset = protocol.length();
            break;
        }
    }
    // take from url between http(s):// and next /
    std::string resourceName = "";
    for (int i = offset; i < url.length(); i++) {
        char ch = url[i];
        if (ch == '/') break;
        // until got to / append every char to resourceName
        resourceName += ch;
    }

    return resourceName;
}

void rtoaListShellSort(std::vector<ResourceToAmount>& rtoaList) {
    // Shell Sort Algorithm (GeeksForGeeks) - upgraded Insertion Sort
    int n = rtoaList.size();
    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            ResourceToAmount temp = rtoaList[i];
            int j;
            for (j = i; j >= gap && rtoaList[j - gap].amount < temp.amount; j -= gap)
                rtoaList[j] = rtoaList[j - gap];
            rtoaList[j] = temp;
        }
}

std::vector<ResourceToAmount> getSortedReferrals(std::vector<VisitStat> stats) {
    // map resourceName : amount
    std::map<std::string, int> resourceToAmtMap;
    for (auto stat : stats) {
        std::string resource = getResourceNameFromUrl(stat.referral);
        if (!resourceToAmtMap.count(resource)) resourceToAmtMap[resource] = 1;
        else resourceToAmtMap[resource]++;  
    }
    // convert into vector for sorting
    std::vector<ResourceToAmount> rtoaList;
    for (auto kv : resourceToAmtMap) {
        ResourceToAmount rtoa = {kv.first, kv.second};
        rtoaList.push_back(rtoa);
    }
    // sort with progressive shell sort - upgrade of insertion sort
    rtoaListShellSort(rtoaList);
    return rtoaList;
}

void printTopReferrals(std::vector<VisitStat> stats) {
    std::vector<ResourceToAmount> rtoaList = getSortedReferrals(stats);
    std::cout << "Top referrals:" << std::endl;
    for (auto rtoa : rtoaList) {
        std::cout << rtoa.toString() << std::endl;
    }
}