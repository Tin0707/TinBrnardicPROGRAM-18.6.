#include <stdio.h>

// Funkcija za ?i�?enje buffera
void ocistiBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
