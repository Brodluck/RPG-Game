#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <string.h>
#include <unistd.h>

void type_text(char *s, unsigned ms_delay)
{
   unsigned usecs = ms_delay * 1000; /* 1000 microseconds per ms */

   for (; *s; s++) {
      putchar(*s);
      fflush(stdout); /* alternatively, do once: setbuf(stdout, NULL); */
      usleep(usecs);
   }
}


int main() {
 chara charac;
 npc enemy;
    char tuto;
    int strt, combatResult;
    strt = menu();

    if (strt == 0) {
        return 0;
    } else {
        printf("Bienvenido al rpg game\n");
        printf("Cree su personaje\n\n");
        character(&charac);
    }
    system("clear");
    /*printf("¿Quieres hacer un tutorial? [Y/N]");
    scanf("\n%c", &tuto);
    if (tuto == 'Y' || tuto == 'y') {
        
    } else if (tuto == 'N' || tuto == 'n') {
        printf("Bien, eres de los que aprenden sobre la marcha");
    }*/

    combatResult=combat(&charac, &enemy);
    if(combatResult==1){
        
    }else if(combatResult==-1){
        printf("Has huido sin problemas\n");
    }


    return 0;
}
