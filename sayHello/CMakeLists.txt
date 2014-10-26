#cmake for a library
cmake_minimum_required(VERSION 2.8)
project(SayHello)

set(PROJECT_SOURCES 
	sayHello.cpp
)

add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
install(TARGETS ${PROJECT_NAME} DESTINATION lib )