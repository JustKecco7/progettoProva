
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
Stats *copiaStatistiche(Stats *stat) {
    if (stat == NULL)
        termina("Valore passato non valido.", stderr, -1, __LINE__, __FILE__);
    Stats *newStat = malloc(sizeof(Stats));
    if (newStat == NULL)
        termina("Errore malloc.", stderr, -1, __LINE__, __FILE__);
    newStat->forza = stat->forza;
    newStat->velocita = stat->velocita;
    newStat->resistenza = stat->resistenza;
    newStat->vitaMassima = stat->vitaMassima;
    newStat->vitaRimasta = stat->vitaRimasta;
    newStat->vista = stat->vista;
    newStat->udito = stat->udito;
    newStat->manaMassimo = stat->manaMassimo;
    newStat->manaRimasto = stat->manaRimasto;
    return newStat;
}
void stampaStatistiche(Stats *stat) {
    if (stat == NULL)
        termina("Valore passato non valido.", stderr, -1, __LINE__, __FILE__);
    printf("Forza: %d\n", stat->forza);
    printf("Velocita: %d\n", stat->velocita);
    printf("Resistenza: %d\n", stat->resistenza);
    printf("Vita: %d/%d\n", stat->vitaRimasta, stat->vitaRimasta);
    printf("Vista: %d\n", stat->vista);
    printf("Udito: %d\n", stat->udito);
    printf("Mana: %d/%d\n", stat->manaRimasto, stat->manaMassimo);
    printf("================================================\n");
}
void distruggiStatistiche(Stats *stat) {
    if (stat == NULL) return;
    free(stat);
}
Stats *leggiStatisticheDaPos(const char* posizione) {
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
































