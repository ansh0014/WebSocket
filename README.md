# WebSocket Client (C++11)

A minimal, cross-platform WebSocket client implemented using modern C++11.
Implements the WebSocket handshake, frame encoding, and basic messaging
over a raw TCP socket. Includes an interactive CLI and GN/Ninja build setup.

------------------------------------------------------------
# Features
------------------------------------------------------------
- C++11 compliant codebase
- Manual HTTP → WebSocket upgrade handshake
- WebSocket text frame send/receive
- Cross-platform socket support (Windows / Linux)
- Simple interactive CLI (connect, send, close, status)
- Clean modular architecture
- GN + Ninja build configuration

------------------------------------------------------------
# Project Structure
------------------------------------------------------------
websocket-client/
    BUILD.gn
    gn/
        BUILDCONFIG.gn
        toolchain.gn
    src/
        main.cpp
        cli/
        websocket/
        utils/

------------------------------------------------------------
# Requirements
------------------------------------------------------------
- C++11-compatible compiler (MSVC, GCC, Clang)
- GN build system
- Ninja build tool
- Windows: link against ws2_32.lib

------------------------------------------------------------
# Build Using GN + Ninja
------------------------------------------------------------
# Generate build files
gn gen out/Default

# Debug build
gn gen out/Debug --args="is_debug=true"

# Compile
ninja -C out/Default
ninja -C out/Debug

# Run
./out/Default/websocket_client          # Linux
out\\Default\\websocket_client.exe      # Windows

------------------------------------------------------------
# Direct Compilation (Simple Method)
------------------------------------------------------------
# Windows (MinGW)
g++ -std=c++11 -o websocket_client.exe \
    src/main.cpp \
    src/cli/cli.cpp \
    src/websocket/websocket_client.cpp \
    src/utils/logger.cpp \
    -lws2_32

# Linux
g++ -std=c++11 -o websocket_client \
    src/main.cpp \
    src/cli/cli.cpp \
    src/websocket/websocket_client.cpp \
    src/utils/logger.cpp

# Run
./websocket_client            # Linux
websocket_client.exe          # Windows

------------------------------------------------------------
# CLI Usage
------------------------------------------------------------
connect <url>      # Connect to WebSocket server
send <message>     # Send text message
status             # Connection state
close              # Disconnect
help               # List available commands
exit               # Quit

# Example
connect ws://echo.websocket.events/.ws
send Hello
status
close

------------------------------------------------------------
# Test WebSocket Servers
------------------------------------------------------------
ws://echo.websocket.events/.ws
ws://demos.kaazing.com/echo

------------------------------------------------------------
# Technical Notes
------------------------------------------------------------
- Implements raw TCP sockets via platform APIs
- Performs HTTP Upgrade handshake manually
- Encodes/decodes WebSocket text frames
- No external networking libraries used
- Designed for educational and evaluation purposes


