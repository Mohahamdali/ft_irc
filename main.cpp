#include "Server.hpp"

int main (int argc, char **argv)
{
    if (argc != 3)
        return 1;
    int port = atoi(argv[1]);
    std::string password = argv[2];
    try
    {
        Server server(port,password);
        server.run();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
  
}