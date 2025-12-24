cmake_minimum_required(VERSION 3.15)

project(SmartMQ.broker VERSION 1.0 LANGUAGES CXX)

find_package(yaml-cpp REQUIRED)

add_executable(SmartMQ.broker src/main.cpp)

target_link_libraries(SmartMQ.broker yaml-cpp::yaml-cpp)