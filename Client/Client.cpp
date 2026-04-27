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
    return buffer.find("\r\n") != std::string::npos;
}

std::vector<std::string> Client::ExtractMessage()
{
    std::vector<std::string> messages;
    if (buffer.empty())
        return messages;
    size_t pos ;
    while (( pos = buffer.find("\r\n")) != std::string::npos)
    {
        std::string message  = buffer.substr(0,pos);
        messages.push_back(message);
        buffer.erase(0,pos + 2);
    }
    return messages;
}

void Client::setNick(const std::string& nick)
{
    nickname = nick;
}

std::string Client::getNick() const
{
    return nickname;
}