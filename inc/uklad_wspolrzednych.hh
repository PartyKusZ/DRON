#ifndef UKLAD_WSP
#define UKLAD_WSP
#include "macierz_obr.hh"
#include "wektor.hh"
class t_uklad_wspolrzednych{

protected:
    t_uklad_wspolrzednych *bazowy = nullptr;
    t_wektor<3> srodek;
    t_macierz<3> polozenie;
    t_wektor<3> front ; 
    double promien_ladowania;
 
public:

    t_uklad_wspolrzednych() = default;
    t_uklad_wspolrzednych(t_wektor<3> w, double kat, char os,t_uklad_wspolrzednych *wks){
    
       
        
        srodek = w;
        polozenie.oblicz(os,kat);
        bazowy = wks;
        front = {0,11.5,0};
        promien_ladowania = 0;

       
    };
    void translacja(t_wektor<3> w) {srodek = srodek + w;};
    void rotacja(double kat, char os) {
        t_macierz<3> m;
        m.oblicz(os,kat);
        polozenie = m * polozenie ;
        
    };
     t_wektor<3> get_front(){return front;};
     void pchnij_front(t_wektor<3> w) {front = front + w;};
      void obkrec_front(double kat, char os){
        t_macierz<3> m;
        m.oblicz(os,kat);
        front = m * front;
    };
    t_wektor<3> get_srodek(){return srodek;};
    t_macierz<3> get_polozenie(){return polozenie;};
    t_uklad_wspolrzednych get_uklad(){return *this;};
    void set_srodek(t_wektor<3> w){srodek = w;};
    void set_polozenie(double kat, char os){polozenie.oblicz(os,kat);};
    void set_uklad(t_uklad_wspolrzednych *uk){bazowy = uk;};

    t_uklad_wspolrzednych przeliczanie_ukladow(){
        t_uklad_wspolrzednych wynikowy = *this;
        while (wynikowy.bazowy != nullptr) {
            wynikowy.srodek = wynikowy.bazowy->srodek + wynikowy.bazowy->polozenie * wynikowy.srodek;
            wynikowy.polozenie = wynikowy.bazowy->polozenie * wynikowy.polozenie;
            wynikowy.bazowy = wynikowy.bazowy->bazowy;
        }
        return wynikowy;    
    };
     
};

#endif



