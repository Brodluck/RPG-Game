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
//ESTO DE AQUI ABAJO ME SIRVE PARA VER COMO ES LA STRUCT
/*typedef struct {
    char name[10];
    int ID, type, nature;
    double stat, statm;
    char atr1[10], atr2[10], atr3[10], atr4[10], nat[10];
}item;*/


intr