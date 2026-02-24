#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>

//#include "Pole.h"
//#include "Goniec.h"
//#include "Hetman.h"
//#include "Krol.h"
//#include "Wieza.h"
//#include "Szachownica.h"

class Pole;

class Figura
{
    public:
        Figura(char, char, Pole *, char);
        virtual ~Figura() = 0;
        virtual int sprawdzMozliwosci() = 0;
        int stan(std::string);
        void stan(std::string&, char&);
        int konfrontacja(char);
        int czyJestBroniona();
        char jakiKolor();
        std::string jakiRodzaj();
        Pole* jakiePole();
        void cofanieEtap1(Pole *);
        void cofanieEtap2();
        void oznaczJakoZbita();
        int CzyDalejWGrze();
        void przywroc();

    protected:

        char kolor;
        std::string rodzaj;
        Pole * aktualnePole;

        int doUsuniecia;

        //----- do cofania gdy ruch okaze sie nieprawidlowy
        Pole * wczesniejszePole;
        int wykonanyDodatkowyRuch;
        //-----

    private:
};

#endif // FIGURA_H
