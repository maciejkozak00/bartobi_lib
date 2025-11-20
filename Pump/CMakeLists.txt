add_library(pump
    Pump.cpp
    # Add other Pump source files here
)

target_include_directories(pump PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(pump PUBLIC utils)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test_Pump tests/test_Pump.cpp)
target_link_libraries(test_Pump pump GTest::gtest_main utils)
gtest_discover_tests(test_Pump)
