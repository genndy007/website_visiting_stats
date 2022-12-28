#include <map>
#include <iostream>

#include "freqip.h"

void ipToAmtListInsertionSort(std::vector<IpToAmount>& ipToAmtList) {
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

std::vector<IpToAmount> getSortedIpToAmount(std::vector<VisitStat> stats) {
    // create map ip -> amount
    std::map<std::string, int> ipToAmount;
    std::string ip;
    for (auto stat : stats) {
        ip = stat.visitorIp;
        if (!ipToAmount.count(ip)) ipToAmount[ip] = 1;
        else ipToAmount[ip]++;      
    }
    // convert map to vector for sorting
    std::vector<IpToAmount> ipToAmtList;
    for (auto kv : ipToAmount) {
        IpToAmount ipToAmt = {kv.first, kv.second};
        ipToAmtList.push_back(ipToAmt);
    }
    // sort with not so primitive insertion sort
    ipToAmtListInsertionSort(ipToAmtList);
    return ipToAmtList;
}

void printTopNMostFreqIp(std::vector<VisitStat> stats, int n) {
    std::vector<IpToAmount> iptoaList = getSortedIpToAmount(stats);
    int length = iptoaList.size();
    if (length < n) n = length;
    std::cout << "Top " << n << " Most Frequent IPs of " << length << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << iptoaList[i].toString() << std::endl;
    }
}