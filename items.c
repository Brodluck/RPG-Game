#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void itemAtbType(item *object){
    int x=rand()%10;
    if (x<5){
        strcpy(object->nat, "físico")
        object->nature=1;
        if (object->type==3){
            object->statm=object->stat*0.3;
        }
    }else {
        strcpy(object->nat, "mágico")
        object->nature=2;
        object->statm=object->stat;
        if (object->type==3){
            object->stat=object->statm*0.3;
        }else object->stat=0;
    }
}
void itemAtbCommon(item *object){
    int x=rand()%100;
    if (x<20){
        strcpy(object->atr1, "inutil");
        object->stat=0;
        object->statm=0;
    }else if (x<40){
        strcpy(object->atr1, "imbuido");
        if (object->type==1 && object->nature==2){
            object->statm=object->stat*1.2;
        }else if (object->type==2 && object->nature==2){
            object->statm=object->stat*1.2;
        }
    }else if (x<60){
        strcpy(object->atr1, "resistente");
        if (object->type==1 && object->nature==1){
            object->stat=object->stat*1.2;
        }else if (object->type==2 && object->nature==1){
            object->stat=object->stat*1.2;
        }
    }else if (x<80){
        strcpy(object->atr1, "fragil");
        if (object->type==1 && object->nature==2){
            object->stat=object->stat*0.8;
        } else if (object->type==2 && object->nature==2){
            object->stat=object->stat*0.8;
        }
    }else{
        strcpy(object->atr1, "maldito");
        if (object->type==1 && object->nature==1){
            object->stat=object->stat*0.8;
        }else if (object->type==2 && object->nature==1){
            
        }           
    }
}
void itemAtbRare(item *object){
    int x=rand()%100;
    if(x<40){
        
    }else if (x<55){
        strcpy(object->atr1, "encantado");
        if (object->type==1 && object->nature==2){
            object->statm=object->statm*1.4;
        }else if (object->type==2 && object->nature==2){
            object->statm=object->statm*1.4;
        }
    }else if (x<70){
        strcpy(object->atr1, "destructor");
        if (object->type==1 && object->nature==1){
            object->stat=object->stat*1.4;
        }else if (object->type==2 && object->nature==1){
            object->stat=object->stat*1.4;
        }
    }else if (x<85){
        strcpy(object->atr1, "cutre");
        if (object->type==1){
            object->stat=object->stat*0.7;
            object->statm=object->statm*0.7;
        } else if (object->type==2){
            object->stat=object->stat*0.7;
            object->statm=object->statm*0.7;
        }
    }
}
void itemAtbExtra(item *object){
    int x=rand()%100;
    if (x<70){
    }else if (x<80){
        strcpy(object->atr1, "megamagico");
        if (object->type==1 && object->nature==2){
            object->statm=object->statm*1.7;
        }else if (object->type==2 && object->nature==2){
            object->statm=object->statm*1.7;
        }
    }else if (x<90){
        strcpy(object->atr1, "asesino");
        if (object->type==1 && object->nature==1){
            object->stat=object->stat*1.7;
        }else if (object->type==2 && object->nature==1){
            object->stat=object->stat*1.7;
        }
    }
}
void itemAtbLegen(item *object){
    int x=rand()%100;
    if (x<93){
        strcpy(object->atr1, "legendario");
        if (object->type==1){
            object->stat=object->stat*3;
            object->statm=object->statm*3;
        } else if (object->type==2){
            object->stat=object->stat*3;
            object->statm=object->statm*3;
        }
    }
}
void itemGen(item *object, chara *charac) {
    object->stat=20 + charac->level*2;
    itemAtbType(&object);
    itemAtbCommon(&object);
    itemAtbRare(&object);
    itemAtbExtra(&object);
    itemAtbLegen(&object);
}

void inventory(){
    
}