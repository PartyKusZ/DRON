#ifndef INTER_DRON
#define INTER_DRON

#include "wektor.hh"
#include "Dr3D_gnuplot_api.hh"

#include "macierz_obr.hh"

class t_inter_dron{
    public:
    virtual void  lec(t_wektor<3> cel,drawNS :: Draw3DAPI *rysownik , double vwir, double vkor,bool wysokosc, t_wektor<2> ladowanie) = 0;
    virtual t_wektor<3>  get_srodek_drona() = 0;
    virtual void przesun (t_wektor<3> w) = 0;
    virtual void obkrec (double kar, char os) = 0;
    virtual void obkrec_front_drona (double kat, char os) = 0;
    virtual void obkrec_wirniki (double kar) = 0;
    virtual t_wektor<3>  get_front_drona() = 0;
    virtual double dlugosc_drona() = 0;
    virtual void przesun_front(t_wektor<3> w) = 0;
};


#endif