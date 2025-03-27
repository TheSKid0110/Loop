cmake_minimum_required(VERSION 3.10)

# Change the project name to "iterator".
project(iterator LANGUAGES CXX)

set(CMAKE_CONFIGURATION_TYPES Release Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Load the gmod-module-base project that sets up headers and settings.
add_subdirectory(include)

# Change the library name to "iterator".
add_library(iterator SHARED)

# Add the source files required for the module.
# Again, the file names don't matter and you can even add multiple files by adding more space-delimited filenames after "main.cpp".
target_sources(iterator PRIVATE main.cpp)

# Actually apply the headers and settings to our module.
target_link_libraries(iterator gmod-module-base)

set_gmod_suffix_prefix(iterator)