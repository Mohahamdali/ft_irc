#ifndef CLIENT_HPP
#define CLIENT_HPP



#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <exception>
#include <vector>
#include <sstream>

class Client
{
    private:
        int fd;
        std::string buffer;
        std::string nickname;
    public:
        Client(int fd);
        int get_fd ();
        void appendBuffer(const std::string& data);
        bool valid_mess ();
        std::string getNick() const;
        void setNick(const std::string& nick);
        std::vector<std::string> ExtractMessage();
};

#endif