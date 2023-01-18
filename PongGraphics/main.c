#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include "Draw_Text.h"

void Game_Init();

//float ratio;



void Init_Window();
void Render_Window();
void Destroy_Window();

static GLFWwindow* window;



typedef struct Racket {
	float x;
	float y;
	float x_size;
	float y_size;
} T_Racket;

typedef struct Ball {
	float x;
	float y;
	float dx;
	float dy;
	float radius;
} T_Ball;

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

void DrawCircle(float r, float g, float b, float x, float y, float DEG2RAD, float radius, float ratio) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        glVertex2d((cos(DEG2RAD * i) * radius + x), (sin(DEG2RAD * i) * radius*ratio + y));
    }
    glEnd();
}

void Render_Window() {

    while (!glfwWindowShouldClose(window)) {
        // Setup view
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        //Draw_Nums_Test();
        //Draw_P1W();
        //Draw_P2W();
        Game_Init();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}



void Game_Init() {
    const float DEG2RAD = 3.14159 / 100;
    float radius = 0.03;

    float r = 1, g = 1, b = 1;
    float speedmult = 1;
    float increase = 5;
    float x = 0, y = 0, dx = 0.01 * speedmult, dy = 0.001 * speedmult;

    // Movement
    if ((x + dx < 1 - radius) && (x + dx > -1 + radius))
        x += dx;
    else {
        dx *= -1;
        if (dx < 0.8) speedmult *= increase;
    }
    if ((y + dy < (1 - radius * ratio)) && (y + dy > (-1 + radius * ratio))) {
        y += dy;
    }
    else {
        dy *= -1;
        if (dy < 0.8) speedmult *= increase;
    }
    if (speedmult > pow(increase, 3)) {
        if (dx < 0.8) dx *= 1.05;
        if (dy < 0.8) dy *= 1.05;
        speedmult = 1;
    }
    // Color
    //r = fmod(r + 0.001, 1);
    //g = fmod(g + 0.002, 1);
    //b = fmod(b + 0.003, 1);
    // Drawing
    DrawCircle(r, g, b, x, y, DEG2RAD, radius, ratio);
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

    glfwSwapInterval(1);
}