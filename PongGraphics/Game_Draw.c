#ifdef WINDOWS_PONG_VISUAL_STUDIO
#include <Game_Draw.h>
#endif  // WINDOWS_PONG_VISUAL_STUDIO
#ifdef WINDOWS_PONG_GCC
#include "include/Game_Draw.h"
#endif  // WINDOWS_PONG_GCC

float ratio;

const float DEG2RAD;

void Draw_Ball(T_Ball bll) {
  glColor3f(bll.color.r, bll.color.g, bll.color.b);
  glBegin(GL_POLYGON);
  for (float i = 0; i < 360; i++) {
    glVertex2d((cos(DEG2RAD * i) * bll.radius + bll.x),
               (sin(DEG2RAD * i) * bll.radius /** ratio*/ + bll.y));
  }
  glEnd();
}

void Draw_Racket(T_Racket racket) {
  glColor3f(racket.color.r, racket.color.g, racket.color.b);
  glBegin(GL_POLYGON);
  glVertex2d(racket.x - racket.x_size / 2,
             (racket.y - racket.y_size / 2) /** ratio*/);
  glVertex2d(racket.x + racket.x_size / 2,
             (racket.y - racket.y_size / 2) /** ratio*/);
  glVertex2d(racket.x + racket.x_size / 2,
             (racket.y + racket.y_size / 2) /** ratio*/ );
  glVertex2d(racket.x - racket.x_size / 2,
             (racket.y + racket.y_size / 2) /** ratio*/ );
  glEnd();
  glBegin(GL_POLYGON);
  /*for (float i = 0; i < 360; i++) {
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
  glEnd();*/
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