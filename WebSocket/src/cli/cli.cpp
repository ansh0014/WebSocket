#include "cli.h"
#include "../websocket/websocket_client.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>

CLI::CLI() {
}

CLI::~CLI() {
}

void CLI::start() {
    WebSocketClient client;
    
    std::cout << " WebSocket Client Started\n";
    std::cout << "Type 'help' for available commands\n\n";
    
    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input.empty()) continue;
        
        // Parse command and arguments
        std::istringstream iss(input);
        std::string command;
        iss >> command;
        
        if (command == "quit" || command == "exit") {
            client.close();
            break;
        } else if (command == "help") {
            printHelp();
        } else if (command == "connect") {
            std::string url;
            iss >> url;  // Get the URL argument
            if (!url.empty()) {
                client.connect(url);
            } else {
                std::cout << "Usage: connect <url>\n";
                std::cout << "Example: connect ws://echo.websocket.events/.ws\n";
            }
        } else if (command == "close") {
            client.close();
        } else if (command == "status") {
            std::cout << "Status: " << (client.isConnected() ? "Connected ✅" : "Disconnected ❌") << "\n";
        } else if (command == "send") {
            // Get the rest of the input as the message
            std::string msg;
            std::getline(iss, msg);
            if (!msg.empty()) {
                // Remove leading space
                if (msg[0] == ' ') msg = msg.substr(1);
                client.send(msg);
            } else {
                std::cout << "Usage: send <message>\n";
            }
        } else {
            // If connected, treat as message to send
            if (client.isConnected()) {
                client.send(input);
            } else {
                std::cout << "Unknown command: '" << command << "'. Type 'help' for available commands.\n";
            }
        }
    }
    
    std::cout << " Goodbye!\n";
}

void CLI::printHelp() {
    std::cout << "\n Available commands:\n";
    std::cout << "  connect <url>    - Connect to WebSocket server\n";
    std::cout << "  send <message>   - Send message to server\n";
    std::cout << "  status           - Show connection status\n"; 
    std::cout << "  close            - Close connection\n";
    std::cout << "  help             - Show this help\n";
    std::cout << "  quit/exit        - Exit application\n";
    std::cout << "\n When connected, you can type messages directly!\n\n";
    std::cout << " Example servers to try:\n";
    std::cout << "  ws://echo.websocket.events/.ws\n";
    std::cout << "  ws://demos.kaazing.com/echo\n\n";
}
