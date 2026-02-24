
#include "Wieza.h"
#include "Pole.h"

Wieza::Wieza(char a,char b,Pole * wsk, char c) : Figura(a,b,wsk,c)
{
    rodzaj = "wieza";
}

Wieza::~Wieza()
{

}

int Wieza::sprawdzMozliwosci(){

    if(aktualnePole==nullptr){return 1;}

    std::cout<<"Mozliwe ruchy wiezy:\n\n";

    char ok = '?';
    std::string ok2 = "?";
    int ok3 = 0;

    aktualnePole->idzWGore(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWDol(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWPrawo(8,8,this,ok,ok2,ok3);
    aktualnePole->idzWLewo(8,8,this,ok,ok2,ok3);

    std::cout<<"\n";

    return 0;
}
