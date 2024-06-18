#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"

// Funkcija za brisanje korisni?kog ra?una
void brisanjeKorisnickogRacuna(Korisnik* korisnik) {
    FILE* file = fopen("korisnici.bin", "rb");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke\n\n");
        return;
    }

    FILE* temp = fopen("temp.bin", "wb");
    if (!temp) {
        perror("\n~Greska prilikom otvaranja privremene datoteke\n\n");
        fclose(file);
        return;
    }

    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnik->korisnickoIme) != 0) {
            // Zapisivanje svih korisnika osim onog koji se briše
            fwrite(&k, sizeof(Korisnik), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    // Brisanje originalne datoteke i preimenovanje privremene
    remove("korisnici.bin");
    rename("temp.bin", "korisnici.bin");
}
