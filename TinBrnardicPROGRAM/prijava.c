#define _CRT_SECURE_NO_WARNINGS

#include "Korisnik.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* Funkcija za prijavu postojećeg korisnika */
int prijava() {
    char* korisnickoIme = (char*)malloc(MAX_LEN * sizeof(char));
    char* lozinka = (char*)malloc(MAX_LEN * sizeof(char));

    // Provjera alokacije memorije
    if (korisnickoIme == NULL || lozinka == NULL) {
        perror("\n~Greska prilikom alokacije memorije~\n\n");
        return 0;
    }

    // Unos korisničkog imena
    printf("\nUnesite korisnicko ime (ili * za povratak): ");
    fgets(korisnickoIme, MAX_LEN, stdin);
    korisnickoIme[strcspn(korisnickoIme, "\n")] = 0;
    if (strcmp(korisnickoIme, "*") == 0) {
        free(korisnickoIme);
        free(lozinka);
        return 0;
    }

    // Unos lozinke
    printf("Unesite lozinku (ili * za povratak): ");
    fgets(lozinka, MAX_LEN, stdin);
    lozinka[strcspn(lozinka, "\n")] = 0;
    if (strcmp(lozinka, "*") == 0) {
        free(korisnickoIme);
        free(lozinka);
        return 0;
    }

    // Provjera korisnika u datoteci
    FILE* file = fopen("korisnici.bin", "rb");
    if (!file) {
        perror("\n~Greska prilikom otvaranja datoteke\n\n");
        return 0;
    }

    Korisnik k;
    while (fread(&k, sizeof(Korisnik), 1, file)) {
        if (strcmp(k.korisnickoIme, korisnickoIme) == 0 && strcmp(k.lozinka, lozinka) == 0) {
            fclose(file);
            printf("\n**Bok %s %s!**\n\n", k.ime, k.prezime);

            // Ispis izbornika za registriranog korisnika
            char unos[4];
            do {
                printf("1. Promjena korisnickog imena\n2. Promjena lozinke\n3. Brisanje korisnickog racuna\n4. Izlaz\n");
                printf("Odaberite opciju: ");
                fgets(unos, sizeof(unos), stdin);

                if (strchr(unos, '\n') == NULL) {
                    ocistiBuffer();
                }

                if (strlen(unos) != 2 || (unos[0] < '1' || unos[0] > '4')) {
                    printf("\n~Neispravan unos~\n\n");
                    continue;
                }

                // Obrada odabira korisnika
                switch (unos[0]) {
                case '1':
                    if (promjenaKorisnickogImena(&k)) {
                        printf("\n~Promjena korisnickog imena uspjesna~\n\n");
                    }
                    else {
                        printf("\n~~Povratak na izbornik~~\n\n");
                    }
                    break;
                case '2':
                    if (promjenaLozinke(&k)) {
                        printf("\n~Promjena lozinke uspjesna~\n\n");
                    }
                    else {
                        printf("\n~~Povratak na izbornik~~\n\n");
                    }
                    break;
                case '3':
                    brisanjeKorisnickogRacuna(&k);
                    printf("\n~Brisanje korisnickog racuna uspjesno~\n");
                    return 0;
                case '4':
                    printf("\n~Izlaz iz korisnickog izbornika~\n");
                    return 1;
                default:
                    printf("\n~Neispravan unos~\n");
                    break;
                }
            } while (1);
        }
    }
    fclose(file);
    printf("\n~Pogresno korisnicko ime ili lozinka~\n\n");

    free(korisnickoIme);
    free(lozinka);

    return 0;
}