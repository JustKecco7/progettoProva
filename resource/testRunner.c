#include "../header/testRunner.h"

#include "../header/errori.h"
#include "../header/statistiche.h"
#include "../header/provaHash.h"


void test(void *parametri) {
    //Qui modifico la funzione che viene chiamata nel main per i test.
    char * posFile = (char*)parametri;
    if(posFile == NULL)
        termina("Errore conversione parametri.", stderr, -1, __LINE__, __FILE__);
    fflag(__LINE__, __FILE__);
    testUTHASH(posFile);
}
void testStatistiche(const char *posFile) {
    Stats **stat;
    int size = 0;
    stat = leggiStatisticheDaPos(posFile, &size);
    stampaStatistiche(stat, size);
}


void testUTHASH(const char *posFile) {
    fflag(__LINE__, __FILE__);
    mainFunction(posFile);
}


