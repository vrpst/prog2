cmake_minimum_required(VERSION 3.10)

project(sdl2-test)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

add_executable(sdl2-test src/main.c)

target_compile_options(sdl2-test PRIVATE
	$<$<CONFIG:>:
        -Wall -Wextra -Wpedantic -fsanitize=address,undefined
    >
)

target_link_options(sdl2-test PRIVATE 
	$<$<CONFIG:>:
        -fsanitize=address,undefined
    >
)

target_link_libraries(sdl2-test PRIVATE SDL2::SDL2)
