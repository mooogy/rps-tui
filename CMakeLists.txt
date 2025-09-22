cmake_minimum_required(VERSION 4.0)
project(rps-tui VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include (FetchContent)

FetchContent_Declare (
  Boost
  URL https://github.com/boostorg/boost/releases/download/boost-1.89.0/boost-1.89.0-cmake.tar.gz
  URL_HASH SHA256=954a01219bf818c7fb850fa610c2c8c71a4fa28fa32a1900056bcb6ff58cf908
)
FetchContent_MakeAvailable(Boost)

set(BOOST_ENABLE_CMAKE ON)
set(BOOST_INCLUDE_LIBRARIES asio system)

add_library(boost INTERFACE)
target_link_libraries(boost INTERFACE
  Boost::asio
  Boost::system
)

target_compile_definitions(boost INTERFACE
  BOOST_ASIO_HEADER_ONLY
  BOOST_SYSTEM_HEADER_ONLY
)

add_executable(rps_client apps/rps_client.cpp)
target_link_libraries(rps_client PRIVATE boost)

add_executable(rps_server apps/rps_server.cpp)
target_link_libraries(rps_server PRIVATE boost)

