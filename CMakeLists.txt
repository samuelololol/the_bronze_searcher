cmake_minimum_required (VERSION 2.9)
project (The_bronze_searcher)

IF ( ${CMAKE_COMPILER_IS_GNUCC} )
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
endif()

set (The_bronze_searcher_VERSION_MAJOR 1)
set (The_bronze_searcher_VERSION_MINOR 0)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
