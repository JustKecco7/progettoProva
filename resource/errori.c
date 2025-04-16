#include "../header/errori.h"

void termina(const char *s, FILE *f, int errcode, int linea, const char* pos) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 12);
    fprintf(f, "\n\t%s\n\tfile: %s linea %d\n", s, pos, linea);
    SetConsoleTextAttribute(h, 7);
    exit(errcode);
}



void fflag(int pos, const char *file) {
    idFlag += 1;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 13);
    printf( "#Flag %d: linea %d in file %s\n", idFlag, pos, file);
    SetConsoleTextAttribute(h, 7);
}