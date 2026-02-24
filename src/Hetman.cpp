
#include "Hetman.h"
#include "Figura.h"
#include "Pole.h"

Hetman::Hetman(char a,char b,Pole * wsk,char c) : Figura(a,b,wsk,c)
{
    rodzaj = "hetman";
}

Hetman::~Hetman()
{
    //std::cout<<"ginie\n";
}

int Hetman::sprawdzMozliwosci(){

    if(aktualnePole==nullptr){return 1;}

    std::cout<<"Mozliwe ruchy hetmana:\n\n";

    char ok = '?';
    std::string ok2 = "?";
    int ok3 = 0;

    aktualnePole->idzWGore(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWDol(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWPrawo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWLewo(8,8,this,ok,ok2,ok3);

    aktualnePole->idzWGoreLewo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWGorePrawo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWDolLewo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWDolPrawo(8,8,this,ok,ok2,ok3);

    std::cout<<"\n";

    return 0;
}
