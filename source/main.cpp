#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "terminal_colors.h"


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // create window object
    GLFWwindow* window = glfwCreateWindow(500, 500, "Active Window", NULL, NULL);

    if (window == NULL)
    {
        std::cout<< "\033[1;31mFailed to create GLFW window\033[0m" <<std::endl;
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << LIGHT_RED << "Failed to initialize GLAD" << RESET << std::endl;
        return -1;
    }

}
