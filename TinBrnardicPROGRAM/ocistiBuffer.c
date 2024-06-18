#include <stdio.h>

// Funkcija za ?iš?enje buffera
void ocistiBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
