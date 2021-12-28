#include <iostream>
#include <thread>
#include "src/pksocket.hpp"

using namespace std;

void handleReceive(Socket* socket)
{
    while(true)
    {
        string data = socket->receiveString();
        cout << data;
    }
}

int main()
{
    // Initialize socket
    Socket socket = Socket("192.168.1.105", 5000);

    // Handle receiving data
    thread t(handleReceive, &socket);

    while(true)
    {
        cout << "> ";
        string data;
        cin >> data;
        socket.sendString(data);
    }

    return 0;
}