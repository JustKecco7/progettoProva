
#include "../header/statistiche.h"
#include "../header/errori.h"
#include <stdlib.h>

struct Statistiche {
    int forza;
    int velocita;
    int resistenza;
    int vitaMassima;
    int vitaRimasta;
    int vista;
    int udito;
    int manaMassimo;
    int manaRimasto;
};


Stats *creaStatistiche(int frz, int vlc, int res, int vitaMax, int vitaAtt, int vist, int udit, int manaMax, int manaAtt) {
    Stats *stat = malloc(sizeof(Stats));
    if (stat == NULL)
        termina("Errore malloc.", stderr, -1, __LINE__, __FILE__);
    stat->forza = frz;
    stat->velocita = vlc;
    stat->resistenza = res;
    stat->vitaMassima = vitaMax;
    stat->vitaRimasta = vitaAtt;
    stat->vista = vist;
    stat->udito = udit;
    stat->manaMassimo = manaMax;
    stat->manaRimasto = manaAtt;
    return stat;
}
void copiaStatistiche(Stats *stat1, Stats *stat2) {
    stat1->forza = stat2->forza;
    stat1->velocita = stat2->velocita;
    stat1->resistenza = stat2->resistenza;
    stat1 -> vitaMassima = stat2->vitaMassima;
    stat1 -> vitaRimasta = stat2->vitaRimasta;
    stat1 -> vista = stat2->vista;
    stat1->udito = stat2->udito;
    stat1->manaMassimo = stat2->manaMassimo;
    stat1->manaRimasto = stat2->manaRimasto;
}
void stampaStatistica(Stats *stat) {
    if (stat == NULL)
        termina("Valore passato non valido.", stderr, -1, __LINE__, __FILE__);
    printf("Forza: %d\n", stat->forza);
    printf("Velocita: %d\n", stat->velocita);
    printf("Resistenza: %d\n", stat->resistenza);
    printf("Vita: %d/%d\n", stat->vitaRimasta, stat->vitaMassima);
    printf("Vista: %d\n", stat->vista);
    printf("Udito: %d\n", stat->udito);
    printf("Mana: %d/%d\n", stat->manaRimasto, stat->manaMassimo);
    printf("================================================\n");
}

void stampaStatistiche(Stats *stat[], int size) {
    if (stat == NULL)
        termina("Valore passato non valido.", stderr, -1, __LINE__, __FILE__);
    for (int i = 0; i<size; i++) {
        if (stat[i] == NULL)
            termina("Valore null nelle statistiche.", stderr, -1, __LINE__, __FILE__);
        stampaStatistica( stat[i] );
    }
}
void distruggiStatistiche(Stats *stat) {
    if (stat == NULL) return;
    free(stat);
}
Stats *leggiStatisticaDaPos(const char* posizione) {
    FILE *f = fopen(posizione, "r");
    if (f == NULL)
        termina( "Errore fopen.", stderr, -1, __LINE__, __FILE__ );
    Stats *stat = malloc(sizeof(Stats));
    if (stat == NULL)
        termina("Errore malloc.", stderr, -1, __LINE__, __FILE__ );
    int e = 0;
    e = fscanf(f, "FORZA: %d\nVELOCITA: %d\nRESISTENZA: %d\nVITAMAX: %d\nVITAATT: %d\nVISTA: %d\nUDITO: %d\nMANAMAX: %d\nMANAATT: %d\n--------------------\n"
        , &stat->forza, &stat->velocita, &stat->resistenza, &stat->vitaMassima, &stat->vitaRimasta, &stat->vista, &stat->udito, &stat->manaMassimo, &stat->manaRimasto);
    if ( e != 9 )
        termina("Errore lettura statistiche.", stderr, -1, __LINE__, __FILE__ );
    fclose(f);
    return stat;
}
Stats *leggiStatisticheDaFile(FILE *f) {
    if (f == NULL)
        termina( "Errore fopen.", stderr, -1, __LINE__, __FILE__ );
    Stats *stat = malloc(sizeof(Stats));
    if (stat == NULL)
        termina("Errore malloc.", stderr, -1, __LINE__, __FILE__ );
    int e = 0;
    e = fscanf(f, "FORZA: %d\nVELOCITA: %d\nRESISTENZA: %d\nVITAMAX: %d\nVITAATT: %d\nVISTA: %d\nUDITO: %d\nMANAMAX: %d\nMANAATT: %d\n--------------------\n"
        , &stat->forza, &stat->velocita, &stat->resistenza, &stat->vitaMassima, &stat->vitaRimasta, &stat->vista, &stat->udito, &stat->manaMassimo, &stat->manaRimasto);
    if ( e != 9 )
        termina("Errore lettura statistiche.", stderr, -1, __LINE__, __FILE__ );
    return stat;
}
Stats **leggiStatisticheDaPos(const char* posizione, int *dim) {
    FILE *f = fopen(posizione, "r");
    if (f == NULL)
        termina( "Errore fopen.", stderr, -1, __LINE__, __FILE__ );
    int statSize = 10;
    int posStat = 0;
    Stats **stat = malloc(statSize * sizeof(Stats*));
    if (stat == NULL)
        termina("Errore malloc.", stderr, -1, __LINE__, __FILE__ );
    int e = 0;

    do {
        if (posStat == statSize) {
            statSize *= 2;
            stat = malloc(statSize * sizeof(Stats*));
            if (stat == NULL)
                termina("Errore malloc.", stderr, -1, __LINE__, __FILE__ );
            }
        stat[posStat] = malloc( sizeof(Stats));
        if (stat[posStat] == NULL)
            termina("Errore malloc.", stderr, -1, __LINE__, __FILE__ );
        e = fscanf(f, "FORZA: %d\nVELOCITA: %d\nRESISTENZA: %d\nVITAMAX: %d\nVITAATT: %d\nVISTA: %d\nUDITO: %d\nMANAMAX: %d\nMANAATT: %d\n--------------------\n"
        , &stat[posStat]->forza, &stat[posStat]->velocita, &stat[posStat]->resistenza, &stat[posStat]->vitaMassima, &stat[posStat]->vitaRimasta
        , &stat[posStat]->vista, &stat[posStat]->udito, &stat[posStat]->manaMassimo, &stat[posStat]->manaRimasto);
        if ( e != 9 && e != EOF )
            termina("Errore lettura statistiche.", stderr, -1, __LINE__, __FILE__ );
        posStat ++ ;
    }while ( e != EOF );
    fclose(f);

    //diminuisco staSize di uno perché era stato incrementato nel while prima dell ultima lettura.
    *dim = posStat -1;
    return stat;
}
































