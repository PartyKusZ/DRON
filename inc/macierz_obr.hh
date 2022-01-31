#ifndef MACIERZ_OBR_HH
#define MACIERZ_OBR_HH

#include <vector>
#include <iostream>
#include "wektor.hh"




template <int ROZMIAR>
class t_macierz{

    private:

        std :: vector <t_wektor<ROZMIAR>> wiersze;
           
    public:

    t_macierz<ROZMIAR> () {
        t_wektor<ROZMIAR> w;
        for(int i = 0; i <  ROZMIAR; ++i)
            wiersze.push_back(w);
    
        
    };

    t_macierz <ROZMIAR> operator *                  (  t_macierz<ROZMIAR> x)const;
    t_wektor  <ROZMIAR> operator *                  ( const t_wektor<ROZMIAR> &x)const;
    t_wektor  <ROZMIAR> & operator []                 (int x)  {return wiersze[x];};
    const t_wektor<ROZMIAR> & operator[]                       (int x) const {return wiersze[x];};
    void                set_wiersz_wartosc_indeks   (t_wektor<ROZMIAR> wart, int ind){wiersze[ind] = wart;};
    void                oblicz                      (char os_obr, double kat);
    t_macierz <ROZMIAR> transpozycja () ;  
    
};

template<int ROZMIAR>
std :: ostream & operator << (std :: ostream &strm, t_macierz<ROZMIAR> w);


#endif