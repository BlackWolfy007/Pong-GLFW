# Commamds and params
CC=gcc
flags=-Wall -Wextra -Werror
cl_format=clang-format -i
# Prog
executeable=-o ../../build/Pong
# Directoties
sources_c=../../PongGraphics/*.c
sources_h=../../PongGraphics/*.h
# Mac libs
Mac_Os_dir=../../PongGraphics/libs/Mac_Os/
Mac_Os_arm=lib-arm64/
Mac_Os_universal=lib-universal/
Mac_Os_x86_x64=lib-x86_x64/
# Libs in build
libs_build_dir=../../build/libs
# Static lib
glfw3_stat=libglfw3.a
# Dynamic lib
glfw3_dynamic=libglfw.3.dylib

# Macro
Mac_Pong=-DMAC_OS_PONG

all: build

build:
	$(CC) $(Mac_Pong) $(executeable) $(Mac_Pong) $(sources)
	mkdir $(libs_build_dir)
	cp $(Mac_Os_dir)$(Mac_Os_universal)$(glfw3_dynamic) $(libs_build_dir)

build_with_flags:
	$(CC) $(Mac_Pong) $(flags) $(executeable) $(Mac_Pong) $(sources)

format:
	$(cl_format) $(sources_c)
	$(cl_format) $(sources_h)

