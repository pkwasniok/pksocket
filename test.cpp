#include <iostream>
#include "pksocket.hpp"

using namespace std;

int main()
{
    Socket socket = Socket("192.168.1.105", 5000, true);

    cout << "Hello world!" << endl;
    return 0;
}