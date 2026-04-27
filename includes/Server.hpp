#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <exception>
#include "Client.hpp"
#include <map>
#include "Command.hpp"
#include "Parser.hpp"
#include <cstdlib>

class Server
{
    private:
        int server_fd;
        int port;
        std::string password;
        std::map<int, Client> clients;
    public:
        Server(int port, std::string password);
        void initSocket();
        void bindSocket();
        void listenSocket();
        void run();
        void init_Server();
        void acceptClient();
};

Command parser(const std::string &msg);
#endif