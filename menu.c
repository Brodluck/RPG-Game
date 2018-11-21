#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int menu() {
    srand(time(NULL));
    int x;
    printf("WELCOME TO THE RPG GAME\n1.Start\n2.Exit\n");
    scanf("%d", &x);
    system("clear");
   
    if (x==1){
        return 1;
    }else return 0;
}

