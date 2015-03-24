//
//  SocketManager.cpp
//  X
//
//  Created by leo on 15/3/17.
//
//

#include "SocketManager.h"

#include "base/ccMacros.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

static SocketManager* s_SharedSocketManger = nullptr;

SocketManager* SocketManager::getInstance()
{
    if (! s_SharedSocketManger) {
        
        s_SharedSocketManger = new SocketManager();
        CCASSERT(s_SharedSocketManger, "FATAL: Not enough memory");
        s_SharedSocketManger->init();
    }
    
    return s_SharedSocketManger;

}

bool SocketManager::init()
{
    
    
    return true;
}

int SocketManager::connectToServerTest()
{
    struct sockaddr_in stSocketAddr;
    int Res;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (-1 == SocketFD) {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }
    
    memset(&stSocketAddr, 0, sizeof(struct sockaddr_in));
    
    stSocketAddr.sin_family = AF_INET;
    stSocketAddr.sin_port = htons(1101);
    Res = inet_pton(AF_INET, "127.0.0.1", &stSocketAddr.sin_addr);
    
    if (0>Res) {
        perror("error: first parameter is not a valid address family");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }
    
    if (-1==connect(SocketFD, (const struct sockaddr*)&stSocketAddr, sizeof(struct sockaddr_in))) {
        perror("connect failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("connected successful!");
    }
    
    shutdown(SocketFD, SHUT_RDWR);
    close(SocketFD);
    return 0;
}