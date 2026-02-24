#ifndef POLE_H
#define POLE_H

#include <iostream>
#include <memory>

class Figura;
class Szachownica;

class Pole
{
    public:

        Pole(char,char,Szachownica*);
        ~Pole();

        Pole * zwrocAdres();

        void przypiszGora(Pole *);
        void przypiszDol(Pole *);
        void przypiszPrawo(Pole *);
        void przypiszLewo(Pole *);
        void przypiszGoraPrawo(Pole *);
        void przypiszGoraLewo(Pole *);
        void przypiszDolPrawo(Pole *);
        void przypiszDolLewo(Pole *);

        char podajLiterke();
        char podajCyferke();

        void wspolnyKod(int&,int,Figura*,char&,std::string&,int&);
        void wspolnyKod2(int&,int,char&,std::string&,int&);

        void idzWPrawo(int,int,Figura*,char&,std::string&,int&);
        void idzWLewo(int,int,Figura*,char&,std::string&,int&);
        void idzWGore(int,int,Figura*,char&,std::string&,int&);
        void idzWDol(int,int,Figura*,char&,std::string&,int&);
        void idzWGorePrawo(int,int,Figura*,char&,std::string&,int&);
        void idzWDolLewo(int,int,Figura*,char&,std::string&,int&);
        void idzWGoreLewo(int,int,Figura*,char&,std::string&,int&);
        void idzWDolPrawo(int,int,Figura*,char&,std::string&,int&);

        void idzWPrawoSzach(int, int, char &, std::string &, int &);
        void idzWDolSzach(int, int, char &, std::string &, int &);
        void idzWLewoSzach(int, int, char &, std::string &, int &);
        void idzWGoreSzach(int, int, char &, std::string &, int &);
        void idzWGoreLewoSzach(int, int, char &, std::string &, int &);
        void idzWGorePrawoSzach(int, int, char &, std::string &, int &);
        void idzWDolLewoSzach(int, int, char &, std::string &, int &);
        void idzWDolPrawoSzach(int, int, char &, std::string &, int &);

        void powiadomPole(std::shared_ptr <Figura>);




    protected:

    private:

        char litera;
        char cyfra;

        Pole * gora;
        Pole * dol;
        Pole * lewo;
        Pole * prawo;

        Pole * goraPrawo;
        Pole * goraLewo;
        Pole * dolPrawo;
        Pole * dolLewo;

        Szachownica * szachownica;

        std::shared_ptr <Figura> figuraKtoraStoiNaTymPolu;

};

#endif // POLE_H
