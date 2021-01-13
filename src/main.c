#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "time.c"

void getHM(int m, int* hm) {
    *(hm + 0) = 0; // ore
    *(hm + 1) = m; // minuti

    while (*(hm + 1) - 60 >= 0) {
        *(hm + 0) += 1;
        *(hm + 1) -= 60;
    }

    *(hm + 1) = m + 6;
}

void getHMD(int h, int m, int refill, int missing, int max, int* hmd) {
    *(hmd + 0) = h; // ore
    *(hmd + 1) = m + refill; // minuti
    *(hmd + 2) = 0; // nuovo giorno

    if (missing + 1 <= max)
        *(hmd + 1) -= 6; //1 di sanity in più per ovviare all'arrotondamento per difetto

    while (*(hmd + 1) - 60 >= 0) {
        *(hmd + 0) += 1;
        *(hmd + 1) -= 60;
    }

    if (*(hmd + 0) >= 24) {
        *(hmd + 0) -= 24;
        *(hmd + 2) = 1;
    }

    *(hmd + 1) += 6;

}

int main() {
    int stamina, max_stamina, missing_stamina;
    int tempo_refill;
    int h, m;
    int hmd[3];

data_input:
    printf("Inserisci la quantita' di stamina che possiedi in questo momento: ");
    scanf("%d", &stamina);

    printf("Inserisci la quantita' massima di stamina che puoi possedere: ");
    scanf("%d", &max_stamina);

    h = getHours();
    m = getMinutes();

    if (stamina > max_stamina) {
        printf("Uno o piu' dati inseriti non sono corretti\n");
        goto data_input;
    }


    printf("---------------------------------------\n");

    missing_stamina = max_stamina - stamina;
    tempo_refill = missing_stamina * 6;

    printf("il tempo necessario per refillare %d stamina e' di %d minuti\n", missing_stamina, tempo_refill);

    getHMD(h, m, tempo_refill, missing_stamina, max_stamina, hmd);

    printf("la stamina sara' refillata completamente alle ");

    if (hmd[1] < 10)
        printf("%d:0%d", hmd[0], hmd[1]);
    else
        printf("%d:%d", hmd[0], hmd[1]);

    if (hmd[2] != 0)
        printf(" di domani (contando 1 di sanity in piu')\n");
    else
        printf(" di oggi (contando 1 di sanity in piu')\n");

    printf("---------------------------------------\n");
    printf("premi un tasto per uscire \n");
    _getch();

    return 0;
}
