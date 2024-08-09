CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
project(ggg)
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML/")

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC C:/SFML-2.6.1/include/)
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC C:/SFML-2.6.1/lib/)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC sfml-graphics-s sfml-window-s sfml-system-s)