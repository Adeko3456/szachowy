
#include "Figura.h"
#include "Pole.h"

Figura::Figura(char a, char b, Pole * wsk, char c) : aktualnePole(wsk)
{
    kolor = c;
    wczesniejszePole = nullptr;
    wykonanyDodatkowyRuch = 0;
    doUsuniecia = 0;

}

Figura::~Figura()
{

}

char Figura::jakiKolor(){return kolor;}

std::string Figura::jakiRodzaj(){return rodzaj;}

Pole * Figura::jakiePole(){return aktualnePole;}

void Figura::cofanieEtap1(Pole * poleDocelowe){

    wczesniejszePole = aktualnePole;
    aktualnePole = poleDocelowe;
    wykonanyDodatkowyRuch = 1;
}

void Figura::cofanieEtap2(){

    aktualnePole = wczesniejszePole;
    wczesniejszePole = nullptr;
    wykonanyDodatkowyRuch = 0;
}

int Figura::stan(std::string _pole){

    if(_pole.length()<2){std::cout<<"error";return 55;}

    char literkaAktualnegoPola = aktualnePole->podajLiterke();
    char cyferkaAktualnegoPola = aktualnePole->podajCyferke();

    if(_pole[0] == literkaAktualnegoPola && _pole[1] == cyferkaAktualnegoPola)
    {
        std::string kol = "";
        if(kolor=='b'){kol="bialy";}
        else{kol="czarny";}
        std::cout<<"tu stoi "<<kol<<" "<<rodzaj<<"\n\n";
        return 1;
    }
    return 0;
}


void Figura::stan(std::string & rodzajPrzeszkody, char & kolorPrzeszkody){

    rodzajPrzeszkody = rodzaj;
    kolorPrzeszkody = kolor;

}

int Figura::konfrontacja(char kolorFiguryKtoraIdzie){

    if(kolor==kolorFiguryKtoraIdzie)
    {
        return 0;
    }

    return 1;
}

void Figura::oznaczJakoZbita(){

    doUsuniecia = 1;
}

void Figura::przywroc(){

    doUsuniecia = 0;
}

int Figura::CzyDalejWGrze(){

    if(doUsuniecia==1){return 0;}

    return 1;
}
