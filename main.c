// ===================================
//
// GLFW
//
// ===================================

#include <GLFW/glfw3.h>

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

// Responsible for the text color: r - red color, g - green color, b - blue
// color
typedef struct Text_Color {
  float r;
  float g;
  float b;
} T_Color;

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

// Draws grid pixel
void Draw_Grid_Pixel(float x, float y);

// Draws grid
void Draw_Grid();

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

  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
  Draw_Char_Test();
  
  // Swap buffers
  glfwSwapBuffers(window);
  glfwPollEvents();
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
  Set_Text_Color(1, 1, 1);
  for (int i = 6 + y, num = 0; i > -1 + y; i -= 6) {
    for (int j = -15 + x; j < 2 + x; j += 4, num++) {
      Draw_Num(num, j, i);
    }
  }

  for (int i = 6, character = 'A'; i > -1; i -= 6) {
    for (int j = -57; j < -3; j += 4, character++) {
      if (character == 'M' || character == 'W') j += 1;
      Draw_Letter(character, j, i);
      if (character == 'G' || character == 'N' || character == 'O' ||
          character == 'Q' || character == 'M' || character == 'W')
        j += 1;
    }
  }

  Draw_Colon(-58, -6);
  Draw_Exclamination(-56, -6);

  Draw_Grid();
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

void Draw_Grid_Pixel(float x, float y) {
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_LOOP);
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

void Draw_Grid() {
  float size_x = 60, size_y = 22;
  for (float i = -size_y; i <= size_y; i++) {
    for (float j = -size_x; j <= size_x;
         j++) {
      Draw_Grid_Pixel(j, i);
    }
  }
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
      if (!(j == x && (i < (2 + y) && i > (-2 + y)))) Draw_Pixel(j, i);
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
      if (i == (2 + y) || j == (1 + x)) Draw_Pixel(j, i);
    }
  }
}

void Draw_8(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (!(j == x && (i == -1 + y || i == 1 + y))) Draw_Pixel(j, i);
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
      if (j == (-1 + x) || j == (1 + x) || i == (y)) Draw_Pixel(j, i);
    }
  }
}

void Draw_I(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || i == (2 + y) || j == (x)) Draw_Pixel(j, i);
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
      if (j == (-1 + x) || i == (-2 + y)) Draw_Pixel(j, i);
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
      if (i == (2 + y) || j == x) Draw_Pixel(j, i);
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
      if (i == (-2 + y) || i == (2 + y) || i - y == j - x) Draw_Pixel(j, i);
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
      if (j == x && i != (-1 + y)) Draw_Pixel(j, i);
    }
  }
}
