cmake_minimum_required(VERSION 4.2)
project(traylib)

add_library(${PROJECT_NAME}
	src/traylib.cpp
	src/logs.cpp
	src/keyInput.cpp
)

add_executable(tester test.cpp)

target_include_directories(tester PUBLIC src/include)
target_include_directories(${PROJECT_NAME} PUBLIC src/include)

target_link_libraries(tester ${PROJECT_NAME})
