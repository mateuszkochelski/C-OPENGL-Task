#include "TrianglesMoving.h"
void draw_triangles(const triangle& t1, const triangle& t2)
{
    if (isColliding(t1, t2))
        glColor3f(1, 0, 0);
    else
        glColor3f(1, 1, 1);

    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);

    glVertex2f(t1.points[0].x, t1.points[0].y);
    glVertex2f(t1.points[1].x, t1.points[1].y);
    glVertex2f(t1.points[2].x, t1.points[2].y);

    glVertex2f(t2.points[0].x, t2.points[0].y);
    glVertex2f(t2.points[1].x, t2.points[1].y);
    glVertex2f(t2.points[2].x, t2.points[2].y);
    glEnd();
}

void move_triangle(triangle& t1, const vec2& direction)
{
    for (int i{}; i < 3; ++i)
    {
        t1.points[i].x += direction.x;
        t1.points[i].y += direction.y;
    }
}
void rotate_triangle(triangle& t1, GLdouble angle)
{
    const auto cosinus{ cos(angle) };
    const auto sinus{ sin(angle) };
    const auto center_x{ (t1.points[0].x + t1.points[1].x + t1.points[2].x) / 3.0 };
    const auto center_y{ (t1.points[0].y + t1.points[1].y + t1.points[2].y) / 3.0 };

    for (int i{}; i < 3; ++i)
    {
        const auto temp{ t1.points[i] };
        t1.points[i].x = center_x + (temp.x - center_x) * cosinus - sinus * (temp.y - center_y);
        t1.points[i].y = center_y + (temp.x - center_x) * sinus + cosinus * (temp.y - center_y);
    }
}
void navigate_triangle(GLFWwindow* window, triangle& t1)
{
    vec2 moveVector{ 0,0 };
    GLdouble angle{};
    if (glfwGetKey(window, GLFW_KEY_W))
        moveVector.y += 0.0005;
    if (glfwGetKey(window, GLFW_KEY_A))
        moveVector.x -= 0.0005;
    if (glfwGetKey(window, GLFW_KEY_S))
        moveVector.y -= 0.0005;
    if (glfwGetKey(window, GLFW_KEY_D))
        moveVector.x += 0.0005;
    if (glfwGetKey(window, GLFW_KEY_LEFT))
        angle += M_PI / 3000;
    if (glfwGetKey(window, GLFW_KEY_RIGHT))
        angle -= M_PI / 3000;
    move_triangle(t1, moveVector);
    rotate_triangle(t1, angle);
}