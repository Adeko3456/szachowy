
#include "Goniec.h"
#include "Figura.h"
#include "Pole.h"

Goniec::Goniec(char a,char b,Pole * wsk,char c) : Figura(a,b,wsk,c)
{
    rodzaj = "goniec";
}

Goniec::~Goniec()
{

}

int Goniec::sprawdzMozliwosci(){

    if(aktualnePole==nullptr){return 1;}

    std::cout<<"Mozliwe ruchy gonca:\n\n";

    char ok = '?';
    std::string ok2 = "?";
    int ok3 = 0;

    aktualnePole->idzWGoreLewo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWGorePrawo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWDolLewo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWDolPrawo(8,8,this,ok,ok2,ok3);

    std::cout<<"\n";

    return 0;
}
