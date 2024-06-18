#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include "globalneVarijable.h"
#include <stdio.h>
#include <string.h>

// Funkcija za promjenu korisni?kog imena
int promjenaKorisnickogImena(Korisnik* korisnik) {
    char novoIme[MAX_LEN];
    printf("\nUnesite novo korisnicko ime (ili * za povratak): ");
    scanf("%s", novoIme);
    ocistiBuffer();
    if (strcmp(novoIme, "*") == 0) return 0;

    // Provjera postojanja novog korisni?kog imena
    if (korisnickoImePostoji(novoIme)) {
        printf("\n~Korisnicko ime je vec zauzeto~\n\n");
        return 0;
    }

    FILE* file = fopen("korisnici.bin", "rb+");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke~\n\n");
        return 0;
    }

    long int trenutnaPozicija;
    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnik->korisnickoIme) == 0) {
            trenutnaPozicija = ftell(file) - sizeof(Korisnik);
            fseek(file, trenutnaPozicija, SEEK_SET);
            strcpy(korisnik->korisnickoIme, novoIme);
            fwrite(korisnik, sizeof(Korisnik), 1, file);
            break;
        }
    }
    fclose(file);

    return 1;
}