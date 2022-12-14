add_library(net STATIC src/base.cpp)
target_include_directories(net
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  )