#include "Caballo.h"


Caballo::Caballo():Pieza(){
 
}



char Caballo::getForma(){
    return 'C';
}


bool Caballo::validarMovimiento(int f1,int c1,int f2,int c2){
      if ((f1-f2)*(f1-f2) +(c1-c2)*(c1-c2) == 5) {
            return true; 
         }else{
             return false;
         }
    }