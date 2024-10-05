//
// Created by amucz0 on 10/4/24.
//
#include <iostream>
#include "../include/server_config.h"
using namespace std;
#define DEFAULT_PATH "~/.ssh/config"

void readConfig(unordered_map<string,string> &sshContents){
    ifstream inputFile(DEFAULT_PATH);
    if(!inputFile.is_open()) {
        cerr << "Can Not Open The File" << endl;
    }
}