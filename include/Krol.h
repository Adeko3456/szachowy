#ifndef KROL_H
#define KROL_H

#include "Figura.h"

class Pole;

class Krol : public Figura
{
    public:
        Krol(char,char,Pole*,char);
        ~Krol();

        int sprawdzMozliwosci();

    protected:

    private:
};

#endif // KROL_H
