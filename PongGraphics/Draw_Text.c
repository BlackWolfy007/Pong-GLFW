#include "Draw_Text.h"

float ratio;

void Draw_Nums_Test() {
    Draw_0(-15, 6);

    Draw_1(-11, 6);

    Draw_2(-7, 6);

    Draw_3(-3, 6);

    Draw_4(1, 6);

    Draw_N(7, 6);

    Draw_O(12, 6);

    Draw_P(17, 6);

    Draw_W(22, 6);

    Draw_5(-15, 0);

    Draw_6(-11, 0);

    Draw_7(-7, 0);

    Draw_8(-3, 0);

    Draw_9(1, 0);

    Draw_Colon(-15, -6);

    Draw_Exclamination(-11, -6);
}

void Draw_P1W() {

    Draw_P(-14, 0);
    
    Draw_1(-10, 0);

    Draw_W(-3, 0);

    Draw_O(2, 0);

    Draw_N(7, 0);

    Draw_Exclamination(11, 0);
}

void Draw_P2W() {
  Draw_P(-14, 0);

  Draw_2(-10, 0);

  Draw_W(-3, 0);

  Draw_O(2, 0);

  Draw_N(7, 0);

  Draw_Exclamination(11, 0);
}

void Draw_Pixel(float x, float y) {
    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);
    glVertex2d((-0.5 + x) * grid_coeff / ratio, (-0.5 + y) * grid_coeff);
    glVertex2d((-0.5 + x) * grid_coeff / ratio, (0.5 + y) * grid_coeff);
    glVertex2d((0.5 + x) * grid_coeff / ratio, (0.5 + y) * grid_coeff);
    glVertex2d((0.5 + x) * grid_coeff / ratio, (-0.5 + y) * grid_coeff);
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
            if (i==(-2+y)||i==(2+y)||j==(-1+x)||j==(2+x))
                Draw_Pixel(j, i);
        }
    }
}

void Draw_P(float x, float y) {
    for (float i = -2 + y; i < 3 + y; i++) {
        for (float j = -1 + x; j < 2 + x; j++) {
            if (j == (-1 + x) || i == (y) || i == (2 + y) || (j==(1+x)&&i>(-1+y)))
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