#include "head.h"

int main() {
    chara charac;
    npc enemy;
    char tuto;
    int strt, combatResult, dead = 0, option, x, y;
    
    strt = menu(&charac, dead);
    switch (strt) {
        case 1:
            typeText("Cree su personaje", delay);
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


    printf("¿Quieres hacer un tutorial? [Y/N]");
    scanf("\n%c", &tuto);
    if (tuto == 'Y' || tuto == 'y') {
        tutorial();
    } else if (tuto == 'N' || tuto == 'n') {
        printf("Bien, eres de los que aprenden sobre la marcha");
    }
        system("clear");
    do{
        printf("Que quieres hacer?\n1.Luchar\n2.Ir al refugio");
        scanf("%d", &x);
        system("clear");
        switch (x){
            case 1:
                option=1;
                break;
            case 2:
                do{
                    system("clear");
                    y=shelter(&charac);
                    if (y==3){
                        return 0;
                    }
                }while (y==2);
                option=0;
                break;
            default:
                printf("Eres idiota?? Elige bien");
                option=0;
        }
    }while (option==0);
    enemyGen(charac, &enemy);
    combatResult = combat(&enemy, &charac);
    if (combatResult == 1) {

    } else if (combatResult == -1) {
        printf("Has huido sin problemas\n");
    } else if (combatResult == 0) {
        dead = 1;
        strt = menu(&charac, dead);
        if (strt = 2) {
            printf("Se ha cargado partida correctamente en el ultimo punto guardado");
        }
    } else if (combatResult == 1){
        
    }
    return 0;
}
