#include "logger.h"
#include <iostream>
#include <chrono>
#include <iomanip>

void Logger::log(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    
    std::cout << "[" << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S") 
              << "] " << message << std::endl;
}