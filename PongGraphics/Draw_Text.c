#include "include/Draw_Text.h"

float ratio;

T_Color text_color = {1, 1, 1};

void Set_Text_Color(float r, float g, float b) {
  text_color.r = r;
  text_color.g = g;
  text_color.b = b;
}

void Draw_Char_Test() {
  int x = -42, y = 13;
  size = 1;
  for (int i = 6 + y, num = 0; i > -1 + y; i -= 6) {
    for (int j = -15 + x; j < 2 + x; j += 4,num++) {
      Draw_Num(num, j, i);
    }
  }

  for (int i = 6, character = 'A'; i > -1; i -= 6) {
    for (int j = -57; j < -3; j+=4,character++) {
      if (character == 'M' || character == 'W') j += 1;
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
            if (!(j==x&&(i<(2+y)&&i>(-2+y))))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_1(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (i==(-2+y)||j==(x)||(i == (1 + y) && j==(-1+x)))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_2(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (i==(-2 + y)|| i == (y)|| i == (2 + y)||(j==(1+x)&&(i==(1+y))) || (j == (-1 + x) && (i == (-1 + y))))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_3(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (i == (-2 + y) || i == (y) || i == (2 + y) || (j == (1 + x) && (i == (-1 + y) || i == (1 + y))))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_4(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (j==(1+x)||i==(y)||(j==(-1+x)&&i>(y)))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_5(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (i == (-2 + y) || i == (y) || i == (2 + y) || (j == (1 + x) && (i == (-1 + y))) || (j == (-1 + x) && (i == (1 + y))))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_6(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (i==(2+y)||i==(y)||i==(-2+y) || j == (-1 + x) || (j==(1+x)&&i<(1+y)))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_7(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (i == (2+y) || j==(1+x))
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
            if (j==(1+x)||i==(-2+y)||i==(y)||i==(2+y)||(i==(1+y)&&j==(-1+x)))
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
      if ((i<(2+y))&&(j==(-1+x)||j==(1+x))||i==(-1+y)||(i==(2+y)&&(j==(x))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_B(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) ||
          ((j == x) && (i == (2 + y) || i == (y)|| i == (-2 + y))) ||
          ((j == (1+x)) && (i == (1 + y) || i == (-1 + y))))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_C(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) && ((i != (-2 + y)) && (i != 2 + y)) || (j != (-1 + x)&&(i==2+y||i==-2+y)))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_D(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || ((j == (1 + x) && (i > (-2 + y)&&(i < (2 + y))))) || (j==(x)&&(i==(-2+y)||i==(2+y))))
      Draw_Pixel(j, i);
    }
  }
}

void Draw_E(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j==(-1+x)||i==(-2+y)||i==(y)||i==(2+y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_F(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || i == (2 + y) || i == (y)&&j!=(1+x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_G(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 3 + x; j++) {
      if ((i == (-2 + y) || i == (2 + y)) && (j!=(-1+x)&&(j!=(2+x))) || i == (y) && j != (x) ||
          j == (-1 + x)&&i!=(-2+y)&&i!=(2+y) || j==(2+x)&&i==(-1+y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_H(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j==(-1+x)||j==(1+x)||i==(y))
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
      if (i == (2 + y) || j == (1 + x) && i != (-2 + y) || j==(x)&&i==(-2+y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_K(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || j == (1 + x)&&i!=y || i==y&&j==x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_L(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (j == (-1 + x) || i == (-2+y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_M(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -2 + x; j < 3 + x; j++) {
      if (j == (-2 + x) || j == (2 + x) || (i == (1 + y) || i == y)&&j!=x || j==x&&i<y)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_N(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 3 + x; j++) {
            if (j==(-1+x)||j==(2+x)||i==(y)||(i==(1+y)&&j==(x)) || (i == (-1 + y) && j == (1+x)))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_O(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 3 + x; j++) {
        if ((i == (-2 + y) || i == (2 + y)) && j != (-1 + x) && j != (2+x) ||
              (j == (-1 + x) || j == (2 + x)) && i != (-2 + y) && i != (2 + y))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_P(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
        if (j == (-1 + x) || i == (2 + y) && j != (1+x) ||
            j == (1 + x) && i > (-1 + y) && i != (2+y) || i==(-1+y)&&j==(x))
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
          i == (-1 + y) && j == (x) || i==(-2+y)&&j==(1+x))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_S(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) && j != (1 + x) || i == (2 + y) && j != (-1 + x) ||
          i-y==-(j-x))
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
      if ((j == (-1 + x) || j == (1 + x)) && i != (-2 + y) || i == (-2 + y) && j == x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_W(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -2 + x; j < 3 + x; j++) {
            if (i>(-2+y)&& (j == (-2 + x)||j==(2+x)||(j==(x)&&i<(2+y)))||(i==(-2+y)&&(j==(-1+x)||j==(1+x))))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_X(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if ((j == (-1 + x) || j == (1 + x))&&i!=y || i==y&&j==x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Y(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if ((j == (-1 + x) || j == (1 + x))&&i>y || j==(x)&&i<=(y))
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Z(float x, float y) {
  for (float i = -2 + y; i < 3 + y; i++) {
    for (float j = -1 + x; j < 2 + x; j++) {
      if (i == (-2 + y) || i == (2 + y) || i-y==j-x)
        Draw_Pixel(j, i);
    }
  }
}

void Draw_Colon(float x, float y) {
    Draw_Pixel(x, 1+y);

    Draw_Pixel(x, -1+y);
}

void Draw_Exclamination(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (j==x&&i!=(-1+y))
                Draw_Pixel(j, i);
        }
    }
}