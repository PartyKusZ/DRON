#ifndef DRON_HH
#define DRON_HH
#define ROZ 2.5
/*!
* \file
* \brief Istota klasy t_dron
* 
*  Oto plik zawierający definicje klasy dron, określone są tu pola i metody
*  zwiazne z ruchem drona, jego rysowaniem, czyszczeniem i położeniem. 
*/

#include"uklad_wspolrzednych.hh"
#include"figury_geometryczne.hh"
#include"Dr3D_gnuplot_api.hh"
#include<cmath>
#include "inter_dron.hh"
#include"inter_rysowania.hh"

/*!
*  \brief Klasa t_dron
*  
*   Klasa ta definiuje typ t_dron realzujcy pewnien model drona, który wyświetlany jest w gnuplocie podczas dizałania programu Dron
*   Zawiera ona następujące pola składające się na drona :
*       \c  t_prostopadloscian  - pełni role korpusu drona 
*       \c  t_graniastoslup6  - pełni role śmigieł drona, występują 4 pola tego typu
*  Klasa zawiera również metory odpowiadające za rysowanie i czyszczenie w porgramie gnuplot.
*  Klasa t_dron dziedziczy następujące intefejsy:
*       \c   t_uklad_wspolrzednych
*       \c   t_interface_rysowania
*/










class t_dron : public t_uklad_wspolrzednych, public t_interface_rysowania , public t_inter_dron, public t_elem_krajobrazu{
 private:
/*!
* \brief Korpus drona 
* 
* Pole stanowiące korpus drona  
*/

   t_prostopadloscian pr{{0,0,0},0,'z',nullptr,{{-6,-11.5,0},{6,-11.5,0},{6,11.5,0},{-6,11.5,0},{-6,-11.5,4},{6,-11.5,4},{6,11.5,4},{-6,11.5,4}}};

 /*!
 * \brief Śmigła dorona
 *
 * Pole stanowiące śmigło dorona 
 */

   t_graniastoslup6 pg1{{-6,-11.5,4},0,'z',&pr,{{-1,1.73,0},{1,1.73,0},{2,0,0},{1,-1.73,0},{-1,-1.73,0},{-2,0,0},{-1,1.73,1},{1,1.73,1},{2,0,1},{1,-1.73,1},{-1,-1.73,1},{-2,0,1}}};  

 /*!
 * \brief Śmigła dorona
 *
 * Pole stanowiące śmigło dorona 
 */
  
   t_graniastoslup6 pg2{{6,-11.5,4},0,'z',&pr,{{-1,1.73,0},{1,1.73,0},{2,0,0},{1,-1.73,0},{-1,-1.73,0},{-2,0,0},{-1,1.73,1},{1,1.73,1},{2,0,1},{1,-1.73,1},{-1,-1.73,1},{-2,0,1}}};  

    /*!
 * \brief Śmigła dorona
 *
 * Pole stanowiące śmigło dorona 
 */
  
   t_graniastoslup6 pg3{{6,11.5,4},0,'z',&pr,{{-1,1.73,0},{1,1.73,0},{2,0,0},{1,-1.73,0},{-1,-1.73,0},{-2,0,0},{-1,1.73,1},{1,1.73,1},{2,0,1},{1,-1.73,1},{-1,-1.73,1},{-2,0,1}}};  

    /*!
 * \brief Śmigła dorona
 *
 * Pole stanowiące śmigło dorona 
 */
  
   t_graniastoslup6 pg4{{-6,11.5,4},0,'z',&pr,{{-1,1.73,0},{1,1.73,0},{2,0,0},{1,-1.73,0},{-1,-1.73,0},{-2,0,0},{-1,1.73,1},{1,1.73,1},{2,0,1},{1,-1.73,1},{-1,-1.73,1},{-2,0,1}}};  


public:
/*!
*   \brief Kostruktor dorna 
*   Konstruktor przyjmuje następujące argumenty : środek drona, domyślne  kąt i oś  wg których  tworzony jest jego układ wsółrzędnych,
*   wskaźnik na układ współrzędnych, w którym powstaje układ drona.
*   \param[in] w - środek drona 
*   \param[in] kat - kąt o jaki ma być obrócony układ wsp drona
*   \param[in] os - oś wokół której ma zostać obrócony układ 
*   \param[in] wsk  - wskaźnik na układ wsp, w którym powstaje układ wsp drona
*/
    t_dron(t_wektor<3> w, double kat, char os, t_uklad_wspolrzednych *wsk){
        pr.set_srodek(w);
        pr.set_polozenie(kat,os);
        pr.set_uklad(wsk);
        
        pg1.zmien_rozmiar(ROZ);
        pg2.zmien_rozmiar(ROZ);
        pg3.zmien_rozmiar(ROZ);
        pg4.zmien_rozmiar(ROZ);
    };   
    t_dron() = default;

/*!
*   \brief Metoda rysuj
*
*   Rysuje drona w gnuplocie 
*   \param[in] rysownik - wskaźnik API
*
*/
    void rysuj(drawNS :: Draw3DAPI *rysownik) override{
        pr.rysuj(rysownik);
        pg1.rysuj(rysownik);
        pg2.rysuj(rysownik);
        pg3.rysuj(rysownik);
        pg4.rysuj(rysownik);
    };

/*!
*   \brief Metoda czyść
*
*   Czyści  drona w gnuplocie 
*   \param[in] rysownik - wskaźnik API
*
*/
    void czysc (drawNS :: Draw3DAPI *rysownik) override{
        pr.czysc(rysownik);
        pg1.czysc(rysownik);
        pg2.czysc(rysownik);
        pg3.czysc(rysownik);
        pg4.czysc(rysownik);
    };

/*!
*   \brief Metoda  przesun
*    
*   Przesuwa środek drona o zadany wektor 
*   \param[in] w - wektor o który ma zostać przesunięty dron 
*/
    void przesun(t_wektor<3> w ) override {pr.translacja(w);};

    /*!
*   \brief Metoda  obkrec
*    
*   Obkręca drona o zadany kąt wokół zadanej osi 
*   \param[in] kat - kąt o który ma zostać obkęcony dron
*   \param[in] os  - os wokół której ma zostać obkręcony doen
*/

    void obkrec (double kat, char os) override {pr.rotacja(kat,os);};

    /*!
*   \brief Metoda  obkrec_front_drona
*    
*   Obkręca front drona  o zadany kąt wokół zadanej osi 
*   \param[in] kat - kąt o który ma zostać obkęcony front drona
*   \param[in] os  - os wokół której ma zostać obkręcony front drona 
*
*/

    void obkrec_front_drona(double kat, char os) override {pr.obkrec_front(kat,os);};

    /*!
*   \brief Metoda  obkrec_wirniki
*    
*   Obkręca wirniki (śmigła) o zadany kąt
*   \param[in] kat - kąt o który ma zostać obkęcony wirnik
*   \param[in] os  - os wokół której ma zostać obkręcony wirnik
*
*/

    
    void obkrec_wirniki(double kat) override {

        pg1.rotacja(kat,'z');
        pg2.rotacja(kat,'z');
        pg3.rotacja(kat,'z');
        pg4.rotacja(kat,'z');
    };

/*!
*  \brief Metoda get_front 
* 
*   Zwraca front drona 
*/
    t_wektor<3> get_front_drona() override {return pr.get_front();};


/*!
*  \brief Metoda get_srodek_drona
* 
*   Zwraca środek drona 
*/
    t_wektor<3> get_srodek_drona() override {return pr.get_srodek();};


/*!
*  \brief Metoda get_korpus
* 
*   Zwraca korpus drona  drona 
*/

    double dlugosc_drona() override {return 11.5;};
    
    t_prostopadloscian get_korpus() {return pr;};

    void lec(t_wektor<3> cel,drawNS :: Draw3DAPI *rysownik , double vwir, double vkor,bool wysokosc, t_wektor<2> ladowanie) override ;
    void przesun_front(t_wektor<3> w) override {front = front + w;};
    bool  czy_nad(t_wektor<3> w)override{return true;};
    t_wektor<2>   czy_ladowac (t_inter_dron *d,t_wektor<3> w) override ;

    
};





#endif



