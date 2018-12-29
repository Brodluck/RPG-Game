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
    charac->class = class;
    charac->race = race;

    fclose(f);
    return 2;
}


short skill_book(chara *charac) {
    int option;
    printf("Bienvenido al libro de habilidades/hechizos\n");
    if (charac->class == 1) {
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
    } else if (charac->class == 2) {
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

    } else if (charac->class == 3) {
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
    for (i=0;i<100 && strcmp(charac->inv[i].name, "not")!=0;i++){
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
        printf("ID: %s", charac->inv[x-1].ID);
        return 1;
    }else return 2;
}

short shelter(chara *charac){
    int x, y, y2;
    typeText("Bienvenido a tu refugio", delay);
    printf("\n1.Inventario\n2.Personaje\n3.Descansar\n4.Volver\n5.Guardar y salir");
    scanf("%d", &x);
    system("clear");
    switch (x){
        case 1:
            do{
            printf("1.Mochila\n2.Cofre\n3.Cambiar equipamiento\n4.Volver");
            scanf("%d", &y);
            switch (y){
                case 1:
                    do{
                    y = mochila(charac);
                    }while (y==1);
                    y2=0;
                    break;
                case 2:
                    Cofre(charac);
                    y2=0;
                    break;
                case 3:
                    changeEquip(charac);
                    break;
                case 4:
                    y2=1;
                }
            }while (y2==0);
            return 2;
            break;
        case 2:
            characterDisplay(charac);
            return 2;
            break;
        case 3:
            typeText("Te tumbas a tomar un apacible descanso... Te sientes descansado", delay);
            charac->rest=1;
            return 2;
            break;
        case 4:
            return 1;
            break;
        case 5:
            return 3;
        default:
            printf("Eres idiota?? Elige bien");
            return 2;
    }
}

void characterDisplay(chara *charac){
    printf("name: %s\n", charac->name);
    printf("Raza: ");
    switch (charac->race){
        case 1:
            printf("Elfo\n");
            break;
        case 2:
            printf("Enano\n");
            break;
        case 3:
            printf("Orco\n");
            break;
        case 4:
            printf("Humano\n");
    }
    printf("Clase: ");
    switch (charac->class){
        case 1:
            printf("Guerrero\n");
            break;
        case 2:
            printf("Mago\n");
            break;
        case 3:
            printf("Paladin\n");
    }
    printf("level: %d\n", charac->level);
    printf("Vida maxima: %d\n", charac->vidamax);
    printf("Ataque: %.1lf\n", charac->att);
    printf("Ataque magico: %.1lf\n", charac->attm);
    printf("Defensa: %.1lf\n", charac->def);
    printf("Defensa magica: %.1lf\n", charac->defm);
    printf("Agilidad %.1lf\n", charac->vel);
}

