#ifndef KORISNIK_H
#define KORISNIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct {
    char ime[MAX_LEN];
    char prezime[MAX_LEN];
    char korisnickoIme[MAX_LEN];
    char lozinka[MAX_LEN];
} Korisnik;

// Funkcije deklarirane u korisnik.h
const char* provjeriJacinuLozinke(const char* lozinka);
void generirajLozinku(char* lozinka, size_t velicina);
int korisnickoImePostoji(const char* korisnickoIme);
int registracija();
int prijava();
int promjenaKorisnickogImena(Korisnik* korisnik);
int promjenaLozinke(Korisnik* korisnik);
void brisanjeKorisnickogRacuna(Korisnik* korisnik);
void prikaziIzbornik();
void prikaziSveKorisnike();
void ocistiBuffer();

#endif
