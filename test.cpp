#include <iostream>
#include "pksocket.hpp"

using namespace std;

int main()
{
    try{
        Socket socket = Socket("0.0.0.0", 2137, true);
    }
    catch(exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }

    cout << "Created socket!" << endl;


    while(true);

    return 0;
}