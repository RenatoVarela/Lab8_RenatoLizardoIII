#include "Alfil.h"
#include <stdlib.h>


Alfil::Alfil():Pieza(){
 
}



char Alfil::getForma(){
    return 'A';
}


bool Alfil::validarMovimiento(int f1,int c1,int f2,int c2){
     if ((abs(f1 - f2)) == (abs(c1 - c2))) {
            return true; 
         }else{
             return false;
         }
    }

