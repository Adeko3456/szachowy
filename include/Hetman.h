#ifndef HETMAN_H
#define HETMAN_H

#include "Figura.h"

class Pole;

class Hetman : public Figura
{
    public:
        Hetman(char,char,Pole*,char);
        ~Hetman();

        int sprawdzMozliwosci();

    protected:

    private:
};

#endif // HETMAN_H
