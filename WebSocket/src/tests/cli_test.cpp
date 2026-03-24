#include "../cli/cli.h"
#include <iostream>
#include <cassert>

void test_cli_creation() {
    CLI cli;
    std::cout << " CLI creation test passed\n";
}

void run_cli_tests() {
    std::cout << " CLI Tests:\n";
    test_cli_creation();
    std::cout << "\n";
}