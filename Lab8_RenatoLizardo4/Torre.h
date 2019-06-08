#ifndef TORRE_H
#define TORRE_H

#include "Pieza.h"

class Torre: public Pieza
{
public:

    char forma = 'T';
    
public:
    Torre();
    virtual char getForma();
    bool validarMovimiento(int, int,int,int);
};

#endif


