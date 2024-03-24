cmake_minimum_required(VERSION 3.14)

project(CollisionDetection VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(CollisionDetection_test)
add_subdirectory(glfw-3.4)
add_executable(${PROJECT_NAME} CollisionDetection.cpp "CollisionDetection.h" "main.cpp" "TrianglesMoving.cpp" "TrianglesMoving.h")
target_link_libraries(CollisionDetection glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(CollisionDetection OpenGL::GL)





