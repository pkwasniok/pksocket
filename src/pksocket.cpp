#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "../pksocket.hpp"

using namespace std;

// Constructors

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

Socket::Socket()
{
    this->sockfd = -1;
}

Socket::Socket(string host, int port)
{
    // Initialize socket
    init(host, port);

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &address.sin_addr);
    connect(this->sockfd, (struct sockaddr *) &address, sizeof(address));
}

Socket::Socket(string host, int port, bool server_mode)
{
    // Initialize socket
    init(host, port);

    // Turn socket into server mode (listen)
    if(server_mode)
        listen(this->sockfd, LISTEN_QUEUE_MAX_LENGTH);
}

Socket::Socket(int sockfd, string host, int port)
{
    this->sockfd = sockfd;
    this->host = host;
    this->port = port;
}

// Methods

Socket Socket::acceptConnection()
{
    // Accept new connection
    sockaddr_in connection_address;
    int connection_address_len = sizeof(connection_address);
    int connection_sockfd = accept(this->sockfd, (struct sockaddr *) &connection_address, (socklen_t *) &connection_address_len);

    // Decode connection host and port
    char ip[14];
    inet_ntop(AF_INET, &connection_address.sin_addr,ip,sizeof(ip));
    int port = ntohs(connection_address.sin_port);

    // Return connection socket
    return Socket(connection_sockfd, ip, port);
}

string Socket::receiveString()
{
    // Receive data from 
    char buff[BUFFER_SIZE];
    memset(buff, 0, BUFFER_SIZE); // Clear buffor
    recv(this->sockfd, &buff, sizeof(buff), 0);

    // Convert data to string
    string data = buff;

    return data;
}

void Socket::sendString(string data)
{
    write(this->sockfd, data.c_str(), data.length());
}

void Socket::close()
{
    if(this->sockfd != -1)
    {
        shutdown(this->sockfd, SHUT_RDWR);
        this->sockfd = -1;
    }
}

// Getters/setters

string Socket::getHost()
{
    return this->host;
}

int Socket::getPort()
{
    return this->port;
}