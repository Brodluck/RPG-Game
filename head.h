#ifndef HEAD_H
#define HEAD_H
typedef struct {
    char name[10];
    int ID, type, nature, type2, legen;                       //type (1=armas, 2=armaduras), nature (1=fisico, 2=magico) 
    double stat, statm;
    char atr1[30], atr2[30], atr3[30], atr4[30], nat[30];
}item;
typedef struct{
    int elfo, enano, orco, humano;          //Races struct
}races;
typedef struct{
    int mage, warrior, paladin;             //Classes struct
}classes;
typedef struct {
    char name[10];
    int  gen, esquivar, vida,stamina;       //atrib
    int level, exp;                             //level
    double def, att, defm, attm, vel;          //stats
    classes class;                             //Classes
    races race;                                // Races
    
    item weapons[2], gear[4];
}chara;
typedef struct {
    char name[10];
    int type, esquivar, vida, stamina;  //atrib
    int level;                               //level
    double def, att, defm, attm, vel;       //stats
    item weapons[2], gear[4];
    races race;
}npc;


 
int menu();
void character(chara *charac);
void levelUp(double *att, double *attm, double *def, double *defm, double *vel, races *race);
void itemGen(item *object, chara *charac, int enemG, int enemG2);
int combat(chara *player, npc *enemy);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HEAD_H */
