#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
void itemType(item *object){
    int x=rand()%10;
    if (x<5){
        object->type=1;                     //arma
    }else{
        object->type=2;                     //armadura
    }
}

void itemTypeSpecific(item *object){
    int x=rand()%6;
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
        x=rand()%4;
        switch (x){
        case 0:
            object->type2=1;
            strcpy(object->name, "yelmo");
            break;
        case 1:
            object->type2=2;
            strcpy(object->name, "pechera");
            break;
        case 2:
            object->type2=3;
            strcpy(object->name, "guanteletes");
            break;
        case 3:
            object->type2=4;
            strcpy(object->name, "perneras");
            break;
        }
    }
}

void itemAtbType(item *object){
    int x=rand()%10;
    if (x<5){                               //50% probabilidad
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "física");
        }else strcpy(object->nat, "físico");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->nat, "físico");
                    break;
                case 1:
                    strcpy(object->nat, "física");
                    break;
                case 2:
                    strcpy(object->nat, "físicos");
                    break;
                case 3:
                    strcpy(object->nat, "físicas");
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
              strcpy(object->nat, "mágica");
        }else strcpy(object->nat, "mágico");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->nat, "mágico");
                    break;
                case 1:
                    strcpy(object->nat, "mágica");
                    break;
                case 2:
                    strcpy(object->nat, "mágicos");
                    break;
                case 3:
                    strcpy(object->nat, "mágicas");
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
void itemAtbCommon(item *object){           //atributo comun
    int x=rand()%100;
    if (x<20){                              //20% probabilidad
        if (object->type==1){
        strcpy(object->atr1, "inútil");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->nat, "inútil");
                    break;
                case 1:
                    strcpy(object->nat, "inútil");
                    break;
                case 2:
                    strcpy(object->nat, "inútiles");
                    break;
                case 3:
                    strcpy(object->nat, "inútiles");
                    break;
            }
        }
        object->stat=0;                     
        object->statm=0;
    }else if (x<40){                        //20% probabilidad
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "imbuida");
            }else strcpy(object->nat, "imbuido");
        }else{
           switch (object->type2){
                case 0:
                    strcpy(object->nat, "imbuido");
                    break;
                case 1:
                    strcpy(object->nat, "imbuida");
                    break;
                case 2:
                    strcpy(object->nat, "imbuidos");
                    break;
                case 3:
                    strcpy(object->nat, "imbuidas");
                    break;
            }
        }
        
        if (object->nature==2){                     //solamente afecta si es un item magico
            object->statm=object->statm*1.2;
        }
    }else if (x<60){
        if (object->type==1){
        strcpy(object->atr1, "resistente");         //solamente afecta si es un item fisico
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcpy(object->nat, "resistente");
                    break;
                case 2:
                case 3:
                    strcpy(object->nat, "resistentes");
                    break;
            }
        }
        
        if (object->nature==1){
            object->stat=object->stat*1.2;
        }
    }else if (x<80){
        if (object->type==1){
        strcpy(object->atr1, "fragil");             //solamente afecta si es un item fisico
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcpy(object->nat, "frágil");
                    break;
                case 2:;
                case 3:
                    strcpy(object->nat, "frágiles");
                    break;
            }
        }
            if (object->nature==2){
            object->stat=object->stat*0.8;
        }
    }else{
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "maldita");
        }else strcpy(object->nat, "maldito");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->nat, "maldito");
                    break;
                case 1:
                    strcpy(object->nat, "maldita");
                    break;
                case 2:
                    strcpy(object->nat, "malditos");
                    break;
                case 3:
                    strcpy(object->nat, "malditas");
                    break;
            }
        }
        if (object->nature==1){                     //solamente afecta si es un item magico
            object->statm=object->statm*0.8;
        }
    }
}
void itemAtbRare(item *object){
    int x=rand()%100;
    if(x<40){
        
    }else if (x<55){
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "encantada");
        }else strcpy(object->nat, "encantado");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->nat, "encantado");
                    break;
                case 1:
                    strcpy(object->nat, "encantada");
                    break;
                case 2:
                    strcpy(object->nat, "encantados");
                    break;
                case 3:
                    strcpy(object->nat, "encantadas");
                    break;
            }
        }
        
        if (object->nature==2){
            object->statm=object->statm*1.4;
        }
    }else if (x<70){
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "destructora");
        }else strcpy(object->nat, "destructor");
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcpy(object->nat, "irrompible");
                    break;
                case 2:
                case 3:
                    strcpy(object->nat, "irrompibles");
                    break;
            }
        }
        if (object->nature==1){
            object->stat=object->stat*1.4;
        }
    }else if (x<85){
        if (object->type==1){
        strcpy(object->atr1, "cutre");
        }else{
            switch (object->type2){
                case 0:
                case 1:
                    strcpy(object->nat, "cutre");
                    break;
                case 2:
                case 3:
                    strcpy(object->nat, "cutres");
                    break;
            }
        }
            object->stat=object->stat*0.7;
            object->statm=object->statm*0.7;
    }
}
void itemAtbExtra(item *object){
    int x=rand()%100;
    if (x<70){
    }else if (x<80){
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "megamagica");
        }else strcpy(object->nat, "megamagico");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->nat, "megamagico");
                    break;
                case 1:
                    strcpy(object->nat, "megamagica");
                    break;
                case 2:
                    strcpy(object->nat, "megamagicos");
                    break;
                case 3:
                    strcpy(object->nat, "megamagicas");
                    break;
            }
        }
        if (object->nature==2){
            object->statm=object->statm*1.7;
        }
    }else if (x<90){
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "asesina");
        }else strcpy(object->nat, "asesino");
            }else{
                switch (object->type2){
                case 0:
                    strcpy(object->nat, "amparador");
                    break;
                case 1:
                    strcpy(object->nat, "ampadora");
                    break;
                case 2:
                    strcpy(object->nat, "amparadores");
                    break;
                case 3:
                    strcpy(object->nat, "amparadoras");
                    break;
                }
            }
        }
        if (object->nature==1){
            object->stat=object->stat*1.7;
        }
    }
void itemAtbLegen(item *object){
    int x=rand()%100;
    if (x>93){
        object->legen=1;
        if (object->type==1){
        if (object->type2<=5 && object->type2>=3){
              strcpy(object->nat, "legendaria");
        }else strcpy(object->nat, "legendario");
        }else{
            switch (object->type2){
                case 0:
                    strcpy(object->nat, "legendario");
                    break;
                case 1:
                    strcpy(object->nat, "legendaria");
                    break;
                case 2:
                    strcpy(object->nat, "legendarios");
                    break;
                case 3:
                    strcpy(object->nat, "legendarias");
                    break;
                }
        }
            object->stat=object->stat*3;
            object->statm=object->statm*3;
    }
}
void itemGen(item *object) {
    int x=rand()%10;
    x=x-5;
    object->stat=charac->level*2+x;
    object->statm=charac->level*2+x;
    
    itemType(object);
    itemTypeSpecific(object);
    itemAtbType(object);
    itemAtbCommon(object);
    itemAtbRare(object);
    itemAtbExtra(object);
    itemAtbLegen(object);
}
