#include <iostream>
#include "src/pksocket.hpp"

using namespace std;

int main()
{
    Socket socket = Socket("192.168.1.105", 33579);
    socket.sendString("{\"type\":}");
    socket.close();

    return 0;
}