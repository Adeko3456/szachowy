
#include "Pole.h"
#include "Figura.h"
#include "Szachownica.h"

enum Informacja{tak, nie};

Pole::Pole(char a, char b, Szachownica * deska) : litera(a), cyfra(b)
{
    gora = nullptr;
    dol = nullptr;
    lewo = nullptr;
    prawo = nullptr;

    goraPrawo = nullptr;
    goraLewo = nullptr;
    dolPrawo = nullptr;
    dolLewo = nullptr;

    figuraKtoraStoiNaTymPolu = nullptr;
    szachownica = deska;
}

Pole::~Pole()
{
    //dtor
}

char Pole::podajLiterke(){return litera;}
char Pole::podajCyferke(){return cyfra;}


Pole * Pole::zwrocAdres(){return this;}

void Pole::przypiszGora(Pole * g){

    gora = g;
}

void Pole::przypiszDol(Pole * d){

    dol = d;
}

void Pole::przypiszPrawo(Pole * p){

    prawo = p;
}

void Pole::przypiszLewo(Pole * l){

    lewo = l;
}

void Pole::przypiszGoraPrawo(Pole * gp){

    goraPrawo = gp;
}

void Pole::przypiszGoraLewo(Pole * gl){

    goraLewo = gl;
}

void Pole::przypiszDolLewo(Pole * dl){

    dolLewo = dl;
}

void Pole::przypiszDolPrawo(Pole * dp){

    dolPrawo = dp;
}




void Pole::wspolnyKod(int & licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    if(licznik!=poczatkowy){    // to jest po to zeby nie wyswietlac pola na ktorym aktualnie stoi figura

        iloscKrokow++;

        if(figuraKtoraStoiNaTymPolu!=nullptr){

            licznik = 0;

            if(kolorPrzeszkody=='!'){  // gdy potrzebujemy tylko tej informacji

                figuraKtoraStoiNaTymPolu->stan(rodzajPrzeszkody, kolorPrzeszkody);

            }
            else{


                figuraKtoraStoiNaTymPolu->stan(rodzajPrzeszkody, kolorPrzeszkody);

                // sprawdzamy czy mozna to bic czy nie:

                char kolorFiguryKtoraIdzie = figuraKtoraIdzie->jakiKolor();

                //std::string rodzajFiguryKtoraIdzie = figuraKtoraIdzie->jakiRodzaj();

                int info = figuraKtoraStoiNaTymPolu->konfrontacja(kolorFiguryKtoraIdzie);

                if(info==1){

                    //std::cout<<"mozliwe ze mozna bic\n\n";

                    figuraKtoraStoiNaTymPolu->oznaczJakoZbita();

                    figuraKtoraIdzie->cofanieEtap1(this);
                    // jest zmienione ale tylko dla figury, a nie dla pol
                    // teraz stworzymy dodatkowa szachownice, bo ze zmianami dla pol bylby problem

                    Szachownica deska2;
                    std::vector<std::shared_ptr<Figura>> figury = szachownica->zestawFigur();
                    // szachownica to jest wskaznik na szachownice glowna
                    deska2.dodajFigury2(figury);

                    //std::cout<<figuraKtoraIdzie->jakiePole()->podajLiterke();
                    //std::cout<<figuraKtoraIdzie->jakiePole()->podajCyferke()<<" ";

                    char kolor = figuraKtoraIdzie->jakiKolor();
                    int infoCzySzach = deska2.czyJestSzach(kolor);

                    figuraKtoraIdzie->cofanieEtap2();

                    //std::cout<<figuraKtoraIdzie->jakiePole()->podajLiterke();
                    //std::cout<<figuraKtoraIdzie->jakiePole()->podajCyferke()<<" ";

                    if(infoCzySzach==0){

                        std::cout<<" - "<<litera<<cyfra<<std::endl;
                    }
                }
                else{


                    //std::cout<<"nie mozna bic swojej figury\n\n";

                }
            }

            //warunki
        }
        else{

            std::string rodzajFiguryKtoraIdzie = figuraKtoraIdzie->jakiRodzaj();

            if(rodzajFiguryKtoraIdzie=="krol"){
                //////////////////////////////////////////
                //////////////////////////////////////////
            }

            figuraKtoraIdzie->cofanieEtap1(this);
            // jest zmienione ale tylko dla figury, a nie dla pol
            // teraz stworzymy dodatkowa szachownice, bo ze zmianami dla pol bylby problem

            Szachownica deska2;
            std::vector<std::shared_ptr<Figura>> figury = szachownica->zestawFigur();
            // szachownica to jest wskaznik na szachownice glowna
            deska2.dodajFigury2(figury);

            //std::cout<<figuraKtoraIdzie->jakiePole()->podajLiterke();
            //std::cout<<figuraKtoraIdzie->jakiePole()->podajCyferke()<<" ";

            char kolor = figuraKtoraIdzie->jakiKolor();
            int infoCzySzach = deska2.czyJestSzach(kolor);

            figuraKtoraIdzie->cofanieEtap2();

            //std::cout<<figuraKtoraIdzie->jakiePole()->podajLiterke();
            //std::cout<<figuraKtoraIdzie->jakiePole()->podajCyferke()<<" ";

            if(infoCzySzach==0){

                std::cout<<" - "<<litera<<cyfra<<std::endl;
            }
        }
    }
}


void Pole::idzWPrawo(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(litera!='h' && licznik > 0)
    {
        licznik--;
        prawo->idzWPrawo(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}



void Pole::idzWLewo(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(litera!='a' && licznik > 0)
    {
        licznik--;
        lewo->idzWLewo(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWGore(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(cyfra!='8' && licznik > 0)
    {
        licznik--;
        gora->idzWGore(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWDol(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(cyfra!='1' && licznik > 0)
    {
        licznik--;
        dol->idzWDol(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWGorePrawo(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(cyfra!='8'&&litera!='h' && licznik > 0)
    {
        licznik--;
        goraPrawo->idzWGorePrawo(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWDolLewo(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(cyfra!='1'&&litera!='a' && licznik > 0)
    {
        licznik--;
        dolLewo->idzWDolLewo(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWGoreLewo(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(cyfra!='8'&&litera!='a' && licznik > 0)
    {
        licznik--;
        goraLewo->idzWGoreLewo(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWDolPrawo(int licznik, int poczatkowy, Figura * figuraKtoraIdzie, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{

    wspolnyKod(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);


    if(cyfra!='1'&&litera!='h' && licznik > 0)
    {
        licznik--;
        dolPrawo->idzWDolPrawo(licznik, poczatkowy, figuraKtoraIdzie, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}



void Pole::powiadomPole(std::shared_ptr <Figura> a){

    figuraKtoraStoiNaTymPolu = a;
}


void Pole::wspolnyKod2(int & licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow){

    if(licznik!=poczatkowy){    // to jest po to zeby nie wyswietlac pola na ktorym aktualnie stoi figura

        iloscKrokow++;

        if(figuraKtoraStoiNaTymPolu!=nullptr){

            figuraKtoraStoiNaTymPolu->stan(rodzajPrzeszkody, kolorPrzeszkody);

            licznik = 0;
        }
    }
}


void Pole::idzWPrawoSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(litera!='h' && licznik > 0)
    {
        licznik--;
        prawo->idzWPrawoSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWDolSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(cyfra!='1' && licznik > 0)
    {
        licznik--;
        dol->idzWDolSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWLewoSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(litera!='a' && licznik > 0)
    {
        licznik--;
        lewo->idzWLewoSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}



void Pole::idzWGoreSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(cyfra!='8' && licznik > 0)
    {
        licznik--;
        gora->idzWGoreSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWGoreLewoSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(cyfra!='8'&&litera!='a' && licznik > 0)
    {
        licznik--;
        goraLewo->idzWGoreLewoSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

void Pole::idzWGorePrawoSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(cyfra!='8'&&litera!='h' && licznik > 0)
    {
        licznik--;
        goraPrawo->idzWGorePrawoSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}


void Pole::idzWDolLewoSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(cyfra!='1'&&litera!='a' && licznik > 0)
    {
        licznik--;
        dolLewo->idzWDolLewoSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}


void Pole::idzWDolPrawoSzach(int licznik, int poczatkowy, char & kolorPrzeszkody, std::string & rodzajPrzeszkody, int & iloscKrokow)
{
    wspolnyKod2(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);

    if(cyfra!='1'&&litera!='h' && licznik > 0)
    {
        licznik--;
        dolPrawo->idzWDolPrawoSzach(licznik, poczatkowy, kolorPrzeszkody, rodzajPrzeszkody, iloscKrokow);
    }
}

