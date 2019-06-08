
#ifndef REINA_H
#define REINA_H

#include "Pieza.h"

class Reina : public Pieza
{
public:
    char forma = 'T';

public:
    Reina();
    virtual char getForma();
    virtual bool validarMovimiento(int, int, int, int);
};

#endif
