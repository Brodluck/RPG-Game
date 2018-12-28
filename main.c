#include "head.h"

int main() {
    chara charac;
    npc enemy;
    char tuto;
    int strt, combatResult, dead = 0;
    
    strt = menu(&charac, dead);
    switch (strt) {
        case 1:
            typeText("Cree su personaje\n\n", delay);
            character(&charac);
            break;
        case -1:
            typeText("Error al leer el archivo de guardado\n", delay);
            break;
        case 0:
            return 0;
            break;
        case 2:
             typeText("Cargado correctamente\n", delay);
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
