#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include "globalneVarijable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Funkcija za promjenu lozinke korisnika
int promjenaLozinke(Korisnik* korisnik) {
    char novaLozinka[MAX_LEN];
    printf("\nUnesite novu lozinku (ili * za povratak): ");
    scanf("%s", novaLozinka);
    ocistiBuffer();
    if (strcmp(novaLozinka, "*") == 0) return 0;

    // Provjera jakosti nove lozinke
    const char* jakost = provjeriJacinuLozinke(novaLozinka);
    printf("\nJakost nove lozinke: %s\n", jakost);

    FILE* file = fopen("korisnici.bin", "rb+");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke~\n\n");
        return 0;
    }

    long int trenutnaPozicija;
    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnik->korisnickoIme) == 0) {
            // Prona?en korisnik, pa se postavlja položaj za ažuriranje
            trenutnaPozicija = ftell(file) - sizeof(Korisnik);
            fseek(file, trenutnaPozicija, SEEK_SET);

            // Kopiranje nove lozinke u strukturu korisnika
            strcpy(korisnik->lozinka, novaLozinka);

            // Ažuriranje korisni?kog zapisa u datoteci
            fwrite(korisnik, sizeof(Korisnik), 1, file);
            break;
        }
    }

    fclose(file);

    printf("\n~Lozinka uspjesno promijenjena~\n\n");
    return 1;
}
