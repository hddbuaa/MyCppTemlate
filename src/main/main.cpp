# include <iostream>

# include <fstream>
# include <iomanip>
# include "spdlog/spdlog.h"
# include "yaml-cpp/yaml.h"

# include "driver_test.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";
    DriverTest driverTest;
    driverTest.Output();

    spdlog::info("Welcome to spdlog!");
    SPDLOG_INFO("Welcome to spdlog!");
    //SPDLOG_DEBUG(...)
    //SPDLOG_INFO(...)
    //SPDLOG_WARN(...)
    //SPDLOG_ERROR(...)
    //SPDLOG_CRITICAL(...)

    YAML::Node ppmRangeYaml;
    std::ofstream fout("../config/null.yaml");
    fout << ppmRangeYaml;
}
