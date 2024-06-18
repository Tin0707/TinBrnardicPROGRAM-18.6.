#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Korisnik.h"
#include "globalneVarijable.h"

// Funkcija za prikaz izbornika
void prikaziIzbornik() {
    char unos[4];
    do {
        // Ispisujemo izbornik
        printf("1. Registracija\n2. Prijava\n3. Prikaz svih korisnika\n4. Izlaz\n");
        printf("Vas odabir: ");

        // Čitamo korisnikov unos
        if (fgets(unos, sizeof(unos), stdin) == NULL) {
            continue; // U slučaju neuspješnog čitanja, preskačemo
        }

        // Provjeravamo je li korisnik unio više od jednog znaka ili neispravan broj
        if (strchr(unos, '\n') == NULL) {
            ocistiBuffer(); // Ako je korisnik unio previše znakova, čistimo buffer
        }

        if (strlen(unos) != 2 || (unos[0] < '1' || unos[0] > '4')) {
            printf("\n~Neispravan unos~\n\n"); // Ako unos nije u rasponu 1-4, ispisujemo grešku
            continue; // I vraćamo se na početak petlje
        }

        // Obrada odabira korisnika
        switch (unos[0]) {
        case '1':
            // Poziv funkcije za registraciju
            if (registracija()) {
                printf("\n~Registracija uspjesna~\n\n");
            }
            else {
                printf("\n~~Povratak na pocetni izbornik~~\n\n");
            }
            break;
        case '2':
            // Poziv funkcije za prijavu
            if (prijava()) {
                printf("\n"); // Ako je prijava uspješna, samo prelazimo u novi red
            }
            else {
                printf("\n~~Povratak na pocetni izbornik~~\n\n");
            }
            break;
        case '3':
            prikaziSveKorisnike(); // Prikaz svih korisnika
            break;
        case '4':
            printf("\n~Izlaz iz programa~\n");
            return; // Izlaz iz programa
        default:
            printf("\n~Neispravan unos~\n\n");
            break;
        }
    } while (1); // Petlja se vrti dok korisnik ne odabere izlaz
}