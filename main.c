#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include<string.h>

int main() {
    chara charac;
    char tuto;
    int strt;
    strt = menu();

    if (strt == 0) {
        return 0;
    } else {
        printf("Bienvenido al rpg game\n");
        printf("Cree su personaje\n\n");
        character(&charac);
    }

        printf("¿Quieres hacer un tutorial? [Y/N]");
        scanf("\n%c", &tuto);
        if (tuto=='Y' || tuto=='y'){
            //tutorial();
        }else if (tuto=='N' || tuto=='n'){
            printf("Bien, eres de los que aprenden sobre la marcha");
        }
        

    
    return 0;
}
