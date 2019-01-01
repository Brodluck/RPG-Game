#include "head.h"

item cofre[1000];

void character(chara *charac) {
    int x, y, selec = 0, i;
    char bool;
    do {
        do {
            typeText("\nSelecciona la raza con la que comenzaras tu aventura:", delay);
            printf("\n1.Elfo\n2.Enano\n3.Orco\n4.Humano\n");
            scanf("%d", &x);
            system("clear");
            switch (x) { //Seleccion de raza
                case 1:
                    typeText("Elfos: afinidad a la magia, veloces pero debiles. Clases: Mago, Guerrero\n", delay);
                    printf("Ataque: -10\nAtaque magico: +10 \nDefensa: -10\nDefensa magica: +10\nVelocidad: +20\n");

                    break;
                case 2:
                    typeText("Enanos: expertos con armas y armaduras, resistentes pero lentos. Clases: Guerrero, Paladin\n", delay);
                    printf("Ataque: +10\nAtaque magico: -10 \nDefensa: +10\nDefensa magica: +10\nVelocidad: +0\n");

                    break;
                case 3:
                    typeText("Orcos: grandes y fuertes, expertos con armas, peligrosos pero muy lentos. No saben usar magia. Clases: Guerrero\n", delay);
                    printf("Ataque: +20\nAtaque magico: -100 \nDefensa: +0\nDefensa magica: +0\nVelocidad: -20\n");
                    break;
                case 4:
                    typeText("Humanos: ninguna especialidad, son normalitos, no tienen ningun atributo aumentado pero tampoco ninguno reducido\n", delay);
                    printf("Clases: Paladin, Guerrero, Mago\n");

                    break;
                default:
                    printf("Eres idiota?? Elige bien\n");
                    break;
            }
        } while (0 > x || x >= 5);


        do { //confirmar seleccion
            typeText("\nDe verdad quieres seleccionar esta raza? [Y/N]", delay);
            scanf("\n%c", &bool);
            system("clear");
            if (bool == 'Y' || bool == 'y') {
                selec = 1;
            } else if (bool == 'N' || bool == 'n') {
                selec = 0;
            } else {
                printf("Eres idiota?? Elige bien\n");
            }
        } while ((bool == 'Y' || bool == 'y') && (bool == 'N' || bool == 'n'));
    } while (selec == 0);
    system("clear");
    switch (x) {
        case 1:
            //elfo
            charac->race = 1;
            charac->vida = 85;
            charac->vidamax = 85;
            charac->level = 1;
            charac->att = 0;
            charac->attm = 10;
            charac->def = 5;
            charac->defm = 10;
            charac->vel = 25;

            break;

        case 2:
            //enano
            charac->race = 2;
            charac->vida = 110;
            charac->vidamax = 110;
            charac->level = 1;
            charac->att = 10;
            charac->attm = 5;
            charac->def = 20;
            charac->defm = 15;
            charac->vel = 0;

            break;
        case 3:
            //orco
            charac->race = 3;
            charac->vida = 110;
            charac->vidamax = 110;
            charac->level = 1;
            charac->att = 20;
            charac->attm = 0;
            charac->def = 20;
            charac->defm = 5;
            charac->vel = -10;

            break;
        case 4:
            //humano
            charac->race = 4;
            charac->vida = 100;
            charac->vidamax = 100;
            charac->level = 1;
            charac->att = 10;
            charac->attm = 10;
            charac->def = 10;
            charac->defm = 10;
            charac->vel = 0;


            break;
        default:
            typeText("Eres idiota?? Elige bien\n", delay);
            break;

    }
    while (0 > x && x > 5);
    do { //Seleccion de clase
        int slclass = 0;
        char race[10];
        if (charac->race == 1) {
            strcpy(race, "elfo");
        } else if (charac->race == 2) {
            strcpy(race, "enano");
        } else if (charac->race == 3) {
            strcpy(race, "orco");
        } else if (charac->race == 4) {
            strcpy(race, "humano");
        }
        if (charac->race == 1 || charac->race == 2 || charac->race == 4) { //elfo
            do {
                typeText("Has elegido ", delay);
                typeText(race, delay);
                typeText(", ahora elige la clase:\n", delay);
                printf("1.Guerrero\n2.Mago\n");
                scanf("%d", &slclass);
                switch (slclass) {
                    case 1:
                        printf("Has elegido %s guerrero!", race);
                        charac->class = 1;
                        selec = 1;
                        break;
                    case 2:
                        printf("Has elegido %s mago!", race);
                        selec = 1;
                        charac->class = 2;
                        break;
                    default:
                        typeText("Eres idiota?? Elige bien\n", delay);
                        selec = 0;
                        break;

                }
            } while (selec == 0);
        } else if (charac->race == 3) { //orco
            printf("Has elegido orco guerrero!");
            charac->class = 1;

        }

    } while (0 > x && x > 5);

    selec = 0;
    char gen;
    do {
        typeText("\nAhora seleccione el genero [M/F]\n", delay);
        typeText("Masculino: +10 de ataque fisico (no soy machista lo juro)\n", delay);
        typeText("Femenino: +10 de ataque magico (no soy sexista lo juro)\n", delay);
        scanf("\n%c", &gen);
        system("clear");

        if (gen == 'M' || gen == 'm') {
            typeText("Tendras +10 de ataque fisico cosas fisiologicas, sorry\n", delay);
            charac->gen = 1;
            charac->att = charac->att + 10;
            typeText("\nConfirmar?[Y/N]", delay);
            scanf("\n%c", &bool);
            system("clear");
            if (bool == 'Y' || bool == 'y') {
                selec = 1;
            }
        } else if (gen == 'F' || gen == 'f') {
            typeText("Tendras +10 de ataque magico, si... ellas son mas listas\n", delay);
            charac->gen = 2;
            charac->attm = charac->attm + 10;
            typeText("\nConfirmar?[Y/N]", delay);
            scanf("\n%c", &bool);
            system("clear");
            if (bool == 'Y' || bool == 'y') {
                selec = 1;
            }
        } else printf("Eres idiota?? Elige bien\n");
    } while (selec == 0);
    for (i = 0; i < 100; i++) {
        strcpy(charac->inv[i].name, "not");
    }
    for (i = 0; i < 1000; i++) {
        strcpy(cofre[i].name, "not");
    }
    strcpy(charac->weapons[0].name, "not");
    strcpy(charac->weapons[1].name, "not");
    strcpy(charac->gear[0].name, "not");
    strcpy(charac->gear[1].name, "not");
    strcpy(charac->gear[2].name, "not");
    strcpy(charac->gear[3].name, "not");
    charac->level = 1;

}

void expUp(chara *charac, int expg) {
    printf("has conseguido %d ptos de experiencia\n", expg);
    charac->exp = charac->exp + expg;
    if (charac->exp > charac->level * charac->level * charac->level) {
        charac->exp = charac->exp - charac->level * charac->level * charac->level;
        charac->level=charac->level + 1;
        printf("Enhorabuena! has subido al nivel %d!\n", charac->level);
        int x = (rand() % 8 + 1) + 3;
        if (charac->race == 1) {
            x = x * 0.5;
        } else if (charac->race == 2) {
            x = x * 1.5;
        } else if (charac->race == 3) {
            x = x * 2;
        } else if (charac->race == 4) {
            x = x * 1;
        }
        charac->att = charac->att + x;
        printf("ataque: %.1lf\n", charac->att);
        x = rand() % 5 + 1;
        if (charac->race == 1) {
            x = x * 0.5;
        } else if (charac->race == 2) {
            x = x * 1.5;
        } else if (charac->race == 3) {
            x = x * 2;
        } else if (charac->race == 4) {
            x = x * 1;
        }
        charac->attm = charac->attm + x;
        printf("ataque magico: %.1lf\n", charac->attm);
        x = rand() % 5 + 1;
        if (charac->race == 1) {
            x = x * 0.5;
        } else if (charac->race == 2) {
            x = x * 1.5;
        } else if (charac->race == 3) {
            x = x * 2;
        } else if (charac->race == 4) {
            x = x * 1;
        }
        charac->def = charac->def + x;
        printf("defensa: %.1lf\n", charac->def);
        x = rand() % 5 + 1;
        if (charac->race == 1) {
            x = x * 0.5;
        } else if (charac->race == 2) {
            x = x * 1.5;
        } else if (charac->race == 3) {
            x = x * 2;
        } else if (charac->race == 4) {
            x = x * 1;
        }
        charac->defm = charac->defm + x;
        printf("adefensa magica: %.1lf\n", charac->defm);
        x = rand() % 5 + 1;
        if (charac->race == 1) {
            x = x * 0.5;
        } else if (charac->race == 2) {
            x = x * 1.5;
        } else if (charac->race == 3) {
            x = x * 2;
        } else if (charac->race == 4) {
            x = x * 1;
        }
        charac->vel = charac->vel + x;
        printf("velocidad: %.1lf\n", charac->vel);
    }
}

void Cofre(chara *charac) {
    int x, y, z, itemnum, itemnum2, i;
    item aux;
    char opt;
    do {
        system("clear");
        printf("1.Guardar items\n2.Retirar items\n3.Volver");
        scanf("%d", &x);
        system("clear");
        switch (x) {
            case 1:
                do {
                    system("clear");
                    for (i = 0; strcmp(charac->inv[i].name, "not") != 0 && i < 100; i++) {
                        printf("%d. %s\n", i + 1, charac->inv[i].name);
                    }
                    printf("seleccione el item que quiere guardar (0 para cancelar)\n");
                    scanf("%d", &itemnum);
                    if (itemnum == 0) {
                        y = 0;
                    } else if (strcmp(cofre[999].name, "not") != 0) {
                        printf("el cofre esta lleno! selecciona un item para sustituirlo\n");
                        for (i = 0; i < 1000; i++) {
                            printf("%d. %s\n", i + 1, cofre[i].name);
                        }
                        printf("selecciona el numero del item que quieres sustituir (0 para cancelar)\n");
                        scanf("%d", &itemnum2);
                        system("clear");
                        if (itemnum2 != 0 && itemnum2 <= 1000 && itemnum2 > 0) {
                            if (strcmp(cofre[itemnum2].name, "not") != 0) {
                                aux = cofre[itemnum2 - 1];
                                cofre[itemnum2 - 1] = charac->inv[itemnum - 1];
                                charac->inv[itemnum - 1] = aux;
                                y = 0;
                            } else {
                                printf("No hay ningun item con ese numero asignado");
                                y = 1;
                            }
                        } else {
                            y = 1;
                        }
                    } else {
                        for (i = 0; strcmp(cofre[i].name, "not") != 0; i++);
                        cofre[i + 1] = charac->inv[itemnum2 - 1];
                        strcpy(charac->inv[itemnum2 - 1].name, "not");
                        y = 0;
                    }
                } while (y == 1);
                x = 1;
                break;
            case 2:
                system("clear");
                if (strcmp(cofre[0].name, "not") == 0) {
                    printf("El cofre esta vacio!!");
                } else {
                    for (i = 0; strcmp(cofre[i].name, "not") != 0 && i < 1000; i++) {
                        printf("%d. %s\n", i + 1, cofre[i].name);
                    }
                    do {
                        printf("Quieres retirar algun item? Inserta el numero del item (0 para volver)");
                        scanf("%d", &itemnum);
                        system("clear");
                        if (itemnum != 0 && itemnum > 0 && itemnum <= 1000) {
                            do {
                                printf("retirar el item numero %d (%s)? [Y/N]", itemnum, cofre[itemnum - 1].name);
                                scanf("%c", &opt);
                                system("clear");
                                if (opt == 'Y' || opt == 'y') {
                                    if (strcmp(charac->inv[99].name, "not") != 0) {
                                        printf("Tu inventario esta lleno! elige un item con el que sustituirlo\n");
                                        for (i = 0; i < 100; i++) {
                                            printf("%d. %s\n", i + 1, charac->inv[i].name);
                                        }
                                        printf("selecciona un item que sustituir (0 para cancelar)\n");
                                        scanf("%d", &itemnum2);
                                        system("clear");
                                        if (itemnum2 != 0 && itemnum > 0 && itemnum <= 100) {
                                            if (strcmp(charac->inv[itemnum2 - 1].name, "not") != 0) {
                                                aux = charac->inv[itemnum2 - 1];
                                                charac->inv[itemnum2] = cofre[itemnum - 1];
                                                cofre[itemnum - 1] = aux;
                                            } else {
                                                printf("Ese numero no tiene ningun item asignado");
                                            }
                                        }
                                        y = 0;
                                    } else {
                                        for (i = 0; strcmp(charac->inv[i].name, "not") != 0; i++);
                                        charac->inv[i + 1] = cofre[itemnum];
                                        strcpy(cofre[itemnum].name, "not");
                                        y = 0;
                                    }
                                } else if (opt == 'N' || opt == 'n') {
                                    y = 0;
                                } else {
                                    printf("Eres idiota?? Elige bien");
                                    y = 1;
                                }
                            } while (y == 1);
                            z = 1;
                        } else {
                            z = 0;
                        }
                        system("clear");
                    } while (z == 1);
                }
                x = 1;
                break;
            case 3:
                x = 0;
                break;
            default:
                printf("Eres idiota?? Elige bien");
                x = 1;
        }
    } while (x == 1);
}

void changeEquip(chara *charac) {
    int i, x, y, z, h;
    item aux;
    system("clear");
    printf("Armas:\n");
    if (strcmp(charac->weapons[0].name, "not") != 0) {
        printf("1. %s\n", charac->weapons[0].name);
    } else {
        printf("1. Nada equipado\n");
    }
    if (strcmp(charac->weapons[1].name, "not") != 0) {
        printf("2. %s\n", charac->weapons[1].name);
    } else {
        printf("2. Nada equipado\n");
    }
    printf("Armaduras:\n");
    if (strcmp(charac->gear[0].name, "not") != 0) {
        printf("3. %s\n", charac->gear[0].name);
    } else {
        printf("3. Nada equipado\n");
    }
    if (strcmp(charac->gear[1].name, "not") != 0) {
        printf("4. %s\n", charac->gear[1].name);
    } else {
        printf("4. Nada equipado\n");
    }

    if (strcmp(charac->gear[2].name, "not") != 0) {
        printf("5. %s\n", charac->gear[2].name);
    } else {
        printf("5. Nada equipado\n");
    }
    if (strcmp(charac->gear[3].name, "not") != 0) {
        printf("6. %s\n", charac->gear[3].name);
    } else {
        printf("6. Nada equipado\n");
    }
    do {
        printf("Que quieres hacer?\n1.Equipar\n2.Desequipar\n3.Volver");
        scanf("%d", &x);
        system("clear");
        switch (x) {
            case 1:
                system("clear");
                printf("1.Bolsa\n2.Cofre\n3.Volver");
                scanf("%d", &i);
                system("clear");
                switch (i) {
                    case 1:
                        for (i = 0; i < 100 && strcmp(charac->inv[i].name, "not") != 0; i++) {
                            printf("%d. %s\n", i + 1, charac->inv[i].name);
                        }
                        do {
                            printf("Seleccione el item que quiere equipar");
                            scanf("%d", &i);
                            system("clear");
                            if (strcmp(charac->inv[i - 1].name, "not") != 0) {
                                if (charac->inv[i - 1].type == 1) {
                                    printf("1.Equipar como arma principal\n2.Equipar como arma secundaria");
                                    scanf("%d", &x);
                                    if (x == 1 || x == 2) {
                                        if (strcmp(charac->weapons[x - 1].name, "not") != 0) {
                                            aux = charac->inv[i - 1];
                                            charac->inv[i - 1] = charac->weapons[x - 1];
                                            charac->weapons[x - 1] = charac->inv[i - 1];
                                        } else {
                                            charac->weapons[x - 1] = charac->inv[i - 1];
                                            strcpy(charac->inv[i - 1].name, "not");
                                        }
                                        z = 0;
                                    } else if (x > 2 && x < 7) {

                                    } else {
                                        printf("Eres idiota?? Elige bien");
                                        z = 1;
                                    }
                                }
                            } else {
                                printf("Eres idiota? Elige bien");
                                z = 1;
                            }
                        } while (z == 1);
                        break;
                    case 2:
                        for (i = 0; i < 1000 && strcmp(cofre[i].name, "not") != 0; i++) {
                            printf("%d. %s\n", i + 1, cofre[i].name);
                        }
                        do {
                            printf("Seleccione el item que quiere equipar");
                            scanf("%d", &i);
                            system("clear");
                            if (strcmp(cofre[i - 1].name, "not") != 0) {
                                if (cofre[i - 1].type == 1) {
                                    printf("1.Equipar como arma principal\n2.Equipar como arma secundaria");
                                    scanf("%d", &x);
                                    if (x == 1 || x == 2) {
                                        if (strcmp(charac->weapons[x - 1].name, "not") != 0) {
                                            aux = cofre[i - 1];
                                            cofre[i - 1] = charac->weapons[x - 1];
                                            charac->weapons[x - 1] = cofre[i - 1];
                                        } else {
                                            charac->weapons[x - 1] = cofre[i - 1];
                                            strcpy(cofre[i - 1].name, "not");
                                        }
                                        z = 0;
                                    } else {
                                        printf("Eres idiota?? Elige bien");
                                        z = 1;
                                    }
                                }
                            } else {
                                printf("Eres idiota? Elige bien");
                                z = 1;
                            }
                        } while (z == 1);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Eres idiota?? Elige bien");
                }
                y = 1;
                break;
            case 2:
                system("clear");
                do {
                    printf("Armas:\n");
                    if (strcmp(charac->weapons[0].name, "not") != 0) {
                        printf("1. %s\n", charac->weapons[0].name);
                    } else {
                        printf("1. Nada equipado\n");
                    }
                    if (strcmp(charac->weapons[1].name, "not") != 0) {
                        printf("2. %s\n", charac->weapons[1].name);
                    } else {
                        printf("2. Nada equipado\n");
                    }
                    printf("Armaduras:\n");
                    if (strcmp(charac->gear[0].name, "not") != 0) {
                        printf("3. %s\n", charac->gear[0].name);
                    } else {
                        printf("3. Nada equipado\n");
                    }
                    if (strcmp(charac->gear[1].name, "not") != 0) {
                        printf("4. %s\n", charac->gear[1].name);
                    } else {
                        printf("4. Nada equipado\n");
                    }
                    if (strcmp(charac->gear[2].name, "not") != 0) {
                        printf("5. %s\n", charac->gear[2].name);
                    } else {
                        printf("5. Nada equipado\n");
                    }
                    if (strcmp(charac->gear[3].name, "not") != 0) {
                        printf("6. %s\n", charac->gear[3].name);
                    } else {
                        printf("6. Nada equipado\n");
                    }
                    printf("Seleccione el item (0 para cancelar)");
                    scanf("%d", &x);
                    if (x <= 6 && x >= 1) {
                        switch (x) {
                            case 1:
                            case 2:
                                do {
                                    printf("Donde lo quiere guardar?\n1.Bolsa\n2.Cofre");
                                    scanf("%d", &x);
                                    system("clear");
                                    if (x == 1) {
                                        for (h = 0; h < 100; h++) {
                                            if (strcmp(charac->inv[i].name, "not") == 0) {
                                                printf("%d. Empty\n", i + 1);
                                            } else {
                                                printf("%d. %s\n", i + 1, charac->inv[i].name);
                                            }
                                        }
                                        printf("Seleccione el lugar en el que guardarlo (0 para cancelar)");
                                        scanf("%d", &h);
                                        system("clear");
                                        if (strcmp(charac->inv[h - 1].name, "not") != 0) {
                                            aux = charac->inv[h - 1];
                                            charac->inv[h - 1] = charac->weapons[x - 1];
                                            charac->weapons[x - 1] = aux;
                                        } else {
                                            charac->inv[h - 1] = charac->weapons[x - 1];
                                            strcpy(charac->weapons[x - 1].name, "not");
                                        }
                                        z = 0;
                                    } else if (x == 2) {
                                        for (h = 0; h < 1000; h++) {
                                            if (strcmp(cofre[h].name, "not") == 0) {
                                                printf("%d. Empty\n", h + 1);
                                            } else {
                                                printf("%d. %s\n", h + 1, cofre[h].name);
                                            }
                                        }
                                        printf("Seleccione el lugar en el que guardarlo (0 para cancelar)");
                                        scanf("%d", &h);
                                        system("clear");
                                        if (strcmp(cofre[h - 1].name, "not") != 0) {
                                            aux = charac->inv[h - 1];
                                            cofre[h - 1] = charac->weapons[x - 1];
                                            charac->weapons[x - 1] = aux;
                                        } else {
                                            cofre[h - 1] = charac->weapons[x - 1];
                                            strcpy(charac->weapons[x - 1].name, "not");
                                        }
                                        z = 0;
                                    } else {
                                        printf("Eres idiota?? Elige bien");
                                        z = 1;
                                    }
                                } while (z == 1);
                                break;
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                                do {
                                    printf("Donde lo quiere guardar?\n1.Bolsa\n2.Cofre");
                                    scanf("%d", &x);
                                    system("clear");
                                    if (x == 1) {
                                        for (h = 0; h < 100; h++) {
                                            if (strcmp(charac->inv[i].name, "not") == 0) {
                                                printf("%d. Empty\n", i + 1);
                                            } else {
                                                printf("%d. %s\n", i + 1, charac->inv[i].name);
                                            }
                                        }
                                        printf("Seleccione el lugar en el que guardarlo (0 para cancelar)");
                                        scanf("%d", &h);
                                        system("clear");
                                        if (strcmp(charac->inv[h - 1].name, "not") != 0) {
                                            aux = charac->inv[h - 1];
                                            charac->inv[h - 1] = charac->gear[x - 3];
                                            charac->gear[x - 3] = aux;
                                        } else {
                                            charac->inv[h - 1] = charac->gear[x - 3];
                                            strcpy(charac->gear[x - 3].name, "not");
                                        }
                                        z = 0;
                                    } else if (x == 2) {
                                        for (h = 0; h < 1000; h++) {
                                            if (strcmp(cofre[i].name, "not") == 0) {
                                                printf("%d. Empty\n", i + 1);
                                            } else {
                                                printf("%d. %s\n", i + 1, cofre[i].name);
                                            }
                                        }
                                        printf("Seleccione el lugar en el que guardarlo (0 para cancelar)");
                                        scanf("%d", &h);
                                        system("clear");
                                        if (strcmp(cofre[h - 1].name, "not") != 0) {
                                            aux = charac->inv[h - 1];
                                            cofre[h - 1] = charac->gear[x - 3];
                                            charac->gear[x - 3] = aux;
                                        } else {
                                            cofre[h - 1] = charac->gear[x - 3];
                                            strcpy(charac->gear[x - 3].name, "not");
                                        }
                                        z = 0;
                                    } else {
                                        printf("Eres idiota?? Elige bien");
                                        z = 1;
                                    }
                                } while (z == 1);
                                break;
                        }
                        i = 0;
                    } else if (x == 0) {
                        i = 1;
                    } else {
                        printf("Eres idiota?? Elige bien");
                        i = 1;
                    }
                } while (i == 1);
                y = 1;
                break;
            case 3:
                y = 0;
                break;
            default:
                printf("Eres idiota?? Elige bien");
                y = 0;
                break;
        }
    } while (y == 1);
}