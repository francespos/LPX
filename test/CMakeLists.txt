find_package(GTest REQUIRED)

add_executable(Test Test.cpp)
target_link_libraries(Test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Test)