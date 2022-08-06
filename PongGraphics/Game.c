#include "Game.h"

float ratio;

void Move_Racket(T_Racket* racket, float dy) { racket->y += dy; }

void Ball_Movement(T_Ball* ball) {
  if (ball->x + ball->dx < 1 - ball->radius &&
      ball->x + ball->dx > -1 + ball->radius)
    ball->x += ball->dx;
  else {
    ball->dx *= -1;
  }
  if (ball->y + ball->dy < 1 - ball->radius * ratio &&
      ball->y + ball->dy > -1 + ball->radius * ratio)
    ball->y += ball->dy;
  else {
    ball->dy *= -1;
  }
}

void Increase_Player_1(T_Score* score) { score->Player_1++; }

void Increase_Player_2(T_Score* score) { score->Player_2++; }

void Reset_Ball(T_Ball* ball) {
  ball->x = 0;
  ball->y = 0;
  ball->dx = 0.01;
  ball->dy = 0.001;
  ball->speedmult = 1;
}

void Keystroke(GLFWwindow* window, T_Racket* Left_Rack, T_Racket* Right_Rack,
               float dy_change) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    if (Left_Rack->y + dy_change < (1 - Left_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Left_Rack, dy_change);
  if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    if (Left_Rack->y - dy_change > (-1 + Left_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Left_Rack, -dy_change);
  if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    if (Right_Rack->y + dy_change <
        (1 - Right_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Right_Rack, dy_change);
  if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    if (Right_Rack->y - dy_change >
        (-1 + Right_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Right_Rack, -dy_change);
}