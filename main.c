#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <string.h>

#define CF_MAX 20
#define NOME_MAX 20

#include "uthash/uthash.h"

struct Utente {
    char *cf;
    char *nome;
    int eta;
    float altezza;
    UT_hash_handle hh;
};

typedef struct Utente User;

User *creaUtente(char *p_cf, char *p_nome, int p_eta, float p_altezza);

int main(int argc, char* argv[]) {
    printf("====== Prova Hash Table ======\n");

    int dim = 10;
    User  *listaUsers = malloc(sizeof(User) * dim);



    return 0;
}



User *creaUtente(char *p_cf, char *p_nome, int p_eta, float p_altezza) {
    User *u;
    u = malloc(sizeof(User) );
    u->cf = malloc(sizeof(char)*CF_MAX );
    strcpy(u->cf, p_cf);
    u->nome = malloc(sizeof(char)*NOME_MAX );
    strcpy(u->nome, p_nome);
    u->eta = p_eta;
    u->altezza = p_altezza;
    return u;
}









