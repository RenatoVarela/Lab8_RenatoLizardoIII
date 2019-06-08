#ifndef PIEZA_H
#define PIEZA_H

class Pieza
{
private:
    /* data */
public:
    Pieza();
    virtual char getForma() = 0;
      virtual bool validarMovimiento(int, int,int,int) =0;
};

#endif