#include "include/GLFW/glfw3.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static GLFWwindow *window;
float ratio;

double previousTime = 0;
double currentTime = 0;
double previousSecond = 0;
int frameCount = 0;

int framerate = 120;

void Init_Window();
void Render_FPS();
void Render_Window();
void Destroy_Window();


int main(void) {
  Init_Window();
  Render_FPS();
  Destroy_Window();

  return 0;
}

void Destroy_Window() {
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}

void Render_FPS() {
  previousSecond = previousTime = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
    currentTime = glfwGetTime();

      if (currentTime - previousTime >= 1.0 / framerate) {
        previousTime = currentTime;
        Render_Window();

        frameCount++;
      }

    if (currentTime - previousSecond >= 1.0) {
        
        printf("\nFPS: %d\n", frameCount);
        frameCount = 0;
        previousSecond = currentTime;
    }
      
      
      
    }
}

void Render_Window() {
  

  
    // Setup view
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window, 1);

    
    
      

      
      
    
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  
}



void Init_Window() {
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  window = glfwCreateWindow(1024, 384, "FPS Test", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window);

  glfwSwapInterval(0);
}

