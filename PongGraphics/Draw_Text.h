#pragma once

#ifdef WINDOWS_PONG_VISUAL_STUDIO
#include <GLFW/glfw3.h>
#endif  // WINDOWS_PONG_VISUAL_STUDIO
#ifdef WINDOWS_PONG_GCC
#include "include/GLFW/glfw3.h"
#endif  // WINDOWS_PONG_GCC
#ifdef MAC_OS_PONG
#include "include/GLFW/glfw3.h"
#endif  // MAC_OS_PONG

typedef struct Text_Color {
  float r;
  float g;
  float b;
} T_Color;

static float size = 1;
static float grid_coeff = 0.04444444444;
extern float ratio;
extern T_Color text_color;

void Set_Text_Color(float r, float g, float b);

// Draws a pixel polygon
void Draw_Pixel(float x, float y);

// Draws inputted num (0<=num<=9)
void Draw_Num(int num, float x, float y);

// Draws inputted letter ('A'-'Z','a'-'z')
void Draw_Letter(char character, float x, float y);

// Nums

void Draw_0(float x, float y);
void Draw_1(float x, float y);
void Draw_2(float x, float y);
void Draw_3(float x, float y);
void Draw_4(float x, float y);
void Draw_5(float x, float y);
void Draw_6(float x, float y);
void Draw_7(float x, float y);
void Draw_8(float x, float y);
void Draw_9(float x, float y);

// Letters

void Draw_A(float x, float y);
void Draw_B(float x, float y);
void Draw_C(float x, float y);
void Draw_D(float x, float y);
void Draw_E(float x, float y);
void Draw_F(float x, float y);
void Draw_G(float x, float y);
void Draw_H(float x, float y);
void Draw_I(float x, float y);
void Draw_J(float x, float y);
void Draw_K(float x, float y);
void Draw_L(float x, float y);
void Draw_M(float x, float y);
void Draw_N(float x, float y);
void Draw_O(float x, float y);
void Draw_P(float x, float y);
void Draw_Q(float x, float y);
void Draw_R(float x, float y);
void Draw_S(float x, float y);
void Draw_T(float x, float y);
void Draw_U(float x, float y);
void Draw_V(float x, float y);
void Draw_W(float x, float y);
void Draw_X(float x, float y);
void Draw_Y(float x, float y);
void Draw_Z(float x, float y);

// Chars

void Draw_Colon(float x, float y);
void Draw_Exclamination(float x, float y);

// Test function to check if letters are shows on screen correctly
void Draw_Char_Test();

// Draws "P1 WON!"
void Draw_P1W();
// Draws "P2 WON!"
void Draw_P2W();
// Draws "Pong"
void Draw_Pong_Logo();