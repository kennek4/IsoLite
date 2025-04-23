cmake_minimum_required(VERSION 3.10)
project(ISOLITE VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create an option to switch between a system sdl library and a vendored SDL
# library
option(ISOLITE_VENDORED "Use vendored libraries" OFF)

if(ISOLITE_VENDORED)
  # This assumes you have added SDL as a submodule in vendored/SDL
  add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
  # 1. Look for a SDL3 package,
  # 2. look for the SDL3-shared component, and
  # 3. fail if the shared component cannot be found.
  find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
  find_package(SDL3_image REQUIRED) # Find the SDL3_image package
endif()

# Get OpenGL Packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)

# Source files
set(MAIN_FILE src/main.cpp)

# Create your game executable target as usual
add_executable(ISOLITE ${MAIN_FILE} ${CORE_EVENTS} ${CORE_SYSTEMS})
target_include_directories(
  ISOLITE PRIVATE src)

# Link to the actual SDL3 library.
target_link_libraries(ISOLITE PRIVATE glm::glm SDL3_image::SDL3_image SDL3::SDL3
                                      OpenGL::OpenGL)
