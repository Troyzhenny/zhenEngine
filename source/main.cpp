#define GLFW_INCLUDE_NONE

#include "terminal_colors.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>




void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main() {

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // create window object
  GLFWwindow *window = glfwCreateWindow(600, 800, "Active Window", NULL, NULL);

  // error checking glfw window
  if (window == NULL) {
    std::cout << "\033[1;31mFailed to create GLFW window\033[0m" << std::endl;
    glfwTerminate();

    return -1;
  }

  // build + compile shader program
  // vertex shader
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  // check for shader compile errors
  // fragment shader
  // check for shader compile errors
  // link shaders
  // check for shader linking errors

  float vertices[] = {
      -2.0f, -2.0, 0.0f,
      2.0f, -2.0f, 0.0f,
      0.0f, 2.0f, 0.0f
  };


  glfwMakeContextCurrent(window);

  // error checking glad
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << LIGHT_RED << "Failed to initialize GLAD" << RESET << std::endl;
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // render loop
  while (!glfwWindowShouldClose(window)) {
    processInput(window);
    glfwSwapBuffers(window);
    glfwPollEvents();
    glClearColor(1.0f, 0.682f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  glfwTerminate();
  return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}
