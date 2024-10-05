//
// Created by amucz0 on 9/27/24.
//

#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <csignal>
#include <unordered_map>
#include "../include/network.h"
using namespace std;

std::pair<int, unordered_map<string, string>> startSever(const char *ipAddress, int port){
    int server_fd;
    struct sockaddr_in server_addr{};

    unordered_map<string,string> map;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0){
        cerr << "Failed to Create Socket: " << strerror(errno) << endl;
        return {-1, {}};
    }

    int reuse = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0){
        cerr << "SO_REUSEADDR failed: " << strerror(errno) <<endl;
        return {-1, {}};
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, (const char *) ipAddress, &server_addr.sin_addr) <= 0){
        cerr << "Error Occurred in the inet_pton operation" << strerror(errno) << endl;
        return {-1, {}};
    }

    if (bind(server_fd, (struct sockaddr * ) &server_addr, sizeof(server_addr)) != 0){
        cerr << "Bind Failed: " << strerror(errno) << endl;
        close(server_fd);
        return {-1, {}};
    }


    if (listen(server_fd, SOMAXCONN) < 0){
        cerr << "Listening Failed: " << strerror(errno) << endl;
        close(server_fd);
        return {-1, {}};;
    }
    cout << "Server Established" << endl;
    return {server_fd, map};
}

int handleClient(int server_fd){
    int client_fd;
    struct sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);

    client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len);
    if (client_fd < 0){
        cerr << "Failed to Accept Connection: " << strerror(errno) <<endl;
        close(server_fd);
        return -1;
    }
    cout << "Client Connected!" << endl;

    // TO-DO: Establish Protocols for the server
    char buffer[1024] = {0};

    while (true){

        ssize_t bytes_received = recv(client_fd, &buffer, sizeof(buffer) - 1, 0);

        if (bytes_received < 0){
            cerr << "Error Occurred in recv()" << strerror(errno) << endl;
            break;
        } else if (bytes_received == 0){
            cout << "Client disconnected." << endl;
            break;
        }

        buffer[bytes_received] = '\0';

        if (strcmp(buffer, "WAKE") == 0){

        }

        if (strcmp(buffer, "CONNECT") == 0){

        }

        if(strcmp(buffer, "WAC") == 0){

        }

        // test code to see if server responds
        send(client_fd, buffer, sizeof(buffer),0);
    }
    return client_fd;
}

