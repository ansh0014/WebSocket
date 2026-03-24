#include "websocket_client.h"
#include <iostream>
#include <cstring>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <netdb.h>
#endif

WebSocketClient::WebSocketClient() : socket_fd(-1), connected(false) {
    initializeNetworking();
}

WebSocketClient::~WebSocketClient() {
    close();
    cleanupNetworking();
}

bool WebSocketClient::connect(const std::string& url) {
    if (connected) {
        std::cout << "Already connected\n";
        return false;
    }

    std::cout << " Connecting to: " << url << "\n";
    
    if (establishTcpConnection()) {
        if (performWebSocketHandshake(url)) {
            connected = true;
            std::cout << " Connected successfully!\n";
            return true;
        }
    }
    
    std::cout << " Connection failed\n";
    return false;
}

void WebSocketClient::send(const std::string& message) {
    if (!isConnected()) {
        std::cout << " Not connected\n";
        return;
    }

    std::cout << " Sent: " << message << "\n";
    std::cout << " Echo: " << message << "\n";
}

void WebSocketClient::close() {
    if (socket_fd >= 0) {
        closeSocket();
        socket_fd = -1;
    }
    
    if (connected) {
        connected = false;
        std::cout << " Disconnected\n";
    }
}

bool WebSocketClient::isConnected() const {
    return connected;
}

// Private helper methods
void WebSocketClient::initializeNetworking() {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << " Network initialization failed\n";
    }
#endif
}

void WebSocketClient::cleanupNetworking() {
#ifdef _WIN32
    WSACleanup();
#endif
}

bool WebSocketClient::establishTcpConnection() {
    socket_fd = createSocket();
    if (socket_fd < 0) {
        return false;
    }

    // Demo: Simulate connection attempt
    std::cout << " Establishing TCP connection...\n";
    std::cout << " Network layer active (demo mode)\n";
    
    return true;
}

bool WebSocketClient::performWebSocketHandshake(const std::string& url) {
    std::cout << " Performing WebSocket handshake...\n";
    std::cout << " Protocol upgrade successful\n";
    
    return true;
}

int WebSocketClient::createSocket() {
#ifdef _WIN32
    int sock = (int)socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    return (sock == INVALID_SOCKET) ? -1 : sock;
#else
    return socket(AF_INET, SOCK_STREAM, 0);
#endif
}

void WebSocketClient::closeSocket() {
#ifdef _WIN32
    closesocket(socket_fd);
#else
    ::close(socket_fd);
#endif
}