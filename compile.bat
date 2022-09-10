mkdir build
gcc -Wall -Wextra -Werror -I. -o .\build\Pong.exe .\PongGraphics\main.c -L.\PongGraphics\libs\
-lglfw3 -lopengl32 -lmingw32 -lgdi32 -luser32 -lkernel32