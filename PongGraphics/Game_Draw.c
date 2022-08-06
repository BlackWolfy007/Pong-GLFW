#include "Game_Draw.h"

float ratio;

const float DEG2RAD = 3.14159 / 100;

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
             (racket.y + racket.y_size / 2) * ratio );
  glVertex2d(racket.x - racket.x_size / 2,
             (racket.y + racket.y_size / 2) * ratio );
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
  float y = 18;

  for (int i = -8; i < 9; i += 4) {
    if (i < 0) {
      Draw_Num((i < -5) ? score.Player_1 / 10 : score.Player_1 % 10, i, y);
    } else if (i > 0) {
      Draw_Num((i < 5) ? score.Player_1 / 10 : score.Player_1 % 10, i, y);
    } else {
      Draw_Colon(i, y);
    }
  }
}