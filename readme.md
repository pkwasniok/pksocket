# PKsocket
PK socket is C++ library for easy sockets handling.

## Reference
### `Socket` object
Socket object i basic psocket type, used for creating, connecting, sending and receiving data through socket.

### `Socket()`
Socket constructor is used for creating new socket object. There are few constructors available:
 - `Socket()` - creates empty socket
 - `Socket(string host, int port)` - creates client socket and connects it to server on host and port
 - `Socket(string host, int port, bool server_mode)` - when server_mode is true, socket will be created in server mode (socket will be listening for connections)
 - `Socket(int sockfd, string host, int port)` - create new socket object based on socket file descriptor, host and port

## About
Made by: pkwasniok