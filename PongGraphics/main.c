#include "include/GLFW/glfw3.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static GLFWwindow *window;
float ratio;

double previousTime = 0;
double currentTime = 0;
int frameCount = 0;

void Init_Window();
void Render_Window();
void Destroy_Window();


int main(void) {
  Init_Window();
  Render_Window();
  Destroy_Window();

  return 0;
}

void Destroy_Window() {
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}

void Render_Window() {
  previousTime = glfwGetTime();
  frameCount = 0;

  while (!glfwWindowShouldClose(window)) {
    // Setup view
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, 1);

    // Measure speed
    currentTime = glfwGetTime();
    if (currentTime - previousTime >= 1.0 / 60) {
      frameCount++;
      // If a second has passed.
      if (currentTime - previousTime >= 1.0) {
        // Display the frame count here any way you want.
        printf("\nFPS: %d\n", frameCount);
        frameCount = 0;
        previousTime = currentTime;
      }

      
      
    }
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void Init_Window() {
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  window = glfwCreateWindow(1024, 384, "Pong", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window);

  glfwSwapInterval(0);
}

