#include "Reina.h"
#include <stdlib.h>

Reina::Reina():Pieza(){
 
}



char Reina::getForma(){
    return 'Q';
}


bool Reina::validarMovimiento(int f1,int c1,int f2,int c2){
     if ((f1==f2) || (c1==c2) || (abs(f1-f2) == abs(c1-c2))) {
            return true; 
         }else{
             return false;
         }
       
    }