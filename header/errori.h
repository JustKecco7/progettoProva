#include <stdio.h>
#include <windows.h>

static int idFlag = 0;

void fflag(int pos, const char *file);
void termina(const char *s, FILE *f, int errcode, int linea, const char* pos) ;