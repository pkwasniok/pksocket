#pragma once

#include <iostream>

using namespace std;

#define LISTEN_QUEUE_MAX_LENGTH 10
#define BUFFER_SIZE 1024

class Socket
{
    public:
        // Constructors
        Socket();
        Socket(string host, int port);
        Socket(string host, int port, bool server_mode);
        Socket(int sockfd, string host, int port);

        // Methods
        Socket acceptConnection();
        string receiveString();
        void sendString(string data);
        void close();

        // Getters/setters
        string getHost();
        int getPort();

    private:
        int sockfd;
        string host;
        int port;
        int init(string host, int port);
};