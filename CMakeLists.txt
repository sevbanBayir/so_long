cmake_minimum_required(VERSION 3.26)
project(so_long C)

set(CMAKE_C_STANDARD 11)

add_executable(so_long main.c
        so_long.h
        input_control.c
        haphazard/map_elements_control.c
        ft_set_window.c
        controls.c
        render.c
        walk.c)
