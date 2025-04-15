#include "../header/testRunner.h"

#include "../header/errori.h"
#include "../header/statistiche.h"
#include "../header/provaHash.h"


void test(void *parametri) {
    //Qui modifico la funzione che viene chiamata nel main per i test.
    char * posFile = (char*)parametri;
    testUTHASH(posFile);
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


