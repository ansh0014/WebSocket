#include "../websocket/websocket_client.h"
#include <iostream>
#include <cassert>

void test_websocket_creation() {
    WebSocketClient client;
    assert(!client.isConnected());
    std::cout << " WebSocket creation test passed\n";
}

void test_websocket_basic_operations() {
    WebSocketClient client;
    
    // Test initial state
    assert(!client.isConnected());
    
    // Test close on unconnected client
    client.close();
    assert(!client.isConnected());
    
    std::cout << " WebSocket basic operations test passed\n";
}

void run_websocket_tests() {
    std::cout << "📡 WebSocket Tests:\n";
    test_websocket_creation();
    test_websocket_basic_operations();
    std::cout << "\n";
}