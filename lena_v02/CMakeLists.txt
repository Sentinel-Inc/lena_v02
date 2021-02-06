# CMakeList.txt: projekt CMake dla elementu lena_v02, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (lena_v02 "lena_v02.cpp" "lena_v02.h" "obraz.h"  "pgm.h" "pgm.cpp" "ppm.h" "ppm.cpp" "_24bit_pixel.cpp" "_24bit_pixel.h" "_8bit_pixel.cpp" "_8bit_pixel.h" "obraz.cpp" )

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
