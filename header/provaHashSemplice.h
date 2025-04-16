
struct User;
typedef struct User Utente;

Utente *creaUtente(const char *cf, const char *nome);
void stampaUtente(Utente *utente);
void aggiungiUtente (Utente *mappa, const char *cf, const char *nome);
