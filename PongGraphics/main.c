// ===================================
// 
// GLFW
// 
// ===================================

#include "include/GLFW/glfw3.h"

// ===================================
//
// Standard libraries
//
// ===================================

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ===================================
//
// Structures declaration
// 
// ===================================

// -----------------------------------
// Color
// -----------------------------------

// Responsible for the text color: r - red color, g - green color, b - blue color
typedef struct Text_Color {
  float r;
  float g;
  float b;
} T_Color;

// Responsible for the object color: r - red color, g - green color, b - blue color
typedef struct Object_Color {
  float r;
  float g;
  float b;
} O_Color;

// -----------------------------------
// Object parameters
// -----------------------------------

// Responsible for the racket parameters: x - x coord, y - y coord, x_size - size by x coord, y_size - size by y coord, color - object color
typedef struct Racket {
  float x;
  float y;
  float x_size;
  float y_size;
  O_Color color;
} T_Racket;

// Responsible for the ball parameters: x - x coord, y - y coord, dx - x coord offset, dy - y coord offset, radius - ball radius, speedmult - ball speedmult, color - object color
typedef struct Ball {
  float x;
  float y;
  float dx;
  float dy;
  float radius;
  float speedmult;
  O_Color color;
} T_Ball;

// Responsible for the score table: Player_1 - Player 1 score, Player_2 - Player 2 score
typedef struct Score {
  int Player_1;
  int Player_2;
} T_Score;

// -----------------------------------
// Game parameters
// -----------------------------------

// Responsible for the menus of the game: options menu, main menu, gameplay
// process, game result
enum E_Game_Menus { OPTIONS = -1, MAIN_MENU, GAME, WIN };
typedef enum E_Game_Menus Game_Menu;

// ===================================
// 
// Global variables
// 
// ===================================

// -----------------------------------
// Windows parameters
// -----------------------------------

// Responsible for window parameters
static GLFWwindow *window;

// Responsible for the aspect ratio of the window
float ratio;

// -----------------------------------
// Framerate parameters
// -----------------------------------

// Responsible for the previous part of second
double previousTime = 0;

// Responsible for the current part of second
double currentTime = 0;

// Responsible for the previous second
double previousSecond = 0;

// Responsible for framerate indicator
int frameCount = 0;

// Responsible for the framerate lock
int framerate = 60;

// -----------------------------------
// Text parameters
// -----------------------------------

// Responsible for the size of the text
static float size = 1;

// Responsible for the grid size for the text
static float grid_coeff = 0.04444444444;

// Responsible for the text color
T_Color text_color = {1, 1, 1};

// Responsible for the number of points needed to win
const int final_score = 5;

// Scoreboard object
T_Score Score = {0, 0};

// -----------------------------------
// Ball parameters
// -----------------------------------

// Used when converting degrees to radians
const float DEG2RAD = 3.14159 / 180;

// Responsible for the default speed of the ball
const float default_speed = 0.07;

// Ball object
T_Ball Ball;

// -----------------------------------
// Racket parameters
// -----------------------------------

// Left racket object
T_Racket Left_Rack = {-0.92, 0, 0.03, 0.20, {1, 1, 1}};

// Right racket object
T_Racket Right_Rack = {0.92, 0, 0.03, 0.20, {1, 1, 1}};

// Racket speed
float dy_change = 0.007;

// -----------------------------------
// Game states parameters
// -----------------------------------

// Responsible for game start
int unlock_main_menu = 0;

// Responsible for pause before game start
int unlock_game = 0;

// Responsible for help disable
int hide_help = 0;

Game_Menu G_Menu = MAIN_MENU;

// ===================================
// 
// Text drawing functions
// 
// ===================================

// -----------------------------------
// Basic functions
// -----------------------------------

// Sets the color of the text in rgb format (input should be in range [0;1])
void Set_Text_Color(float r, float g, float b);

// Draws a pixel polygon
void Draw_Pixel(float x, float y);

// -----------------------------------
// Character decision functions
// -----------------------------------

// Draws inputted num (num belong to [0;9])
void Draw_Num(int num, float x, float y);

// Draws inputted letter ('A'-'Z','a'-'z')
void Draw_Letter(char character, float x, float y);

// -----------------------------------
// Digit rendering functions
// -----------------------------------

// Draws character '0'
void Draw_0(float x, float y);

// Draws character '1'
void Draw_1(float x, float y);

// Draws character '2'
void Draw_2(float x, float y);

// Draws character '3'
void Draw_3(float x, float y);

// Draws character '4'
void Draw_4(float x, float y);

// Draws character '5'
void Draw_5(float x, float y);

// Draws character '6'
void Draw_6(float x, float y);

// Draws character '7'
void Draw_7(float x, float y);

// Draws character '8'
void Draw_8(float x, float y);

// Draws character '9'
void Draw_9(float x, float y);

// -----------------------------------
// Letter rendering functions
// -----------------------------------

// Draws character 'A' or 'a'
void Draw_A(float x, float y);

// Draws character 'B' or 'b'
void Draw_B(float x, float y);

// Draws character 'C' or 'c'
void Draw_C(float x, float y);

// Draws character 'D' or 'd'
void Draw_D(float x, float y);

// Draws character 'E' or 'e'
void Draw_E(float x, float y);

// Draws character 'F' or 'f'
void Draw_F(float x, float y);

// Draws character 'G' or 'g'
void Draw_G(float x, float y);

// Draws character 'H' or 'h'
void Draw_H(float x, float y);

// Draws character 'I' or 'i'
void Draw_I(float x, float y);

// Draws character 'J' or 'j'
void Draw_J(float x, float y);

// Draws character 'K' or 'k'
void Draw_K(float x, float y);

// Draws character 'L' or 'l'
void Draw_L(float x, float y);

// Draws character 'M' or 'm'
void Draw_M(float x, float y);

// Draws character 'N' or 'n'
void Draw_N(float x, float y);

// Draws character 'O' or 'o'
void Draw_O(float x, float y);

// Draws character 'P' or 'p'
void Draw_P(float x, float y);

// Draws character 'Q' or 'q'
void Draw_Q(float x, float y);

// Draws character 'R' or 'r'
void Draw_R(float x, float y);

// Draws character 'S' or 's'
void Draw_S(float x, float y);

// Draws character 'T' or 't'
void Draw_T(float x, float y);

// Draws character 'U' or 'u'
void Draw_U(float x, float y);

// Draws character 'V' or 'v'
void Draw_V(float x, float y);

// Draws character 'W' or 'w'
void Draw_W(float x, float y);

// Draws character 'X' or 'x'
void Draw_X(float x, float y);

// Draws character 'Y' or 'y'
void Draw_Y(float x, float y);

// Draws character 'Z' or 'z'
void Draw_Z(float x, float y);

// -----------------------------------
// Characters rendering functions
// -----------------------------------

// Draws character ':'
void Draw_Colon(float x, float y);

// Draws character '!'
void Draw_Exclamination(float x, float y);

// -----------------------------------
// Rendering test
// -----------------------------------

// Test function to check if letters are shows on screen correctly
void Draw_Char_Test();

// -----------------------------------
// Text draw functions
// -----------------------------------

// Draws "P1 WON!"
void Draw_P1W();

// Draws "P2 WON!"
void Draw_P2W();

// Draws "Pong"
void Draw_Pong_Logo();

// Draws help for controls
void Draw_Help();

// Draws FPS
void Draw_FPS(int framerate);

// ===================================
//
// Game mechanics functions
//
// ===================================

// Sets the default parameters for the ball
void Ball_Init();

// Changes the position of the racket with an offset along the Y coordinate by the received value
void Move_Racket(T_Racket *racket, float dy);

// Collider of ball with racket
int Racket_Collide(T_Ball *ball, T_Racket *Left_Rack, T_Racket *Right_Rack);
int Border_X_Left_Collide(T_Ball *ball);
int Border_X_Right_Collide(T_Ball *ball);
int Border_Y_Up_Collide(T_Ball *ball);
int Border_Y_Down_Collide(T_Ball *ball);

int Border_X_Collide(T_Ball *ball);
int Border_Y_Collide(T_Ball *ball);
void Ball_Collide(T_Ball *ball, T_Racket *Left_Rack, T_Racket *Right_Rack,
                  T_Score *Score);

// Increases the score for Player 1 by 1
void Increase_Player_1(T_Score *score);

// Increases the score for Player 2 by 1
void Increase_Player_2(T_Score *score);

// Increases the speed multiplier for ball
void Increase_Speedmult(T_Ball *ball);

// Resets the ball parameters
void Reset_Ball(T_Ball *ball);

// Resets the racket parameters
void Reset_racket(T_Racket *racket);

// Resets the round
void Reset_Round(T_Ball *ball, T_Racket *Left_Rack, T_Racket *Right_Rack);

// Responsible for handling keys
void Keystroke(GLFWwindow *window, T_Ball *ball, T_Racket *Left_Rack,
               T_Racket *Right_Rack, float dy_change);

// ===================================
//
// Object drawing functions
//
// ===================================

// Draws the ball sprite
void Draw_Ball(T_Ball bll);

// Draws the rocket sprite
void Draw_Racket(T_Racket racket);

// Draws the score text
void Draw_Score(T_Score score);

// ===================================
//
// Window operation functions
//
// ===================================

// Responsible for the window initialization 
void Init_Window();

// Responsible for the window render process
void Render_FPS();

// Responsible for the one frame render process
void Render_Window();

// Responsible for the window destruction
void Destroy_Window();

// ===================================
//
// Program initialization function
//
// ===================================

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

void Render_Window() {
    // Setup view
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) G_Menu = GAME;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, 1);
    

    if (G_Menu == OPTIONS) {
      if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        G_Menu = MAIN_MENU;
      }

    }

    if (G_Menu == MAIN_MENU) {
      if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
        G_Menu = OPTIONS;
      }

      Draw_Pong_Logo();
    }
    if (G_Menu == GAME) {
      // Key Check
      if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) unlock_game = 1;
      if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) hide_help = 1;

      if (unlock_game) {
        Keystroke(window, &Ball, &Left_Rack, &Right_Rack, dy_change);

        Ball_Collide(&Ball, &Left_Rack, &Right_Rack, &Score);
        Increase_Speedmult(&Ball);
      }

      if (!hide_help) Draw_Help();
      Draw_Score(Score);
      Draw_Racket(Left_Rack);
      Draw_Racket(Right_Rack);
      Draw_Ball(Ball);

      if (Score.Player_1 >= final_score || Score.Player_2 >= final_score) {
        G_Menu = WIN;
      }
    }
    if (G_Menu == WIN) {
      if (Score.Player_1 >= final_score) {
        Draw_P1W();
      } else {
        Draw_P2W();
      }
    }
    // Draw_Char_Test();
    // Draw_P1W();
    // Draw_P2W();
    // Draw_Pong_Logo();

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  
}

void Render_FPS() { 
    Ball_Init();

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
      printf("speedmult: %f, current_ball->dx: %f, current_ball->dy: %f\n",
             Ball.speedmult, Ball.dx * Ball.speedmult,
             Ball.dy * Ball.speedmult);
      frameCount = 0;
      previousSecond = currentTime;
    }
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

void Set_Text_Color(float r, float g, float b) {
  text_color.r = r;
  text_color.g = g;
  text_color.b = b;
}

void Draw_Char_Test() {
  int x = -42, y = 13;
  size = 1;
  for (int i = 6 + y, num = 0; i > -1 + y; i -= 6) {
    for (int j = -15 + x; j < 2 + x; j += 4, num++) {
      Draw_Num(num, j, i);
    }
  }

  for (int i = 6, character = 'A'; i > -1; i -= 6) {
    for (int j = -57; j < -3; j += 4, character++) {
      if (character == 'M' || character == 'W')
        j += 1;
      Draw_Letter(character, j, i);
      if (character == 'G' || character == 'N' || character == 'O' ||
          character == 'Q' || character == 'M' || character == 'W')
        j += 1;
    }
  }

  Draw_Colon(-57, -6);
  Draw_Exclamination(-53, -6);
}

void Draw_P1W() {
  int x_pos = -22, y_pos = 3;
  size = 2;
  Set_Text_Color(1, 1, 1);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('L', 4 + x_pos, 0 + y_pos);
  Draw_Letter('A', 8 + x_pos, 0 + y_pos);
  Draw_Letter('Y', 12 + x_pos, 0 + y_pos);
  Draw_Letter('E', 16 + x_pos, 0 + y_pos);
  Draw_Letter('R', 20 + x_pos, 0 + y_pos);
  Draw_Num(1, 25 + x_pos, 0 + y_pos);
  Draw_Letter('W', 31 + x_pos, 0 + y_pos);
  Draw_Letter('O', 36 + x_pos, 0 + y_pos);
  Draw_Letter('N', 41 + x_pos, 0 + y_pos);

  Draw_Exclamination(45 + x_pos, 0 + y_pos);

  size = 1;
  x_pos = -31;
  y_pos = -10;
  Set_Text_Color(0.2, 0.2, 0.2);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('R', 4 + x_pos, 0 + y_pos);
  Draw_Letter('E', 8 + x_pos, 0 + y_pos);
  Draw_Letter('S', 12 + x_pos, 0 + y_pos);
  Draw_Letter('S', 16 + x_pos, 0 + y_pos);

  Draw_Letter('E', 22 + x_pos, 0 + y_pos);
  Draw_Letter('S', 26 + x_pos, 0 + y_pos);
  Draw_Letter('C', 30 + x_pos, 0 + y_pos);

  Draw_Letter('T', 36 + x_pos, 0 + y_pos);
  Draw_Letter('O', 40 + x_pos, 0 + y_pos);

  Draw_Letter('E', 47 + x_pos, 0 + y_pos);
  Draw_Letter('X', 51 + x_pos, 0 + y_pos);
  Draw_Letter('I', 55 + x_pos, 0 + y_pos);
  Draw_Letter('T', 59 + x_pos, 0 + y_pos);
}

void Draw_P2W() {
  int x_pos = -22, y_pos = 3;
  size = 2;
  Set_Text_Color(1, 1, 1);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('L', 4 + x_pos, 0 + y_pos);
  Draw_Letter('A', 8 + x_pos, 0 + y_pos);
  Draw_Letter('Y', 12 + x_pos, 0 + y_pos);
  Draw_Letter('E', 16 + x_pos, 0 + y_pos);
  Draw_Letter('R', 20 + x_pos, 0 + y_pos);
  Draw_Num(2, 25 + x_pos, 0 + y_pos);
  Draw_Letter('W', 31 + x_pos, 0 + y_pos);
  Draw_Letter('O', 36 + x_pos, 0 + y_pos);
  Draw_Letter('N', 41 + x_pos, 0 + y_pos);

  Draw_Exclamination(45 + x_pos, 0 + y_pos);

  size = 1;
  x_pos = -31;
  y_pos = -10;
  Set_Text_Color(0.2, 0.2, 0.2);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('R', 4 + x_pos, 0 + y_pos);
  Draw_Letter('E', 8 + x_pos, 0 + y_pos);
  Draw_Letter('S', 12 + x_pos, 0 + y_pos);
  Draw_Letter('S', 16 + x_pos, 0 + y_pos);

  Draw_Letter('E', 22 + x_pos, 0 + y_pos);
  Draw_Letter('S', 26 + x_pos, 0 + y_pos);
  Draw_Letter('C', 30 + x_pos, 0 + y_pos);

  Draw_Letter('T', 36 + x_pos, 0 + y_pos);
  Draw_Letter('O', 40 + x_pos, 0 + y_pos);

  Draw_Letter('E', 47 + x_pos, 0 + y_pos);
  Draw_Letter('X', 51 + x_pos, 0 + y_pos);
  Draw_Letter('I', 55 + x_pos, 0 + y_pos);
  Draw_Letter('T', 59 + x_pos, 0 + y_pos);
}

void Draw_Help() {
  float x_pos = 0, y_pos = 0;
  size = 1;
  Set_Text_Color(0.5, 0.5, 0.5);
  Draw_Letter('A', -55 + x_pos, 18 + y_pos);
  Draw_Letter('Z', -55 + x_pos, -18 + y_pos);
  Draw_Letter('K', 55 + x_pos, 18 + y_pos);
  Draw_Letter('M', 55 + x_pos, -18 + y_pos);
  x_pos = -112;
  y_pos = 27;
  size = 0.5;
  Set_Text_Color(0.25, 0.25, 0.25);
  Draw_Letter('U', 0 + x_pos, 0 + y_pos);
  Draw_Letter('P', 4 + x_pos, 0 + y_pos);
  x_pos = 108;
  y_pos = 27;
  size = 0.5;
  Set_Text_Color(0.25, 0.25, 0.25);
  Draw_Letter('U', 0 + x_pos, 0 + y_pos);
  Draw_Letter('P', 4 + x_pos, 0 + y_pos);
  x_pos = -118;
  y_pos = -27;
  size = 0.5;
  Set_Text_Color(0.25, 0.25, 0.25);
  Draw_Letter('D', 0 + x_pos, 0 + y_pos);
  Draw_Letter('O', 4 + x_pos, 0 + y_pos);
  Draw_Letter('W', 10 + x_pos, 0 + y_pos);
  Draw_Letter('N', 15 + x_pos, 0 + y_pos);
  x_pos = 102;
  y_pos = -27;
  size = 0.5;
  Set_Text_Color(0.25, 0.25, 0.25);
  Draw_Letter('D', 0 + x_pos, 0 + y_pos);
  Draw_Letter('O', 4 + x_pos, 0 + y_pos);
  Draw_Letter('W', 10 + x_pos, 0 + y_pos);
  Draw_Letter('N', 15 + x_pos, 0 + y_pos);
  size = 1;
  x_pos = -28;
  y_pos = -10;
  Set_Text_Color(0.2, 0.2, 0.2);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('R', 4 + x_pos, 0 + y_pos);
  Draw_Letter('E', 8 + x_pos, 0 + y_pos);
  Draw_Letter('S', 12 + x_pos, 0 + y_pos);
  Draw_Letter('S', 16 + x_pos, 0 + y_pos);

  Draw_Letter('E', 22 + x_pos, 0 + y_pos);
  Draw_Letter('S', 26 + x_pos, 0 + y_pos);
  Draw_Letter('C', 30 + x_pos, 0 + y_pos);

  Draw_Letter('T', 36 + x_pos, 0 + y_pos);
  Draw_Letter('O', 40 + x_pos, 0 + y_pos);

  Draw_Letter('E', 47 + x_pos, 0 + y_pos);
  Draw_Letter('X', 51 + x_pos, 0 + y_pos);
  Draw_Letter('I', 55 + x_pos, 0 + y_pos);
  Draw_Letter('T', 59 + x_pos, 0 + y_pos);
  size = 1;
  x_pos = -33;
  y_pos = -17;
  Set_Text_Color(0.2, 0.2, 0.2);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('R', 4 + x_pos, 0 + y_pos);
  Draw_Letter('E', 8 + x_pos, 0 + y_pos);
  Draw_Letter('S', 12 + x_pos, 0 + y_pos);
  Draw_Letter('S', 16 + x_pos, 0 + y_pos);

  Draw_Letter('H', 22 + x_pos, 0 + y_pos);

  Draw_Letter('T', 28 + x_pos, 0 + y_pos);
  Draw_Letter('O', 32 + x_pos, 0 + y_pos);

  Draw_Letter('H', 39 + x_pos, 0 + y_pos);
  Draw_Letter('I', 43 + x_pos, 0 + y_pos);
  Draw_Letter('D', 47 + x_pos, 0 + y_pos);
  Draw_Letter('E', 51 + x_pos, 0 + y_pos);

  Draw_Letter('H', 57 + x_pos, 0 + y_pos);
  Draw_Letter('E', 61 + x_pos, 0 + y_pos);
  Draw_Letter('L', 65 + x_pos, 0 + y_pos);
  Draw_Letter('P', 69 + x_pos, 0 + y_pos);
}

void Draw_FPS(int framerate) {
  size = 1;
  Set_Text_Color(0.2, 0.3, 0.4);
  if (framerate < 10) {
    Draw_Num(framerate, 0, 0);
  } else if (framerate < 100) {
    Draw_Num(framerate / 10, -5, 0);
    Draw_Num(framerate % 10, 0, 0);
  } else if (framerate < 1000) {
    Draw_Num(framerate / 100, -10, 0);
    Draw_Num((framerate % 100) / 10, -5, 0);
    Draw_Num(framerate % 10, 0, 0);
  }
}

void Draw_Pong_Logo() {
  float x_pos = -7, y_pos = 6;
  size = 2;
  Set_Text_Color(1, 1, 1);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('O', 4 + x_pos, 0 + y_pos);
  Draw_Letter('N', 9 + x_pos, 0 + y_pos);
  Draw_Letter('G', 14 + x_pos, 0 + y_pos);
  size = 1;
  x_pos = -43;
  y_pos = -10;
  Set_Text_Color(0.2, 0.2, 0.2);
  Draw_Letter('P', 0 + x_pos, 0 + y_pos);
  Draw_Letter('R', 4 + x_pos, 0 + y_pos);
  Draw_Letter('E', 8 + x_pos, 0 + y_pos);
  Draw_Letter('S', 12 + x_pos, 0 + y_pos);
  Draw_Letter('S', 16 + x_pos, 0 + y_pos);

  Draw_Letter('S', 22 + x_pos, 0 + y_pos);
  Draw_Letter('P', 26 + x_pos, 0 + y_pos);
  Draw_Letter('A', 30 + x_pos, 0 + y_pos);
  Draw_Letter('C', 34 + x_pos, 0 + y_pos);
  Draw_Letter('E', 38 + x_pos, 0 + y_pos);

  Draw_Letter('T', 44 + x_pos, 0 + y_pos);
  Draw_Letter('O', 48 + x_pos, 0 + y_pos);

  Draw_Letter('C', 55 + x_pos, 0 + y_pos);
  Draw_Letter('O', 59 + x_pos, 0 + y_pos);
  Draw_Letter('N', 64 + x_pos, 0 + y_pos);
  Draw_Letter('T', 69 + x_pos, 0 + y_pos);
  Draw_Letter('I', 73 + x_pos, 0 + y_pos);
  Draw_Letter('N', 77 + x_pos, 0 + y_pos);
  Draw_Letter('U', 82 + x_pos, 0 + y_pos);
  Draw_Letter('E', 86 + x_pos, 0 + y_pos);
}

void Draw_Pixel(float x, float y) {
  glColor3f(text_color.r, text_color.g, text_color.b);

  glBegin(GL_POLYGON);
  glVertex2d((-0.5 + x) * grid_coeff * size / ratio,
             (-0.5 + y) * grid_coeff * size);
  glVertex2d((-0.5 + x) * grid_coeff * size / ratio,
             (0.5 + y) * grid_coeff * size);
  glVertex2d((0.5 + x) * grid_coeff * size / ratio,
             (0.5 + y) * grid_coeff * size);
  glVertex2d((0.5 + x) * grid_coeff * size / ratio,
             (-0.5 + y) * grid_coeff * size);
  glEnd();
}

void Draw_Num(int num, float x, float y) {
  switch (num) {
  case 0: {
    Draw_0(x, y);
    break;
  }
  case 1: {
    Draw_1(x, y);
    break;
  }
  case 2: {
    Draw_2(x, y);
    break;
  }
  case 3: {
    Draw_3(x, y);
    break;
  }
  case 4: {
    Draw_4(x, y);
    break;
  }
  case 5: {
    Draw_5(x, y);
    break;
  }
  case 6: {
    Draw_6(x, y);
    break;
  }
  case 7: {
    Draw_7(x, y);
    break;
  }
  case 8: {
    Draw_8(x, y);
    break;
  }
  case 9: {
    Draw_9(x, y);
    break;
  }
  }
}

void Draw_0(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (!(j == x && (i < (2 + y) && i > (-2 + y))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_1(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || j == (x) || (i == (1 + y) && j == (-1 + x)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_2(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || i == (y) || i == (2 + y) ||
          (j == (1 + x) && (i == (1 + y))) ||
          (j == (-1 + x) && (i == (-1 + y))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_3(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || i == (y) || i == (2 + y) ||
          (j == (1 + x) && (i == (-1 + y) || i == (1 + y))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_4(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (1 + x) || i == (y) || (j == (-1 + x) && i > (y)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_5(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || i == (y) || i == (2 + y) ||
          (j == (1 + x) && (i == (-1 + y))) ||
          (j == (-1 + x) && (i == (1 + y))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_6(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (2 + y) || i == (y) || i == (-2 + y) || j == (-1 + x) ||
          (j == (1 + x) && i < (1 + y)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_7(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (2 + y) || j == (1 + x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_8(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (!(j == x && (i == -1 + y || i == 1 + y)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_9(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (1 + x) || i == (-2 + y) || i == (y) || i == (2 + y) ||
          (i == (1 + y) && j == (-1 + x)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Letter(char character, float x, float y) {
  switch (character) {
  case 'A': {
    Draw_A(x, y);
    break;
  }
  case 'a': {
    Draw_A(x, y);
    break;
  }
  case 'B': {
    Draw_B(x, y);
    break;
  }
  case 'b': {
    Draw_B(x, y);
    break;
  }
  case 'C': {
    Draw_C(x, y);
    break;
  }
  case 'c': {
    Draw_C(x, y);
    break;
  }
  case 'D': {
    Draw_D(x, y);
    break;
  }
  case 'd': {
    Draw_D(x, y);
    break;
  }
  case 'E': {
    Draw_E(x, y);
    break;
  }
  case 'e': {
    Draw_E(x, y);
    break;
  }
  case 'F': {
    Draw_F(x, y);
    break;
  }
  case 'f': {
    Draw_F(x, y);
    break;
  }
  case 'G': {
    Draw_G(x, y);
    break;
  }
  case 'g': {
    Draw_G(x, y);
    break;
  }
  case 'H': {
    Draw_H(x, y);
    break;
  }
  case 'h': {
    Draw_H(x, y);
    break;
  }
  case 'I': {
    Draw_I(x, y);
    break;
  }
  case 'i': {
    Draw_I(x, y);
    break;
  }
  case 'J': {
    Draw_J(x, y);
    break;
  }
  case 'j': {
    Draw_J(x, y);
    break;
  }
  case 'K': {
    Draw_K(x, y);
    break;
  }
  case 'k': {
    Draw_K(x, y);
    break;
  }
  case 'L': {
    Draw_L(x, y);
    break;
  }
  case 'l': {
    Draw_L(x, y);
    break;
  }
  case 'M': {
    Draw_M(x, y);
    break;
  }
  case 'm': {
    Draw_M(x, y);
    break;
  }
  case 'N': {
    Draw_N(x, y);
    break;
  }
  case 'n': {
    Draw_N(x, y);
    break;
  }
  case 'O': {
    Draw_O(x, y);
    break;
  }
  case 'o': {
    Draw_O(x, y);
    break;
  }
  case 'P': {
    Draw_P(x, y);
    break;
  }
  case 'p': {
    Draw_P(x, y);
    break;
  }
  case 'Q': {
    Draw_Q(x, y);
    break;
  }
  case 'q': {
    Draw_Q(x, y);
    break;
  }
  case 'R': {
    Draw_R(x, y);
    break;
  }
  case 'r': {
    Draw_R(x, y);
    break;
  }
  case 'S': {
    Draw_S(x, y);
    break;
  }
  case 's': {
    Draw_S(x, y);
    break;
  }
  case 'T': {
    Draw_T(x, y);
    break;
  }
  case 't': {
    Draw_T(x, y);
    break;
  }
  case 'U': {
    Draw_U(x, y);
    break;
  }
  case 'u': {
    Draw_U(x, y);
    break;
  }
  case 'V': {
    Draw_V(x, y);
    break;
  }
  case 'v': {
    Draw_V(x, y);
    break;
  }
  case 'W': {
    Draw_W(x, y);
    break;
  }
  case 'w': {
    Draw_W(x, y);
    break;
  }
  case 'X': {
    Draw_X(x, y);
    break;
  }
  case 'x': {
    Draw_X(x, y);
    break;
  }
  case 'Y': {
    Draw_Y(x, y);
    break;
  }
  case 'y': {
    Draw_Y(x, y);
    break;
  }
  case 'Z': {
    Draw_Z(x, y);
    break;
  }
  case 'z': {
    Draw_Z(x, y);
    break;
  }
  }
}

void Draw_A(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if ((i < (2 + y)) && (j == (-1 + x) || j == (1 + x)) || i == (-1 + y) ||
          (i == (2 + y) && (j == (x))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_B(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) ||
          ((j == x) && (i == (2 + y) || i == (y) || i == (-2 + y))) ||
          ((j == (1 + x)) && (i == (1 + y) || i == (-1 + y))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_C(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) && ((i != (-2 + y)) && (i != 2 + y)) ||
          (j != (-1 + x) && (i == 2 + y || i == -2 + y)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_D(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) ||
          ((j == (1 + x) && (i > (-2 + y) && (i < (2 + y))))) ||
          (j == (x) && (i == (-2 + y) || i == (2 + y))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_E(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || i == (-2 + y) || i == (y) || i == (2 + y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_F(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || i == (2 + y) || i == (y) && j != (1 + x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_G(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 3 + x; j++) {
      if ((i == (-2 + y) || i == (2 + y)) &&
              (j != (-1 + x) && (j != (2 + x))) ||
          i == (y) && j != (x) ||
          j == (-1 + x) && i != (-2 + y) && i != (2 + y) ||
          j == (2 + x) && i == (-1 + y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_H(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || j == (1 + x) || i == (y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_I(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || i == (2 + y) || j == (x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_J(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (2 + y) || j == (1 + x) && i != (-2 + y) ||
          j == (x) && i == (-2 + y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_K(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || j == (1 + x) && i != y || i == y && j == x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_L(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || i == (-2 + y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_M(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -2 + x; j < 3 + x; j++) {
      if (j == (-2 + x) || j == (2 + x) || (i == (1 + y) || i == y) && j != x ||
          j == x && i < y)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_N(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 3 + x; j++) {
      if (j == (-1 + x) || j == (2 + x) || i == (y) ||
          (i == (1 + y) && j == (x)) || (i == (-1 + y) && j == (1 + x)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_O(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 3 + x; j++) {
      if ((i == (-2 + y) || i == (2 + y)) && j != (-1 + x) && j != (2 + x) ||
          (j == (-1 + x) || j == (2 + x)) && i != (-2 + y) && i != (2 + y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_P(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || i == (2 + y) && j != (1 + x) ||
          j == (1 + x) && i > (-1 + y) && i != (2 + y) ||
          i == (-1 + y) && j == (x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Q(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 3 + x; j++) {
      if ((j == (-1 + x) && i > (-2 + y) || j == (2 + x) && i > (-1 + y)) &&
              i != (2 + y) ||
          i == (2 + y) && j != (-1 + x) && j != (2 + x) ||
          i == (-1 + y) && j == (1 + x) ||
          i == (-2 + y) && j != (-1 + x) && j != (1 + x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_R(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || i == (2 + y) && j != (1 + x) ||
          j == (1 + x) && i > (-1 + y) && i != (2 + y) ||
          i == (-1 + y) && j == (x) || i == (-2 + y) && j == (1 + x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_S(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) && j != (1 + x) || i == (2 + y) && j != (-1 + x) ||
          i - y == -(j - x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_T(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (2 + y) || j == x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_U(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (1 + x) || i == (-2 + y) && j != (-1 + x) ||
          i != (-2 + y) && j == (-1 + x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_V(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if ((j == (-1 + x) || j == (1 + x)) && i != (-2 + y) ||
          i == (-2 + y) && j == x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_W(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -2 + x; j < 3 + x; j++) {
      if (i > (-2 + y) &&
              (j == (-2 + x) || j == (2 + x) || (j == (x) && i < (2 + y))) ||
          (i == (-2 + y) && (j == (-1 + x) || j == (1 + x))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_X(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if ((j == (-1 + x) || j == (1 + x)) && i != y || i == y && j == x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Y(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if ((j == (-1 + x) || j == (1 + x)) && i > y || j == (x) && i <= (y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Z(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || i == (2 + y) || i - y == j - x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Colon(float x, float y) {
  Draw_Pixel(x, 1 + y);

  Draw_Pixel(x, -1 + y);
}

void Draw_Exclamination(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == x && i != (-1 + y))
        Draw_Pixel(j, i);
    }
  }
}

void Ball_Init() {
  Ball.x = Ball.y = 0;
  Ball.dx = 0.01;
  Ball.dy = 0.001;
  Ball.radius = 0.03;
  Ball.speedmult = default_speed;
  Ball.color.r = Ball.color.g = Ball.color.b = 0.95;
}

void Move_Racket(T_Racket *racket, float dy) { racket->y += dy; }

int Left_Racket_Collide(T_Ball *ball, T_Racket *Left_Rack) {
  int collide = 0;
  float sin_y = 0, cos_x = 0;
  for (int i = 90; i <= 270; i++) {
    sin_y = sin(DEG2RAD * i);
    cos_x = cos(DEG2RAD * i);
    collide = (((ball->x - ball->radius + ball->dx * ball->speedmult) <
                (Left_Rack->x + Left_Rack->x_size / 2)) &&
               ((ball->y - ball->radius /** sin_y*/) <
                    (Left_Rack->y + Left_Rack->y_size / 2) * ratio
                && (ball->y + ball->radius /** sin_y*/) >
                       (Left_Rack->y - Left_Rack->y_size / 2)  * ratio));
  }

  return collide;

  /*return (((ball->x - ball->radius + ball->dx) < (Left_Rack->x +
     Left_Rack->x_size / 2)) && (ball->y < (Left_Rack->y + Left_Rack->y_size /
     2) * ratio && ball->y > (Left_Rack->y - Left_Rack->y_size / 2) * ratio));*/
}

int Right_Racket_Collide(T_Ball *ball, T_Racket *Right_Rack) {
  int collide = 0;
  float sin_y = 0, cos_x = 0;
  for (int i = 270; i <= 450; i++) {
    sin_y = sin(DEG2RAD * i);
    cos_x = cos(DEG2RAD * i);
    collide = (((ball->x + ball->radius + ball->dx * ball->speedmult) >
                (Right_Rack->x - Right_Rack->x_size / 2)) &&
               ((ball->y - ball->radius /** sin_y*/) <
                    (Right_Rack->y + Right_Rack->y_size / 2) * ratio
                && (ball->y + ball->radius /** sin_y*/) >
                       (Right_Rack->y - Right_Rack->y_size / 2) * ratio));
  }

  return collide;

  /*return (((ball->x + ball->radius + ball->dx) >
           (Right_Rack->x - Right_Rack->x_size / 2)) &&
          (ball->y < (Right_Rack->y + Right_Rack->y_size / 2) * ratio &&
           ball->y > (Right_Rack->y - Right_Rack->y_size / 2) * ratio));*/
}

int Racket_Collide(T_Ball *ball, T_Racket *Left_Rack, T_Racket *Right_Rack) {
  return (Left_Racket_Collide(ball, Left_Rack) ||
          Right_Racket_Collide(ball, Right_Rack));
}

int Border_X_Left_Collide(T_Ball *ball) {
  return (ball->x + ball->dx * ball->speedmult < (-1 + ball->radius));
}

int Border_X_Right_Collide(T_Ball *ball) {
  return (ball->x + ball->dx * ball->speedmult > (1 - ball->radius));
}

int Border_Y_Up_Collide(T_Ball *ball) {
  return (ball->y + ball->dy * ball->speedmult >
          (1 - ball->radius * ratio));
}

int Border_Y_Down_Collide(T_Ball *ball) {
  return (ball->y + ball->dy * ball->speedmult <
          (-1 + ball->radius * ratio));
}

int Border_X_Collide(T_Ball *ball) {
  return (Border_X_Left_Collide(ball) || Border_X_Right_Collide(ball));
}

int Border_Y_Collide(T_Ball *ball) {
  return (Border_Y_Up_Collide(ball) || Border_Y_Down_Collide(ball));
}

void Ball_Collide(T_Ball *ball, T_Racket *Left_Rack, T_Racket *Right_Rack,
                  T_Score *Score) {
  if (Border_X_Collide(ball)) {
    if (Border_X_Right_Collide(ball)) {
      Increase_Player_1(Score);
      Reset_Round(ball, Left_Rack, Right_Rack);
    } else if (Border_X_Left_Collide(ball)) {
      Increase_Player_2(Score);
      Reset_Round(ball, Left_Rack, Right_Rack);
    } else
      ball->dx *= -1;
  } else {
    ball->x += ball->dx * ball->speedmult;
  }

  if (Border_Y_Collide(ball)) {
    ball->dy *= -1;
  } else {
    ball->y += ball->dy * ball->speedmult;
  }

  if (Racket_Collide(ball, Left_Rack, Right_Rack)) {
    ball->dx *= -1;
  }
}

void Increase_Player_1(T_Score *score) { score->Player_1++; }

void Increase_Player_2(T_Score *score) { score->Player_2++; }

void Increase_Speedmult(T_Ball *ball) { ball->speedmult += 0.0005; }

void Reset_Ball(T_Ball *ball) {
  ball->x = 0;
  ball->y = 0;
  ball->dx = 0.01;
  ball->dy = 0.001;
  ball->speedmult = default_speed;
}

void Reset_racket(T_Racket *racket) { racket->y = 0; }

void Reset_Round(T_Ball *ball, T_Racket *Left_Rack, T_Racket *Right_Rack) {
  Reset_Ball(ball);
  Reset_racket(Left_Rack);
  Reset_racket(Right_Rack);
}

void Keystroke(GLFWwindow *window, T_Ball *ball, T_Racket *Left_Rack,
               T_Racket *Right_Rack, float dy_change) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    if (Left_Rack->y + dy_change < (1 - Left_Rack->y_size * ratio / 2 -
                                    Left_Rack->x_size / 2) / ratio)
      Move_Racket(Left_Rack, dy_change);
  if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    if (Left_Rack->y - dy_change > (-1 + Left_Rack->y_size * ratio / 2 +
                                    Left_Rack->x_size / 2) / ratio)
      Move_Racket(Left_Rack, -dy_change);
  if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    if (Right_Rack->y + dy_change < (1 - Right_Rack->y_size * ratio / 2 -
                                     Right_Rack->x_size / 2) / ratio)
      Move_Racket(Right_Rack, dy_change);
  if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    if (Right_Rack->y - dy_change > (-1 + Right_Rack->y_size * ratio / 2 +
                                     Right_Rack->x_size / 2) / ratio)
      Move_Racket(Right_Rack, -dy_change);
  if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
    Reset_Round(ball, Left_Rack, Right_Rack);
  }
}

void Draw_Ball(T_Ball bll) {
  glColor3f(bll.color.r, bll.color.g, bll.color.b);
  glBegin(GL_POLYGON);
  for (float i = 0; i < 360; i++) {
    glVertex2d((cos(DEG2RAD * i) * bll.radius + bll.x),
               (sin(DEG2RAD * i) * bll.radius * ratio + bll.y));
  }
  glEnd();
}

void Draw_Racket(T_Racket racket) {
  glColor3f(racket.color.r, racket.color.g, racket.color.b);
  glBegin(GL_POLYGON);
  glVertex2d(racket.x - racket.x_size / 2,
             (racket.y - racket.y_size / 2) * ratio);
  glVertex2d(racket.x + racket.x_size / 2,
             (racket.y - racket.y_size / 2) * ratio);
  glVertex2d(racket.x + racket.x_size / 2,
             (racket.y + racket.y_size / 2) * ratio);
  glVertex2d(racket.x - racket.x_size / 2,
             (racket.y + racket.y_size / 2) * ratio);
  glEnd();
  glBegin(GL_POLYGON);
  for (float i = 0; i < 360; i++) {
    glVertex2d((cos(DEG2RAD * i) * racket.x_size / 2 + racket.x),
        (sin(DEG2RAD * i) * racket.x_size / 2 + racket.y_size / 2 + racket.y) *
            ratio);
  }
  glEnd();
  glBegin(GL_POLYGON);
  for (float i = 0; i < 360; i++) {
    glVertex2d(
        (cos(DEG2RAD * i) * racket.x_size / 2 + racket.x),
        (sin(DEG2RAD * i) * racket.x_size / 2 - racket.y_size / 2 + racket.y) *
            ratio);
  }
  glEnd();
}

void Draw_Score(T_Score score) {
  float y_pos = 18;
  size = 1;
  Set_Text_Color(0.7, 0.7, 0.7);
  for (int i = -8; i < 9; i += 4) {
    if (i < 0) {
      Draw_Num((i < -5) ? score.Player_1 / 10 : score.Player_1 % 10, i, y_pos);
    } else if (i > 0) {
      Draw_Num((i < 5) ? score.Player_2 / 10 : score.Player_2 % 10, i, y_pos);
    } else {
      Draw_Colon(i, y_pos);
    }
  }
}
