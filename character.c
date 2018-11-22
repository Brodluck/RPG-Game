#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include "head.h"
#include <time.h>

void character(chara *charac) {
    int x, y, selec;
    char bool;
    do {
        do {
            printf("Selecciona la raza con la que comenzaras tu aventura:\n1.elfo\n2.enano\n3.orco\n4.humano\n");
            scanf("%d", &x);
            system("clear");
            switch (x) {
                case 1:
                    printf("Elfos: afinidad a la magia, veloces pero debiles\n");
                    printf("Ataque: -10\nAtaque magico: +10 \nDefensa: -10\nDefensa mágica: +10\nVelocidad: +20\n");

                    break;
                case 2:
                    printf("Enanos: expertos con armas y armaduras, resistentes pero lentos\n");
                    printf("Ataque: +10\nAtaque magico: -10 \nDefensa: +10\nDefensa mágica: +10\nVelocidad: +0\n");

                    break;
                case 3:
                    printf("Orcos: grandes y fuertes, expertos con armas, peligrosos pero muy lentos. No saben usar magia\n");
                    printf("Ataque: +20\nAtaque magico: -100 \nDefensa: +0\nDefensa mágica: +0\nVelocidad: -20\n");
                    break;
                case 4:
                    printf("Humanos: ninguna especialidad, son normalitos, no tienen ningun atributo aumentado pero tampoco ninguno reducido\n");

                    break;
                default:
                    printf("Eres idiota?? Elige bien\n");
                    break;
            }
        } while (0 > x && x > 5);
        do { //confirmar seleccion
            printf("\nDe verdad quieres seleccionar esta raza? [Y/N]");
            scanf("\n%c", &bool);
            system("clear");
            if (bool == 'Y' || bool == 'y') {
                selec = 1;
            } else if (bool == 'N' || bool == 'n') {
                selec = 0;
            } else printf("Eres idiota?? Elige bien\n");
        } while ((bool == 'Y' || bool == 'y') && (bool == 'N' || bool == 'n'));
    } while (selec == 0);
    y = x;
    switch (y) {
        case 1:
            //elfo
            charac->vida=85;
            charac->stamina=100;
            charac->att = -10;
            charac->attm = 10;
            charac->def = -10;
            charac->defm = 10;
            charac->vel = 20;
            printf("Enhorabuena, ahora seras un elfo!");
            break;

        case 2:
            //enano
            charac->vida=110;
            charac->stamina=100;
            charac->att = 10;
            charac->attm = -10;
            charac->def = 10;
            charac->defm = 10;
            charac->vel = 0;
            printf("Enano, eres de esos entonces");
            break;
        case 3:
            //orco
            charac->vida=110;
            charac->stamina=100;
            charac->att = 20;
            charac->attm = -100;
            charac->def = 0;
            charac->defm = 0;
            charac->vel = -20;
            printf("Enhorabuena eres un Orco!");
            break;
        case 4:
            //humano
            charac->vida=100;
            charac->stamina=100;
            charac->att = 0;
            charac->attm = 0;
            charac->def = 0;
            charac->defm = 0;
            charac->vel = 0;
            printf("Enhorabuena, eres el tipico humano");

            break;
        default:
            printf("Eres idiota?? Elige bien\n");
            break;

    }
    while (0 > x && x > 5);


    charac->race = x;
    int selec2;
    char gen;
    do {
        printf("\nAhora seleccione el genero [M/F]\n");
        printf("Masculino: +10 de ataque fisico (no soy machista lo juro)\n");
        printf("Femenino: +10 de ataque magico (no soy sexista lo juro)\n");
        scanf("\n%c", &gen); 
        system("clear");
        
        if (gen == 'M' || gen == 'm') {
            printf("Tendras +10 de ataque fisico cosas fisiologicas, sorry\n");
            charac->gen = 1;
            charac->att = charac->att + 10;
            printf("\nConfirmar?[Y/N]");
            scanf("\n%c", &bool);
            system("clear");
            if (bool=='Y' || bool=='y'){
                selec=1;
            }
        } else if (gen == 'F' || gen == 'f') {
            printf("Tendras +10 de ataque magico, si... ellas son mas listas\n");
            charac->gen = 2;
            charac->attm = charac->attm + 10;
            printf("\nConfirmar?[Y/N]");
            scanf("\n%c", &bool);
            system("clear");
            if (bool=='Y' || bool=='y'){
                selec=1;
            }
        } else printf("Eres idiota?? Elige bien\n");
    } while (selec == 0);
}

void levelUp(double *att, double *attm, double *def, double *defm, double *vel, int *race) {

    double x = (rand() % 8 + 1) + 3;
    if (*race == 1) {
        x = x * 0.5;
    } else
        if (*race == 2) {
        x = x * 1.5;
    } else
        if (*race == 3) {
        x = x * 2;
    } else
        if (*race == 4) {
        x = x * 1;
    }
    *att = *att + x;
    printf("\nataque: %.0lf", *att);
    x = rand() % 5 + 1;
    if (*race == 1) {
        x = x * 1.5;
    } else
        if (*race == 2) {
        x = x * 0.5;
    } else
        if (*race == 3) {
        x = x * 0;
    } else
        if (*race == 4) {
        x = x * 1;
    }
    *attm = *attm + x;
    printf("\nataque magico: %.0lf", *attm);
    x = rand() % 5 + 1;
    if (*race == 1) {
        x = x * 0.5;
    } else
        if (*race == 2) {
        x = x * 1.2;
    } else
        if (*race == 3) {
        x = x * 1;
    } else
        if (*race == 4) {
        x = x * 1;
    }
    *def = *def + x;
    printf("\ndefensa: %.0lf", *def);
    x = rand() % 5 + 1;
    if (*race == 1) {
        x = x * 1.3;
    } else
        if (*race == 2) {
        x = x * 0.5;
    } else
        if (*race == 3) {
        x = x * 1;
    } else
        if (*race == 4) {
        x = x * 1;
    }
    *defm = *defm + x;
    printf("\nadefensa magica: %.0lf", *defm);
    x = rand() % 5 + 1;
    if (*race == 1) {
        x = x * 1.7;
    } else
        if (*race == 2) {
        x = x * 0.5;
    } else
        if (*race == 3) {
        x = x * 0.5;
    } else
        if (*race == 4) {
        x = x * 1;
    }
    *vel = *vel + x;
    printf("\nvelocidad: %.0lf", *vel);
}

void expUp(chara *charac, int expg) {
    printf("has conseguido %d ptos de experiencia", expg);
    charac->exp = charac->exp + expg;
    if (charac->exp > pow(charac->level, 3)) {
        charac->level++;
        levelUp(&charac->att, &charac->attm, &charac->def, &charac->defm, &charac->vel, &charac->race);
        printf("Enhorabuena!! has subido al nivel %d", charac->level);
    }
}
