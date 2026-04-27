#include "Parser.hpp"

Command Parser::parse(const std::string &msg)
{
    Command cmd;
    std::stringstream ss(msg);
    ss >> cmd.name;
    std::string args;
    while (ss >> args)
    {
        cmd.args.push_back(args);
    }
    return cmd;
}