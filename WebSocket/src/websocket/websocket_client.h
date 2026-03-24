#pragma once

#include <string>

class WebSocketClient {
public:
    WebSocketClient();
    ~WebSocketClient();

    bool connect(const std::string& url);
    void send(const std::string& message);
    void close();
    bool isConnected() const;

private:
    // Private helper methods - these were missing!
    void initializeNetworking();
    void cleanupNetworking();
    bool establishTcpConnection();
    bool performWebSocketHandshake(const std::string& url);
    int createSocket();
    void closeSocket();

    int socket_fd;
    bool connected;
};