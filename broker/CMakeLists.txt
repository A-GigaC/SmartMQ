cmake_minimum_required(VERSION 4.0)

project(SmartMQ-broker VERSION 1.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)


find_package(yaml-cpp REQUIRED)

target_link_libraries(SmartMQ-broker yaml-cpp::yaml-cpp)