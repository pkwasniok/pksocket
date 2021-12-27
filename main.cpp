#include <iostream>
#include "src/pksocket.hpp"

using namespace std;

int main()
{
    Socket socket = Socket("192.168.1.105", 5000, true);

    while(true)
    {
        Socket nodeSocket = socket.acceptConnection();
        cout << nodeSocket.getHost() << ":" << nodeSocket.getPort() << ">" << nodeSocket.receiveString() << endl;
        nodeSocket.close();
    }

    return 0;
}