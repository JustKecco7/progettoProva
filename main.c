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
void termina(const char *s, FILE *f, int errcode) ;
void stampaUtente(User *u, int colore);
User *leggiUtente(FILE *f);




int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso:\n\t%s nomefile.txt\n",argv[0]);
        return 0;
    }
    FILE *f = fopen( argv[1], "r" );
    if (f == NULL)
        termina("Errore lettura file.", stderr, -1);

    h = GetStdHandle(STD_OUTPUT_HANDLE);


    printf("====== Prova Hash Table ======\n");

    User  *listaUsers = NULL;

    //User *utente = creaUtente("VRGFNC02D06B354M", "Francesco Vargiu", 22, 74.5);
    User *utente = leggiUtente(f);
    aggiungiUtente( listaUsers, utente );
    stampaUtente(utente, 10);


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


void termina(const char *s, FILE *f, int errcode) {
    SetConsoleTextAttribute(h, 12);
    fprintf(f, "\n\t%s\n", s);
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
    ////if (e==0) termina( "Errore lettura cf", stderr, -1);
    u->nome = malloc(sizeof(char)*NOME_MAX );
    e = fscanf(f, "%s\n", u->nome);
    ////if (e==0) termina( "Errore lettura cf", stderr, -1);
    e = fscanf(f, "%d\n", &u->eta);
    ////if (e==0) termina( "Errore lettura cf", stderr, -1);
    e = fscanf(f, "%f\n", &u->peso);
    ////if (e==0) termina( "Errore lettura cf", stderr, -1);
    return u;
}



