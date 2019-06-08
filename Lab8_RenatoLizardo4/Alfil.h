#ifndef REINA_H
#define REINA_H

#include "Pieza.h"

class Alfil: public Pieza
{
public:

    //char forma = '';
    
public:
    Alfil();
    virtual char getForma();
    virtual bool validarMovimiento(int,int,int,int);
};

#endif