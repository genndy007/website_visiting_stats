#ifndef SRC_CLI_APP_H
#define SRC_CLI_APP_H

#include <vector>

#include <src/utils/stats.h>

void printMenu();
int getUserIntInput();
bool activateChoice(std::vector<VisitStat> stats, int input);
void cliApp(std::string statsPath);

#endif