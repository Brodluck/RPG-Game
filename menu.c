#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int menu() {
    srand(time(NULL));
    int x;
    printf("WELCOME TO THE RPG GAME\n1.Start\n2.Exit\n");
    scanf("%d", &x);
    system("clear");
   
    if (x==1){
        return 1;
    }else return 0;
}
//ESTO DE AQUI ABAJO ME SIRVE PARA VER COMO ES LA STRUCT
/*typedef struct {
    char name[10];
    int ID, type, nature;
    double stat, statm;
    char atr1[10], atr2[10], atr3[10], atr4[10], nat[10];
}item;*/


void inventario(item *mochila){
    int select;
    while(1){
    for(int i=0; (*(mochila+i)->nature==1)||(*(mochila + i))->nature==2; i++){
        printf("Elemento nº%i: (ID: %i) \n%s %s %s %s %s\n",i+1 , *(mochila+i)->ID, *(mochila+i)->name, *(mochila+i)->atr1, *(mochila+i)->atr2, *(mochila+i)->atr3, *(mochila+i)->atr4);
    }
    printf("¿Que elemento quieres ver? Pulsa 0 para salir del inventario\n");
    scanf("%i", &select);
    if(select==0){break;}
    else{
        select--; //esto lo hago porque cuando eligen un elemento cuando los mostre tenian sumado 
                  //un uno para que fuese una interfaz mas bonita
        printf("Elemento nº%i: (ID: %i) \n%s %s %s %s %s\n",select+1, *(mochila+select)->ID, *(mochila+select)->name, *(mochila+select)->atr1, *(mochila+select)->atr2, *(mochila+select)->atr3, *(mochila+select)->atr4);
        switch(*(mochila+select)->type){
            case 1: printf("Tipo: Arma\n"); break;
            case 2: printf("Tipo: Armadura\n"); break;
            default: printf("Ese tipo no esta definido loko, ere hackerman o q"); break;
        
        }
        
        switch(*(mochila+select)->nature){
            case 1: printf("\nNaturaleza: Tipo Físico\n"); break;
            case 2: printf("\nNaturaleza: Tipo Mágico\n"); break;
            default: printf("Esa naturaleza no esta definido loko, ere hackerman o q"); break;
        
        }
        printf("Estadisticas:\nAtaque Físico: %i\nAtaque mágico: %i\n", *(mochila+select)->stat, *(mochila+select)->statm);
        }
        
        
        
    
    
    
    
    }


}