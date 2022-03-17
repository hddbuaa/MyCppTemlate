set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE PROJECT_SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE DRIVERS_SRCS ${PROJECT_SOURCE_DIR}/src/drivers/*.cpp)
file(GLOB_RECURSE LIBS_SRCS ${PROJECT_SOURCE_DIR}/src/libs/*.cpp)
file(GLOB_RECURSE MODULES_SRCS ${PROJECT_SOURCE_DIR}/src/modules/*.cpp)

set(MAIN_DIR ${PROJECT_SOURCE_DIR}/src/main)
set(TOOLS_DIR ${PROJECT_SOURCE_DIR}/src/tools)

set(EXTERNAL_LIB_DIR ${PROJECT_SOURCE_DIR}/external_lib)
set(DRIVERS_DIR ${PROJECT_SOURCE_DIR}/src/drivers)
set(LIBS_DIR ${PROJECT_SOURCE_DIR}/src/libs)
set(MODULES_DIR ${PROJECT_SOURCE_DIR}/src/modules)

find_package(spdlog)
find_package(yaml-cpp)
find_package(osqp REQUIRED)
find_package(OsqpEigen REQUIRED)

link_directories(${EXTERNAL_LIB_DIR})

include_directories("/usr/local/include/eigen3/")
include_directories(${DRIVERS_DIR} ${LIBS_DIR} ${MODULES_DIR} ${EXTERNAL_LIB_DIR})

add_executable(MyCppTemplate ${MAIN_DIR}/main.cpp
    ${DRIVERS_SRCS}
    ${LIBS_SRCS}
    ${MODULES_SRCS}
)

target_link_libraries(MyCppTemplate PRIVATE
    spdlog::spdlog
    yaml-cpp
    osqp::osqp
    OsqpEigen::OsqpEigen
)
