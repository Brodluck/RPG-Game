#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include<string.h>

int main() {
    chara *charac;
    npc *enemy;
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
    if (tuto == 'Y' || tuto == 'y') {
        if (charac->class->warrior == 1) {
            combat_warrior(&enemy, &charac);
        } else if (charac->class->mage == 1) {
            combat_mage(&enemy, &charac);
        } else if (charac->class->mage == 1) {
            combat_paladin(&enemy, &charac);
        }
    } else if (tuto == 'N' || tuto == 'n') {
        printf("Bien, eres de los que aprenden sobre la marcha");
    }




    return 0;
}
