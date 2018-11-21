/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   head.h
 * Author: Olinone de Guille
 *
 * Created on 20 de noviembre de 2018, 9:23
 */

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
    int raze, gen;                      //atrib
    int level, exp;                     //level
    double def, att, defm, attm, vel;   //stats
    item equip[5];
}chara;
typedef struct {
    int type, raze;                           //atrib
    int level;                          //level
    double def, att, defm, attm, vel;   //stats
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

