#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>
#include <unistd.h>

void typeText(char *s, unsigned msDelay) {
    unsigned usecs = msDelay * 1000; /* 1000 microseconds per ms */

    for (; *s; s++) {
        putchar(*s);
        fflush(stdout); /* alternatively, do once: setbuf(stdout, NULL); */
        usleep(usecs);
    }
}
void typeText_double(double *s, unsigned msDelay) {
    unsigned usecs = msDelay * 1000; /* 1000 microseconds per ms */

    for (; *s; s++) {
        putchar(*s);
        fflush(stdout); /* alternatively, do once: setbuf(stdout, NULL); */
        usleep(usecs);
    }
}

void healthBar(int vida1, int vidamax1, int vida2, int vidamax2){
    int i;
    double percent1, percent2;
    percent1=vida1*100/vidamax1;
    percent2=vida2*100/vidamax2;
    printf("tu vida:          [");
    for (i=0; i<100;i=i+5){
        if (i<percent1){
            printf("#");
        }else printf("-");
    }
    printf("]%d/%d\nVida del enemigo: [", vida1, vidamax1);
    for (i=0;i<100;i=i+5){
        if (i<percent2){
            printf("#");
        }else printf("-");
    }
    printf("]");
    printf("%d/%d", vida2, vidamax2);
}

void personDisplay(int vida1, int vidamax1, int vida2, int vidamax2){
    system("clear");
    printf("\n                    o\n      o            / \\\n     / \\\n\n");
    healthBar(vida1, vidamax1, vida2, vidamax2);
}

void personAttack1(int vida1, int vidamax1, int vida2, int vidamax2){
    system("clear");
    printf("\n                    o\n        o          / \\\n       / \\\n\n");
    fflush(stdout);
    usleep(80);
    healthBar(vida1, vidamax1, vida2, vidamax2);
    fflush(stdout);
    usleep(80000);
    system("clear");
    printf("\n                    o\n      o            / \\\n     / \\\n\n");
    fflush(stdout);
    usleep(80);
    healthBar(vida1, vidamax1, vida2, vidamax2);
}

void personAttack2(int vida1, int vidamax1, int vida2, int vidamax2){
    system("clear");
    printf("\n                  o\n      o          / \\\n     / \\\n\n");
    fflush(stdout);
    usleep(80);
    healthBar(vida1, vidamax1, vida2, vidamax2);
    fflush(stdout);
    usleep(80000);
    system("clear");
    printf("\n                    o\n      o            / \\\n     / \\\n\n");
    fflush(stdout);
    usleep(80);
    healthBar(vida1, vidamax1, vida2, vidamax2);
}