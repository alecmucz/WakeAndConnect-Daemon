#include <iostream>
#include <fstream>
#include <unordered_map>
#include "include/network.h"
using namespace std;
#define DEFAULT_PATH "~/.ssh/config"

void readConfig (FILE &File, unordered_map<string,string> *sshContents) {
    ifstream inputFile(DEFAULT_PATH);
    if(!inputFile.is_open()) {
        cerr << "Can Not Open The File" << endl;
    }

}

int main() {
    startSever("XXX.XX.XXX.XXX", 56000);
    unordered_map<string, string> map;
    cout << DEFAULT_PATH << std::endl;
    return 0;
}
