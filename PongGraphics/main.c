#include "include/GLFW/glfw3.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static GLFWwindow *window;
float ratio;

// Parameters for rhombus resize

int switcher = 0;
float resize = 0;

// Parameters for FPS

double previousTime = 0;
double currentTime = 0;
double previousSecond = 0;
int frameCount = 0;

// Current window framerate
int framerate = 120;

void Init_Window();
// Function to render window
void Render_FPS();
// Function to render one frame of window
void Render_Window();
void Destroy_Window();

// Rhombus draw function
void Rhombus();

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

    // Setting up the framerate
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) framerate = 30;
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) framerate = 60;
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) framerate = 90;
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) framerate = 120;
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) framerate = 150;
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) framerate = 180;

    Rhombus();

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

void Rhombus() {

  glColor3f(1, 1, 1);

  glBegin(GL_POLYGON);
  glVertex2d(-0.5 - resize, 0);
  glVertex2d(0, 0.5);
  glVertex2d(0.5 + resize, 0);
  glVertex2d(0, -0.5);
  glEnd();

  if (!switcher) {
    resize += 0.01;
  } else {
    resize -= 0.01;
  }
  if (resize >= 0.35) {
    switcher = 1;
  }
  if (resize <= -0.25) {
    switcher = 0;
  }
}