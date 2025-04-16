cmake_minimum_required(VERSION 3.30)
project(progettoProva C)

set(CMAKE_C_STANDARD 11)


add_executable(progettoProva
        header/grafo.h
        resource/grafo.c
        main.c
        header/errori.h
        resource/errori.c
        header/personaggio.h
        resource/personaggio.c
        utili/enum.h
        utili/costanti.h
        header/statistiche.h
        resource/statistiche.c
        header/testRunner.h
        resource/testRunner.c
        header/zolla.h
        resource/zolla.c
        header/evento.h
        resource/evento.c
        resource/provaHash.c
        header/provaHash.h
        header/provaHashSemplice.h
        resource/provaHashSemplice.c)
