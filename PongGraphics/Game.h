#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef WINDOWS_PONG
#include <GLFW/glfw3.h>
#endif  // WINDOWS_PONG
#ifdef MAC_OS_PONG
#include <include/GLFW/glfw3.h>
#endif  // MAC_OS_PONG


typedef struct Object_Color {
  float r;
  float g;
  float b;
} O_Color;

typedef struct Racket {
  float x;
  float y;
  float x_size;
  float y_size;
  O_Color color;
} T_Racket;

typedef struct Ball {
  float x;
  float y;
  float dx;
  float dy;
  float radius;
  float speedmult;
  O_Color color;
} T_Ball;

typedef struct Score {
  int Player_1;
  int Player_2;
} T_Score;

extern float ratio;

extern const int final_score;

extern const float DEG2RAD;

void Move_Racket(T_Racket* racket, float dy);
int Racket_Collide(T_Ball* ball, T_Racket* Left_Rack, T_Racket* Right_Rack);
int Border_X_Left_Collide(T_Ball* ball);
int Border_X_Right_Collide(T_Ball* ball);
int Border_Y_Up_Collide(T_Ball* ball);
int Border_Y_Down_Collide(T_Ball* ball);


int Border_X_Collide(T_Ball* ball);
int Border_Y_Collide(T_Ball* ball);
void Ball_Collide(T_Ball* ball, T_Racket* Left_Rack, T_Racket* Right_Rack,
                  T_Score* Score);
void Increase_Player_1(T_Score* score);
void Increase_Player_2(T_Score* score);
void Reset_Ball(T_Ball* ball);
void Reset_racket(T_Racket* racket);
void Reset_Round(T_Ball* ball, T_Racket* Left_Rack, T_Racket* Right_Rack);
void Keystroke(GLFWwindow* window, T_Ball* ball, T_Racket* Left_Rack,
               T_Racket* Right_Rack, float dy_change);