cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

# TODO: Cambien acá el nombre del proyecto
project(calculadora)

enable_language(CXX)

# TODO: Cambien acá la versión de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules/)

# TODO: Pueden activar esto cuando vayan terminando el proyecto, para que les avise si no llegan a la cobertura deseada
# set(GCOVR_ADDITIONAL_ARGS --fail-under-line 90 --fail-under-branch 80)

add_subdirectory(src)
add_subdirectory(tests)
