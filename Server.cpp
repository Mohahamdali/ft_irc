#include "Server.hpp"


Server::Server(int pt, std::string pass) : port(pt) , password(pass)
{
}

void Server::initSocket ()
{
    server_fd =  socket(AF_INET,SOCK_STREAM,0);
    if (server_fd == -1)
        throw std::runtime_error("can't create socket\n");
}


void Server::bindSocket()
{
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_fd, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) == -1)
        throw std::runtime_error("can't bind socket to table network\n");
}

void Server::listenSocket ()
{
    if (listen(server_fd,SOMAXCONN))
        throw std::runtime_error("can't listen\n");
}

void Server::acceptClient()
{
    int fd_client = accept(server_fd,NULL,NULL);
    if (fd_client < 0)
        return ;
    clients.insert(std::make_pair(fd_client, Client(fd_client)));
}


void Server::init_Server()
{
    initSocket();
    bindSocket();
    listenSocket();
}

void Server::run()
{
    init_Server();
    while (true)
    {
        int max = server_fd;
        fd_set watch_table;
        FD_ZERO(&watch_table);
        FD_SET(server_fd,&watch_table);
        for (std::map<int, Client>::iterator it = clients.begin(); it != clients.end();++it)
        {
            FD_SET(it ->first,&watch_table);
            if (it ->first > max)
                max = it ->first;
        }
        int activity = select(max +1,&watch_table,NULL,NULL,NULL);
        if (activity < 0)
            continue;
        if(FD_ISSET(server_fd, &watch_table))
            acceptClient();
        int i  = 0;
        for (std::map<int,\
            Client>::iterator it = clients.begin();\
            it != clients.end();)
        {
            int fd = it ->first;
            if(FD_ISSET(fd,&watch_table))
            {
                char  buffer[1337];
                int check = recv(fd,buffer,sizeof(buffer),0);
                if(check > 0)
                {
                    std::string data(buffer,check);
                    std::cout << "Received: " << data << std::endl;
                    it->second.appendBuffer(data);
                }
                else
                {
                    close(fd);
                    it = clients.erase(it);
                    continue;
                }
            }
            ++it;
        }
    }
}