cmake_minimum_required(VERSION 4.2)
project(traylib)

add_library(Engine
	src/Engine/traylib.cpp
	src/Engine/Utils/logs.cpp
	src/Engine/Input/keyInput.cpp
	src/Engine/Graphics/renderer.cpp
	src/Engine/Graphics/ui.cpp
	src/Engine/Graphics/primitives.cpp
)

add_executable(Editor  src/Editor/editor.cpp)
add_executable(Runtime src/Runtime/runtime.cpp)

target_include_directories(Editor  PUBLIC src/include)
target_include_directories(Runtime PUBLIC src/include)

target_link_libraries(Editor Engine)
target_link_libraries(Runtime Engine)
