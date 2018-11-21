#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include "head.h"
#include <time.h>

void character(chara *charac) {
    int x, selec;
    char bool;
    do{
        do{
    printf("seleccione raza:\n1.elfo\n2.enano\n3.orco\n4.humano\n");
    scanf("%d", &x);
    system("clear");
    switch (x){
        case 1:
            printf("elfos: afinidad a la magia, veloces pero debiles");
            break;
        case 2:
            printf("enanos: expertos con armas y armaduras, resistentes pero lentos");
            break;
        case 3:
            printf("orcos: grandes expertos con armas, peligrosos pero muy lentos, no saben usar magia");
            break;
        case 4:
            printf("humanos: ninguna especialidad");
            break;
         default:
            printf("eres idiota??");
            break;
    }
        }while (0>x && x>5);
            do{             //confirmar seleccion
                printf("\nquieres seleccionar esta raza?[Y/N]");
                scanf("\n%c", &bool);
                system("clear");
                    if (bool=='Y') {
                    selec = 1;
                }else if (bool=='N'){
                selec = 0;
            }else printf ("eres idiota??");
        }while (bool!='Y' && bool!='N');
    } while (selec == 0);
    
    if (x==1){              //elfo
    charac->att = -10;
    charac->attm = 10;
    charac->def = -10;
    charac->defm = 10;
    charac->vel = 20;
    printf("seleccionada la raza elfa");
    } else if (x==2){       //enano
    charac->att = 10;
    charac->attm = -10;
    charac->def = 10;
    charac->defm = -10;
    charac->vel = 0;
    printf("seleccionada la raza enana");
    } else if (x==3){       //orco
    charac->att = 20;
    charac->attm = -100;
    charac->def = 0;
    charac->defm = 0;
    charac->vel = -20;
    printf("seleccionada la raza orca");
    } else if (x==4){       //humano
    charac->att = 0;
    charac->attm = 0;
    charac->def = 0;
    charac->defm = 0;
    charac->vel = 0;
    printf("seleccionada la raza humana");
    }    
    charac->raze = x;
    int selec2;
    char gen;
    do{
        printf("\nahora seleccione el género[M/F]");
        scanf ("\n%c", &gen);
        system("clear");
        if (gen=='M'){
            printf("+10 de ataque fisico (no soy machista lo juro)");
            charac->gen=1;
            charac->att=charac->att + 10;
        } else if (gen=='F'){
            printf("+10 de ataque magico (no soy sexista lo juro)");
            charac->gen=2;
            charac->attm=charac->attm + 10;
        } else  printf("eres idiota??");
    }while (selec2==0);
}
void levelUp(double *att, double *def, double *attm, double *defm, double *vel, int raze){
    
    double x=rand()%5+1;
    if (raze==1){
    x=x*0.5;
    }else 
    if (raze==2){
    x=x*1.5;
    }else 
    if (raze==3){
    x=x*2;
    }else 
    if (raze==4){
    x=x*1;
    }
    *att=*att + x;
      printf("\nataque: %.0lf", att);
    x=rand()%5+1;
    if (raze==1){
    x=x*1.5;
    }else 
    if (raze==2){
    x=x*0.5;
    }else 
    if (raze==3){
    x=x*0;
    }else 
    if (raze==4){
    x=x*1;
    }
    *attm=*attm + x;
      printf("\nataque magico: %.0lf", *attm);
    x=rand()%5+1;
    if (raze==1){
    x=x*0.5;
    }else 
    if (raze==2){
    x=x*1.8;
    }else 
    if (raze==3){
    x=x*1;
    }else 
    if (raze==4){
    x=x*1;
    }
    *def=*def + x;
      printf("\ndefensa: %.0lf", *def);
    x=rand()%5+1;
    if (raze==1){
    x=x*1.7;
    }else 
    if (raze==2){
    x=x*0.5;
    }else 
    if (raze==3){
    x=x*1;
    }else 
    if (raze==4){
    x=x*1;
    }
    *defm=*defm + x;
      printf("\nadefensa magica: %.0lf", *defm);
      x=rand()%5+1;
    if (raze==1){
    x=x*1.7;
    }else 
    if (raze==2){
    x=x*0.5;
    }else 
    if (raze==3){
    x=x*0.5;
    }else 
    if (raze==4){
    x=x*1;
    }
    *vel=*vel + x;
      printf("\nvelocidad: %.0lf", *vel);
}
void expUp(chara *charac, int expg){
    printf("has conseguido %d ptos de experiencia", expg);
    charac->exp=charac->exp + expg;
    if (charac->exp>pow(3, charac->level)){
        charac->level++;
        levelUp(charac->att, charac->def, charac->attm, charac->defm, charac->vel, charac->raze);
        printf ("enhorabuena!! has subido al nivel %d", charac->level);
    }
}
