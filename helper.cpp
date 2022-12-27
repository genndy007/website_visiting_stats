#include <sstream>
#include <iostream>

#include "helper.h"

// Helper functions for data types

std::vector<std::string> splitString(std::string str, char delim){
    std::stringstream ss(str);
    std::string buf;
    std::vector<std::string> splitted;
    while(getline(ss, buf, delim)){
        splitted.push_back(buf);
    }
    return splitted;
}

void printVector(std::vector<std::string> vec) {
    for (auto el : vec) {
        std::cout << el << ',';
    }
    std::cout << std::endl;
}