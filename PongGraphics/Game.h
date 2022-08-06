#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLFW/glfw3.h>

typedef struct Color {
  float r;
  float g;
  float b;
} T_Color;

typedef struct Racket {
  float x;
  float y;
  float x_size;
  float y_size;
  T_Color color;
} T_Racket;

typedef struct Ball {
  float x;
  float y;
  float dx;
  float dy;
  float radius;
  float speedmult;
  T_Color color;
} T_Ball;

typedef struct Score {
  int Player_1;
  int Player_2;
} T_Score;

extern float ratio;

void Move_Racket(T_Racket* racket, float dy);
void Ball_Movement(T_Ball* ball);
void Increase_Player_1(T_Score* score);
void Increase_Player_2(T_Score* score);
void Reset_Ball(T_Ball* ball);
void Keystroke(GLFWwindow* window, T_Racket* Left_Rack, T_Racket* Right_Rack,
               float dy_change);