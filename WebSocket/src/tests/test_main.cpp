#include <iostream>

extern void run_websocket_tests();
extern void run_cli_tests();

int main() {
    std::cout << " Running WebSocket Client Tests\n";
    std::cout << "================================\n\n";
    
    run_websocket_tests();
    run_cli_tests();
    
    std::cout << "\n All tests completed!\n";
    return 0;
}