#ifndef REY_H
#define REY_H

#include "Pieza.h"

class Rey:public Pieza
{
private:
    /* data */
public:
    Rey(/* args */);
    virtual char getForma();
    virtual bool validarMovimiento(int, int,int,int);
    
};

#endif


