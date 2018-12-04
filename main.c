#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>
#include <unistd.h>

int main() {
    chara charac;
    npc enemy;
    char tuto;
    int strt, combatResult, dead = 0;
    strt = menu(&charac, dead);
    switch (strt) {
        case 1:
            printf("Bienvenido al rpg game\n");
            printf("Cree su personaje\n\n");
            character(&charac);
            break;
        case -1:
            printf("Error al leer el archivo de guardado\n");
            break;
        case 0:
            exit;
            break;
        case 2:
            printf("Cargado correctamente\n");
            break;

   
    }


    /*printf("¿Quieres hacer un tutorial? [Y/N]");
    scanf("\n%c", &tuto);
    if (tuto == 'Y' || tuto == 'y') {
        
    } else if (tuto == 'N' || tuto == 'n') {
        printf("Bien, eres de los que aprenden sobre la marcha");
    }*/

    combatResult = combat(&charac, &enemy);
    if (combatResult == 1) {

    } else if (combatResult == -1) {
        printf("Has huido sin problemas\n");
    } else if (combatResult == 0) {
        dead = 1;
        strt = menu(&charac, dead);
        if (strt = 2) {
            printf("Se ha cargado partida correctamente en el ultimo punto guardado");
        }
    }

    return 0;
}
