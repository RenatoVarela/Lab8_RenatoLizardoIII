#include "Rey.h"
#include <stdlib.h>


Rey::Rey():Pieza(){

}

char Rey::getForma(){
    return 'R';
}


bool Rey::validarMovimiento(int f1,int c1,int f2,int c2){
    //abs(f1-f2)<=1 && (c1-c2) <=1

        if ((abs(f1-f2)<=1 && abs(c1-c2) <=1)) {
            return true; 
         }else{
             return false;
         }
    }

