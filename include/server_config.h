//
// Created by amucz0 on 10/4/24.
//

#ifndef WAKEANDCONNECT_SERVER_CONFIG_H
#define WAKEANDCONNECT_SERVER_CONFIG_H

#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;
void readConfig(ifstream &File, unordered_map<string,string> *sshContents);
#endif //WAKEANDCONNECT_SERVER_CONFIG_H
