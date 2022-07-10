# ---------------------------------------------------------------------------
# This project is a self-taught exercise. For more examples of various coding
# projects, please see my GitHub portfolio at https://github.com/JayMassey98.
# ---------------------------------------------------------------------------

# ---------------------------------------
# Eight Queens Problem CMake Project File
# ---------------------------------------

cmake_minimum_required (VERSION 3.8)

# Specify that the project is C++, not C.
project ("eight-queens-algorithm")

# Add source to this project's executable.
add_executable (eight-queens-algorithm "eight-queens-algorithm.cpp" "eight-queens-algorithm.h")

if (MSVC)
    # Warning level 4 and all warnings as errors.
    add_compile_options(/W4 /WX)
else()
    # Lots of warnings and all warnings as errors.
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
