#include "Torre.h"


Torre::Torre():Pieza(){
 
}



char Torre::getForma(){
    return 'T';
}


bool Torre::validarMovimiento(int f1,int c1,int f2,int c2){
     if ((f1==f2) || (c1==c2)) {
            return true; 
         }else{
             return false;
         }
    }
