#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <string.h>

// Funkcija koja provjerava postoji li korisni?ko ime u datoteci korisnika
int korisnickoImePostoji(const char* korisnickoIme) {
    FILE* file = fopen("korisnici.bin", "rb"); // Otvaranje binarne datoteke "korisnici.bin" za ?itanje
    if (!file) return 0; // Ako datoteka ne postoji, vrati 0 (ne postoji korisni?ko ime)

    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) { // ?itanje svakog zapisa o korisniku iz datoteke
        if (strcmp(k.korisnickoIme, korisnickoIme) == 0) { // Usporedba korisni?kog imena s traženim imenom
            fclose(file); // Zatvaranje datoteke nakon što je korisnik prona?en
            return 1; // Vrati 1 (korisni?ko ime postoji)
        }
    }

    fclose(file); // Zatvaranje datoteke ako korisni?ko ime nije prona?eno
    return 0; // Vrati 0 (korisni?ko ime ne postoji)
}
