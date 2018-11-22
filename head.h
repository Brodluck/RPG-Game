#ifndef HEAD_H
#define HEAD_H
typedef struct {
    char name[10];
    int ID, type, nature, type2, legen;                       //type (1=armas, 2=armaduras), nature (1=fisico, 2=magico) 
    double stat, statm;
    char atr1[15], atr2[15], atr3[15], atr4[15], nat[15];
}item;
typedef struct {
    char name[10];
    int race, gen, esquivar, vida,stamina;       //atrib
    int level, exp;                             //level
    double def, att, defm, attm, vel;          //stats
    
    item weapons[2], gear[4];
}chara;
typedef struct {
    char name[10];
    int type, race, esquivar, vida, stamina;  //atrib
    int level;                               //level
    double def, att, defm, attm, vel;       //stats
    item weapons[2], gear[4];
}npc;

int menu();
void character(chara *charac);
void levelUp(double *att, double *attm, double *def, double *defm, double *vel, int *race);
void itemGen(item *object, chara *charac);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HEAD_H */
