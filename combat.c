#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "head.h"

typedef struct {
    double normalattack, heavyattack, break_armor; // Habilidades warrior
    double light_hammer, heal, divine_shield; //Hechizos paladin
    double fire_ball, magic_armor, ilusion; //Hechizos mago
} skills;

short skill_book() {
    int option;
    printf("Bienvenido al libro de habilidades/hechizos");
    if (chara->class->warrior == 1) {
        do {
            printf("Elige la habilidad a consultar: 1.Ataque normal\n2.Ataque fuerte\n3.Romper armadura\n4.Salir");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("'Ataque normal'\nCoste: 20 realiza un ataque basico inflingiendo x1 tu daño de ataque base\n");
                    break;
                case 2:
                    printf("'Ataque fuerte'\nCoste: 40 realiza un ataque mas fuerte infligiendo x2.5 de tu daño de ataque base. Ademas de esto tiene una probabilidad de fallar del 15 por ciento\n");
                    break;
                case 3:
                    printf("'Romper armadura'\nCoste: 30 reduce la armadura de tu enemigo un 25 %% durante todo el combate\n");
                    break;
                case 4:
                    return 1;
            }
        } while (option != 4);
    } else if (chara->class->mage == 1) {
        do {
            printf("Elige el hechizo a consultar: 1.Bola de fuego\n2.Armadura magica\n3.Ilusion\n4.Salir");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("'Bola de fuego'\nCoste: 35 mana\nConjuras una flameante bola de intenso fuego que inflinge 15 de daño base mas x1.8 de tu daño magico\n");
                    break;
                case 2:
                    printf("'Armadura magica'\nCoste: 50 mana\nTe imbuyes en magia arcana aumentando tu armadura en 50 y al recibir daño, reflejas un 20 %% al enemigo\n");
                    break;
                case 3:
                    printf("'Ilusion'\nCoste: 35 mana\nCreas una copia falsa de ti mismo, aumentando tu probabilidad de esquivar en el proximo turno de un 50 %%\n");
                    break;
                case 4:
                    return 1;
            }
        } while (option != 4);

    } else if (chara->class->paladin == 1) {
        do {
            printf("Elige el hechizo a consultar: 1.Martillo de luz\n2.Luz sagrada\n3.Escudo divino\n4.Salir");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("'Martillo de luz'\nCoste: 35 de mana\Un martillo de luz bendita sentencia al enemigo inflingiendole tu daño base x1.5 mas x0.7 de tu daño magico\n");
                    break;
                case 2:
                    printf("'Luz sagrada'\nCoste: 30 mana\nLa luz te bendice haciendote recuperar de un 25-35 %% de tu vida maxima\n");
                    break;
                case 3:
                    printf("'Escudo divino'\nCoste: 80 mana\nCreas una barrera de luz impenetrable que te protege el proximo turno de cualquier daño o accion del enemigo\n");
                    break;
                case 4:
                    return 1;
            }
        } while (option != 4);

    }
}

short tutorial(npc enemy, chara player) {
    int playertuto;
    int enemytuto;
    player = playertuto;
    enemy = enemytuto;

    printf("Bien, para empezar, tienes que saber que esto es un juego de rol por turnos. Que significa esto? Pues que tu tienes unas habilidades y unos atributos\ny al enfrentarte a enemigos te pones a prueba");
    printf("\nPara empezar vamos a hacer un pequeño combate para que te ubiques. Presiona enter para empezar");
    scanf("");
    system("clear");






}       //FALTA acabar esto

short takepotion(int currentHealth, int staminaGained) {
    if ((currentHealth + staminaGained) > 100) {
        return 100;
    } else {
        return currentHealth + staminaGained;
    }
}  //protipo para uso de potis

short range_vida(int x, chara player) { // X->vida 
    if (x > 100 && player->race->humano==1) {
        return 1;
    }else if(x>110 && player->race->enano==1){
        return 1; 
    } else {
        return 0;
    }
}

short range_stamina(int y) { //Y->stamina)
    if (y < 0) {
        return 1;
    } else {
        return 0;
    }
}

int combat_warrior(npc *enemy, chara *player) { //************************Clase guerrero
    skills s;
    s.heavyattack = 2.5, s.normalattack = 1, s.break_armor = 0.25;
    s.fire_ball = 1.7;
    s.light_hammer = 1.5;
    s.heal = (rand() % 35) + 1;

    double dmg, deftemp;
    int turno = 1, option, percentage, x, miss;
    short y, rangeV, rangeS;

    //turno=1 es turno del jugador
    printf("Te enfrentas a %s !! Es hora de un combate glorioso! Que quieres hacer?", enemy->name);
    printf("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades");
    switch (option) {
        case 1:

            break;
        case 2:
            //Esto lo tiene que hacer rodri que no sé que ha hecho en el equipamiento/mochila
        case 3:
            percentage = (rand() % 100) + 1;
            if (percentage >= 1 && percentage <= 20) {
                printf("No puedes huir! %s te ha atrapado! Tocará luchar", enemy->name);
                break;
            } else {
                return 0; // printf("Has huido sin problema\n") hay que ponerlo en la funcion cuando se llame, que return 0 es combate nulo o whatever...
            }
        case 4:
            y = skill_book();
            if (y == 1)
                break;


    }
    if (enemy->vel < player->vel) { //Aqui se decide quien empezará primero
        turno = 0;
    }
    do { //Comienzo del combate
        dmg = 0;
        if (player->stamina <= 0) {
            printf("Tu aguante ha llegado a cero! Debes descansar este turno\n");
            player->stamina += 100;
            turno = 0;
        }
        if (turno == 1) { //Si turno ==1 es el turno del jugador



combat_start_warrior:
            printf("Elige la habilidad que quieres utilizar\n: 1.Ataque\n 2.Ataque fuerte\n3.Romper armadura\n");
            printf("Escribe 10 para ver tu libro de habilidades");
            scanf("%d", &option);
            if (option == 10) {
                y = skill_book();
                if (y == 1) {
                    continue;
                }
            }
            switch (option) {
                case 1:
                    dmg = s.normalattack * player->att;
                    player->stamina -= 20;
                    break;
                case 2:
                    miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15) {
                        printf("Fallo!");
                    } else {
                        dmg = s.heavyattack * player->att;
                        player->stamina -= 40;
                    }
                    break;
                case 3:
                    printf("La armadura del enemigo se ha reducido un 25 por ciento!");
                    deftemp = enemy->def;
                    deftemp -= (deftemp * s.break_armor);
                    player->stamina -= 30;
                    break;

            }
            rangeS = range_stamina(player->stamina); //Comprobacion de stamina
            if (rangeS == 1) {
                printf("No tienes suficiente estamina!\n");
                goto combat_start_warrior;
            }
            dmg -=(dmg * (enemy->def * 0.05));
            enemy->vida -= dmg;
            printf("Vida de %s : %d", enemy->name, enemy->vida);
            printf("Stamina: %d", player->stamina);

        } else if (turno == 0) {
            dmg=0;
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    printf("%s ha hecho un ataque normal\n", enemy->name);
                    dmg = s.normalattack * enemy->att;
                    enemy->stamina -= 15;
                    break;
                case 2:
                    printf("%s ha hecho un ataque fuerte\n", enemy->name);
                    miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15) {
                        printf("Fallo!");
                        break;
                    } else {
                        dmg = s.heavyattack * enemy->att;
                    }
                    enemy->stamina -= 30;
                    break;
            }
            dmg = dmg - ((dmg * (player->def * 0.05)) / 100);
            player->vida -= dmg;
            printf("Tu vida: %d\n", player->vida);
            printf("Stamina de %s: %d\n", enemy->name, enemy->stamina);
        }

    } while ((enemy->vida > 0) || (player->vida > 0));

    if (enemy->vida > 0) {
        printf("Estupendo! Has derrotado a %s! ", enemy->name);
        //items(caca caca); llamamos a la funcion de items para poner el drop etc
        printf("Escarvas e inspeccionas en el cadaver aun caliente de %s y descubres un objeto interesante\n", enemy->name);
        //printf("Has recibido: % ",objeto etc etc); willy pls help con esto
        return 1; //Ganaste 1=win
    } else if (player->vida <= 0) {
        printf("Has sido derrotado por %s! Volveras al ultimo punto guardado\n", enemy->name);
        return 0; // return 0, 0 será para empezar en el punto de guardado

    }




}

int combat_mage(npc *enemy, chara *player) {
    skills s;
    s.heavyattack = 2.5, s.normalattack = 1, s.break_armor = 0.25;
    s.fire_ball = 1.7;
    s.light_hammer = 1.5;
    s.heal = (rand() % 35) + 1;

    double dmg, deftemp, reflected_dmg;
    int turno = 1, option, percentage, x, miss;
    short y, rangeV, rangeS;


    printf("Te enfrentas a %s !! Es hora de un combate glorioso! Que quieres hacer?", enemy->name);
    printf("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades");
    switch (option) {
        case 1:

            break;
        case 2:
            //Esto lo tiene que hacer rodri que no sé que ha hecho en el equipamiento/mochila
        case 3:
            percentage = (rand() % 100) + 1;
            if (percentage >= 1 && percentage <= 20) {
                printf("No puedes huir! %s te ha atrapado! Tocará luchar", enemy->name);
                break;
            } else {
                return 0; // printf("Has huido sin problema\n") hay que ponerlo en la funcion cuando se llame, que return 0 es combate nulo o whatever...
            }
        case 4:
            y = skill_book();
            if (y == 1)
                break;


    }
    if (enemy->vel < player->vel) { //Aqui se decide quien empezará primero  turno=1 es turno del jugador, 0=enemy
        turno = 0;
    }
    do { //Comienzo del combate
        dmg = 0;
        if (player->stamina <= 0) {
            printf("Tu aguante ha llegado a cero! Debes descansar este turno\n");
            player->stamina += 100;
            turno = 0;
        }
        if (turno == 1) { //Si turno ==1 es el turno del jugador
combat_start_mage:
            printf("Elige la habilidad que quieres utilizar\n: 1.Bola de fuego\n 2.Armadura magica\n3.Ilusion\n");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    dmg = (s.fire_ball * player->attm) + 15;
                    player->stamina -= 35;
                    break;
                case 2:
                    s.magic_armor == 1;
                    player->def += 50;
                    player->stamina-=50;
                    break;
                case 3:
                    s.ilusion = 1;
                    player->esquivar += 50;
                    player->stamina-=35;
            }

            rangeS = range_stamina(player->stamina); //Comprobacion de stamina
            if (rangeS == 1) {
                printf("No tienes suficiente estamina!\n");
                goto combat_start_mage;
            }
            dmg = dmg - ((dmg * (enemy->def * 0.05)) / 100);
            enemy->vida -= dmg;
            printf("Vida de %s : %d", enemy->name, enemy->vida);
            printf("Estamina: %d", player->stamina);

        } else if (turno == 0) {
            dmg=0;
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    printf("%s ha hecho un ataque normal\n", enemy->name);
                    dmg = s.normalattack * enemy->att;
                    enemy->stamina -= 15;
                    break;
                case 2:
                    printf("%s ha hecho un ataque fuerte\n", enemy->name);
                    miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15) {
                        printf("Fallo!");
                        break;
                    } else {
                        dmg = s.heavyattack * enemy->att;
                    }
                    enemy->stamina -= 30;
                    break;
            }

            dmg -= (dmg * (player->def * 0.05));
            if (s.ilusion == 1) {
                miss = (rand() % 100) + 1;
                if (miss >= 1 && miss <= 50){
                        printf("%s ha fallado el ataque porque ha atacado a la tu ilusion!");
                    }
                } else if (s.magic_armor == 1) {
                reflected_dmg = dmg * 0.20;
                        enemy->vida -= reflected_dmg;
                        printf("%s ha recibido %0.lf de daño reflejado por Armadura magica", enemy->name, reflected_dmg);
            } else {
                player->vida -= dmg;

                        printf("Tu vida: %d\n", player->vida);
                        printf("Stamina de %s: %d\n", enemy->name, enemy->stamina);
            }
        }

    } while ((enemy->vida > 0) || (player->vida > 0));

        if (s.magic_armor == 1) {
            player->def -= 50;
        } //Restaurar defensa
    if (enemy->vida > 0) {
        printf("Estupendo! Has derrotado a %s! ", enemy->name);
                //items(caca caca); llamamos a la funcion de items para poner el drop etc
                printf("Escarvas e inspeccionas en el cadaver aun caliente de %s y descubres un objeto interesante\n", enemy->name);
                //printf("Has recibido: % ",objeto etc etc); willy pls help con esto
        return 1; //Ganaste 1=win
    } else if (player->vida <= 0) {
        printf("Has sido derrotado por %s! Volveras al ultimo punto guardado\n", enemy->name);

        return 0; // return 0, 0 será para empezar en el punto de guardado

    }

}
int combat_paladin(npc *enemy, chara *player) {
    skills s;
            s.heavyattack = 2.5, s.normalattack = 1, s.break_armor = 0.25;
            s.fire_ball = 1.7;
            s.light_hammer = 1.5;
            s.heal = (rand() % 35) + 1;

            double dmg, deftemp;
            int turno = 1, option, percentage, x, miss;
            short y, rangeV, rangeS;

            //turno=1 es turno del jugador
            printf("Te enfrentas a %s !! Es hora de un combate glorioso! Que quieres hacer?", enemy->name);
            printf("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades");
    switch (option) {
        case 1:

            break;
        case 2:
            //Esto lo tiene que hacer rodri que no sé que ha hecho en el equipamiento/mochila
        case 3:
            percentage = (rand() % 100) + 1;
            if (percentage >= 1 && percentage <= 20) {
                printf("No puedes huir! %s te ha atrapado! Tocará luchar", enemy->name);
                break;
            } else {
                return 0; // printf("Has huido sin problema\n") hay que ponerlo en la funcion cuando se llame, que return 0 es combate nulo o whatever...
            }
        case 4:
            y = skill_book();
            if (y == 1)
                break;


            }
    if (enemy->vel < player->vel) { //Aqui se decide quien empezará primero
        turno = 0;
    }
    do { //Comienzo del combate
        dmg = 0;
        if (player->stamina <= 0) {
            printf("Tu aguante ha llegado a cero! Debes descansar este turno\n");
                    player->stamina += 100;
                    turno = 0;
        }
        if (turno == 1) { //Si turno ==1 es el turno del jugador
           combat_start_paladin:
            printf("Elige la habilidad que quieres utilizar\n: 1.Martillo de luz\n 2.Luz sagrada\n3.Escudo divino\n");
                    scanf("%d", &option);
            switch (option) {
                case 1:
                    dmg = (s.light_hammer*player->att)+(0.7*player->attm);
                            player->stamina -=35;
                    break;
                case 2:
                    player->vida+=(player->vida*0.20);
                    rangeV=range_vida(player->vida);
                    if(rangeV==1){
                        if(player->race->humano==1){
                        player->vida=100;}
                    }else if(player->race->enano==1){
                        player->vida=110;
                    }else{
                        printf("Has usado luz sagrada, tu vida pasa de %d a %d", player->-(player->vida*0.20), player->vida);
                    }
                    player->stamina-=30;
                    break;
                case 3:
                    s.divine_shield==1;
                    player->stamina-=80;
                    
            }
            rangeS = range_stamina(player->stamina); //Comprobacion de stamina
            if (rangeS == 1) {
                printf("No tienes suficiente estamina!\n");
                        goto combat_start_paladin;
            }
            
             dmg -= (dmg * (player->def * 0.05));
                    enemy->vida -= dmg;
                    printf("Vida de %s : %d", enemy->name, enemy->vida);
                    printf("Estamina: %d", player->stamina);


        } else if (turno == 0) {
            dmg=0;
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    printf("%s ha hecho un ataque normal\n", enemy->name);
                            dmg = s.normalattack * enemy->att;
                            enemy->stamina -= 15;
                    break;
                case 2:
                    printf("%s ha hecho un ataque fuerte\n", enemy->name);
                            miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15) {
                        printf("Fallo!");
                        break;
                    } else {
                        dmg = s.heavyattack * enemy->att;
                    }
                    enemy->stamina -= 30;
                    break;
            }
           
            dmg = dmg - ((dmg * (player->def * 0.05)) / 100);
             if(s.divine_shield==1){
                dmg=0;
            }
                    player->vida -= dmg;
                    printf("Tu vida: %d\n", player->vida);
                    printf("Stamina de %s: %d\n", enemy->name, enemy->stamina);
        }

    } while ((enemy->vida > 0) || (player->vida > 0));

        if (enemy->vida > 0) {
            printf("Estupendo! Has derrotado a %s! ", enemy->name);
                    //items(caca caca); llamamos a la funcion de items para poner el drop etc
                    printf("Escarvas e inspeccionas en el cadaver aun caliente de %s y descubres un objeto interesante\n", enemy->name);
                    //printf("Has recibido: % ",objeto etc etc); willy pls help con esto
            return 1; //Ganaste 1=win
        } else if (player->vida <= 0) {
            printf("Has sido derrotado por %s! Volveras al ultimo punto guardado\n", enemy->name);
            return 0; // return 0, 0 será para empezar en el punto de guardado

        }

}
