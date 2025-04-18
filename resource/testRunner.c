#include "../header/testRunner.h"

#include "../header/errori.h"
#include "../header/statistiche.h"
#include "../header/provaHash.h"
#include "../header/provaHashSemplice.h"


void test(void *parametri) {
    //Qui modifico la funzione che viene chiamata nel main per i test.
    char * posFile = (char*)parametri;
    if(posFile == NULL)
        termina("Errore conversione parametri.", stderr, -1, __LINE__, __FILE__);
    testHashSemplice(posFile);
}
void testStatistiche(const char *posFile) {
    Stats **stat;
    int size = 0;
    stat = leggiStatisticheDaPos(posFile, &size);
    stampaStatistiche(stat, size);
}


void testUTHASH(const char *posFile) {
    mainFunction(posFile);
}

void testHashSemplice(const char *posFile) {
    char **nomi;
    int dimensione;
    nomi = leggiNomi(posFile, &dimensione);
    stampaArrayNomi(nomi, dimensione);
}


