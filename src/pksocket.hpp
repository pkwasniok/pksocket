#include <iostream>

using namespace std;

#define LISTEN_QUEUE_MAX_LENGTH 10
#define BUFFER_SIZE 1024

class Socket
{
    public:
        Socket(string host, int port);
        Socket(string host, int port, bool server_mode);
        Socket acceptConnection();
        string recvStr();

    private:
        int sockfd;
        string host;
        int port;
        void init(string host, int port);
};