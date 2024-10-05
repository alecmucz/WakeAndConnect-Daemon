//
// Created by amucz0 on 9/27/24.
//

#ifndef WAKEANDCONNECT_NETWORK_H
#define WAKEANDCONNECT_NETWORK_H

#include <string>
using namespace std;
std::pair<int, unordered_map<string, string>> startSever(const char *ipAddress, int port);
int handleClient(int server_fd);

#endif //WAKEANDCONNECT_NETWORK_H
