#include "../header/provaHashSemplice.h"
#include <stdlib.h>
#include <string.h>
#include "../uthash/uthash.h"
#include <stdio.h>

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