cmake_minimum_required(VERSION 3.0.0)
project(arknights-stamina-calculator VERSION 2.2.0)

include(CTest)
enable_testing()

add_executable(arknights-stamina-calculator src/main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
