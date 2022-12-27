#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// helper functions for data types
vector<string> splitString(string str, char delim='\n'){
    stringstream ss(str);
    string buf;
    vector<string> splitted;
    while(getline(ss, buf, delim)){
        splitted.push_back(buf);
    }
    return splitted;
}

void printVector(vector<string> vec) {
    for (auto el : vec) {
        cout << el << ',';
    }
    cout << endl;
}

// stats structs
struct DateTime{
    int year;
    int month;
    int day;
    int hour;
    int minute;

    string toString(){
        return to_string(year) + '-' + to_string(month) + '-' + to_string(day) + ' '
        + to_string(hour) + ':' + to_string(minute);
    }
};

struct VisitStat{
    string pageAddress;
    string visitorIp;
    string browser;
    DateTime visitTimestamp;
    int spentTimeMinutes;
    string referral;

    string toString() {
        return "Stat:\nAddr: " + pageAddress + " Ip: " + visitorIp + " Browser: " + browser + '\n'
        + "Timestamp: " + visitTimestamp.toString() + " Spent minutes: " + to_string(spentTimeMinutes) + '\n'
        + "Referral: " + referral;
    }
};

// read stats file
DateTime castStringToDateTime(string dateString){
    DateTime dt;
    // split by space on date and time
    vector<string> dateAndTime = splitString(dateString, ' ');
    if (dateAndTime.size() < 2) return dt;
    string dateOnly = dateAndTime[0];
    string timeOnly = dateAndTime[1];

    // split date by '-' and split time by ':'
    vector<string> yyyymmdd = splitString(dateOnly, '-');
    if (yyyymmdd.size() < 3) return dt;
    vector<string> hhmm = splitString(timeOnly, ':');
    if (hhmm.size() < 2) return dt;

    int year = stoi(yyyymmdd[0]);
    int month = stoi(yyyymmdd[1]);
    int day = stoi(yyyymmdd[2]);
    int hour = stoi(hhmm[0]);
    int minute = stoi(hhmm[1]);

    dt = {year, month, day, hour, minute};
    return dt;
}

VisitStat castLineToVisitStat(string line){
    stringstream ss(line);
    string buf;
    vector<string> items;
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

vector<VisitStat> readVisitStatsFromFileName(string path){
    ifstream file(path);
    vector<VisitStat> stats;
    string line;
    while(getline(file, line)){
        stats.push_back(castLineToVisitStat(line));
    }
    file.close();
    return stats;
}



// MAIN PROGRAM LOOP
int main() {
    vector<VisitStat> stats = readVisitStatsFromFileName("stats.txt");
    for (auto stat : stats) cout << stat.toString() << endl;
    return 0;
}