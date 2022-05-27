# version 3.15 or later of CMake needed for GoogleTest on Windows
# so let's require it now.
cmake_minimum_required(VERSION 3.11-3.18)

project(model)

set(BUILD_SHARED_LIBS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS True)

add_library(model src/model.cpp)

# PUBLIC needed to make both model.h and model library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Tell compiler to use C++20 features. The code doesn't actually use any of them.
target_compile_features(model PUBLIC cxx_std_20)

add_custom_command(TARGET model POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:model>"
     "../apps/$<CONFIGURATION>/$<TARGET_FILE_NAME:model>" 
  COMMENT "Copying to output directory")

  add_custom_command(TARGET model POST_BUILD 
  COMMAND "${CMAKE_COMMAND}" -E copy 
     "$<TARGET_FILE:model>"
     "../tests/$<CONFIGURATION>/$<TARGET_FILE_NAME:model>" 
  COMMENT "Copying to tests directory")