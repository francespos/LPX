enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(Vector2Test unit/math/Vector2Test.cpp)
target_link_libraries(Vector2Test PRIVATE GTest::gtest_main lpx)
gtest_discover_tests(Vector2Test)