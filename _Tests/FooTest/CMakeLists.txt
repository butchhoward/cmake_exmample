#a sample cmakelists.txt for a unit test

cmake_minimum_required(VERSION 2.8)
project(FooTest)

#the sources
set(PROJECT_SOURCES 
	testMain.cpp
	SayHelloTest.cpp
	)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME}
	SayHello
	gmock_main
)

#add the tests to the ctest list
add_test(${PROJECT_NAME}, ${PROJECT_NAME})
