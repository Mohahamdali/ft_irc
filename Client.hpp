#ifndef CLIENT_HPP
#define CLIENT_HPP



#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <exception>

class Client
{
    private:
        int fd;
        std::string buffer;
    public:
        Client(int fd);
        int get_fd ();
        void appendBuffer(const std::string& data);
        bool valid_mess ();
        std::string getMessage();
};


#endif