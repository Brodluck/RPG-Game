#include "head.h"

typedef struct {
    double normalattack, heavyattack, break_armor; // Habilidades warrior
    double light_hammer, heal, divine_shield; //Hechizos paladin
    double fire_ball, magic_armor, ilusion; //Hechizos mago
} skills;



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

short range_health_above(chara *charac, npc *enemy, short x) { //Check if life goes over than the max
   
    if(x==1){
    if (charac->vida > 100 && charac->race.humano == 1) {
        return 100;
    } else if (charac->vida > 100 && charac->race.humano == 1) {
        return 110;
    } else if(charac->vida > 100 && charac->race.humano == 1)  {
        return 85;
    }else if(charac->vida > 100 && charac->race.humano == 1){
        return 110;
    } else{
        return 0;
    }
    }else{
    if (enemy->vida > 100 && enemy->race.humano == 1) {
        return 100;
    } else if (enemy->vida > 100 && enemy->race.humano == 1) {
        return 110;
    } else if(enemy->vida > 100 && enemy->race.humano == 1)  {
        return 85;
    }else if(enemy->vida > 100 && enemy->race.humano == 1){
        return 110;
    } else{
        return 0;
    }
    }
}


short range_health_below(chara *charac, npc *enemy, short x) { //Check if life goes under the min
    if (x==1){
    if (charac->vida <= 0){
        return 1;
    
    }else{
        return 0;
        }
    }else{
        if (enemy->vida <=0 ){
        return 1;
    
    }else{
        return 0;
        }
    }
}
int combat_warrior(npc *enemy, chara *charac) { //************************Clase guerrero
    skills s;
    s.heavyattack = 2.5, s.normalattack = 1, s.break_armor = 0.25;
    s.fire_ball = 1.7;
    s.light_hammer = 1.5;
    item drop;
    double dmg, deftemp;
    int turno = 1, option, percentage, x, miss, flag, cont;
    short y, rangeHA, rangeHB, moch=0;
    
    //turno=1 es turno del jugador
    typeText("Te enfrentas a ",delay); typeText(enemy->name,delay); typeText("!! Es hora de un combate glorioso! Que quieres hacer?\n",delay);
    do { //Comienzo del combate
    do {
    printf("1.Luchar \n2.Objetos \n3.Huir \n4.Ver libro de habilidades\n");
    scanf("%d", &option);
    system("clear");
        switch (option) {
            case 1:
                cont=1;
                break;
            case 2:
                do{
                moch=mochila(charac);
                }while (moch==1);
                option = 5;
                cont=0;
                break;
            case 3:
                percentage = (rand() % 100) + 1;
                if (percentage >= 1 && percentage <= 20) {
                   typeText("No puedes huir! ", delay); typeText(enemy->name, delay); typeText(" te ha atrapado! Toca luchar\n", delay);
                } else {
                    //Huido sin problemas
                    return -1;
                }
                cont=1;
                break;
            case 4:
                y = skill_book(charac);
                if (y == 1)
                cont=0;
                break;
            default:
                printf("Eres idiota?? Elige bien\n");
                cont=0;
                break;

        }
    } while (cont==0);

    if (enemy->vel < charac->vel) { //Aqui se decide quien empezará primero
        turno = 0;
        typeText("Comienza atacando ",delay); typeText(enemy->name,delay); typeText(" ya que es mas rapido\n",delay);
    }
        dmg = 0;
        if (turno == 1) { //Si turno ==1 es el turno del jugador
           printf("----------------------------------\nTu turno\n");
           do{
            printf("Elige la habilidad que quieres utilizar: \n1.Ataque \n2.Ataque fuerte \n3.Romper armadura \n4.ver libro de habilidades\n");
            scanf("%d", &option);
            system("clear");
            switch (option) {
                case 1:
                    dmg = s.normalattack * charac->att;
                    typeText("Has realizado un ataque normal",delay);
                    cont=1;
                    break;
                case 2:
                    miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15){
                        typeText("Fallo\n!",delay);
                    } else {
                        dmg = s.heavyattack * charac->att;

                    }
                    cont=1;
                    break;
                case 3:
                    typeText("La armadura del enemigo se ha reducido un 25 por ciento!\n",delay);
                    deftemp = enemy->def;
                    deftemp -= (deftemp * s.break_armor);
                    dmg=0;
                    cont=1;
                    break;
                case 4:
                    do{
                    y = skill_book(charac);
                    }while (y!=1);
                    cont=0;
                    break;
                default:
                    printf ("eres idiota?? Elige bien\n");
                    cont=0;
                    break;
                }
            }while (cont==0);
            dmg -=  (enemy->def * 0.05);
            enemy->vida -= dmg;
            rangeHB=range_health_below(charac,enemy, 2);
             if(rangeHB){
                typeText("infliges ",delay);printf(" %0.2lf ",dmg);typeText(" a ",delay);typeText(enemy->name,delay);
                typeText("\nLa vida de ",delay); typeText(enemy->name,delay); typeText(" ahora es de 0\n", delay);
            }else{
            typeText("infliges ",delay); printf("%0.2lf",dmg); typeText(" a ",delay); typeText(enemy->name,delay);
            typeText("\nLa vida de ",delay);typeText(enemy->name,delay);typeText(" ahora es de ", delay); printf("%d\n",enemy->vida);
            }
            turno = 0;
            
            if (enemy->vida <= 0) {
                typeText("Estupendo! Has derrotado a ",delay); typeText(enemy->name,delay);
                x=rand()%4;
                if(x==1){
                    x=rand()%7;
                    if(x==1){
                        drop = enemy->gear[0];
                    }else if (x==2){
                        drop = enemy->gear[1];
                    }else if (x==3){
                        drop = enemy->gear[2];
                    }else if (x==4){
                        drop = enemy->gear[3];
                    }else if (x==5){
                        drop = enemy->weapons[0];
                    }else{
                        drop = enemy->weapons[1];
                    }
                    printf("\n");
                typeText("Escarvas e inspeccionas en el cadaver aun caliente de ",delay);typeText(enemy->name,delay);typeText(" y descubres un objeto interesante\n", delay);
                printf("obtienes el siguiente item: %s", drop.name);
                }
                return 1;
            }

        } else if (turno == 0) {
           dmg = 0;
           printf("----------------------------------\nTurno de %s\n",enemy->name);
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    typeText(enemy->name,delay);typeText(" ha hecho un ataque normal\n",delay);
                    dmg = s.normalattack * enemy->att;
                    break;
                case 2:
                    typeText(enemy->name,delay);typeText(" ha hecho un ataque fuerte\n",delay);
                    miss = (rand() % 100) + 1;
                    if (miss <= 15) {
                        typeText("Fallo!",delay);
                    } else {
                        dmg = s.heavyattack * enemy->att;
                    }
                    break;
            
            }
            dmg = dmg - (charac->def * 0.05);
            charac->vida -= dmg;
            rangeHB=range_health_below(charac,enemy, 1);
            if(rangeHB){
            typeText(enemy->name,delay);typeText(" te ha infligido ",delay); printf("%0.2lf \n",dmg);
            typeText("Tu vida es 0\n",delay);
            }else if(!rangeHB){
            typeText(enemy->name,delay);typeText(" te ha infligido ",delay); printf("%0.2lf \n",dmg);
            typeText("Tu vida: ",delay); printf("%d\n",charac->vida);
            typeText("Vida de ",delay);typeText(enemy->name,delay); typeText(": ",delay);printf("%d\n",enemy->vida);
            }
            turno = 1;
            if (charac->vida <= 0) {
                 typeText("Has sido derrotado por ",delay);typeText(enemy->name,delay); typeText("! Volveras al ultimo punto guardado\n",delay);
                return 0; // return 0, 0 será para empezar en el punto de guardado
            }
        }

    } while ((enemy->vida > 0) && (charac->vida > 0));

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
    printf("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades\n");
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
                    typeText("No puedes huir!",delay); typeText(enemy->name,delay); typeText(" te ha atrapado! Toca luchar\n",delay);
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
        typeText("Comienza atacando ",delay); typeText(enemy->name,delay); typeText(" ya que es mas rapido\n",delay);
    }
    do { //Comienzo del combate
        dmg = 0;
        if (turno == 1) { //Si turno ==1 es el turno del jugador
            printf("----------------------------------\nTu turno\n");
            printf("Elige la habilidad que quieres utilizar:\n1.Bola de fuego \n2.Armadura magica\n3.Ilusion\n10.Ver libro de habilidades\n");
            scanf("%d", &option);
            if (option == 10) {
                y = skill_book(charac);
                if (y == 1) {
                    continue;
                }
            }
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
            rangeHB=range_health_below(charac,enemy, 0);
            if(rangeHB){
                 if (flag) { // 0 para char, 1 para double, 2 para int
                typeText("inflinge ",delay); printf("%0.2lf",dmg); typeText(" a ",delay); typeText(enemy->name,delay);
            }
                 typeText("La vida de ",delay); typeText(enemy->name,delay); typeText(" is 0\n", delay);
            }else if (!rangeHB){
             if (flag) {
                 typeText("inflinge ",delay); printf("%0.2lf",dmg); typeText(" a ",delay); typeText(enemy->name,delay);
                
            }
            typeText(", su vida ahora es: ", delay); printf("%d\n",enemy->vida);
            }
            turno = 0;

            if (enemy->vida <= 0) {
                typeText("Estupendo! Has derrotado a ",delay); typeText(enemy->name,delay);
                //items(caca caca); llamamos a la funcion de items para poner el drop etc
                typeText("Escarvas e inspeccionas en el cadaver aun caliente de ",delay);typeText(enemy->name,delay);typeText(" y descubres un objeto interesante\n", delay);
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
            printf("----------------------------------\nTurno de %s\n",enemy->name);
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    typeText(enemy->name,delay);typeText(" ha hecho un ataque normal\n",delay);
                    dmg = s.normalattack * enemy->att;
                    break;
                case 2:
                    typeText(enemy->name,delay);typeText(" ha hecho un ataque fuerte\n",delay);
                    miss = (rand() % 100) + 1;
                    if (miss >= 1 && miss <= 15) {
                        typeText("Fallo!",delay);
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
                    typeText(enemy->name,delay);typeText(" ha fallado el ataque porque ha atacado a tu ilusion!\n",delay);
                    dmg=0;
                }
            } else if (s.magic_armor) {
                reflected_dmg = dmg * 0.20;
                enemy->vida -= reflected_dmg;
                if(dmg!=0){
                    typeText(enemy->name,delay); typeText(" ha recibido ",delay); printf("%0.2lf",reflected_dmg); typeText(" reflejado por Armadura magica\n",delay);
                }
            }
            charac->vida -= dmg;
            rangeHB=range_health_below(charac,enemy, 1);
            if(rangeHB){
            typeText(enemy->name,delay);typeText(" te ha inflingido ",delay); printf("%0.2lf \n",dmg);
            typeText("Tu vida es 0\n",delay);
            }else if(!rangeHB){
            typeText(enemy->name,delay);typeText(" te ha inflingido ",delay); printf("%0.2lf \n",dmg);
            typeText("Tu vida: ",delay); printf("%d\n",charac->vida);
            typeText("Vida de ",delay);typeText(enemy->name,delay); typeText(": ",delay);printf("%d\n",enemy->vida);
            }
            turno = 1;
            if (charac->vida <= 0) {
                if (s.magic_armor) { //Restaurar defensa
                    charac->def -= 50;
                    s.magic_armor = 0;
                }
                typeText("Has sido derrotado por ",delay);typeText(enemy->name,delay);typeText("! Volveras al ultimo punto guardado\n",delay);

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
   typeText("Te enfrentas a ",delay); typeText(enemy->name,delay); typeText(" !! Es hora de un combate glorioso! Que quieres hacer?\n",delay);
    printf("1.Luchar\n2.Objetos\n3.Huir\n4.Ver libro de habilidades\n");
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
            printf("----------------------------------\nTu turno\n");
            printf("Elige la habilidad que quieres utilizar:\n1.Martillo de luz\t2.Luz sagrada\t3.Escudo divino\t10. Ver libro de habilidades\n");
            scanf("%d", &option);
            if (option == 10) {
                y = skill_book(charac);
                if (y == 1) {
                    continue;
                }
            }
            switch (option) {
                case 1:
                    dmg = (s.light_hammer * charac->att)+(0.7 * charac->attm);
                    typeText("Has utilizado martillo de luz que",delay);
                    break;
                case 2:
                    if(charac->race.enano){
                    charac->vida += (110 * 0.35);
                    }else if(charac->race.humano){
                        charac->vida+=(100*0.35);
                    }
                    rangeHA = range_health_above(charac, enemy, 1);
                    if (rangeHA == 0) {
                        int healthOld = charac->vida - (charac->vida * 0.35);
                       
typeText("Has usado luz sagrada, tu vida pasa de ",delay); printf("%d",healthOld);typeText(" a ",delay); printf("%d\n",charac->vida);
                    } else {
                        charac->vida = rangeHA;
                    }
                    break;
                case 3:
                    s.divine_shield == 1;

            }
            dmg -= (charac->def * 0.05);
            enemy->vida -= dmg;
             rangeHB=range_health_below(charac,enemy, 0);
             
            if(rangeHB){
                typeText(" inflinge ",delay);printf("%0.2lf ",dmg);typeText(" a ",delay);typeText(enemy->name,delay);printf("\n");
                
                typeText("La vida de",delay); typeText(enemy->name,delay); typeText(" is 0\n", delay);
            }else if (!rangeHB){
            typeText(" inflinge ",delay); printf("%0.2lf ",dmg); typeText("a ",delay); typeText(enemy->name,delay);
            typeText("La vida de ",delay);typeText(enemy->name,delay);typeText(" ahora es de", delay); printf("%d\n",enemy->vida);
            }
            turno = 0;
             if (enemy->vida <= 0) {
                typeText("Estupendo! Has derrotado a ",delay); typeText(enemy->name,delay);
                //items(caca caca); llamamos a la funcion de items para poner el drop etc
                typeText("\nEscarvas e inspeccionas en el cadaver aun caliente de ",delay);typeText(enemy->name,delay);typeText(" y descubres un objeto interesante\n", delay);
                //printf("Has recibido: % ",objeto etc etc); willy pls help con esto
                return 1;
            }

        } else if (turno == 0) {
            dmg = 0;
            printf("----------------------------------\nTurno de %s\n",enemy->name);
            x = (rand() % 2) + 1;
            switch (x) {
                case 1:
                    typeText(enemy->name,delay);typeText(" ha hecho un ataque normal\n",delay);
                    dmg = s.normalattack * enemy->att;
                    break;
                case 2:
                     typeText(enemy->name,delay);typeText(" ha hecho un ataque fuerte\n",delay);
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
                typeText("Pero tu escudo divino te ha protegido de los ataques de ",delay); typeText(enemy->name,delay);printf("\n");                
            }
            
            charac->vida -= dmg;
            rangeHB=range_health_below(charac,enemy, 1);
            if(rangeHB){
            typeText(enemy->name,delay);typeText(" te ha inflingido ",delay); printf("%0.2lf \n",dmg);
            typeText("Tu vida es 0\n",delay);
            }else if(!rangeHB){
            typeText(enemy->name,delay);typeText(" te ha inflingido ",delay); printf("%0.2lf \n",dmg);
            typeText("Tu vida: ",delay); printf("%d\n",charac->vida);
            typeText("Vida de ",delay);typeText(enemy->name,delay); typeText(": ",delay);printf("%d\n",enemy->vida);
            }
            turno = 1;
            if (charac->vida <= 0) {
                typeText("Has sido derrotado por ",delay);typeText(enemy->name,delay); typeText("! Volveras al ultimo punto guardado\n",delay);
                return 0; // return 0, 0 será para empezar en el punto de guardado
            }
        }

    } while ((enemy->vida > 0) || (charac->vida > 0));
}

int combat(chara *charac, npc *enemy) {
    int x = 0, y = 0, z = 0;
    enemyGen(*charac, enemy);
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
