#ifndef GONIEC_H
#define GONIEC_H

#include "Figura.h"

class Pole;

class Goniec : public Figura
{
    public:
        Goniec(char,char,Pole*,char);
        ~Goniec();

        int sprawdzMozliwosci();

    protected:

    private:
};

#endif // GONIEC_H
