/* 
 * File:   main.cpp
 * Author: Vicky.H
 * Email:  eclipser@163.com
 */
#include "../game-engine/engine-socket/ServerSocket.h"
#include "../game-engine/engine-thread/Thread.h"
#include <iostream>


#define SERVER_PORT 4777

class ClientRead : public Thread {
private :
    BOOL isRunning;
    Socket* socket;
public:
    ClientRead(Socket* socket){
        ::Thread();
        this->socket = socket;
        this->isRunning = true;
    }
    
    VOID run() {
        char buf[1024] = {0};
        while (this->isRunning) {
            UINT received = socket->receive(buf, sizeof(buf));
            std::cout << "buf: " << buf << std::endl;
        }
    }
    
    VOID stop() {
        this->isRunning = false;
    }
};

/*
 * 
 */
int main(void) {

    ServerSocket* serverSocket = new ServerSocket(SERVER_PORT);
    serverSocket->setNonBlocking(true);
    serverSocket->setSendBufferSize(1024);
    serverSocket->setReceiveBufferSize(1024);
    for (;;) {
        Socket* socket = new Socket();
        if (serverSocket->accept(socket)) {
            //            const char* msg = "hello world !";
            //            socket->send(msg, strlen(msg));
            ClientRead* client = new ClientRead(socket);
            client->start();
        }
    }

    return 0;
}
