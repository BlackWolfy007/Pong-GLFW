# Pong GLFW

## Getting the code

The easiest way to get hold of the pong glfw is to run the following command using a shell you can run git from:

```
git clone --recursive https://github.com/b3r8t3r/Pong-GLFW.git
```

## Using CMake to create the project

From a command prompt in the `GLFW-CMake-starter` directory:
1. `mkdir build`
1. `cd build`
1. `cmake ..` (for MinGW the build system generator needs to be specified using the -G option: `cmake .. -G "MinGW Makefiles"`)
1. Either run `make all` or for Visual Studio open `GLFW-CMake-starter.sln` or for MinGW run `mingw32-make`

