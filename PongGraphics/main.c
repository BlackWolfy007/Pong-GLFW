#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef WINDOWS_PONG_VISUAL_STUDIO
#include <GLFW/glfw3.h>
#endif  // WINDOWS_PONG_VISUAL_STUDIO
#ifdef WINDOWS_PONG_GCC
#include "include/GLFW/glfw3.h"
#endif  // WINDOWS_PONG_GCC

//#include "linmath.h"
#include "Draw_Text.h"
#include "Game.h"
#include "Game_Draw.h"

//float ratio;

void Init_Window();
void Render_Window();
void Destroy_Window();

static GLFWwindow* window;

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
  T_Ball Ball = {0, 0, 0.01, 0.001, 0.03, default_speed, {0.95, 0.95, 0.95}};
  T_Racket Left_Rack = {-0.92, 0, 0.03, 0.20, {1, 1, 1}},
           Right_Rack = {0.92, 0, 0.03, 0.20, {1, 1, 1}};
  T_Score Score = {0, 0};
  float dy_change = 0.007;
  int unlock_main_menu = 0, unlock_game = 0;
  int count = 0;
    while (!glfwWindowShouldClose(window)) {
      
        // Setup view
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
          unlock_main_menu = 1;
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
          glfwSetWindowShouldClose(window, 1);

        if (!unlock_main_menu)
          Draw_Pong_Logo();
        else {
          if (Score.Player_1 < final_score && Score.Player_2 < final_score) {
            // Key Check
            if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
              unlock_game = 1;
            
            if (unlock_game) {
              Keystroke(window, &Ball, &Left_Rack, &Right_Rack, dy_change);

              Ball_Collide(&Ball, &Left_Rack, &Right_Rack, &Score);
              Increase_Speedmult(&Ball);
            }

            Draw_Score(Score);
            Draw_Racket(Left_Rack);
            Draw_Racket(Right_Rack);
            Draw_Ball(Ball);
            if ((count % 100) == 0)
              printf("speedmult: %f, current_ball->dx: %f, current_ball->dy: %f\n",
                     Ball.speedmult, Ball.dx*Ball.speedmult, Ball.dy*Ball.speedmult);
            count++;
            if (count > 9999) count = 0;
          } else {
            if (Score.Player_1 >= final_score) {
              Draw_P1W();
            } else {
              Draw_P2W();
            }
          }
        }
        //Draw_Char_Test();
        //Draw_P1W();
        //Draw_P2W();
        //Draw_Pong_Logo();
        
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

    glfwSwapInterval(1);
}