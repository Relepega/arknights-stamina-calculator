#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "time.c"

void getHM(int m, int* hm) {
    *(hm + 0) = 0; // hours
    *(hm + 1) = m; // minutes

    while (*(hm + 1) - 60 >= 0) {
        *(hm + 0) += 1;
        *(hm + 1) -= 60;
    }

    *(hm + 1) = m + 6;
}

void getHMD(int h, int m, int refill, int missing, int max, int* hmd) {
    *(hmd + 0) = h; // hours
    *(hmd + 1) = m + refill; // minutes
    *(hmd + 2) = 0; // new day flag

    if (missing + 1 <= max)
        *(hmd + 1) -= 6; //added 1 sanity for even calculation

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
    int refill_time;
    int h, m;
    int hmd[3];

data_input:
    printf("Insert your current stamina: ");
    scanf("%d", &stamina);

    printf("insert your stamina cap: ");
    scanf("%d", &max_stamina);

    h = getHours();
    m = getMinutes();

    if (stamina > max_stamina) {
        printf("Your input is invalid\n");
        goto data_input;
    }


    printf("---------------------------------------\n");

    missing_stamina = max_stamina - stamina;
    refill_time = missing_stamina * 6;

    printf("The time needed for refilling %d stamina is of %d minute(s)\n", missing_stamina, refill_time);

    getHMD(h, m, refill_time, missing_stamina, max_stamina, hmd);

    printf("The stamina will be refilled at: ");

    if (hmd[1] < 10)
        printf("%d:0%d", hmd[0], hmd[1]);
    else
        printf("%d:%d", hmd[0], hmd[1]);

    if (hmd[2] != 0)
        printf(" of tomorrow (counting 1 more stamina)\n");
    else
        printf(" of today (counting 1 more stamina)\n");

    printf("---------------------------------------\n");
    printf("Press any key to leave \n");
    _getch();

    return 0;
}
