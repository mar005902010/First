cmake_minimum_required(VERSION 3.27)
project(Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Game main.cpp
        Player.cpp
        Player.h
        Database.cpp
        Database.h
        HashedPassword.cpp
        HashedPassword.h
        Authentification.cpp
        Authentification.h
        Jobs.h
        Jobs.cpp)

target_include_directories(Game PRIVATE
        /usr/local/opt/mysql-connector-c++/include
)

target_link_directories(Game PRIVATE
        /usr/local/opt/mysql-connector-c++/lib
)
find_package(OpenSSL REQUIRED)

target_link_libraries(Game PRIVATE
        mysqlcppconnx
        OpenSSL::Crypto
)
