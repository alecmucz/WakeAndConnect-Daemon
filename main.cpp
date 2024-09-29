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
    int server_fd = startSever("XXX.XXX.XX.XXX", 56000);
    int client_fd = handleClient(server_fd);

    return 0;
}
