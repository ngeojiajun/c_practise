add_library(stdlib STATIC 
src/strings.c
include/strings_utils.h
src/array.c
include/array.h
include/math.h
)
target_include_directories(stdlib
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)