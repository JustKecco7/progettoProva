#include "../header/errori.h"

void termina(const char *s, FILE *f, int errcode, int linea, const char* pos) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 12);
    fprintf(f, "\n\t%s\n\tfile: %s linea %d\n", s, pos, linea);
    SetConsoleTextAttribute(h, 7);
    exit(errcode);
}