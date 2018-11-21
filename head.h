#ifndef HEAD_H
#define HEAD_H
typedef struct {
    char name[10];
    int ID, type, nature, legen;                       //type (1=armas, 2=armaduras), nature (1=fisico, 2=magico) 
    double stat, statm;
    char atr1[10], atr2[10], atr3[10], atr4[10], nat[10];
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

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HEAD_H */
