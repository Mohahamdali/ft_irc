#include "Client.hpp"


Client::Client(int fd_c) : fd(fd_c)
{
}

int Client::get_fd ()
{
    return fd;
}

void Client::appendBuffer(const std::string& data)
{
    buffer += data;
}
bool Client::valid_mess()
{

}

std::string Client::getMessage()
{

}