#include "head.h"

int menu(chara *charac, int dead) {
    FILE *f;
    srand(time(NULL));
    int option, gen, esquivar, vida, lvl, def, att, defm, attm, vel, class, race;

    if (dead) {
        option = 2;
    }else{
    typeText("WELCOME TO THE RPG GAME\n1.Start\n2.Load Game\n3.Exit\n", delay);
    scanf("%d", &option);
    system("clear");
    }
    switch (option) {
        case 1:
            return 1;
        case 2:
            f = fopen("Save.txt", "r");
            if (f == NULL) {
                return 0;
            }
            while ((fscanf(f, "%d %d %d %d %d %d %d %d %d %d", &gen, &vida, &lvl, &def, &att, &defm, &attm, &vel, &class, &race)) == 10);
            break;
        case 3:
            return 0;
            break;
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

short mochila(chara *charac){
    int x, i;
    printf ("mochila de %s\n\n", charac->name);
    while (i<100 && strcmp(charac->inv[i].name, "not")!=0){
        printf("%d. %s\n", i+1, charac->inv[i]);
    }
    printf("Enter an inventory number (0 to exit)");
    scanf("%d", &x);
    system("clear");
    if (x!=0){
        printf("%s\n\n", charac->inv[x-1].name);
        printf("Power: %.1lf\n", charac->inv[x-1].stat);
        printf("Magic power: %.1lf\n", charac->inv[x-1].statm);
        printf("Level: %d\n", charac->inv[x-1].lvl);
        if (charac->inv[x-1].rare==0){
            printf ("Atribute level: Common\n");
        }else if(charac->inv[x-1].extr==0){
            printf ("Atribute level: Rare\n");
        }else if (charac->inv[x-1].legen==0){
            printf("Atribute level: Very rare\n");
        }else{
            printf("Atribute level: Legendary\n");
        }
        printf("ID: %d", charac->inv[x-1].ID);
        return 1;
    }else return 2;
}