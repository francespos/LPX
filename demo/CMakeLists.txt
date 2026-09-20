add_executable(LpxDemo Main.cpp)
set_property(TARGET LpxDemo PROPERTY CXX_STANDARD 17)
target_link_libraries(LpxDemo PRIVATE lpx)