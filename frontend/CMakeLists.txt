cmake_minimum_required(VERSION 3.10)
project(ChessFrontend)

# Look for raylib on the system
find_package(raylib 5.0 REQUIRED)

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the found raylib package
target_link_libraries(${PROJECT_NAME} raylib)

add_custom_target(run
	COMMAND ChessFrontend 
	DEPENDS ChessFrontend 
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
