#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include<string.h>

void EnemyGen(chara *charac, npc *enemy) {
    int x=rand()%21, y=rand()%5, i;
    enemy->level=charac->level + (x-10);
    if (enemy->level<10){
        enemy->type=1;
    } else if (enemy->level<20){
        enemy->type=2;
    } else if (enemy->level<30){
        enemy->type=3;
    } else if (enemy->level<40){
        enemy->type=4;
    } else if (enemy->level<50){
        enemy->type=5;
    }
    enemy->raze=y;
    if (enemy->raze==1){              //elfo
    enemy->att = -10;
    enemy->attm = 10;
    enemy->def = -10;
    enemy->defm = 10;
    enemy->vel = 20;
    printf("seleccionada la raza elfa");
    } else if (npc->raze==2){       //enano
    enemy->att = 10;
    enemy->attm = -10;
    enemy->def = 10;
    enemy->defm = -10;
    enemy->vel = 0;
    printf("seleccionada la raza enana");
    } else if (npc->raze==3){       //orco
    enemy->att = 20;
    enemy->attm = -100;
    enemy->def = 0;
    enemy->defm = 0;
    enemy->vel = -20;
    printf("seleccionada la raza orca");
    } else if (npc->raze==4){       //humano
    enemy->att = 0;
    enemy->attm = 0;
    enemy->def = 0;
    enemy->defm = 0;
    enemy->vel = 0;
    printf("seleccionada la raza humana");
    }
    for (i=0; i<npc->level; i++){
        levelUp(&enemy->att, &enemy->def, &enemy->attm, &enemy->defm, &enemy->vel, enemy.raze);
    }
}

