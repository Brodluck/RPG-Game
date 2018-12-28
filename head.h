#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#define delay 15

typedef struct {
    char name[100];
    int lvl, type, nature, type2, legen, comm, rare, extr; //type (1=armas, 2=armaduras), nature (1=fisico, 2=magico) 
    double stat, statm;
    char ID[9];
} item;

typedef struct {
    int elfo, enano, orco, humano; //Races struct
} races;

typedef struct {
    int mage, warrior, paladin; //Classes struct
} classes;

typedef struct {
    char name[10];
    int gen, esquivar, vida, vidamax; //atrib
    int level, exp; //level
    double def, att, defm, attm, vel; //stats
    int class; // 1=warrior, 2=mage, 3=paladin
    int race; // 1=elfo, 2=enano, 3=orco, 4=humano
    item inv[100];
    item weapons[2], gear[4];
} chara;

typedef struct {
    char name[10];
    int type, esquivar, vida, vidamax; //atrib
    int level; //level
    double def, att, defm, attm, vel; //stats
    item weapons[2], gear[4];
    int race;
} npc;

int menu(chara *charac, int dead);
void character(chara *charac);
void levelUp(double *att, double *attm, double *def, double *defm, double *vel, int race);
void itemGen(item *object, chara *charac, int enemG, int enemG2);
int combat(npc *enemy, chara *charac);
void enemyGen(chara charac, npc *enemy);
void itemIDLoad(item *object, char *ID);
void typeText(char *s, unsigned msDelay);
void healthBar(int vida1, int vidamax1, int vida2, int vidamax2);
void personDisplay();
void personAttack1(int vida1, int vidamax1, int vida2, int vidamax2);
void personAttack2(int vida1, int vidamax1, int vida2, int vidamax2);
short skill_book(chara *charac);
short mochila(chara *charac);
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HEAD_H */
