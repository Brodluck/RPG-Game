#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int menu(chara *charac, int dead) {
    FILE *f;
    srand(time(NULL));
    int option, gen, esquivar, vida, lvl, def, att, defm, attm, vel, class, race;

    if (dead) {
        option = 2;
        goto load;
    }

    printf("WELCOME TO THE RPG GAME\n1.Start\n2.Load Game\n3.Exit\n");
    scanf("%d", &option);
    system("clear");
load:
    switch (option) {
        case 1:
            return 1;
        case 2:
            f = fopen("Save.txt", "r");
            if (f == NULL) {
                return 0;
            }
            while ((fscanf(f, "%d %d %d %d %d %d %d %d %d %d", &gen, &vida, &lvl, &def, &att, &defm, &attm, &vel, &class, &race)) == 10);
    }
    charac->gen = gen;
    charac->vida = vida;
    charac->level = lvl;
    charac->def = def;
    charac->att = att;
    charac->defm = defm;
    charac->attm = attm;
    charac->vel = vel;

    if (class == 1) {
        charac->class.warrior = 1;
    } else if(class==2){
        charac->class.mage = 1;
    } else if (class == 3) {
        charac->class.paladin = 1;
    }

    if (race == 1) {
        charac->race.elfo = 1;
    } else if (race == 2) {
        charac->race.enano == 1;
    } else if (race == 3) {
        charac->race.orco = 1;
    } else if (race == 4) {
        charac->race.humano = 1;
    }

    fclose(f);
    return 2;
}


//ESTO DE AQUI ABAJO ME SIRVE PARA VER COMO ES LA STRUCT
/*typedef struct {
    char name[10];
    int ID, type, nature;
    double stat, statm;
    char atr1[10], atr2[10], atr3[10], atr4[10], nat[10];
}item;*/
/*

int inventario(item *mochila){
    int select;
    while(1){
    for(int i=0; mochila[i]->nature==1||mochila[i]->nature==2; i++){
        printf("Elemento nº%i: (ID: %i) \n%s %s %s %s %s\n",i+1 , *(mochila+i)->ID, *(mochila+i)->name, *(mochila+i)->atr1, *(mochila+i)->atr2, *(mochila+i)->atr3, *(mochila+i)->atr4);
    }
    printf("¿Que elemento quieres ver? Pulsa 0 para dejar de ver + información\n");
    scanf("%i", &select);
    if(select==0){break;}
    else{
        select--; //esto lo hago porque cuando eligen un elemento cuando los mostre tenian sumado 
                  //un uno para que fuese una interfaz mas bonita
        printf("Elemento nº%i: (ID: %i) \n%s %s %s %s %s\n",select+1, mochila[select]->ID, mochila[select]->name, mochila[select]->atr1, mochila[select]->atr2, mochila[select]->atr3, mochila[select]->atr4);
        switch(mochila[select]->type){
            case 1: printf("Tipo: Arma\n"); break;
            case 2: printf("Tipo: Armadura\n"); break;
            default: printf("Ese tipo no esta definido loko, ere hackerman o q"); break;
        
        }
        
        switch(mochila[select]->nature){
            case 1: printf("\nNaturaleza: Tipo Físico\n"); break;
            case 2: printf("\nNaturaleza: Tipo Mágico\n"); break;
            default: printf("Esa naturaleza no esta definido loko, ere hackerman o q"); break;
        
        }
        printf("Estadisticas:\nAtaque Físico: %i\nAtaque mágico: %i\n", mochila[select]->stat, mochila[select]->statm);
        }
           
    }
    for(int i=0; mochila[i]->nature==1||mochila[i]->nature==2; i++){
        printf("Elemento nº%i: (ID: %i) \n%s %s %s %s %s\n",i+1 , *(mochila+i)->ID, *(mochila+i)->name, *(mochila+i)->atr1, *(mochila+i)->atr2, *(mochila+i)->atr3, *(mochila+i)->atr4);
    }
    int decision;
    printf("Elige el elemento que deseas usar: ");
    scanf("%i", &decision);
    decision--;
    return decision;
}
 */
