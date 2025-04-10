#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define CF_MAX_ 20
#define NOME_MAX 30
HANDLE h;

#include "uthash/uthash.h"

struct Utente {
    char *cf;
    char *nome;
    int eta;
    float peso;
    UT_hash_handle hh;
};

typedef struct Utente User;

User *creaUtente(char *p_cf, char *p_nome, int p_eta, float p_peso);
void aggiungiUtente(User *hash, User *u);
void aggiungiUtente_(User *hash, char *p_cf, char *p_nome, int p_eta, float p_peso);
void termina(const char *s, FILE *f, int errcode, int linea) ;
void stampaUtente(User *u, int colore);
User *leggiUtente(FILE *f);
User ** leggiUtenti(FILE *f, User *hash, int *dimensione);



int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso:\n\t%s nomefile.txt\n",argv[0]);
        return 0;
    }
    FILE *f = fopen( argv[1], "r" );
    if (f == NULL)
        termina("Errore lettura file.", stderr, -1, __LINE__);

    h = GetStdHandle(STD_OUTPUT_HANDLE);


    printf("====== Prova Hash Table ======\n");

    User  *listaUsers = NULL;
    int size;

    printf("====== Leggo utenti da %s =======\n",argv[1]);
    leggiUtenti(f, listaUsers, &size);
    printf("====== Lettura completata. ======\n");
    printf("====== Stampo l utente BRTGRG01C12H223D ======\n");
    char * cf = "BRTGRG01C12H223D";
    User *uToPrint;
    HASH_FIND_STR(listaUsers, cf, uToPrint);
    stampaUtente( uToPrint, 10 );
    printf("===== Ottimo =====\n");
    fclose(f);
    return 0;
}



User *creaUtente(char *p_cf, char *p_nome, int p_eta, float p_peso) {
    User *u;
    u = malloc(sizeof(User) );
    u->cf = malloc(sizeof(char)*CF_MAX_ );
    strcpy(u->cf, p_cf);
    u->nome = malloc(sizeof(char)*NOME_MAX );
    strcpy(u->nome, p_nome);
    u->eta = p_eta;
    u->peso = p_peso;
    return u;
}

void aggiungiUtente(User *hash, User *u) {
    HASH_ADD_STR(hash, cf, u);
}

void aggiungiUtente_(User *hash, char *p_cf, char *p_nome, int p_eta, float p_peso) {
    User *u;
    u = malloc(sizeof(User) );
    u->cf = malloc(sizeof(char)*CF_MAX_ );
    strcpy(u->cf, p_cf);
    u->nome = malloc(sizeof(char)*NOME_MAX );
    strcpy(u->nome, p_nome);
    u->eta = p_eta;
    u->peso = p_peso;
    HASH_ADD_STR(hash, cf, u);
}


void termina(const char *s, FILE *f, int errcode, int linea) {
    SetConsoleTextAttribute(h, 12);
    fprintf(f, "\n\t%s in linea %d\n", s, linea);
    SetConsoleTextAttribute(h, 7);
    exit(errcode);
}



void stampaUtente(User *u, int colore) {
    SetConsoleTextAttribute(h, colore);
    printf("+==========================================+\n");
    printf("CV: %s\n",u->cf);
    printf("NOME: %s\n",u->nome);
    printf("ETA: %d\n",u->eta);
    printf("PESO: %3.1f\n",u->peso);
    printf("+==========================================+\n");
    SetConsoleTextAttribute(h, 7);
}



User *leggiUtente(FILE *f) {
    User *u;
    int e;
    u = malloc(sizeof(User) );
    u->cf = malloc(sizeof(char)*CF_MAX_ );
    e = fscanf(f, "%s\n", u->cf);
    ////if (e==0) termina( "Errore lettura cf", stderr, -1, __LINE__);
    u->nome = malloc(sizeof(char)*NOME_MAX );
    e = fscanf(f, "%s\n", u->nome);
    ////if (e==0) termina( "Errore lettura cf", stderr, -1, __LINE__);
    e = fscanf(f, "%d\n", &u->eta);
    ////if (e==0) termina( "Errore lettura cf", stderr, -1, __LINE__);
    e = fscanf(f, "%f\n", &u->peso);
    ////if (e==0) termina( "Errore lettura cf", stderr, -1, __LINE__);
    return u;
}

User ** leggiUtenti(FILE *f, User *hash, int *dimensione) {
    User **listaUtenti;
    int e;

    fscanf(f,"%d\n",dimensione);
    int n = *dimensione;
    listaUtenti = (User**) malloc( sizeof(User*) * n );

    for (int i = 0; i<n; i++) {
        listaUtenti[i] = malloc(sizeof(User) );
        listaUtenti[i]->cf = malloc(sizeof(char)*CF_MAX_ );
        fscanf(f, "%s\n", listaUtenti[i]->cf);
        listaUtenti[i]->nome = malloc(sizeof(char)*NOME_MAX );
        fscanf(f, "%s\n", listaUtenti[i]->nome);
        fscanf(f, "%d\n", &listaUtenti[i]->eta);
        fscanf(f, "%f\n", &listaUtenti[i]->peso);
        aggiungiUtente(hash, listaUtenti[i]);
    }
    return listaUtenti;
}

