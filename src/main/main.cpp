# include <iostream>

# include "spdlog/spdlog.h"

# include "driver_test.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";
    DriverTest driverTest;
    driverTest.Output();

    // spdlog::info("Welcome to spdlog!");
    SPDLOG_INFO("Welcome to spdlog!");
    //SPDLOG_DEBUG(...)
    //SPDLOG_INFO(...)
    //SPDLOG_WARN(...)
    //SPDLOG_ERROR(...)
    //SPDLOG_CRITICAL(...)

}
