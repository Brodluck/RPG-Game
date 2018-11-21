#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include<string.h>

int main() {
    chara charac;
    int strt;
    strt=menu();
    
    if (strt==0){
        return 0;
    }else {
        printf("bienvenido al rpg game\n");
        printf("cree su personaje\n\n");
        character(&charac);
    }
    return 0;
}

