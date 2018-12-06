#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "head.h"
#define delay 25
typedef struct {
    double normalattack, heavyattack, break_armor; // Habilidades warrior
    double light_hammer, heal, divine_shield; //Hechizos paladin
    double fire_ball, magic_armor, ilusion; //Hechizos mago
} skills;

short skill_book(chara *charac) {
    int option;
    printf("Bienvenido al libro de habilidades/hechizos\n");
    if (charac->class.warrior == 1) {
        do {
            printf("Elige la habilidad a consultar:\n1.Ataque normal\n2.Ataque fuerte\n3.Romper armadura\n4.Salir\n");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("'Ataque normal'\nrealiza un ataque basico inflingiendo x1 tu daño de ataque base\n");
                    break;
                case 2:
                    printf("'Ataque fuerte'\nrealiza un ataque mas fuerte infligiendo x2.5 de tu daño de ataque base.\nAdemas de esto tiene una probabilidad de fallar del 15 por ciento\n");
                    break;
                case 3:
                    printf("'Romper armadura'\nreduce la armadura de tu enemigo un 25 %% durante todo el combate\n");
                    break;
                case 4:
                    return 1;
            }
        } while (option != 4);
    } else if (charac->class.mage == 1) {
        do {
            printf("Elige el hechizo a consultar:\n1.Bola de fuego\n2.Armadura magica\n3.Ilusion\n4.Salir\n");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("'Bola de fuego'\nConjuras una flameante bola de intenso fuego que inflinge 15 de daño base mas x1.8 de tu daño magico\n");
                    break;
                case 2:
                    printf("'Armadura magica'\nTe imbuyes en magia arcana aumentando tu armadura en 50 y al recibir daño, reflejas un 20 %% al enemigo\n");
                    break;
                case 3:
                    printf("'Ilusion'\nCreas una copia falsa de ti mismo, aumentando tu probabilidad de esquivar en el proximo turno de un 50 %%\n");
                    break;
                case 4:
                    return 1;
            }
        } while (option != 4);

    } else if (charac->class.paladin == 1) {
        do {
            printf("Elige el hechizo a consultar:\n1.Martillo de luz\n2.Luz sagrada\n3.Escudo divino\n4.Salir\n");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    printf("'Martillo de luz'\nUn martillo de luz bendita sentencia al enemigo inflingiendole tu daño base x1.5 mas x0.7 de tu daño magico\n");
                    break;
                case 2:
                    printf("'Luz sagrada'\nLa luz te bendice haciendote recuperar de un 25-35 %% de tu vida maxima\n");
                    break;
                case 3:
                    printf("'Escudo divino'\nCreas una barrera de luz impenetrable que te protege el proximo turno de cualquier daño o accion del enemigo\n");
                    break;
                case 4:
                    return 1;
            }
        } while (option != 4);

    }
}

/*short tutorial(npc enemy, chara charac) {
    int charactuto;
    int enemytuto;
    charac = charactuto;
    enemy = enemytuto;

    printf("Bien, para empezar, tienes que saber que esto es un juego de rol por turnos. Que significa esto? Pues que tu tienes unas habilidades y unos atributos\ny al enfrentarte a enemigos te pones a prueba");
    printf("\nPara empezar vamos a hacer un pequeño combate para que te ubiques. Presiona enter para empezar");
    scanf("");
    system("clear");






}       //FALTA acabar esto*/

short takepotion(int currentHealth) {
    if (currentHealth > 100) {
        return 100;
    } else {
        return currentHealth;
    }
} //protipo para uso de potis

short range_health_above(chara *charac, npc *enemy) { //Check if life goes over than the max
    
    if ((charac->vida || enemy->vida) > 100 && (charac->race.humano == 1 || enemy->race.humano==1)) {
        return 100;
    } else if ((charac->vida || enemy->vida)> 110 && (charac->race.enano == 1 || enemy->race.enano==1)) {
        return 110;
    } else if((charac->vida || enemy->vida)> 85 && (charac->race.elfo== 1 || enemy->race.elfo==1))  {
        return 85;
    }else if((charac->vida || enemy->vida)> 110 && (charac->race.orco == 1 || enemy->race.orco==1)){
        return 110;
    } else{
        return 0;
    }
}
short range_health_below(chara *charac, npc *enemy) { //Check if life goes under the min
    
    if (charac->vida <= 0 || enemy->vida <=0 ){
        return 1;
    
    }else if(charac->vida >0 || enemy->vida > 0 ){
        return 0;
    }
    
}
int combat_warrior(npc *enemy, chara *charac) { //************************Clase guerrero
    skills s;
    s.heavyattack = 2.5, s.normalattack = 1, s.break_armor = 0.25;
    s.fire_ball = 1.7;
    s.light_hammer = 1.5;

    double dmg, deftemp;
    int turno = 1, option, percentage, x, miss, flag;
    short y, rangeHA, rangeHB;

    //turno=1 es turno del jugador
    printf("Te enfrentas a %s !! Es hora de un combate glorioso! Que quieres hacer?\n", enemy->name);
    printf("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades\n");
    scanf("%d", &option);
    do {
        switch (option) {
            case 1:

                break;
            case 2:
                //Esto lo tiene que hacer rodri que no sé que ha hecho en el equipamiento/mochila
            case 3:
                percentage = (rand() % 100) + 1;
                if (percentage >= 1 && percentage <= 20) {
                    printf("No puedes huir! %s te ha atrapado! Tocará luchar\n", enemy->name);
                    break;
                } else {
                    //Huido sin problemas
                    return -1;
                }
            case 4:
                y = skill_book(charac);
                if (y == 1)
                    break;

        }
    } while (option < 1 && option > 4);

    if (enemy->vel < charac->vel) { //Aqui se decide quien empezará primero
        turno = 0;
        printf("Comienza atacando %s ya que es mas rapido\n", enemy->name);
    }
    do { //Comienzo del combate
        dmg = 0;
        if (turno == 1) { //Si turno ==1 es el turno del jugador
combat_start_warrior:
            printf("Tu turno\n");
            printf("Elige la habilidad que quieres utilizar:\n1.Ataque\n2.Ataque fuerte\n3.Romper armadura\n");
            printf("Escribe 10 para ver tu libro de habilidades\n");
            scanf("%d", &option);
            if (option == 10) {
                y = skill_book(charac);
                if (y == 1) {
                    continue;
                }
            }
            switch (option) {
                case 1:
                    dmg = s.normalattack * charac->att;
                    printf("Has realizado un ataque normal");
                    break;
                case 2:
                    miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15) {
                        printf("Fallo\n!");
                    } else {
                        dmg = s.heavyattack * charac->att;

                    }
                    break;
                case 3:
                    printf("La armadura del enemigo se ha reducido un 25 por ciento!\n");
                    deftemp = enemy->def;
                    deftemp -= (deftemp * s.break_armor);
                    dmg=0;

                    break;

            }
            dmg -=  (enemy->def * 0.05);
            enemy->vida -= dmg;
            rangeHB=range_health_below(charac,enemy);
            if(rangeHB){
                printf("e inflinges %0.2lf a %s\n", dmg, enemy->name);
                printf("La vida de %s es 0\n", enemy->name);
            }else if (!rangeHB){
            printf("e inflinges %0.2lf a %s\n", dmg, enemy->name);
            printf(", su vida ahora es: %d\n", enemy->vida);
            }
            turno = 0;
            if (enemy->vida <= 0) {
                printf("Estupendo! Has derrotado a %s! ", enemy->name);
                //items(caca caca); llamamos a la funcion de items para poner el drop etc
                printf("Escarvas e inspeccionas en el cadaver aun caliente de %s y descubres un objeto interesante\n", enemy->name);
                //printf("Has recibido: % ",objeto etc etc); willy pls help con esto
                return 1;
            }

        } else if (turno == 0) {
            dmg = 0;
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    printf("%s ha hecho un ataque normal", enemy->name);
                    dmg = s.normalattack * enemy->att;
                    break;
                case 2:
                    printf("%s ha hecho un ataque fuerte", enemy->name);
                    miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15) {
                        printf("Fallo\n!");
                        break;
                    } else {
                        dmg = s.heavyattack * enemy->att;
                    }
                    break;
            }
            dmg = dmg - (charac->def * 0.05);
            charac->vida -= dmg;
            rangeHB=range_health_below(charac,enemy);
            if(rangeHB){
            printf("y ha inflingido %0.2lf\n", dmg);
            printf("T vida es 0");
            }else if(!rangeHB){
            printf("y ha inflingido %0.2lf\n", dmg);
            printf("T vida: %d\n", charac->vida);
            }
            turno = 1;
            if (charac->vida <= 0) {
                printf("Has sido derrotado por %s! Volveras al ultimo punto guardado\n", enemy->name);

                return 0; // return 0, 0 será para empezar en el punto de guardado
            }
        }

    } while ((enemy->vida < 0) || (charac->vida < 0));

}

int combat_mage(npc *enemy, chara *charac) {
    skills s;
    s.heavyattack = 2.5, s.normalattack = 1, s.break_armor = 0.25;
    s.fire_ball = 1.7;
    s.light_hammer = 1.5;
    s.magic_armor=0;

    double dmg, deftemp, reflected_dmg;
    int turno = 1, option, percentage, x, miss, flag;
    short y, rangeHA, rangeHB;

    typeText("Te enfrentas a ",delay); typeText(enemy->name,delay); typeText(" !! Es hora de un combate glorioso! Que quieres hacer?\n",delay);
    typeText("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades\n",delay);
    do {
        scanf("%d", &option);
        switch (option) {
            case 1:

                break;
            case 2:
                //Esto lo tiene que hacer rodri que no sé que ha hecho en el equipamiento/mochila
            case 3:
                percentage = (rand() % 100) + 1;
                if (percentage >= 1 && percentage <= 20) {
                    typeText("No puedes huir! ,",delay); typeText(enemy->name,delay); typeText(" te ha atrapado! Toca luchar\n",delay);
                    break;
                } else {
                    //Has huido sin problemas
                    return -1;
                }
            case 4:
                y = skill_book(charac);
                if (y == 1)
                    break;
        }
    } while (option < 1 && option > 4);



    if (enemy->vel < charac->vel) { //Aqui se decide quien empezará primero
        turno = 0;
        typeText("Comienza atacando ,",delay); typeText(enemy->name,delay); typeText(" ya que es mas rapido\n",delay);
    }
    do { //Comienzo del combate
        dmg = 0;
        if (turno == 1) { //Si turno ==1 es el turno del jugador
combat_start_mage:
            typeText("Tu turno\n",delay);
            typeText("Elige la habilidad que quieres utilizar:\n1.Bola de fuego\n2.Armadura magica\n3.Ilusion\n",delay);
            scanf("%d", &option);
            do {
                switch (option) {
                    case 1:
                        dmg = (s.fire_ball * charac->attm) + 15;
                        typeText("Has conjurado una bola de fuego, que ",delay);
                        flag = 1;
                        break;
                    case 2:
                        s.magic_armor = 1;
                        charac->def += 50;
                        typeText("Has utilizado armadura magica\n",delay);
                        break;
                    case 3:
                        s.ilusion = 1;
                        charac->esquivar += 50;
                        typeText("Has utilizado ilusion\n",delay);
                }
            } while (x < 1 && x > 3);
            dmg = dmg - (enemy->def * 0.05);
            enemy->vida -= dmg;
            rangeHB=range_health_below(charac,enemy);
            if(rangeHB){
                 if (flag) { // 0 para char, 1 para double, 2 para int
                typeText("inflinge ",delay); typeText_double(&dmg,delay); typeText("a ",delay); typeText(enemy->name,delay);
            }
                typeText("La vida de %s es 0\n", enemy->name);
            }else if (!rangeHB){
             if (flag) {
                printf("inflinge %0.2lf a %s", dmg, enemy->name);
            }
            printf(", su vida ahora es: %d\n", enemy->vida);
            }
           
            turno = 0;

            if (enemy->vida <= 0) {
                printf("Estupendo! Has derrotado a %s! ", enemy->name);
                //items(caca caca); llamamos a la funcion de items para poner el drop etc
                printf("Escarvas e inspeccionas en el cadaver aun caliente de %s y descubres un objeto interesante\n", enemy->name);
                //printf("Has recibido: % ",objeto etc etc); willy pls help con esto
                if (s.magic_armor == 1) { //Restaurar defensa
                    charac->def -= 50;
                    s.magic_armor = 0;
                }
                return 1; //Ganaste 1=win
            }

            //Turno enemigo
        } else if (turno == 0) {
            dmg = 0;
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    printf("%s ha hecho un ataque normal\n", enemy->name);
                    dmg = s.normalattack * enemy->att;
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
                    break;
            }

            dmg = dmg - (charac->def * 0.05);
            if (s.ilusion == 1) {
                s.ilusion=0;
                miss = (rand() % 100) + 1;
                if (miss >= 1 && miss <= 50) {
                    printf("%s ha fallado el ataque porque ha atacado a tu ilusion!\n", enemy->name);
                    dmg=0;
                }
            } else if (s.magic_armor) {
                reflected_dmg = dmg * 0.20;
                enemy->vida -= reflected_dmg;
                if(dmg!=0){
                printf("%s ha recibido %0.lf de daño reflejado por Armadura magica\n", enemy->name, reflected_dmg);
                }
            }
            charac->vida -= dmg;
            rangeHB=range_health_below(charac,enemy);
            if(rangeHB){
            printf("%s te ha inflingido %0.2lf\n", enemy->name, dmg);
            printf("Tu vida es 0\n");
            }else if(!rangeHB){
            printf("%s te ha inflingido %0.2lf\n", enemy->name, dmg);
            printf("Tu vida: %d\n", charac->vida);
            printf("Vida de %s: %d\n", enemy->name, enemy->vida);
            }

            turno = 1;
            if (charac->vida <= 0) {
                if (s.magic_armor) { //Restaurar defensa
                    charac->def -= 50;
                    s.magic_armor = 0;
                }
                printf("Has sido derrotado por %s! Volveras al ultimo punto guardado\n", enemy->name);

                return 0; // return 0, 0 será para empezar en el punto de guardado
            }
        }

    } while ((enemy->vida > 0) || (charac->vida > 0));

}

int combat_paladin(npc *enemy, chara *charac) {
    skills s;
    s.heavyattack = 2.5, s.normalattack = 1, s.break_armor = 0.25;
    s.fire_ball = 1.7;
    s.light_hammer = 1.5;
    s.heal = 35;

    double dmg, deftemp;
    int turno = 1, option, percentage, x, miss;
    short y, rangeHA,rangeHB;

    //turno=1 es turno del jugador
    printf("Te enfrentas a %s !! Es hora de un combate glorioso! Que quieres hacer?\n", enemy->name);
    printf("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades");
    scanf("%d", &option);
    do {
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
                    //Has huido sin problemas
                    return -1;
                }
            case 4:
                y = skill_book(charac);
                if (y == 1)
                    break;
        }
    } while (option < 1 && option > 4);

    if (enemy->vel < charac->vel) { //Aqui se decide quien empezará primero
        turno = 0;
        printf("Comienza atacando %s ya que es mas rapido\n", enemy->name);
    }
    do { //Comienzo del combate
        dmg = 0;
        if (turno == 1) { //Si turno ==1 es el turno del jugador
combat_start_paladin:
            printf("Tu turno\n");
            printf("Elige la habilidad que quieres utilizar:\n1.Martillo de luz\n2.Luz sagrada\n3.Escudo divino\n");
            scanf("%d", &option);
            switch (option) {
                case 1:
                    dmg = (s.light_hammer * charac->att)+(0.7 * charac->attm);
                    printf("Has utilizado martillo de luz que");
                    break;
                case 2:
                    if(charac->race.enano){
                    charac->vida += (110 * 0.35);
                    }else if(charac->race.humano){
                        charac->vida+=(100*0.35);
                    }
                    rangeHA = range_health_above(charac, enemy);
                    if (rangeHA == 0) {
                        int healthOld = charac->vida - (charac->vida * 0.35);
                        printf("Has usado luz sagrada, tu vida pasa de %d a %d", healthOld, charac->vida);
                    } else {
                        charac->vida = rangeHA;
                    }
                    break;
                case 3:
                    s.divine_shield == 1;

            }
            dmg -= (charac->def * 0.05);
            enemy->vida -= dmg;
             rangeHB=range_health_below(charac,enemy);
            if(rangeHB){
                printf(" inflinge %0.2lf a %s\n", dmg, enemy->name);
                printf("La vida de %s es 0\n", enemy->name);
            }else if (!rangeHB){
            printf(" inflinge %0.2lf a %s\n", dmg, enemy->name);
            printf("La vida de %s ahora es %d\n", enemy->name, enemy->vida);
            }
            turno = 0;
            if (enemy->vida <= 0) {
                printf("Estupendo! Has derrotado a %s! ", enemy->name);
                //items(caca caca); llamamos a la funcion de items para poner el drop etc
                printf("Escarvas e inspeccionas en el cadaver aun caliente de %s y descubres un objeto interesante\n", enemy->name);
                //printf("Has recibido: % ",objeto etc etc); willy pls help con esto
                return 1;
            }

        } else if (turno == 0) {
            dmg = 0;
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    printf("%s ha hecho un ataque normal\n", enemy->name);
                    dmg = s.normalattack * enemy->att;
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
                    break;
            }

            dmg = dmg - (charac->def * 0.05);
            if (s.divine_shield == 1) {
                dmg = 0;
                s.divine_shield = 0;
                printf("Pero tu escudo divino te ha protegido de los ataques de %s\n", enemy->name);                
            }
            
            charac->vida -= dmg;
            rangeHB=range_health_below(charac,enemy);
            if(rangeHB){
            printf("y ha inflingido %0.2lf\n", dmg);
            printf("T vida es 0");
            }else if(!rangeHB){
            printf("y ha inflingido %0.2lf\n", dmg);
            printf("T vida: %d\n", charac->vida);
            }
            turno = 1;
            if (charac->vida <= 0) {

                printf("Has sido derrotado por %s! Volveras al ultimo punto guardado\n", enemy->name);

                return 0; // return 0, 0 será para empezar en el punto de guardado
            }
        }

    } while ((enemy->vida > 0) || (charac->vida > 0));
}

int combat(chara *charac, npc *enemy) {
    int x = 0, y = 0, z = 0;
    EnemyGen(*charac, enemy);
    if (charac->class.warrior == 1) {
        x = combat_warrior(enemy, charac);
        if (x == 1) {
            return 1;
        } else if (x == -1) {
            return -1;
        } else {
            return 0;
        }
    } else if (charac->class.mage == 1) {
        y = combat_mage(enemy, charac);
        if (y == 1) {
            return 1;
        } else if (x == -1) {
            return -1;
        } else {
            return 0;
        }
    } else if (charac->class.paladin == 1) {
        z = combat_paladin(enemy, charac);
        if (z == 1) {
            return 1;
        } else if (x == -1) {
            return -1;
        } else {
            return 0;
        }
    }



}
