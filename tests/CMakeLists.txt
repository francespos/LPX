enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(Vector2Test unit/math/Vector2Test.cpp)
target_link_libraries(Vector2Test PRIVATE GTest::gtest_main lpx)
gtest_discover_tests(Vector2Test)

add_executable(Matrix2Test unit/math/Matrix2Test.cpp)
target_link_libraries(Matrix2Test PRIVATE GTest::gtest_main lpx)
gtest_discover_tests(Matrix2Test)