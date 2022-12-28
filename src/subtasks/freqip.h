#ifndef SRC_SUBTASKS_FREQIP_H
#define SRC_SUBTASKS_FREQIP_H

#include <vector>
#include <string>
#include <src/utils/stats.h>

// sort by most frequent ip addresses
struct IpToAmount{
    std::string ip;
    int amount;

    std::string toString() {
        return "IP: " + ip + "; times: " + std::to_string(amount);
    }
};

void ipToAmtListInsertionSort(std::vector<IpToAmount>& ipToAmtList);
std::vector<IpToAmount> getSortedIpToAmount(std::vector<VisitStat> stats);
void printTopNMostFreqIp(std::vector<VisitStat> stats, int n);

#endif