#include "head.h"

void itemType(item *object, int load){
    int x=rand()%10;
    if (x<5){
        object->type=1;                     //arma
    }else{
        object->type=2;                     //armadura
    }
}

void itemTypeSpecific(item *object,int enemG, int load){
    int x, g;
    
    if (load==-1) {
        x==rand()%6;
    }else x=load;
    if (load==-1 && enemG!=-1){
        x=enemG;
    }
    if (object->type==1){
    switch (x){
        case 0:
            object->type2=1;
            strcpy(object->name, "mandoble");
            break;
        case 1:
            object->type2=2;
            strcpy(object->name, "martillo");
            break;
        case 2:
            object->type2=3;
            strcpy(object->name, "espada");
            break;
        case 3:
            object->type2=4;
            strcpy(object->name, "lanza");
            break;
        case 4:
            object->type2=5;
            strcpy(object->name, "hacha");
            break;
        case 5:
            object->type2=6;
            strcpy(object->name, "escudo");
            break;
        }
    }else{
        if (load==-1) {
        x==rand()%4;
    }else x=load;
        switch (x){
        case 0:
            object->type2=0;
            strcpy(object->name, "yelmo");
            break;
        case 1:
            object->type2=1;
            strcpy(object->name, "pechera");
            break;
        case 2:
            object->type2=2;
            strcpy(object->name, "guanteletes");
            break;
        case 3:
            object->type2=3;
            strcpy(object->name, "perneras");
            break;
        }
    }
}

void itemAtbType(item *object, int load){
    int x;
    switch (load){
        case -1:
            x=rand()%10;
            break;
        case 1:
            x=1;
            break;
        case 2:
            x=6;
            break;
    }
    if (x<5){                               //50% probabilidad
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " física");
        }else strcat(object->name, " físico");
        }else{
            switch (object->type2){
                case 0:
                    strcat(object->name, " físico");
                    break;
                case 1:
                    strcat(object->name, " física");
                    break;
                case 2:
                    strcat(object->name, " físicos");
                    break;
                case 3:
                    strcat(object->name, " físicas");
                    break;
            }
        }
        object->nature=1;                   //asigna naturaleza fisica
        if (object->type==2){               
            object->statm=object->stat*0.3; //si es armadura, no elimina por completo la estadistica magica
        }
    }else {  
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " mágica");
        }else strcat(object->name, " mágico");
        }else{
            switch (object->type2){
                case 0:
                    strcat(object->name, " mágico");
                    break;
                case 1:
                    strcat(object->name, " mágica");
                    break;
                case 2:
                    strcat(object->name, " mágicos");
                    break;
                case 3:
                    strcat(object->name, " mágicas");
                    break;
            }
        }
        object->nature=2;                   //asigna naturaleza magica
        object->statm=object->stat;
        if (object->type==2){
            object->stat=object->statm*0.3; //si es armadura, no elimina por completo la estadistica fisica
        }else object->stat=0;               //is no lo es, elimina estadistica fisica
    }
}
void itemAtbCommon(item *object, int load){           //atributo comun
    int x;
    switch (load){
        case -1:
            x==rand()%100;
            break;
        case 1:
            x=9;
            break;
        case 2:
            x=32;
            break;
        case 3:
            x=55;
            break;
        case 4:
            x=77;
            break;
        case 5:
            x=80;
            break;
    }
    if (x<10){                              //10% probabilidad
        object->comm=1;
        if (object->type==1){
        strcat(object->name, " inútil");
        }else{
            switch (object->type2){
                case 0:
                    strcat(object->name, " inútil");
                    break;
                case 1:
                    strcat(object->name, " inútil");
                    break;
                case 2:
                    strcat(object->name, " inútiles");
                    break;
                case 3:
                    strcat(object->name, " inútiles");
                    break;
            }
        }
        object->stat=0;                     
        object->statm=0;
    }else if (x<33){                        //20% probabilidad
        object->comm=2;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " imbuida");
            }else strcat(object->name, " imbuido");
        }else{
           switch (object->type2){
                case 0:
                    strcat(object->name, " imbuido");
                    break;
                case 1:
                    strcat(object->name, " imbuida");
                    break;
                case 2:
                    strcat(object->name, " imbuidos");
                    break;
                case 3:
                    strcat(object->name, " imbuidas");
                    break;
            }
        }
        
        if (object->nature==2){                     //solamente afecta si es un item magico
            object->statm=object->statm*1.2;
        }
    }else if (x<56){
        object->comm=3;
        if (object->type==1){
        strcat(object->name, " resistente");         //solamente afecta si es un item fisico
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcat(object->name, " resistente");
                    break;
                case 2:
                case 3:
                    strcat(object->name, " resistentes");
                    break;
            }
        }
        
        if (object->nature==1){
            object->stat=object->stat*1.2;
        }
    }else if (x<78){
        object->comm=4;
        if (object->type==1){
        strcat(object->name, " fragil");             //solamente afecta si es un item fisico
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcat(object->name, " frágil");
                    break;
                case 2:;
                case 3:
                    strcat(object->name, " frágiles");
                    break;
            }
        }
            if (object->nature==2){
            object->stat=object->stat*0.8;
        }
    }else{
        object->comm=5;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " maldita");
        }else strcat(object->name, " maldito");
        }else{
            switch (object->type2){
                case 0:
                    strcat(object->name, " maldito");
                    break;
                case 1:
                    strcat(object->name, " maldita");
                    break;
                case 2:
                    strcat(object->name, " malditos");
                    break;
                case 3:
                    strcat(object->name, " malditas");
                    break;
            }
        }
        if (object->nature==1){                     //solamente afecta si es un item magico
            object->statm=object->statm*0.8;
        }
    }
}
void itemAtbRare(item *object, int load){
    int x;
    switch (load){
        case -1:
            x==rand()%100;
            break;
        case 0:
            x=39;
            break;
        case 1:
            x=54;
            break;
        case 2:
            x=69;
            break;
        case 3:
            x=84;
            break;
    }
    if(x<40){
        object->rare=0;
    }else if (x<55){
        object->rare=1;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " encantada");
        }else strcat(object->name, " encantado");
        }else{
            
            switch (object->type2){
                case 0:
                    strcat(object->name, " encantado");
                    break;
                case 1:
                    strcat(object->name, " encantada");
                    break;
                case 2:
                    strcat(object->name, " encantados");
                    break;
                case 3:
                    strcat(object->name, " encantadas");
                    break;
            }
        }
        
        if (object->nature==2){
            object->statm=object->statm*1.4;
        }
    }else if (x<70){
        object->rare=2;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " destructora");
        }else strcat(object->name, " destructor");
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcat(object->name, " irrompible");
                    break;
                case 2:
                case 3:
                    strcat(object->name, " irrompibles");
                    break;
            }
        }
        if (object->nature==1){
            object->stat=object->stat*1.4;
        }
    }else if (x<85){
        object->rare=3;
        if (object->type==1){
        strcat(object->name, " cutre");
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcat(object->name, " cutre");
                    break;
                case 2:
                case 3:
                    strcat(object->name, " cutres");
                    break;
            }
        }
            object->stat=object->stat*0.7;
            object->statm=object->statm*0.7;
    }
}
void itemAtbExtra(item *object, int load){
    int x;
    switch (load){
        case -1:
            x=rand()%100;
            break;
        case 0:
            x=69;
            break;
        case 1:
            x=79;
            break;
        case 2:
            x=89;
            break;
    }
    if (x<70){
        object->extr=0;
    }else if (x<80){
        object->extr=1;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " dracónica");
        }else strcat(object->name, " dracónico");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->name, " dracónico");
                    break;
                case 1:
                    strcpy(object->name, " dracónica");
                    break;
                case 2:
                    strcpy(object->name, " dracónicos");
                    break;
                case 3:
                    strcpy(object->name, " dracónicas");
                    break;
            }
        }
        if (object->nature==2){
            object->statm=object->statm*1.7;
        }
    }else if (x<90){
        object->extr=2;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " asesina");
        }else strcat(object->name, " asesino");
            }else{
                switch (object->type2){
                case 0:
                    strcat(object->name, " amparador");
                    break;
                case 1:
                    strcat(object->name, " ampadora");
                    break;
                case 2:
                    strcat(object->name, " amparadores");
                    break;
                case 3:
                    strcat(object->name, " amparadoras");
                    break;
                }
            }
        if (object->nature==1){
            object->stat=object->stat*1.7;
        }
        }
    }
void itemAtbLegen(item *object, int load){
    int x;
    switch  (load){
        case -1:
            x=rand()%100;
            break;
        case 0:
            x=96;
            break;
        case 1:
            x=99;
            break;
    }
    if (x>97){
        object->legen=1;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcat(object->name, " legendaria");
        }else strcat(object->name, " legendario");
        }else{
            switch (object->type2){
                case 0:
                    strcat(object->name, " legendario");
                    break;
                case 1:
                    strcat(object->name, " legendaria");
                    break;
                case 2:
                    strcat(object->name, " legendario");
                    break;
                case 3:
                    strcat(object->name, " legendarias");
                    break;
                }
        }
            object->stat=object->stat*3;
            object->statm=object->statm*3;
    }
}

void itemGenID(item *object){
    int lvl=object->lvl/10;;
    object->ID[0]=object->type;
    object->ID[1]=object->type2;
    object->ID[2]=object->nature;
    object->ID[3]=object->comm;
    object->ID[4]=object->rare;
    object->ID[5]=object->extr;
    object->ID[6]=object->legen;
    object->ID[7]=(object->lvl / 10) + 0x30;
    object->ID[8]=(object->lvl % 10) + 0x30;
}

void itemGen(item *object, chara *charac, int enemG, int enemG2) {
    object->lvl=charac->level;
    object->stat=object->lvl*2;
    object->statm=object->lvl*2;
    if (enemG==0){
    itemType(object, -1);
    }else object->type=enemG;
    if (enemG2==0){
    itemTypeSpecific(object, -1, -1);
    }else{
        itemTypeSpecific(object, enemG2-1, -1);
    }
    itemAtbType(object, -1);
    itemAtbCommon(object, -1);
    itemAtbRare(object, -1);
    itemAtbExtra(object, -1);
    itemAtbLegen(object, -1);
    itemGenID(object);
}
int parseInt(char cha) {
    return cha - '0';
}
void itemIDLoad(item *object, char *ID){
    int IDN[9], i;
    for (i=0;i<9;i++){
    IDN[i]=parseInt(ID[i]);
    }
    itemType(object, IDN[0]);
    itemTypeSpecific(object, -1, IDN[1]);
    itemAtbType(object, IDN[2]);
    itemAtbCommon(object, IDN[3]);
    itemAtbRare(object, IDN[4]);
    itemAtbExtra(object, IDN[5]);
    itemAtbLegen(object, IDN[6]);
    itemGenID(object);
}