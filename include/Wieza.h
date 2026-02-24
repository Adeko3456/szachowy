#ifndef WIEZA_H
#define WIEZA_H

#include "Figura.h"

class Pole;

class Wieza : public Figura
{
    public:
        Wieza(char,char,Pole*,char);
        ~Wieza();

        int sprawdzMozliwosci();

    protected:

    private:
};

#endif // WIEZA_H
