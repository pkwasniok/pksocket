#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "pksocket.hpp"

using namespace std;

void Socket::init(string host, int port)
{
    this->host = host;
    this->port = port;

    // Create socket
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    this->sockfd;

    // Bind socket
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &address.sin_addr);
    bind(this->sockfd, (struct sockaddr *) &address, sizeof(address));
}

Socket::Socket(string host, int port)
{
    // Initialize socket
    init(host, port);
}

Socket::Socket(string host, int port, bool server_mode)
{
    // Initialize socket
    init(host, port);

    // Turn socket into server mode (listen)
    if(server_mode)
        listen(this->sockfd, LISTEN_QUEUE_MAX_LENGTH);
}

Socket Socket::acceptConnection()
{
    sockaddr_in connection_address;
    int connection_address_len = sizeof(connection_address);
    int conn_sockfd = accept(this->sockfd, (struct sockaddr *) &connection_address, (socklen_t *) &connection_address_len);
    cout << conn_sockfd << endl;
}

string Socket::recvStr()
{
    // Receive data from 
    char buff[BUFFER_SIZE];
    recv(this->sockfd, &buff, sizeof(buff), 0);

    // Convert data to string
    string data = buff;

    return data;
}