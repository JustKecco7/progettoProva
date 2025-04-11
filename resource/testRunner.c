#include "../header/testRunner.h"
#include "../header/statistiche.h"

void test(void *parametri) {
    //Qui modifico la funzione che viene chiamata nel main per i test.
    char * posFile = (char*)parametri;
    testStatistiche(posFile);
}
void testStatistiche(const char *posFile) {
    Stats *stat;
    stat = leggiStatisticheDaPos(posFile);
    stampaStatistiche(stat);
}


