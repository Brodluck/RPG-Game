#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include<string.h>

void EnemyGen(chara *charac, npc *enemy) {
    
    int x=rand()%21, i;
    enemy->level=charac->level + (x-10);
    if (enemy->level<0){
        enemy->level=0;
    }
    if (enemy->level<10){
        enemy->type=1;
        strcpy(enemy->name, "rebelde");
        enemy->type=2;
    } else if (enemy->level<30){
        strcpy(enemy->name, "delincuente");
        enemy->type=3;
    } else if (enemy->level<40){
        strcpy(enemy->name, "maton");
        enemy->type=4;
    } else if (enemy->level<50){
        strcpy(enemy->name, "asesino");
        enemy->type=5;
    }
    x=(rand()%4)+1;
    enemy->race=x;
    if (enemy->race==1){              //elfo
    enemy->att = -10;
    enemy->attm = 10;
    enemy->def = -10;
    enemy->defm = 10;
    enemy->vel = 20;
    strcat(enemy->name, " elfo");
    } else if (enemy->race==2){       //enano
    enemy->att = 10;
    enemy->attm = -10;
    enemy->def = 10;
    enemy->defm = -10;
    enemy->vel = 0;
    strcat(enemy->name, " enano");
    } else if (enemy->race==3){       //orco
    enemy->att = 20;
    enemy->attm = -100;
    enemy->def = 0;
    enemy->defm = 0;
    enemy->vel = -20;
    strcat(enemy->name, " orco");
    } else if (enemy->race==4){       //humano
    enemy->att = 0;
    enemy->attm = 0;
    enemy->def = 0;
    enemy->defm = 0;
    enemy->vel = 0;
    strcat(enemy->name, " humano");
    }
    for (i=0; i<enemy->level; i++){
        levelUp(&enemy->att, &enemy->attm, &enemy->def, &enemy->defm, &enemy->vel, &enemy->race);
    }
     
    itemGen(&enemy->weapons[0], &enemy->level, 1, 0);
    itemGen(&enemy->weapons[1], &enemy->level, 1, 0);
    itemGen(&enemy->gear[0], &enemy->level, 2, 1);
    itemGen(&enemy->gear[1], &enemy->level, 2, 2);
    itemGen(&enemy->gear[2], &enemy->level, 2, 3);
    itemGen(&enemy->gear[3], &enemy->level, 2, 4);
}

