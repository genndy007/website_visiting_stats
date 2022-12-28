#ifndef REFERRALS_H
#define REFERRALS_H


#include <string>
#include <vector>

#include "stats.h"

// resource referral frequency
struct ResourceToAmount{
    std::string resource;
    int amount;

    std::string toString() {
        return "Resource: " + resource + "; times: " + std::to_string(amount);
    }
};

std::string getResourceNameFromUrl(std::string url);
void rtoaListShellSort(std::vector<ResourceToAmount>& rtoaList);
std::vector<ResourceToAmount> getSortedReferrals(std::vector<VisitStat> stats);
void printTopReferrals(std::vector<VisitStat> stats);

#endif