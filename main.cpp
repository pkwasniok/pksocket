#include <iostream>
#include "src/pksocket.hpp"

using namespace std;

int main()
{
    Socket socket("0.0.0.0", 5000, true);

    while(true)
    {
        socket.acceptConnection();
    }

    return 0;
}