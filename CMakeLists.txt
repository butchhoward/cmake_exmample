cmake_minimum_required(VERSION 3.0)

#enable testing, this enables the use of ctest
enable_testing()

#the test target runs ctest such that it suppresses the output from the actual test program
#this creates a 'check' target that passes the --output-on-failure flag to ctest so the original output can be seen
if (CMAKE_CONFIGURATION_TYPES)
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} 
        --force-new-ctest-process --output-on-failure 
        --build-config "$<CONFIGURATION>")
else()
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} 
        --force-new-ctest-process --output-on-failure)
endif()	

set(TOOLS_DIR "${CMAKE_SOURCE_DIR}/Tools")
#build gmock from a known source location. gmock must be built with the same compile flags as the project under test or bad things happen
set(GMOCK_DIR "${TOOLS_DIR}/gmock")
add_subdirectory( ${GMOCK_DIR} ${CMAKE_CURRENT_BINARY_DIR}/gmock)
include_directories(
	${GMOCK_DIR}/gtest/include
	${GMOCK_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

#add the libraries to build
add_subdirectory( sayHello )

#add the unit tests to build
add_subdirectory( _Tests/FooTest )
