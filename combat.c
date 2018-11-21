#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "head.h"

typedef struct{
    double normalattack;
    double heavyattack;    
}skills;

int combat(npc *enemy, chara *player) {
    skills s;
    s.heavyattack=2.5;
    s.normalattack=1;
    double dmg;
    int turno=1, option, percentage,x, miss;
    if(enemy->vel<player->vel){
        turno=0;    
    }
                       //turno=1 es turno del jugador
        printf("Te enfrentas a %s !! Es hora de un combate glorioso! Que quieres hacer?", enemy->name);
        printf("1.Luchar\n2.Objetos\n3.Huir");
        switch(option){
            case 1:
                break;
            case 2: 
                //Esto lo tiene que hacer rodri que no sé que ha hecho en el equipamiento/mochila
            case 3:
                percentage=(rand()%100)+1;
                if(percentage>=1 && percentage<=20){
                    printf("No puedes huir! %s te ha atrapado! Tocará luchar", enemy->name);
                    break;
                }else {
                    return 0; // printf("Has huido sin problema\n") hay que ponerlo en la funcion cuando se llame
                }
                   
        }
        do{
            dmg=0;
            if(player->stamina==0){
            printf("Tu aguante ha llegado a cero! Debes descansar este turno\n");
            player->stamina+=100;
            turno=0;
            }
    if (turno==1){
        
           
        
        
        printf("Elige la habilidad que quieres utilizar\n: 1.Ataque\n 2.Ataque fuerte\n");
        scanf("%d", &option);
        switch (option){
            case 1:
                dmg=s.normalattack * player->att;
                player->stamina-=15;
        break;
            case 2:
                miss=(rand()%100)+1;
                 if(miss>=1 && miss<=15){
                     printf("Fallo!");
                 }else{
                dmg=s.heavyattack * player->att;}
                player->stamina-=30;
                break;
        }
        dmg=dmg-((dmg*(enemy->def*0.05))/100);
        enemy->vida-=dmg;
        printf("Vida de %s : %d", enemy->name, enemy->vida);
        printf("Stamina: %d", player->stamina);
        
    }
    else if(turno==0){
        x=(rand()%2)+1;
                switch(x){
                      case 1:
                          printf("%s ha hecho un ataque normal\n", enemy->name);
                dmg=s.normalattack * enemy->att;
                enemy->stamina-=15;
        break;
            case 2:
                 printf("%s ha hecho un ataque fuerte\n", enemy->name);
                 miss=(rand()%100)+1;
                 if(miss>=1 && miss<=15){
                     printf("Fallo!");
                     break;
                 }else{
                dmg=s.heavyattack * enemy->att;}
                enemy->stamina-=30;
                break;
                }
         dmg=dmg-((dmg*(player->def*0.05))/100);
        player->vida-=dmg;
        printf("Tu vida: %d\n",player->vida);
        printf("Stamina de %s: %d\n",enemy->stamina);
    }
    }while((enemy->vida >0) || (player->vida >0));

}

