#pragma once


#include "Dr3D_gnuplot_api.hh"
class t_interface_rysowania{
public:
    virtual void rysuj(drawNS :: Draw3DAPI *rysownik) = 0 ;
    virtual void czysc(drawNS :: Draw3DAPI *rysownik) = 0 ;
}; 
