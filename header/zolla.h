#include "evento.h"
#include <stdio.h>

struct zolla;
typedef struct zolla Zolla;


Zolla *creaZolla();
Zolla *copiaZolla(Zolla *zolla);
void stampaZolla(Zolla *zolla);
void distruggiZolla(Zolla *zolla);
Zolla *leggiZollaDaPos(const char *posizione);
Zolla *leggiZollaDaFile(FILE *f);
