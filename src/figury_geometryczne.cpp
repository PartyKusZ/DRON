#include"figury_geometryczne.hh"
#include<vector>
#include"wektor.hh"
#include"Dr3D_gnuplot_api.hh"
#include"uklad_wspolrzednych.hh"

void t_prostopadloscian :: rysuj(drawNS :: Draw3DAPI *rysownik) {
    std :: vector<std ::vector<drawNS :: Point3D>> wsp;
    std :: vector<drawNS :: Point3D> wspp;
    std :: vector<drawNS :: Point3D> wsppp;
    t_wektor<3> w;
    drawNS :: Point3D p(0,0,0);
    t_prostopadloscian tmp;
    t_uklad_wspolrzednych uk;
    uk = this->przeliczanie_ukladow();
    tmp = *this;
   for(int i = 0; i < 8; ++i ){
        tmp.wierzcholki[i] = uk.get_polozenie() * wierzcholki[i]  + uk.get_srodek();
    }
  
    for(int i = 0; i < 8; ++i){
        w = tmp.wierzcholki[i];
        for(int j = 0; j < 3; ++j){
            p[j] = w[j];
        }
        wspp.push_back(p);
        if(i == 3)
            wsp.push_back(wspp);
        if(i > 3){
            wsppp.push_back(p);
        }
        if(i == 7)
            wsp.push_back(wsppp);    
    }
       
    
    id_rysunku = rysownik->draw_polyhedron(wsp,"yellow");
    rysownik->redraw();
}

bool t_prostopadloscian :: czy_nad(t_wektor<3> w){
    t_wektor<3> tmp;
    tmp = wierzcholki[5];
    if(w.get_wartosc(2) > tmp.get_wartosc(2))
        return true;
    else
        return false;
}

t_wektor<2> t_prostopadloscian :: czy_ladowac(t_inter_dron *d,t_wektor<3> w){
    double promien_maly_x;
    double promien_maly_y;
    double promien_maly;
    double promien_duzy;
    double odleglosc;
    t_wektor<3> pomocniczy;
    t_wektor<3> cel;
    t_wektor<2> wynik;
    w.set_pkt_wartosc_indeks(0,2);
    pomocniczy = srodek + wierzcholki[0];

    promien_maly_x = abs(srodek.get_wartosc(0) - pomocniczy.get_wartosc(0));
    promien_maly_y = abs(srodek.get_wartosc(1) - pomocniczy.get_wartosc(1));
    std :: cout << promien_maly_x << std :: endl;
    std :: cout << promien_maly_y << std :: endl;


    if(promien_maly_x < promien_maly_y){
        promien_maly = promien_maly_x;
    }
    else{
        promien_maly = promien_maly_y;

    }
    std :: cout << promien_maly << std :: endl;

    promien_duzy = srodek.dlugosc_odcinka(pomocniczy);
    std :: cout << promien_duzy << std :: endl;
    cel = w - d->get_srodek_drona();

    d->przesun(cel);
    
    
    odleglosc = srodek.dlugosc_odcinka(d->get_srodek_drona());
    std :: cout << odleglosc << std :: endl;
    std :: cout << d->dlugosc_drona() << std :: endl;

    if(odleglosc > (promien_duzy + d->dlugosc_drona()) ||  odleglosc < promien_maly){
        d->przesun(cel.przeciwny());
        
        wynik.set_pkt_wartosc_indeks(odleglosc,0);
        wynik.set_pkt_wartosc_indeks(wierzcholki[5].get_wartosc(2),1);

    }
    else{
        d->przesun(cel.przeciwny());
        
        
        wynik.set_pkt_wartosc_indeks(-1,0);
        wynik.set_pkt_wartosc_indeks(-1,1);
    }

    return wynik;
}  


void t_graniastoslup6 :: rysuj(drawNS :: Draw3DAPI *rysownik){
    std :: vector<std ::vector<drawNS :: Point3D>> wsp;
    std :: vector<drawNS :: Point3D> wspp;
    std :: vector<drawNS :: Point3D> wsppp;
    t_wektor<3> w;
    drawNS :: Point3D p(0,0,0);
    t_graniastoslup6 tmp;
    t_uklad_wspolrzednych uk;
    uk = this->przeliczanie_ukladow();
    tmp = *this;
    for(int i = 0; i < 12; ++i){
        tmp.wierzcholkii[i] = uk.get_polozenie() * wierzcholkii[i]  + uk.get_srodek();
    }

    for(int i = 0; i < 12; ++i){
        w = tmp.wierzcholkii[i];
        for(int j = 0; j < 3; ++j){
            p[j] = w[j];
        }
        wspp.push_back(p);
        if(i == 5)
            wsp.push_back(wspp);
        if(i > 5){
            wsppp.push_back(p);
        }
        if(i == 11)
            wsp.push_back(wsppp);   
    }
    id_rysunku = rysownik->draw_polyhedron(wsp,"green");
    rysownik->redraw();
}


bool t_graniastoslup6 :: czy_nad(t_wektor<3> w){
    t_wektor<3> tmp;
    tmp = wierzcholkii[7];
    if(w.get_wartosc(2) > tmp.get_wartosc(2))
        return true;
    else
        return false;    
}

t_wektor<2>  t_graniastoslup6 :: czy_ladowac(t_inter_dron *d,t_wektor<3> w){
   t_wektor<2>  wynik {1,1};
   return wynik ;
}


void t_powierzchnia :: rysuj(drawNS :: Draw3DAPI *rysownik){
    std :: vector<std :: vector <drawNS :: Point3D>> mapa;
    std :: vector<drawNS :: Point3D> tmp;
    drawNS :: Point3D pkt{0,0,0};
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            pkt[0] = i * 15;
            pkt[1] = j * 15;
            pkt[2] = wysokosc;
            tmp.push_back(pkt);
        }
    }
    mapa.push_back(tmp);
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            pkt[0] = i * -15;
            pkt[1] = j * -15;
            pkt[2] = wysokosc;
            tmp.push_back(pkt);
        }
    }
    mapa.push_back(tmp);
      for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            pkt[0] = i * 15;
            pkt[1] = j *-15;
            pkt[2] = wysokosc;
            tmp.push_back(pkt);
        }
    }
    mapa.push_back(tmp);
      for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            pkt[0] = i * -15;
            pkt[1] = j *  15;
            pkt[2] = wysokosc;
            tmp.push_back(pkt);
        }
    }
    mapa.push_back(tmp);
  
    id_rysunku = rysownik->draw_surface(mapa,"red");
    rysownik->redraw();
}


void t_plaskowyz :: rysuj(drawNS :: Draw3DAPI *rysownik){
    std :: vector<std ::vector<drawNS :: Point3D>> wsp;
    std :: vector<drawNS :: Point3D> wspp;
    std :: vector<drawNS :: Point3D> wsppp;
    t_wektor<3> w;
    drawNS :: Point3D p(0,0,0);
    t_plaskowyz tmp;
    t_uklad_wspolrzednych uk;
    uk = this->przeliczanie_ukladow();
    tmp = *this;
    for(int i = 0; i < 8; ++i ){
        tmp.wierzcholki[i] = uk.get_polozenie() * wierzcholki[i]  + uk.get_srodek();
    }
    for(int i = 0; i < 8; ++i){
        w = tmp.wierzcholki[i];
        for(int j = 0; j < 3; ++j){
            p[j] = w[j];
        }
        wspp.push_back(p);
        if(i == 3)
            wsp.push_back(wspp);
        if(i > 3){
            wsppp.push_back(p);
        }
        if(i == 7)
            wsp.push_back(wsppp);    
    }
       
    
    id_rysunku = rysownik->draw_polyhedron(wsp,"blue");
    rysownik->redraw();
}


bool t_plaskowyz :: czy_nad(t_wektor<3> w){
    t_wektor<3> tmp;
    tmp = wierzcholki[5];
    if(w.get_wartosc(2) > tmp.get_wartosc(2))
        return true;
    else
        return false;    
}


t_wektor<2>  t_plaskowyz :: czy_ladowac(t_inter_dron *d, t_wektor<3> w){
   double promien_duzy;
   double promien_maly_x;
   double promien_maly_y;
   double promien_maly;
   double odleglosc;
   t_wektor<3> pomocniczy;
   t_wektor<3> cel;
   t_wektor <2> wynik;
    w.set_pkt_wartosc_indeks(0,2);

   pomocniczy = srodek + wierzcholki[5];
   promien_maly_x = abs(srodek.get_wartosc(0) - pomocniczy.get_wartosc(0));
   promien_maly_y = abs(srodek.get_wartosc(1) - pomocniczy.get_wartosc(1));

   if(promien_maly_x < promien_maly_y){
       promien_maly = promien_maly_x;
   }
   else{
       promien_maly = promien_maly_y;

   }

   promien_duzy = srodek.dlugosc_odcinka(wierzcholki[0] + srodek);
   cel = w - d->get_srodek_drona();
   d->przesun(cel);
   

   odleglosc = srodek.dlugosc_odcinka(d->get_srodek_drona());

   if(odleglosc > (promien_duzy + d->dlugosc_drona()) || odleglosc < promien_maly){
       d->przesun(cel.przeciwny());
       wynik.set_pkt_wartosc_indeks(odleglosc,0);
       wynik.set_pkt_wartosc_indeks(wierzcholki[5].get_wartosc(2), 1);

   }
   else{
       d->przesun(cel.przeciwny());
        std :: cout << "zwraca plaskowyrz" << std :: endl;

       wynik.set_pkt_wartosc_indeks(-1,0);
       wynik.set_pkt_wartosc_indeks(-1,1);

       
   }
    return wynik;

}


void t_wzgorze :: rysuj(drawNS :: Draw3DAPI *rysownik){
    std :: vector<std ::vector<drawNS :: Point3D>> wsp;
    std :: vector<drawNS :: Point3D> wspp;
    std :: vector<drawNS :: Point3D> wsppp;
    t_wektor<3> w;
    drawNS :: Point3D p(0,0,0);
    t_wzgorze tmp;
    t_uklad_wspolrzednych uk;
    uk = this->przeliczanie_ukladow();
    tmp = *this;
    for(int i = 0; i < 8; ++i ){
        tmp.wierzcholki[i] = uk.get_polozenie() * wierzcholki[i]  + uk.get_srodek();
    }
    for(int i = 0; i < 8; ++i){
        w = tmp.wierzcholki[i];
        for(int j = 0; j < 3; ++j){
            p[j] = w[j];
        }
        wspp.push_back(p);
        if(i == 3)
            wsp.push_back(wspp);
        if(i > 3){
            wsppp.push_back(p);
        }
        if(i == 7)
            wsp.push_back(wsppp);    
    }
       
    
    id_rysunku = rysownik->draw_polyhedron(wsp,"blue");
    rysownik->redraw();
} 



bool t_wzgorze :: czy_nad(t_wektor<3> w){
    t_wektor<3> tmp;
    tmp = wierzcholki[5];
    if(w.get_wartosc(2) > tmp.get_wartosc(2))
        return true;
    else
        return false;    
}

t_wektor<2>  t_wzgorze :: czy_ladowac(t_inter_dron *d, t_wektor<3> w){
   
    double promien;
    double odleglosc;
    t_wektor<3> pomocniczy;
    t_wektor<3> cel;
    t_wektor<2> wynik;

     w.set_pkt_wartosc_indeks(0,2);
    pomocniczy = srodek + wierzcholki[0];

    promien = srodek.dlugosc_odcinka(pomocniczy);
       cel = w - d->get_srodek_drona();


    d->przesun(cel);

    odleglosc = srodek.dlugosc_odcinka(d->get_srodek_drona());

    if(odleglosc > (promien + d->dlugosc_drona())){
        d->przesun(cel.przeciwny());
        wynik.set_pkt_wartosc_indeks(odleglosc,0);
        wynik.set_pkt_wartosc_indeks(wierzcholki[5].get_wartosc(2),1);
    }
    else{ 
        d->przesun(cel.przeciwny());
        std :: cout << "zwraca wzgorze" << std :: endl;
        wynik.set_pkt_wartosc_indeks(-1,0);
        wynik.set_pkt_wartosc_indeks(-1,1);
    }
    return wynik;
}



void  t_plaskowz_pros :: rysuj (drawNS :: Draw3DAPI *rysownik){
    std :: vector<std ::vector<drawNS :: Point3D>> wsp;
    std :: vector<drawNS :: Point3D> wspp;
    std :: vector<drawNS :: Point3D> wsppp;
    t_wektor<3> w;
    drawNS :: Point3D p(0,0,0);
    t_plaskowz_pros tmp;
    t_uklad_wspolrzednych uk;
    uk = this->przeliczanie_ukladow();
    tmp = *this;
   for(int i = 0; i < 8; ++i ){
        tmp.wierzcholki[i] = uk.get_polozenie() * wierzcholki[i]  + uk.get_srodek();
    }
  
    for(int i = 0; i < 8; ++i){
        w = tmp.wierzcholki[i];
        for(int j = 0; j < 3; ++j){
            p[j] = w[j];
        }
        wspp.push_back(p);
        if(i == 3)
            wsp.push_back(wspp);
        if(i > 3){
            wsppp.push_back(p);
        }
        if(i == 7)
            wsp.push_back(wsppp);    
    }
       

  
    id_rysunku = rysownik->draw_polyhedron(wsp,"yellow");
    rysownik->redraw();
}


bool t_plaskowz_pros :: czy_nad(t_wektor<3> w){
    t_wektor<3> tmp;
    tmp = wierzcholki[5];
    if(w.get_wartosc(2) > tmp.get_wartosc(2))
        return true;
    else
        return false;    
}

t_wektor<2>  t_plaskowz_pros :: czy_ladowac(t_inter_dron *d, t_wektor<3> w){
     double promien_maly_x;
    double promien_maly_y;
    double promien_maly;
    double promien_duzy;
    double odleglosc;
    t_wektor<3> pomocniczy;
    t_wektor<2> wynik; 
    pomocniczy = srodek + wierzcholki[0];
     w.set_pkt_wartosc_indeks(0,2);
    

    promien_maly_x = abs(srodek.get_wartosc(0) - pomocniczy.get_wartosc(0));
    promien_maly_y = abs(srodek.get_wartosc(1) - pomocniczy.get_wartosc(1));
    if(promien_maly_x < promien_maly_y){
        promien_maly = promien_maly_x;
    }
    else{
        promien_maly = promien_maly_y;

    }

    promien_duzy = srodek.dlugosc_odcinka(pomocniczy);

    d->przesun(w);
    d->przesun_front(w);
    odleglosc = srodek.dlugosc_odcinka(d->get_srodek_drona());

    if(odleglosc > (promien_duzy + d->dlugosc_drona()) || odleglosc < promien_maly){
        d->przesun(w.przeciwny());
        d->przesun_front(w.przeciwny());
        wynik.set_pkt_wartosc_indeks(odleglosc,0);
        wynik.set_pkt_wartosc_indeks(wierzcholki[5].get_wartosc(2),1);

    }
    else{
        d->przesun(w.przeciwny());
        d->przesun_front(w.przeciwny());
       std :: cout << "Zwraca plaskowyz pros"<< std :: endl;

       wynik.set_pkt_wartosc_indeks(-1,0);
       wynik.set_pkt_wartosc_indeks(-1,1);
       
    }
    return wynik;

}


void  t_fig_random :: rysuj (drawNS :: Draw3DAPI *rysownik){
    std :: vector<std ::vector<drawNS :: Point3D>> wsp;
    std :: vector<drawNS :: Point3D> wspp;
    std :: vector<drawNS :: Point3D> wsppp;
    t_wektor<3> w;
    drawNS :: Point3D p(0,0,0);
    t_fig_random tmp;
    t_uklad_wspolrzednych uk;
    uk = this->przeliczanie_ukladow();
    tmp = *this;
   for(int i = 0; i < wierzcholki.size(); ++i ){
        tmp.wierzcholki[i] = uk.get_polozenie() * wierzcholki[i]  + uk.get_srodek();
    }
  
    for(int i = 0; i < wierzcholki.size(); ++i){
        w = tmp.wierzcholki[i];
        for(int j = 0; j < 3; ++j){
            p[j] = w[j];
        }
        wspp.push_back(p);
        if(i == (wierzcholki.size() / 2) -1)
            wsp.push_back(wspp);
        if(i > (wierzcholki.size() / 2) -1){
            wsppp.push_back(p);
        }
        if(i == wierzcholki.size() - 1)
            wsp.push_back(wsppp);    
    }
       

  
    id_rysunku = rysownik->draw_polyhedron(wsp,"blue");
    rysownik->redraw();

}



bool t_fig_random  :: czy_nad(t_wektor<3> w){
    t_wektor<3> tmp;
    double nr;
    nr = (wierzcholki.size() / 2) + 1;
    tmp = wierzcholki[nr];
    if(w.get_wartosc(2) > tmp.get_wartosc(2))
        return true;
    else
        return false;       
}

t_wektor<2>  t_fig_random  :: czy_ladowac(t_inter_dron *d,t_wektor<3> w){
   double promien_maly;
   double promien_duzy;
   double odleglosc;
   std :: vector<t_wektor<3>> pomocnicze_wierzcholki;
   t_wektor<3> cel;
   t_wektor<2> wynik;
    w.set_pkt_wartosc_indeks(0,2);

   for(int i = 0; i < wierzcholki.size(); ++i){
       pomocnicze_wierzcholki.push_back(wierzcholki[i] + srodek);
   }

   promien_maly = srodek.dlugosc_odcinka(pomocnicze_wierzcholki[0]);
   for(int i = 1; i < ((pomocnicze_wierzcholki.size() / 2) - 1); ++i){
       if(srodek.dlugosc_odcinka(pomocnicze_wierzcholki[i]) < promien_maly){
            promien_maly = srodek.dlugosc_odcinka(pomocnicze_wierzcholki[i]);
       }
   }
   promien_duzy = srodek.dlugosc_odcinka(pomocnicze_wierzcholki[0]);
   for(int i = 1; i < ((pomocnicze_wierzcholki.size() / 2) - 1); ++i){
       if(srodek.dlugosc_odcinka(pomocnicze_wierzcholki[i]) > promien_duzy){
           promien_duzy = srodek.dlugosc_odcinka(pomocnicze_wierzcholki[i]);
       }
   }
      cel = w - d->get_srodek_drona();

   d->przesun(cel);
   odleglosc = srodek.dlugosc_odcinka(d->get_srodek_drona());
   if(odleglosc > (promien_duzy + d->dlugosc_drona()) ||  odleglosc < promien_maly){
       
       d->przesun(cel.przeciwny());
       
       wynik.set_pkt_wartosc_indeks(odleglosc,0);
       wynik.set_pkt_wartosc_indeks(wierzcholki[wierzcholki.size() - 1].get_wartosc(2),1);
   }
   else{
       
       d->przesun(cel.przeciwny());
       std :: cout << "Zwraca fig random"<< std :: endl;
       wynik.set_pkt_wartosc_indeks(-1,0);
       wynik.set_pkt_wartosc_indeks(-1,1);
   }
    return wynik;
}