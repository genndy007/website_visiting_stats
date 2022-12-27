#include <string>
#include <vector>

// Stats structs
struct DateTime{
    int year;
    int month;
    int day;
    int hour;
    int minute;

    std::string toString(){
        return std::to_string(year) + '-' 
        + std::to_string(month) + '-' 
        + std::to_string(day) + ' '
        + std::to_string(hour) + ':' 
        + std::to_string(minute);
    }
};

struct VisitStat{
    std::string pageAddress;
    std::string visitorIp;
    std::string browser;
    DateTime visitTimestamp;
    int spentTimeMinutes;
    std::string referral;

    std::string toString() {
        return "Stat:\nAddr: " + pageAddress 
        + " Ip: " + visitorIp 
        + " Browser: " + browser + '\n'
        + "Timestamp: " + visitTimestamp.toString() 
        + " Spent minutes: " + std::to_string(spentTimeMinutes) + '\n'
        + "Referral: " + referral;
    }
};


// Functions
DateTime castStringToDateTime(std::string dateString);
VisitStat castLineToVisitStat(std::string line);
std::vector<VisitStat> readVisitStatsFromFileName(std::string path);