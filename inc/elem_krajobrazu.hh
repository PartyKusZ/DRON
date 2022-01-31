#pragma once 


#include "inter_dron.hh"

class t_elem_krajobrazu{

public:


virtual bool czy_nad(t_wektor<3> w) = 0;
virtual t_wektor<2>  czy_ladowac(t_inter_dron *d,t_wektor<3> w) = 0;

};