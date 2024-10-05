#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cstring>
#include <csignal>
#include "include/network.h"
#include "include/server_config.h"
using namespace std;
#define DEFAULT_PATH "~/.ssh/config"


int main() {
    auto [server_fd, deviceMap] = startSever("XXX.XXX.XXX.XXX", 56000);
    // Temp fix "Nothing more permanent"
    while(true){
        int client_fd = handleClient(server_fd);
        if(client_fd < 0){
            cerr << "Failure Within Client Connection" << strerror(errno) << endl;
            continue;
        }
        if (close(client_fd) < 0){
            cerr << "Failed to Close Client Connection" << strerror(errno) << endl;
            continue;
        }
    }
    if (close(server_fd)){
        cerr << "Failed to Close Server Socket" << strerror(errno) << endl;
    }
    return 0;
}
