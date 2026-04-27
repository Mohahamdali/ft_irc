#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include "Command.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <exception>
#include <vector>
#include <sstream>

class Parser
{
public:
    static Command parse(const std::string& msg);
};

#endif