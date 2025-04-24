cmake_minimum_required(VERSION 3.10)
project(
  ISOLITE_CMAKE
  VERSION 0.1.0
  DESCRIPTION "A game engine geared towards isometric style games"
  LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ##############################################################################
# ###### PROJECT DIRECTORIES ###################################################
# ##############################################################################

add_subdirectory(include/isolite/)
add_subdirectory(lib/doctest)
add_subdirectory(src)
add_subdirectory(tests)
