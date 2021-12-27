#include <iostream>
#include <thread>
#include "src/pksocket.hpp"

using namespace std;

void handleReceive()
{
    cout << "test" << endl;
}

int main()
{
    // Initialize socket
    Socket socket = Socket("192.168.1.105", 33579);

    // Handle receiving data
    thread t(handleReceive);

    while(true)
    {
        string data;
        cin >> data;
        socket.sendString(data);
    }

    return 0;
}