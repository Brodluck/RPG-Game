#ifndef HEAD_H
#define HEAD_H

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
    int gen, esquivar, vida; //atrib
    int level, exp; //level
    double def, att, defm, attm, vel; //stats
    classes class; //Classes
    races race; // Races

    item weapons[2], gear[4];
} chara;

typedef struct {
    char name[10];
    int type, esquivar, vida; //atrib
    int level; //level
    double def, att, defm, attm, vel; //stats
    item weapons[2], gear[4];
    races race;
} npc;



int menu(chara *charac, int dead);
void character(chara *charac);
void levelUp(double *att, double *attm, double *def, double *defm, double *vel, races *race);
void itemGen(item *object, chara *charac, int enemG, int enemG2);
int combat(chara *charac, npc *enemy);
void EnemyGen(chara charac, npc *enemy);
void itemIDLoad(item *object, char *ID);
void type_text(char *s, unsigned ms_delay);
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HEAD_H */
