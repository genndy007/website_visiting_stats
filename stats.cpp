#include <sstream>
#include <fstream>

#include "stats.h"
#include "helper.h"

// read stats file
DateTime castStringToDateTime(std::string dateString){
    DateTime dt;
    // split by space on date and time
    std::vector<std::string> dateAndTime = splitString(dateString, ' ');
    if (dateAndTime.size() < 2) return dt;
    std::string dateOnly = dateAndTime[0];
    std::string timeOnly = dateAndTime[1];

    // split date by '-' and split time by ':'
    std::vector<std::string> yyyymmdd = splitString(dateOnly, '-');
    if (yyyymmdd.size() < 3) return dt;
    std::vector<std::string> hhmm = splitString(timeOnly, ':');
    if (hhmm.size() < 2) return dt;

    int year = stoi(yyyymmdd[0]);
    int month = stoi(yyyymmdd[1]);
    int day = stoi(yyyymmdd[2]);
    int hour = stoi(hhmm[0]);
    int minute = stoi(hhmm[1]);

    dt = {year, month, day, hour, minute};
    return dt;
}

VisitStat castLineToVisitStat(std::string line){
    std::stringstream ss(line);
    std::string buf;
    std::vector<std::string> items;
    while(getline(ss, buf, ',')){
        items.push_back(buf);
    }

    VisitStat vs;
    if(items.size() < 6) return vs;
    vs.pageAddress = items[0];
    vs.visitorIp = items[1];
    vs.browser = items[2];
    vs.visitTimestamp = castStringToDateTime(items[3]);
    vs.spentTimeMinutes = stoi(items[4]);
    vs.referral = items[5];
    
    return vs;
}

std::vector<VisitStat> readVisitStatsFromFileName(std::string path){
    std::ifstream file(path);
    std::vector<VisitStat> stats;
    std::string line;
    while(getline(file, line)){
        stats.push_back(castLineToVisitStat(line));
    }
    file.close();
    return stats;
}