
#include "Krol.h"
#include "Figura.h"
#include "Pole.h"

Krol::Krol(char a,char b,Pole * wsk, char c) : Figura(a,b,wsk,c)
{
    rodzaj = "krol";
}

Krol::~Krol()
{

}

int Krol::sprawdzMozliwosci(){

    if(aktualnePole==nullptr){return 1;}

    std::cout<<"Mozliwe ruchy krola:\n\n";

    char ok = '?';
    std::string ok2 = "?";
    int ok3 = 0;

    aktualnePole->idzWGore(1,1,this,ok,ok2,ok3);
    aktualnePole->idzWDol(1,1,this,ok,ok2,ok3);
    aktualnePole->idzWPrawo(1,1,this,ok,ok2,ok3);
    aktualnePole->idzWLewo(1,1,this,ok,ok2,ok3);

    aktualnePole->idzWGoreLewo(1,1,this,ok,ok2,ok3);
    aktualnePole->idzWGorePrawo(1,1,this,ok,ok2,ok3);
    aktualnePole->idzWDolLewo(1,1,this,ok,ok2,ok3);
    aktualnePole->idzWDolPrawo(1,1,this,ok,ok2,ok3);

    std::cout<<"\n";

    return 0;
}
