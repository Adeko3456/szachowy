#ifndef SZACHOWNICA_H
#define SZACHOWNICA_H

#include <iostream>
#include <vector>
#include <memory>

class Pole;
class Figura;

class Szachownica
{
    public:
        Szachownica();
        ~Szachownica();
        void dodajSzachowePola();
        void dodajFigury();
        void dodajFigury2(std::vector <std::shared_ptr<Figura>>);
        Pole * znajdzAdres(char,char);
        int zlapFigure(std::string);
        void wyswietlWszystkieOpcje();
        std::shared_ptr <Figura> znajdzKrola(char);
        std::vector<std::shared_ptr<Figura>> zestawFigur();
        void dodajPojedynczaFigure(char,char,std::string,char);
        int czyJestSzach(char kolor);

    protected:

    private:

        std::vector <Pole> szachowePola;
        std::vector <std::shared_ptr<Figura>> figury;
};

#endif // SZACHOWNICA_H
