#include <iostream>
#include "wektor.hh"
#include <math.h>

using std :: cout;
using std :: cin;
using std :: endl;

template<int ROZMIAR>

t_wektor<ROZMIAR> t_wektor<ROZMIAR> ::  operator + (const t_wektor<ROZMIAR> &x) const{

    t_wektor<ROZMIAR> wynik;

    for(int i = 0; i < ROZMIAR; ++i){
        wynik.pkt[i] = pkt[i] + x.pkt[i];
    }
    return wynik;
}

template<int ROZMIAR>

t_wektor<ROZMIAR> t_wektor<ROZMIAR> ::  operator - (const t_wektor<ROZMIAR> &x) const{

    t_wektor<ROZMIAR> wynik;

    for(int i = 0; i < ROZMIAR; ++i){
        wynik.pkt[i] = pkt[i] - x.pkt[i];
    }
    return wynik;
}

template<int ROZMIAR>

double t_wektor<ROZMIAR> ::  operator * (const t_wektor<ROZMIAR> &x) const{

    t_wektor<ROZMIAR> wynik;
    double w = 0;

    for(int i = 0; i < ROZMIAR; ++i){
        wynik.pkt[i] = pkt[i] * x.pkt[i];
    }
    for(int i = 0; i < ROZMIAR; ++i){
        w = w  + wynik.pkt[i];
    }
    return w;
}


template <int ROZMIAR>

t_wektor<ROZMIAR> t_wektor<ROZMIAR> ::  operator * (const double  &x) const{

    t_wektor<ROZMIAR> wynik;

    for(int i = 0; i < ROZMIAR; ++i){
        wynik.pkt[i] = pkt[i] * x ;  
    }
    return wynik;

}
template <int ROZMIAR>

double t_wektor<ROZMIAR> :: dlugosc_odcinka(const t_wektor<ROZMIAR> &x) const{
    double wynik = 0;
    for(int i = 0; i < ROZMIAR; ++i){
       wynik =  pow(pkt[i] - x.pkt[i], 2) + wynik;   
    }       
    return sqrt(wynik);
}

template <int ROZMIAR>


bool t_wektor<ROZMIAR> :: prostopadlosc(const t_wektor<ROZMIAR> &x) const{
    if((*this  * x) == 0 )  
        return true;
    else 
        return false;
         
}       

template<int ROZMIAR>
double t_wektor<ROZMIAR> :: dlugosc_wektora(){
    return sqrt(pow(pkt[0],2) + pow(pkt[1], 2) + pow(pkt[2],2));
}

template<int ROZMIAR>
t_wektor<ROZMIAR>  t_wektor<ROZMIAR> :: przeciwny(){
    t_wektor<ROZMIAR> tmp;
    
    for(int i = 0; i < ROZMIAR; ++i){
        tmp.set_pkt_wartosc_indeks(-pkt[i], i);
        
    }
    return tmp;
}

template<int ROZMIAR>

std :: ostream & operator << (std :: ostream &strm, t_wektor<ROZMIAR> w){
    strm << "[";
    for(int i = 0; i < ROZMIAR; ++i){
        if((ROZMIAR - i) != 1 )
            strm << w[i] << " , ";
        else
            strm << w[i];

    }
    strm << "]";
    return strm;
}

template<int ROZMIAR>

std :: istream & operator >> (std :: istream &strm, t_wektor<ROZMIAR> &w){
    char tmp;
    double x;
    strm >> tmp;
    if(tmp != '[')
        strm.setstate(std :: ios :: failbit);
    for(int i = 0; i < ROZMIAR; ++i){
        strm >> x;
        w.set_pkt_wartosc_indeks(x,i);
        strm >> tmp;
        if(tmp != ',' && tmp != ']')
            strm.setstate(std :: ios :: failbit);
           

    }
    return strm;

}

template class t_wektor<3>;
template class t_wektor<2>;
template std :: istream & operator >> (std :: istream &strm, t_wektor<2> &w);
template std :: istream & operator >> (std :: istream &strm, t_wektor<3> &w);
template std :: ostream & operator << (std :: ostream &strm, t_wektor<2> w);
template std :: ostream & operator << (std :: ostream &strm, t_wektor<3> w);

