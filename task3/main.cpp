#include "TrianglesMoving.h"



int main()
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(1080, 1080, "CollisionDetection", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    triangle t1{ {vec2{0, 0}, {0,0.7}, {0.7, 0}} };
    triangle t2{ {vec2{0.5, 0.1}, {0.8, 0.8}, {0.1, 0.1}} };

    glfwMakeContextCurrent(window);
    
    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL))
            navigate_triangle(window, t1);
        else if (glfwGetKey(window, GLFW_KEY_LEFT_ALT))
            navigate_triangle(window, t2);
        draw_triangles(t1, t2);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}