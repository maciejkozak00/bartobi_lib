add_library(bartender
    Drink.cpp
    DrinkBuilder.cpp
    Bartender.cpp
    # Add other Bartender source files here
)

target_link_libraries(bartender PUBLIC utils)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test_drink tests/test_drink.cpp)
target_link_libraries(test_drink bartender GTest::gtest_main utils)
gtest_discover_tests(test_drink)

add_executable(test_drinkBuilder tests/test_drinkBuilder.cpp)
target_link_libraries(test_drinkBuilder bartender GTest::gtest_main utils)
gtest_discover_tests(test_drinkBuilder)

add_executable(test_bartender tests/test_bartender.cpp)
target_link_libraries(test_bartender bartender GTest::gtest_main utils)
gtest_discover_tests(test_bartender)