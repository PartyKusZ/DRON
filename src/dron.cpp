#include "dron.hh"


void t_dron :: lec(t_wektor<3> cel,drawNS :: Draw3DAPI *rysownik , double vwir, double vkor, bool wysokosc,t_wektor<2> ladowanie ){
    
    t_wektor<3> srodek_cel;
    t_wektor<3> srodek_front;
    t_wektor<3> front;
    t_wektor<3> srodek;
    double wysokosc_drona;
    double a1;
    double a2;
    double katobr;
    double kierunek_obr;
    t_prostopadloscian pros;
    t_uklad_wspolrzednych uk;


    pros = this->get_korpus();
    uk = pros.przeliczanie_ukladow();
    front = uk.get_polozenie() * this->get_front_drona() + uk.get_srodek();
    srodek = this->get_srodek_drona();
    srodek.set_pkt_wartosc_indeks(cel.get_wartosc(2),2);
    front.set_pkt_wartosc_indeks(cel.get_wartosc(2),2);

    srodek_cel = cel  - srodek;
    srodek_front = front - srodek;

    katobr = acos((srodek_cel * srodek_front) / (srodek_front.dlugosc_wektora() * srodek_cel.dlugosc_wektora()));

    katobr = (katobr * 180) / ( M_PI);

    this->obkrec(katobr,'z');
    
    pros = this->get_korpus();
    uk = pros.przeliczanie_ukladow();
    front = uk.get_polozenie() * this->get_front_drona() + uk.get_srodek();
    front.set_pkt_wartosc_indeks(cel.get_wartosc(2),2);
    srodek_front = front - srodek;

    a1 = srodek_cel.get_wartosc(1) / srodek_cel.get_wartosc(0);
    a2 = srodek_front.get_wartosc(1) / srodek_front.get_wartosc(0);

    if(abs(a1 - a2) > 0.001){
        kierunek_obr = -1;
        this->obkrec(-katobr,'z');
    }
    else{
        kierunek_obr = 1;
        this->obkrec(-katobr,'z');

    }

    cel  = cel - this->get_srodek_drona();
     


    if(wysokosc == true){
        if(ladowanie.get_wartosc(0) != -1){
            for(int i = 0; i < cel.get_wartosc(2); ++i){
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->przesun({0,0,1});
                system("sleep 0.1");
                 }
    
            for(int i = 1; i < katobr; ++i){ // for obkręcający, 
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->obkrec(kierunek_obr,'z'); // obracam o jeden stopien drona tyle razy ile wynosi kąt 
    
                 system("sleep 0.02");

                }
            for(int i = 0; i < cel.dlugosc_wektora(); ++i){
                 this->czysc(rysownik);
                 this->rysuj(rysownik);
                 this->obkrec_wirniki(vwir);
                 this->przesun({cel.get_wartosc(0) / cel.dlugosc_wektora(), cel.get_wartosc(1) / cel.dlugosc_wektora(), 0});
                 system("sleep 0.1");

                }
                wysokosc_drona = this->get_srodek_drona().get_wartosc(2); 
             for(int i = 0; i < wysokosc_drona - ladowanie.get_wartosc(1); ++i){
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->przesun({0,0,-1});
                system("sleep 0.1");
                }
        }
        else{
                for(int i = 0; i < cel.get_wartosc(2); ++i){
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->przesun({0,0,1});
                system("sleep 0.1");
                 }
    
            for(int i = 1; i < katobr; ++i){ // for obkręcający, 
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->obkrec(kierunek_obr,'z'); // obracam o jeden stopien drona tyle razy ile wynosi kąt 
    
                 system("sleep 0.02");

                }
            for(int i = 0; i < cel.dlugosc_wektora(); ++i){
                 this->czysc(rysownik);
                 this->rysuj(rysownik);
                 this->obkrec_wirniki(vwir);
                 this->przesun({cel.get_wartosc(0) / cel.dlugosc_wektora(), cel.get_wartosc(1) / cel.dlugosc_wektora(), 0});
                 system("sleep 0.1");

                }
                for(int i = 0; i < cel.dlugosc_wektora(); ++i){
                 this->czysc(rysownik);
                 this->rysuj(rysownik);
                 this->obkrec_wirniki(vwir);
                 this->przesun({-cel.get_wartosc(0) / cel.dlugosc_wektora(), -cel.get_wartosc(1) / cel.dlugosc_wektora(), 0});
                 system("sleep 0.1");

                }
                for(int i = 0; i < cel.get_wartosc(2); ++i){
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->przesun({0,0,-1});
                system("sleep 0.1");
                 }
        }
    }
    else{
            for(int i = 0; i < cel.get_wartosc(2); ++i){
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->przesun({0,0,1});
                system("sleep 0.1");
                 }
                 for(int i = 0; i < cel.get_wartosc(2); ++i){
                this->czysc(rysownik);
                this->rysuj(rysownik);
                this->obkrec_wirniki(vwir);
                this->przesun({0,0,-1});
                system("sleep 0.1");
                 }
    }
 
  
}

t_wektor<2>  t_dron ::   czy_ladowac (t_inter_dron *d,t_wektor<3> w){
    t_wektor<2> wynik;
    if(this !=  d){
        t_wektor<3> cel;
        double odleglosc;
        cel = w - d->get_srodek_drona();
        d->przesun(cel);
        odleglosc = this->srodek.dlugosc_odcinka(d->get_srodek_drona());
        if(odleglosc > 2 * d->dlugosc_drona()){
            d->przesun(cel.przeciwny());
            wynik.set_pkt_wartosc_indeks(odleglosc,0);
            wynik.set_pkt_wartosc_indeks(0,1);


         }
        else{
             d->przesun(cel.przeciwny());
            wynik.set_pkt_wartosc_indeks(-1,0);
            wynik.set_pkt_wartosc_indeks(-1,1);

         }
    }
    else{
        wynik.set_pkt_wartosc_indeks(100000000000000,0);
        wynik.set_pkt_wartosc_indeks(0,1);
    }
    return wynik;
}