#pragma once
#include <string>

class CLI
{
public:
    CLI();
    ~CLI();

    void start();

private:
    void handleCommand(const std::string &cmd);
    void printHelp();
};
