cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

project(Pong_GLFW)		# Название проекта

include_directories("PongGraphics/include")

add_definitions(-D_CMAKE_)

set(SOURCE_DIR PongGraphics/)

set(SOURCE_EXE 	${SOURCE_DIR}main.c)		# Установка переменной со списком исходников

#include_directories(glfw)			# Расположение заголовочных файлов

add_executable(Pong ${SOURCE_EXE})	# Создает исполняемый файл с именем main

#add_subdirectory(glfw)				# Добавление подпроекта, указывается имя дирректории

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

#target_include_directories(gltuto PUBLIC
#                           $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
#                           $<INSTALL_INTERFACE:include>)

target_link_libraries(Pong -lm glfw OpenGL::GL ${CMAKE_DL_LIBS})		# Линковка программы с библиотекой
#target_link_libraries(gltuto PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})
