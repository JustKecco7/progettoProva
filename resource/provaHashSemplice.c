#include "../header/provaHashSemplice.h"
#include <stdlib.h>
#include <string.h>
#include "../uthash/uthash.h"
#include <stdio.h>
#include "../header/errori.h"

struct User{
    char codiceFiscale[20];
    char nome[20];
    UT_hash_handle hh;
};

Utente *creaUtente(const char *cf, const char *nome){
  Utente *u = malloc(sizeof(Utente));
  strcpy(u->codiceFiscale, cf);
  strcpy(u->nome, nome);
  return u;
    }
void stampaUtente(Utente *utente){
     printf("Utente:\n Nome: %s\n Cf: %s\n======================\n", utente->nome, utente->codiceFiscale);
    }
void aggiungiUtente (Utente *mappa, const char *cf, const char *nome){
      Utente *u = creaUtente(cf, nome);
      HASH_ADD_STR(mappa, codiceFiscale, u);
      printf("Utente %s aggiunto.\n", u->nome);
    }


char **leggiNomi(const char *posFile, int *dimensione) {
    FILE *f = fopen(posFile, "r");
    if (f == NULL)
        termina("Apertura file fallita.", stderr, -1, __LINE__, __FILE__);
    int dimensioneArray = 10;
    int puntatoreArray = 0;
    char **listaNomi = malloc(dimensioneArray * sizeof(char *));
    if (listaNomi == NULL)
        termina("Malloc fallita.", stderr, -1, __LINE__, __FILE__);
    int errore;
    do {
        listaNomi[puntatoreArray] = malloc(sizeof (char) * 30);
        errore = fscanf(f, "%s\n", listaNomi[puntatoreArray] );
        puntatoreArray++;
        if ( puntatoreArray == dimensioneArray ) {
            dimensioneArray *= 2;
            if (realloc (listaNomi, dimensioneArray)  == NULL)
                termina("Realloc fallita.", stderr, -1, __LINE__, __FILE__);
        }
    }while (errore == 1);
    fclose(f);
    if (errore != EOF)
        termina("Lettura file fallita. Probabile formattazione errata dei dati.", stderr, -1, __LINE__, __FILE__);
    *dimensione = puntatoreArray-1;
    return listaNomi;
}


void stampaArrayNomi(char **nomi, int dimensione) {
    if (nomi == NULL)
        printf("Nessun nome è stato letto.");
    for (int i = 0; i<dimensione; i++)
        printf("%d) %s\n", i + 1, nomi[i]);
    printf("==================Fine=================\n");
}