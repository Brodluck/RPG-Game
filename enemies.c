#include "head.h"

void enemyGen(chara charac, npc *enemy) {

    int x = rand() % 21, i;
    enemy->level = charac.level + (x - 10);
    if (enemy->level < 1) {
        enemy->level = 1;
    }
    if (enemy->level < 10) {
        enemy->type = 1;
        strcpy(enemy->name, "rebelde");
        enemy->type = 2;
    } else if (enemy->level < 30) {
        strcpy(enemy->name, "delincuente");
        enemy->type = 3;
    } else if (enemy->level < 40) {
        strcpy(enemy->name, "maton");
        enemy->type = 4;
    } else if (enemy->level < 50) {
        strcpy(enemy->name, "asesino");
        enemy->type = 5;
    }
    x = (rand() % 4) + 1;

    if (x == 1) { //elfo
        enemy->race = 1;
        enemy->vida = 85;
        enemy->vidamax = 85;
        enemy->att = 5;
        enemy->attm = 10;
        enemy->def = 5;
        enemy->defm = 10;
        enemy->vel = 25;
        strcat(enemy->name, " elfo");
    } else if (x == 2) { //enano
        enemy->race = 2;
        enemy->vida = 110;
        enemy->vidamax = 110;
        enemy->att = 10;
        enemy->attm = 5;
        enemy->def = 20;
        enemy->defm = 15;
        enemy->vel = 0;
        strcat(enemy->name, " enano");
    } else if (x == 3) { //orco
        enemy->race = 3;
        enemy->vida = 110;
        enemy->vidamax = 110;
        enemy->att = 20;
        enemy->attm = 0;
        enemy->def = 20;
        enemy->defm = 5;
        enemy->vel = -10;
        strcat(enemy->name, " orco");
    } else if (x == 4) { //humano
        enemy->race = 4;
        enemy->vida = 100;
        enemy->vidamax = 100;
        enemy->att = 10;
        enemy->attm = 10;
        enemy->def = 10;
        enemy->defm = 10;
        enemy->vel = 0;
        strcat(enemy->name, " humano");
    }
    for (i = 0; i < enemy->level; i++) {
        int x = (rand() % 8 + 1) + 3;
    if (enemy->race == 1) {
        x = x * 0.5;
    } else if (enemy->race == 2) {
        x = x * 1.5;
    } else if (enemy->race == 3) {
        x = x * 2;
    } else if (enemy->race == 4) {
        x = x * 1;
    }
    enemy->att = enemy->att + x;
    x = rand() % 5 + 1;
    if (enemy->race == 1) {
        x = x * 0.5;
    } else if (enemy->race == 2) {
        x = x * 1.5;
    } else if (enemy->race == 3) {
        x = x * 2;
    } else if (enemy->race == 4) {
        x = x * 1;
    }
    enemy->attm = enemy->attm + x;
    x = rand() % 5 + 1;
    if (enemy->race == 1) {
        x = x * 0.5;
    } else if (enemy->race == 2) {
        x = x * 1.5;
    } else if (enemy->race == 3) {
        x = x * 2;
    } else if (enemy->race == 4) {
        x = x * 1;
    }
    enemy->def = enemy->def + x;
    x = rand() % 5 + 1;
    if (enemy->race == 1) {
        x = x * 0.5;
    } else if (enemy->race == 2) {
        x = x * 1.5;
    } else if (enemy->race == 3) {
        x = x * 2;
    } else if (enemy->race == 4) {
        x = x * 1;
    }
    enemy->defm = enemy->defm + x;
    x = rand() % 5 + 1;
    if (enemy->race == 1) {
        x = x * 0.5;
    } else if (enemy->race == 2) {
        x = x * 1.5;
    } else if (enemy->race == 3) {
        x = x * 2;
    } else if (enemy->race == 4) {
        x = x * 1;
    }
    enemy->vel = enemy->vel + x;
    }

    itemGen(&enemy->weapons[0], &charac, 1, 0);
    itemGen(&enemy->weapons[1], &charac, 1, 0);
    itemGen(&enemy->gear[0], &charac, 2, 1);
    itemGen(&enemy->gear[1], &charac, 2, 2);
    itemGen(&enemy->gear[2], &charac, 2, 3);
    itemGen(&enemy->gear[3], &charac, 2, 4);
}

