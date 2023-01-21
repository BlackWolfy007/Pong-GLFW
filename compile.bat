if not exist ".\build" (echo "") else (rd /S/Q build)
mkdir build
gcc -Wextra -Werror -I. -o .\build\Pong.exe .\PongGraphics\main.c -L.\PongGraphics\libs\Windows\lib-mingw -lglfw3 -lopengl32 -lmingw32 -lgdi32 -luser32 -lkernel32
echo "Compilation is done."