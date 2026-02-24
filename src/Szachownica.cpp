
#include "Szachownica.h"
#include "Pole.h"
#include "Figura.h"
#include "Hetman.h"
#include "Krol.h"
#include "Goniec.h"
#include "Wieza.h"

Szachownica::Szachownica()
{
    dodajSzachowePola();
}

Szachownica::~Szachownica()
{
    //dtor
}

void Szachownica::dodajSzachowePola()
{


    char l = 'a';
    char c = '1';

    for(int i=0; i<64; i++){

        Pole pole1(l,c,this);

        szachowePola.push_back(pole1);

        if(l!='h'){
            l++;
        }
        else{
            l='a';
            c++;
        }
    }

    for(auto & naszePole : szachowePola){

        char litera = naszePole.podajLiterke();
        char cyfra = naszePole.podajCyferke();

        if(litera!='a'){

            for(auto & innePole : szachowePola){

                char litera2 = innePole.podajLiterke();
                char cyfra2 = innePole.podajCyferke();

                if(cyfra==cyfra2)
                {
                    if(litera-1==litera2){

                        naszePole.przypiszLewo(&innePole);
                    }
                }
                else if(cyfra-1==cyfra2)
                {
                    if(litera-1==litera2){

                        naszePole.przypiszDolLewo(&innePole);
                    }
                }
                else if(cyfra+1==cyfra2)
                {
                    if(litera-1==litera2){

                        naszePole.przypiszGoraLewo(&innePole);
                    }
                }
            }
        }
        if(litera!='h'){

            for(auto & innePole : szachowePola){

                char litera2 = innePole.podajLiterke();
                char cyfra2 = innePole.podajCyferke();

                if(cyfra==cyfra2)
                {
                    if(litera+1==litera2){

                        naszePole.przypiszPrawo(&innePole);
                    }
                }
                else if(cyfra-1==cyfra2)
                {
                    if(litera+1==litera2){

                        naszePole.przypiszDolPrawo(&innePole);
                    }
                }
                else if(cyfra+1==cyfra2)
                {
                    if(litera+1==litera2){

                        naszePole.przypiszGoraPrawo(&innePole);
                    }
                }
            }
        }

        for(auto & innePole : szachowePola){

            char litera2 = innePole.podajLiterke();
            char cyfra2 = innePole.podajCyferke();

            if(cyfra!='1' && cyfra-1==cyfra2)
            {
                if(litera==litera2){

                    naszePole.przypiszDol(&innePole);
                }
            }
            else if(cyfra!='8' && cyfra+1==cyfra2)
            {
                if(litera==litera2){

                    naszePole.przypiszGora(&innePole);
                }
            }
        }
    }

    //szachowePola = Pola;

}

int Szachownica::zlapFigure(std::string _pole){

    int rozmiar = figury.size();

    for(int i=0; i<rozmiar; i++){

        int info = figury[i]->stan(_pole);
        if(info==1){

            figury[i]->sprawdzMozliwosci();
            return 1;
        }
    }

    std::cout<<"Nic tu nie ma\n";

    return 0;

}

void Szachownica::wyswietlWszystkieOpcje(){

    int rozmiar = figury.size();

    for(int i=0; i<rozmiar; i++){

        figury[i]->sprawdzMozliwosci();
    }
}



void Szachownica::dodajFigury2(std::vector <std::shared_ptr<Figura>> figury2){

    for(auto x: figury2)
    {
        if(x->CzyDalejWGrze()==1){
            char a = x->jakiePole()->podajLiterke();
            char b = x->jakiePole()->podajCyferke();
            std::string c = x->jakiRodzaj();
            char d = x->jakiKolor();

            dodajPojedynczaFigure(a,b,c,d);
        }
        else{

            x->przywroc();
        }
    }
}

void Szachownica::dodajPojedynczaFigure(char literka, char cyferka, std::string rodzaj, char kolor){

    Pole * adres = znajdzAdres(literka,cyferka);

    if(rodzaj=="hetman"){

        std::shared_ptr <Figura> Het(new Hetman(literka,cyferka,adres,kolor));
        figury.push_back(Het);
        adres->powiadomPole(Het);
    }
    else if(rodzaj=="krol"){

        std::shared_ptr <Figura> Kr(new Krol(literka,cyferka,adres,kolor));
        figury.push_back(Kr);
        adres->powiadomPole(Kr);
    }
    else if(rodzaj=="goniec"){

        std::shared_ptr <Figura> Gon(new Goniec(literka,cyferka,adres,kolor));
        figury.push_back(Gon);
        adres->powiadomPole(Gon);
    }
    else if(rodzaj=="wieza"){

        std::shared_ptr <Figura> Wie(new Wieza(literka,cyferka,adres,kolor));
        figury.push_back(Wie);
        adres->powiadomPole(Wie);
    }
}

Pole * Szachownica::znajdzAdres(char literka, char cyferka){

    Pole * wsk = nullptr;

    for(auto & naszePole : szachowePola){

        char Litera = naszePole.podajLiterke();
        char Cyfra = naszePole.podajCyferke();

        if( Litera==literka && Cyfra==cyferka )
        {
            wsk = naszePole.zwrocAdres();
            break;
        }
    }

    if(wsk==nullptr){std::cout<<"error";}

    return wsk;
}

std::shared_ptr<Figura> Szachownica::znajdzKrola(char kolor){

    for(auto x: figury){

        std::string rodzajFigury = x->jakiRodzaj();

        if(rodzajFigury=="krol"){

            char kolorFigury = x->jakiKolor();

            if(kolor==kolorFigury){

                return x;
            }
        }
    }
    std::cout<<"\n\n jakis error \n\n";
    return nullptr;
}


std::vector<std::shared_ptr<Figura>> Szachownica::zestawFigur(){

    return figury;

}

int Szachownica::czyJestSzach(char kolor){

    // 1. musimy znalezc krola

    std::shared_ptr<Figura> krol = znajdzKrola(kolor);

    Pole * poleKrola = krol->jakiePole();

    //char literka = poleKrola->podajLiterke();
    //char cyferka = poleKrola->podajCyferke();
    //std::cout<<"\nKrol stoi na polu "<<literka<<cyferka<<"\n";

    // 2. jedziemy we wszystkich kierunkach od krola czy aby nie ma szacha krolowi

    char kolorPrzeszkody = '?';
    std::string rodzajPrzeszkody = "?";
    int iloscKrokow = 0;

    poleKrola->idzWPrawoSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="wieza"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }
    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }

    kolorPrzeszkody = '?';
    rodzajPrzeszkody = "?";
    iloscKrokow = 0;

    poleKrola->idzWDolSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="wieza"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }

    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }

    kolorPrzeszkody = '?';
    rodzajPrzeszkody = "?";
    iloscKrokow = 0;

    poleKrola->idzWLewoSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="wieza"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }

    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }

    kolorPrzeszkody = '?';
    rodzajPrzeszkody = "?";
    iloscKrokow = 0;

    poleKrola->idzWGoreSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="wieza"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }

    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }

    kolorPrzeszkody = '?';
    rodzajPrzeszkody = "?";
    iloscKrokow = 0;

    poleKrola->idzWGoreLewoSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="goniec"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }

    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }

    kolorPrzeszkody = '?';
    rodzajPrzeszkody = "?";
    iloscKrokow = 0;

    poleKrola->idzWGorePrawoSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="goniec"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }
    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }

    kolorPrzeszkody = '?';
    rodzajPrzeszkody = "?";
    iloscKrokow = 0;

    poleKrola->idzWDolLewoSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="goniec"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }
    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }

    kolorPrzeszkody = '?';
    rodzajPrzeszkody = "?";
    iloscKrokow = 0;

    poleKrola->idzWDolPrawoSzach(8,8,kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(rodzajPrzeszkody=="hetman"||rodzajPrzeszkody=="goniec"){

        if(kolor!=kolorPrzeszkody){
            //std::cout<<"\n\nnie mozna bo jest szach\n\n";
            return 1;
        }
    }
    else if(rodzajPrzeszkody=="krol"){

        if(iloscKrokow==1){

            if(kolor!=kolorPrzeszkody){
                //std::cout<<"\n\nnie mozna bo jest szach\n\n";
                return 1;
            }
        }
    }


    //std::cout<<"\nmozna tak zagrac\n";


    return 0;

}






void Szachownica::dodajFigury(){

    dodajPojedynczaFigure('d','1',"hetman",'b');
    //dodajPojedynczaFigure('c','3',"hetman",'c');
    dodajPojedynczaFigure('a','3',"krol",'c');
    dodajPojedynczaFigure('b','1',"krol",'b');
    //dodajPojedynczaFigure('a','2',"goniec",'c');
    dodajPojedynczaFigure('a','7',"goniec",'c');
    dodajPojedynczaFigure('b','3',"wieza",'c');
    //dodajPojedynczaFigure('c','4',"wieza",'c');
    dodajPojedynczaFigure('h','2',"wieza",'b');
    dodajPojedynczaFigure('a','2',"goniec",'c');
}
