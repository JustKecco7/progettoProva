#include <stdio.h>


struct Statistiche;
typedef struct Statistiche Stats;

Stats *creaStatistiche(int frz, int vlc, int res, int vitaMax, int vitaAtt, int vist, int udit, int manaMax, int manaAtt);
void copiaStatistiche(Stats *stat1, Stats *stat2);
void stampaStatistica(Stats *stat);
void stampaStatistiche(Stats *stat[], int size);
void distruggiStatistiche(Stats *stat);
Stats *leggiStatisticaDaPos(const char* posizione);
Stats **leggiStatisticheDaPos(const char* posizione, int *dim);
Stats *leggiStatisticheDaFile(FILE *f);
