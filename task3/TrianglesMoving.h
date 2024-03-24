#include "glfw-3.4/include/GLFW/glfw3.h"
#include "CollisionDetection.h"
void draw_triangles(const triangle& t1, const triangle& t2);

void move_triangle(triangle& t1, const vec2& direction);

void rotate_triangle(triangle& t1, GLdouble angle);

void navigate_triangle(GLFWwindow* window, triangle& t1);
