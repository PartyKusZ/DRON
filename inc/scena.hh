#ifndef SCENA_HH
#define SCENA_HH

#include "figury_geometryczne.hh"
#include "dron.hh"
#include "Dr3D_gnuplot_api.hh"
#include <cstdlib>
#include "inter_rysowania.hh"
#include "elem_krajobrazu.hh"

enum elem_krajobrazu {wzgorze, plaskowyz, palskowyz_pros, figura_losowa};



class t_scena  {
private:


    std :: vector<t_elem_krajobrazu *> e_krajobrazu;
    std :: vector<t_interface_rysowania *> e_rysowania;
    std :: vector<t_interface_rysowania *> e_rys_drony;

public:
    t_scena() = default;

    void rysuj_wszystkie_przeszkody(drawNS :: Draw3DAPI *rysownik);
    void rysuj_wszystkie_drony(drawNS :: Draw3DAPI *rysownik);

    bool sprawdz_wysokosc(t_inter_dron *d, t_wektor<3> w);
    void dodaj_elem_krajobrazu(elem_krajobrazu elem, t_uklad_wspolrzednych *uk);
    void dodaj_elem_krajobrazu(t_elem_krajobrazu *elem);
    void dodaj_drona(t_inter_dron *dron);
    void dodaj_dorna(t_uklad_wspolrzednych *uk);
    void usun_ostatni_krajobrazu();
    void usun_ostatni_drona();
    void kreator_przeszkod(t_uklad_wspolrzednych *uk);
    void kreator_dronow(t_uklad_wspolrzednych *uk);
    t_dron*  zworc_dorna(int numer_drona);
    t_wektor<2> sprawdz_ladowanie(t_inter_dron *d, t_wektor<3> w);
};



#endif























































