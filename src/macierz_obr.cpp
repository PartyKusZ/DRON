#include"macierz_obr.hh"
#include"wektor.hh"
#include <vector>
#include <math.h>

template<int ROZMIAR>

t_macierz <ROZMIAR> t_macierz <ROZMIAR> :: transpozycja () { // rozwiązanie zdecydwanie nie wpisuje się w idee szablonu 
   t_macierz<ROZMIAR> wynik;                                 
   t_wektor<ROZMIAR>  w1;
   t_wektor<ROZMIAR>  w2;
   t_wektor<ROZMIAR>  w3;
   t_wektor<ROZMIAR>  wp1;
   t_wektor<ROZMIAR>  wp2;
   t_wektor<ROZMIAR>  wp3;
   w1 = wiersze[0];
   w2 = wiersze[1];
   w3 = wiersze[2];
   wp1 = wiersze[0];
   wp2 = wiersze[1];
   wp3 = wiersze[2];
   w1.set_pkt_wartosc_indeks(w2.get_wartosc(0),1); 
   w1.set_pkt_wartosc_indeks(wp3.get_wartosc(0),2);
   w2.set_pkt_wartosc_indeks(wp1.get_wartosc(1),0);
   w2.set_pkt_wartosc_indeks(wp3.get_wartosc(1),2);
   w3.set_pkt_wartosc_indeks(wp1.get_wartosc(2),0);
   w3.set_pkt_wartosc_indeks(wp2.get_wartosc(2),1);

   wynik[0] = w1;
   wynik[1] = w2;
   wynik[2] = w3;



    return wynik;
}

template<int ROZMIAR>

t_macierz <ROZMIAR> t_macierz <ROZMIAR> ::  operator * (  t_macierz<ROZMIAR> x)const{
    t_macierz<ROZMIAR> wynik;
    t_wektor<ROZMIAR> pomocniczy;
    t_macierz <ROZMIAR> xx;
    xx = x.transpozycja();
    for(int i = 0; i < ROZMIAR; ++i){
        for(int j = 0; j < ROZMIAR; ++j){
         pomocniczy.set_pkt_wartosc_indeks((wiersze[i] * xx[j]), j);
        }
        wynik.set_wiersz_wartosc_indeks(pomocniczy,i);
     }
     return wynik;
}   

template<int ROZMIAR>

t_wektor <ROZMIAR> t_macierz <ROZMIAR> :: operator * (const t_wektor<ROZMIAR> &x)const{
    t_wektor <ROZMIAR> wynik;
    double w;
    for(int i = 0; i < ROZMIAR; ++i){
        w = wiersze[i] * x;
        wynik.set_pkt_wartosc_indeks(w,i);
     }
    return wynik;    
}

template<int ROZMIAR>

void t_macierz <ROZMIAR> :: oblicz( char os_obr, double kat){
    t_wektor<ROZMIAR> pomocniczy;
    kat = kat * 2 * M_PI / 360; 
   
    switch (os_obr)
    {
    case 'x':
        
        pomocniczy.set_pkt_wartosc_indeks(1,0);
        pomocniczy.set_pkt_wartosc_indeks(0,1);
        pomocniczy.set_pkt_wartosc_indeks(0,2);
        wiersze[0] = pomocniczy;
        pomocniczy.set_pkt_wartosc_indeks(0,0);
        pomocniczy.set_pkt_wartosc_indeks(cos(kat),1);
        pomocniczy.set_pkt_wartosc_indeks((-sin(kat)),2);
        wiersze[1] = pomocniczy;
        pomocniczy.set_pkt_wartosc_indeks(0,0);
        pomocniczy.set_pkt_wartosc_indeks(sin(kat),1);
        pomocniczy.set_pkt_wartosc_indeks(cos(kat),2);
        wiersze[2] = pomocniczy;

    break;

    case 'y':
       
        pomocniczy.set_pkt_wartosc_indeks(cos(kat),0);
        pomocniczy.set_pkt_wartosc_indeks(0,1);
        pomocniczy.set_pkt_wartosc_indeks(sin(kat),2);
        wiersze[0] = pomocniczy;
        pomocniczy.set_pkt_wartosc_indeks(0,0);
        pomocniczy.set_pkt_wartosc_indeks(1,1);
        pomocniczy.set_pkt_wartosc_indeks(0,2);
        wiersze[1] = pomocniczy;
        pomocniczy.set_pkt_wartosc_indeks((-sin(kat)),0);
        pomocniczy.set_pkt_wartosc_indeks(0,1);
        pomocniczy.set_pkt_wartosc_indeks(cos(kat),2);
        wiersze[2] = pomocniczy;
    break;
   
    case 'z':
       
        pomocniczy.set_pkt_wartosc_indeks(cos(kat),0);
        pomocniczy.set_pkt_wartosc_indeks((-sin(kat)),1);
        pomocniczy.set_pkt_wartosc_indeks(0,2);
        wiersze[0] = pomocniczy;
        pomocniczy.set_pkt_wartosc_indeks(sin(kat),0);
        pomocniczy.set_pkt_wartosc_indeks(cos(kat),1);
        pomocniczy.set_pkt_wartosc_indeks(0,2);
        wiersze[1] = pomocniczy;
        pomocniczy.set_pkt_wartosc_indeks(0,0);
        pomocniczy.set_pkt_wartosc_indeks(0,1);
        pomocniczy.set_pkt_wartosc_indeks(1,2);
        wiersze[2] = pomocniczy;
    break;
    
    default: std :: cout << "Dozwolone osie to x, y, z"<< std :: endl;
        break;
    }
}


template<int ROZMIAR>

std :: ostream & operator << (std :: ostream &strm, t_macierz<ROZMIAR> w){
    for(int i = 0; i < ROZMIAR; ++i){
        strm << w[i] << std :: endl;
    }
    return strm;
}

template class t_macierz<3>;
template class t_macierz<2>;
template std :: ostream & operator << (std :: ostream &strm, t_macierz<2> w);
template std :: ostream & operator << (std :: ostream &strm, t_macierz<3> w);
