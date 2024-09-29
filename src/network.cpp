//
// Created by amucz0 on 9/27/24.
//

#include <netdb.h>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include "../include/network.h"

int startSever(const char *ipAddress, int port){
    int server_fd;
    struct sockaddr_in server_addr{};

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, (const char *) ipAddress, &server_addr.sin_addr) <= 0){
        cerr << "Error Occurred in the inet_pton operation" << strerror(errno) << endl;
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0){
        cerr << "Failed to Create Socket: " << strerror(errno) << endl;
        return 1;
    }

    if (bind(server_fd, (struct sockaddr * ) &server_addr, sizeof(server_addr)) != 0){
        cerr << "Bind Failed: " << strerror(errno) << endl;
        return 1;
    }

    return 0;
}
void stopServer(){

}