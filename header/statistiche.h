#include <stdio.h>


struct Statistiche;
typedef struct Statistiche Stats;

Stats *creaStatistiche(int frz, int vlc, int res, int vitaMax, int vitaAtt, int vist, int udit, int manaMax, int manaAtt);
Stats *copiaStatistiche(Stats *stat);
void stampaStatistiche(Stats *stat);
void distruggiStatistiche(Stats *stat);
Stats *leggiStatisticheDaPos(const char* posizione);
Stats *leggiStatisticheDaFile(FILE *f);
