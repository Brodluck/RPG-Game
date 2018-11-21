#ifndef HEAD_H
#define HEAD_H
typedef struct {
    char name[10];
    int ID, type, nature;
    double stat, statm;
    char atr1[10], atr2[10], atr3[10], atr4[10], nat[10];
}item;
typedef struct {
    char name[10];
    int race, gen, esquivar, vida,stamina;       //atrib
    int level, exp;                             //level
    double def, att, defm, attm, vel;          //stats
    
    item equip[5];
}chara;
typedef struct {
    int type, race, esquivar, vida, stamina;  //atrib
    int level;                               //level
    double def, att, defm, attm, vel;       //stats
    item equip[5];
}npc;

int menu();
void character(chara *charac);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* HEAD_H */
