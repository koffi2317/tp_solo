cmake_minimum_required(VERSION 3.29)
project(tp_solo C)

set(CMAKE_C_STANDARD 11)

add_executable(tp_solo main.c
        util.h
        util.c
        terrain.h
        terrain.c
        jeu.h
        jeu.c
        interaction.h
        interaction.c
        dijkstra.h
        dijkstra.c
        couleur.c
        "couleur (2).h")
