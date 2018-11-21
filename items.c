#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
void itemType(){
    
}
void itemAtbType(item *object){
    int x=rand()%10;
    if (x<5){                               //50% probabilidad
        strcpy(object->nat, "físico");      
        object->nature=1;                   //asigna naturaleza fisica
        if (object->type==2){               
            object->statm=object->stat*0.3; //si es armadura, no elimina por completo la estadistica magica
        }
    }else {                                 
        strcpy(object->nat, "mágico");      
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
        strcpy(object->atr1, "inutil");     
        object->stat=0;                     //pone stats a 0
        object->statm=0;
    }else if (x<40){                        //20% probabilidad
        strcpy(object->atr1, "imbuido");
        if (object->nature==2){                     //solamente afecta si es un item magico
            object->statm=object->statm*1.2;
        }
    }else if (x<60){
        strcpy(object->atr1, "resistente");         //solamente afecta si es un item fisico
        if (object->nature==1){
            object->stat=object->stat*1.2;
        }
    }else if (x<80){
        strcpy(object->atr1, "fragil");             //solamente afecta si es un item fisico
        if (object->nature==2){
            object->stat=object->stat*0.8;
        }
    }else{
        strcpy(object->atr1, "maldito");           //solamente afecta si es un item magico
        if (object->nature==1){
            object->statm=object->statm*0.8;
        }
    }
}
void itemAtbRare(item *object){
    int x=rand()%100;
    if(x<40){
        
    }else if (x<55){
        strcpy(object->atr1, "encantado");
        if (object->nature==2){
            object->statm=object->statm*1.4;
        }
    }else if (x<70){
        strcpy(object->atr1, "destructor");
        if (object->nature==1){
            object->stat=object->stat*1.4;
        }
    }else if (x<85){
        strcpy(object->atr1, "cutre");
            object->stat=object->stat*0.7;
            object->statm=object->statm*0.7;
    }
}
void itemAtbExtra(item *object){
    int x=rand()%100;
    if (x<70){
    }else if (x<80){
        strcpy(object->atr1, "megamagico");
        if (object->nature==2){
            object->statm=object->statm*1.7;
        }
    }else if (x<90){
        strcpy(object->atr1, "asesino");
        if (object->nature==1){
            object->stat=object->stat*1.7;
        }
    }
}
void itemAtbLegen(item *object){
    int x=rand()%100;
    if (x<93){
        strcpy(object->atr1, "legendario");
            object->stat=object->stat*3;
            object->statm=object->statm*3;
    }
}
void itemGen(item *object, chara *charac) {
    object->stat=20 + charac->level*2;
    itemAtbType(object);
    itemAtbCommon(object);
    itemAtbRare(object);
    itemAtbExtra(object);
    itemAtbLegen(object);
}

void inventory(){
    
}
