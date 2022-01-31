#ifndef FIGURY_GEOMERTYCZNE
#define FIGURY_GEOMERTYCZNE

#include<vector>
#include"wektor.hh"
#include"Dr3D_gnuplot_api.hh"
#include"uklad_wspolrzednych.hh"
#include<cstdlib>
#include<ctime>

#include"elem_krajobrazu.hh"

#include "inter_rysowania.hh"


class t_prostopadloscian : public t_interface_rysowania, public t_uklad_wspolrzednych,public t_elem_krajobrazu {
protected:

    std :: vector<t_wektor<3>> wierzcholki;
    int id_rysunku;
    

public:
    t_prostopadloscian (t_wektor<3> sr, double kat, char os,t_uklad_wspolrzednych *wks, std :: initializer_list<t_wektor<3>> wi) : t_uklad_wspolrzednych(sr,kat,os,wks), wierzcholki(wi) {};
    t_prostopadloscian () = default;
    void rysuj(drawNS :: Draw3DAPI *rysownik) override ;
    void czysc(drawNS :: Draw3DAPI *rysownik) override {rysownik->erase_shape(id_rysunku);};
    bool czy_nad(t_wektor<3> w) override;
    t_wektor<2> czy_ladowac(t_inter_dron *d,t_wektor<3> w) override;
   
    
   
    void zmien_rozmiar(double x) {
        for(int i = 0; i < wierzcholki.size(); ++i){
            wierzcholki[i] = wierzcholki[i] * x;
        }
    };
    
    
    
  
    
    
};


class t_graniastoslup6: public t_uklad_wspolrzednych, public t_interface_rysowania,public t_elem_krajobrazu{
protected:

    std :: vector<t_wektor<3>> wierzcholkii;
    int id_rysunku;

public:

    t_graniastoslup6(t_wektor<3> sr, double kat, char os, t_uklad_wspolrzednych *wks, std :: initializer_list<t_wektor<3>> wi) : t_uklad_wspolrzednych(sr,kat,os,wks), wierzcholkii(wi) {};
    t_graniastoslup6() = default;
    void rysuj(drawNS :: Draw3DAPI *rysownik) override ;
    void czysc(drawNS :: Draw3DAPI *rysownik) override {rysownik->erase_shape(id_rysunku);};
    bool czy_nad(t_wektor<3> w) override;
    t_wektor<2>  czy_ladowac(t_inter_dron *d,t_wektor<3> w) override;
   
    void zmien_rozmiar(double x) {
        for(int i = 0; i < wierzcholkii.size(); ++i){
            wierzcholkii[i] = wierzcholkii[i] * x;
        }
    };
    
    
};

class t_powierzchnia: public t_interface_rysowania, public t_elem_krajobrazu {
private:
    double wysokosc;
    int id_rysunku;
public:
    t_powierzchnia (double h)  {wysokosc = h;};

    void rysuj (drawNS :: Draw3DAPI *rysownik) override;

    void czysc (drawNS :: Draw3DAPI *rysownik) override{rysownik->erase_shape(id_rysunku);};
    bool czy_nad(t_wektor<3> w) override{return true;};
    t_wektor <2>  czy_ladowac(t_inter_dron *d,t_wektor<3> w) override{t_wektor<2> wynik {1,1}; return wynik;};
   
};



class t_plaskowz_pros: public t_prostopadloscian,public t_elem_krajobrazu{

private:

public:
    void rysuj(drawNS :: Draw3DAPI *rysownik) override ;
    void czysc(drawNS :: Draw3DAPI *rysownik) override {rysownik->erase_shape(id_rysunku);};
    bool czy_nad(t_wektor<3> w) override;
    t_wektor<2>  czy_ladowac(t_inter_dron *d,t_wektor<3> w) override;
   
};



class t_plaskowyz: public t_interface_rysowania, public t_uklad_wspolrzednych,public t_elem_krajobrazu{

private:

    std :: vector<t_wektor<3>> wierzcholki;
    int id_rysunku;

public:

    t_plaskowyz(t_wektor<3> sr, double kat, char os,t_uklad_wspolrzednych *wks, std :: initializer_list<t_wektor<3>> wi): t_uklad_wspolrzednych(sr,kat,os,wks), wierzcholki(wi){};
    t_plaskowyz () = default;
    void rysuj(drawNS :: Draw3DAPI *rysownik) override ;
    void czysc(drawNS :: Draw3DAPI *rysownik) override {rysownik->erase_shape(id_rysunku);};
   bool czy_nad(t_wektor<3> w) override;
    t_wektor<2>  czy_ladowac(t_inter_dron *d,t_wektor<3> w) override;
    
   
    void zmien_rozmiar(double x) {
        for(int i = 0; i < wierzcholki.size(); ++i){
            wierzcholki[i] = wierzcholki[i] * x;
        }
    };
};




class t_wzgorze: public t_interface_rysowania, public t_uklad_wspolrzednych,public t_elem_krajobrazu {

private:

    std :: vector<t_wektor<3>> wierzcholki;
    double wysokosc;
    int id_rysunku;

public:
    t_wzgorze(t_wektor<3> sr, double kat, char os,t_uklad_wspolrzednych *wks, std :: initializer_list<t_wektor<3>> wi,double h): t_uklad_wspolrzednych(sr,kat,os,wks), wierzcholki(wi){
        wysokosc = h;
        t_wektor<3> w1 {-0.0001,-0.0001,wysokosc};
        t_wektor<3> w2 {0.0001,-0.0001,wysokosc};
        t_wektor<3> w3 {0.0001,0.0001,wysokosc};
        t_wektor<3> w4 {-0.0001,0.0001,wysokosc};
        wierzcholki.push_back(w1);
        wierzcholki.push_back(w2);
        wierzcholki.push_back(w3);
        wierzcholki.push_back(w4);
    };
    t_wzgorze () = default;
    void rysuj(drawNS :: Draw3DAPI *rysownik) override ;
    void czysc(drawNS :: Draw3DAPI *rysownik) override {rysownik->erase_shape(id_rysunku);};
    
    bool czy_nad(t_wektor<3> w) override;
    t_wektor<2>  czy_ladowac(t_inter_dron *d,t_wektor<3> w) override;
    
   
    void zmien_rozmiar(double x) {
        for(int i = 0; i < wierzcholki.size(); ++i){
            wierzcholki[i] = wierzcholki[i] * x;
        }
    };
};



class t_fig_random: public t_interface_rysowania, public t_uklad_wspolrzednych,public t_elem_krajobrazu{
private:
    std :: vector<t_wektor<3>> wierzcholki;
    int id_rysunku;

public:
 void zmien_rozmiar(double x) {
        for(int i = 0; i < wierzcholki.size(); ++i){
            wierzcholki[i] = wierzcholki[i] * x;
        }
    };

    t_fig_random(t_wektor<3> sr, double kat, char os, t_uklad_wspolrzednych *wsk): t_uklad_wspolrzednych(sr,kat,os,wsk){
        int ilosc_wierzcholkow;
        double x;
        double y;
        double x1;
        double y1;
        
        double wielkosc;
        double kat2;
        int rozmiar;
        t_macierz<3> m;
        t_wektor<3> w;
    
            
        
        ilosc_wierzcholkow = (std::rand() % 15) + 3;
        kat2 = 360 / ilosc_wierzcholkow;
        x = ((std::rand() % 100) + 150) / 100;
        y = ((std::rand() % 100) + 150) / 100;
        for(int i = 0; i < ilosc_wierzcholkow; ++i){
            x1 = x;
            y1 = y;
            wielkosc = ((std::rand() % 3) + 4);
        
            x1 = x1 * wielkosc;
            y1 = y1 * wielkosc;
            w = {x1,y1,0};
            m.oblicz('z', kat2 * i);
            w = m * w;
            wierzcholki.push_back(w);

        }
            

        wielkosc = (std :: rand() % 10) + 7;
        for(int i = 0; i < ilosc_wierzcholkow; ++i){
            w = wierzcholki[i];
            w.set_pkt_wartosc_indeks(wielkosc,2);
            wierzcholki.push_back(w);
        }   
        rozmiar = (std :: rand() % 2) + 1;
        //this->zmien_rozmiar(rozmiar);
    };
    t_fig_random() = default;
    void rysuj(drawNS :: Draw3DAPI *rysownik) override ;
    void czysc(drawNS :: Draw3DAPI *rysownik) override {rysownik->erase_shape(id_rysunku);};
    
    bool czy_nad(t_wektor<3> w) override;
    t_wektor<2>  czy_ladowac(t_inter_dron *d,t_wektor<3> w) override;

};




class t_lista_obj_do_rysowania{
protected:
  inline static  std :: vector<t_interface_rysowania*> lista;
public:
   static void dodaj(t_interface_rysowania* elem){
       lista.push_back(elem);
   }; 
    static void usun_ostatni(){
       lista.pop_back();
   }; 
    static void rysuj_wszystkie(drawNS :: Draw3DAPI *rysownik){
        for (t_interface_rysowania* &x : lista){
            x->rysuj(rysownik);
        }
        
    };
};
#endif