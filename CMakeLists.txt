
cmake_minimum_required(VERSION 3.30)
project(C__)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
CACHE STRING "Vcpkg toolchain file")

find_package(unofficial-mysql-connector-cpp CONFIG REQUIRED)

add_executable(C__ main.cpp
        header/LoggerAndLoggerFactory.h
        cpp/LoggerAndLoggerFactory.cpp
        header/Time.h
        cpp/Time.cpp
        header/FileLoggerAndFileLoggerFactory.h
        cpp/FileLoggerAndFileLoggerFactory.cpp
        header/DatabaseLoggerAndDatabaseLoggerFactory.h
        cpp/DatabaseLoggerAndDatabaseLoggerFactory.cpp)


target_link_libraries(C__ PRIVATE unofficial::mysql-connector-cpp::connector)
