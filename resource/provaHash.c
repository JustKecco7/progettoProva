#include "../header/provaHash.h"
#include "../uthash/uthash.h"
#include "../utili/costanti.h"
#include "../header/statistiche.h"
#include <string.h>
#include "../header/errori.h"


struct MostroProva {
    char chiave[ 30 ] ;
    Stats *satistiche;
    UT_hash_handle hh;
};

void stampaMostroProva(MostroProva *mP) {
    if (mP == NULL)
        termina("Passato valore null.", stderr, -1, __LINE__, __FILE__);
    printf("==========Mostro prova=========\n");
    printf("NOME: %s\n",mP->chiave);
    stampaStatistica(mP->satistiche);
}

void mainFunction(const char *path) {
    MostroProva *mappa = NULL;
    MostroProva *temp = NULL;

    int size;
    Stats **listaStatistiche = leggiStatisticheDaPos(path, &size);
    char *nomi[] = {"Bee", "Radesh", "Samson", "Circe", "Doraemon", "Suzune", "Trittica", "Underbart"};
    int nomiSize = 8;


    for (int i = 0; i<size; i++) {
        temp = malloc( sizeof(MostroProva)  );
        if (temp == NULL)
            termina("Fallita malloc.", stderr, -1, __LINE__, __FILE__);
        strcpy(temp->chiave, nomi[i%nomiSize]);
        temp->satistiche = malloc(sizeof(listaStatistiche));
        if (temp->satistiche == NULL)
            termina("Fallita malloc.", stderr, -1, __LINE__, __FILE__);
        copiaStatistiche(temp->satistiche, listaStatistiche[i]);
        HASH_ADD_STR(mappa, chiave, temp);
    }

    //ORA PROVO UNA RICERCA
    MostroProva *mostroCercato;
    HASH_FIND_STR(mappa, nomi[3], mostroCercato);
    if (mostroCercato == NULL)
        printf("Chiave non trovata.\n");
    else
        stampaMostroProva(mostroCercato);

    printf("\t ==========Fine prova.=============");



}