#ifndef REINA_H
#define REINA_H

#include "Pieza.h"

class Caballo: public Pieza
{
public:

    //char forma = '';
    
public:
    Caballo();
    virtual char getForma();
    virtual bool validarMovimiento(int,int,int,int);
};

#endif