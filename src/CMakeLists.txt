set(LPX_SRC math/Vector2.cpp math/Matrix2.cpp math/Rotation.cpp math/Transform.cpp)

add_library(lpx STATIC ${LPX_SRC})

target_link_libraries(lpx PUBLIC m)
target_include_directories(lpx PUBLIC ${CMAKE_SOURCE_DIR}/include)