#include "scena.hh"

void t_scena :: rysuj_wszystkie_przeszkody(drawNS :: Draw3DAPI *rysownik){
    for(int i = 0; i < e_rysowania.size(); ++i){
        e_rysowania[i]->rysuj(rysownik);
    }
}
 void t_scena :: rysuj_wszystkie_drony(drawNS :: Draw3DAPI *rysownik){
    for(int i = 0; i < e_rys_drony.size(); ++i){
        e_rys_drony[i]->rysuj(rysownik);
    }     
 }

void t_scena :: dodaj_elem_krajobrazu(elem_krajobrazu elem, t_uklad_wspolrzednych *uk){
        t_wektor<3> w;
        std :: cout << " Podaj polozenie przeszkody: " << std ::endl;
        std :: cin >> w;
         while(std ::cin.fail()){
            std :: cout << "Wektor podaj w formacie [x,y,z] : " << std :: endl;
           std ::  cin.clear();
            std :: cin.ignore(1000, '\n');
            std :: cin >> w;
            }
        t_elem_krajobrazu *nowy_elem;
        t_interface_rysowania *elem_do_rysowania;

    switch (elem)
    {
    case wzgorze:
       
        
        nowy_elem = new t_wzgorze {w, 0 , 'z', uk, {{-12,-12,0},{12,-12,0},{12,12,0},{-12,12,0}},18};
        
        e_krajobrazu.push_back(nowy_elem);
        elem_do_rysowania = dynamic_cast<t_interface_rysowania*>(nowy_elem);
        e_rysowania.push_back(elem_do_rysowania);

        break;

    case plaskowyz:    
        
        
        nowy_elem = new t_plaskowyz {w,0,'z',uk,{{-12,-12,0},{12,-12,0},{12,12,0},{-12,12,0},{-6,-6,18},{6,-6,18},{6,6,18},{-6,6,18}}};
        
        e_krajobrazu.push_back(nowy_elem);
        elem_do_rysowania = dynamic_cast<t_interface_rysowania*>(nowy_elem);
        e_rysowania.push_back(elem_do_rysowania);

        break;

    case palskowyz_pros:
     
        
        nowy_elem = new t_prostopadloscian{w,0,'z',uk,{{-12,-12,0},{12,-12,0},{12,12,0},{-12,12,0},{-12,-12,18},{12,-12,18},{12,12,18},{-12,12,18}}};
        
        e_krajobrazu.push_back(nowy_elem);
        elem_do_rysowania = dynamic_cast<t_interface_rysowania*>(nowy_elem);
        e_rysowania.push_back(elem_do_rysowania);

        break;

    case figura_losowa:
     
        
        nowy_elem = new t_fig_random {w,0,'z',uk};
        
        e_krajobrazu.push_back(nowy_elem);
        elem_do_rysowania = dynamic_cast<t_interface_rysowania*>(nowy_elem);
        e_rysowania.push_back(elem_do_rysowania);

        break;
    
    default:
        break;
    }

}
void t_scena :: dodaj_elem_krajobrazu(t_elem_krajobrazu *elem){
    t_interface_rysowania *elemr;
    e_krajobrazu.push_back(elem);
    elemr = dynamic_cast<t_interface_rysowania*>(elem);
    e_rysowania.push_back(elemr);


}

void t_scena :: dodaj_drona(t_inter_dron *dron){  
    t_elem_krajobrazu *dron_krajobrazu;
    t_interface_rysowania *dorn_rysowanie;
    dron_krajobrazu = dynamic_cast<t_elem_krajobrazu*>(dron);
    dorn_rysowanie = dynamic_cast<t_interface_rysowania*>(dron);
    e_krajobrazu.push_back(dron_krajobrazu);
    e_rys_drony.push_back(dorn_rysowanie);
    
}

void t_scena :: dodaj_dorna(t_uklad_wspolrzednych *uk){
    t_wektor<3> w;
        std :: cout << " Podaj polozenie drona: " << std ::endl;
        std :: cin >> w;
         while(std ::cin.fail()){
            std :: cout << "Wektor podaj w formacie [x,y,z] : " << std :: endl;
           std ::  cin.clear();
            std :: cin.ignore(1000, '\n');
            std :: cin >> w;
            }
        t_elem_krajobrazu *nowy_dron;
        t_interface_rysowania *nowy_dron_rysowania;
        nowy_dron = new t_dron  (w,0,'z',uk);
        e_krajobrazu.push_back(nowy_dron);
        nowy_dron_rysowania = dynamic_cast<t_interface_rysowania*>(nowy_dron);
        e_rys_drony.push_back(nowy_dron_rysowania);

}

void t_scena :: usun_ostatni_krajobrazu(){

    e_krajobrazu.pop_back();
    e_rysowania.pop_back();
}

void t_scena :: usun_ostatni_drona(){

    if(e_krajobrazu.size() > e_rysowania.size()){
        e_rys_drony.pop_back();
        e_krajobrazu.pop_back();
    }  
    else {
        std :: cout << "Brak dronow!" << std :: endl;
    }

}
bool t_scena :: sprawdz_wysokosc(t_inter_dron *d, t_wektor<3> w){
    
    for(int i = 0; i < e_krajobrazu.size(); ++i){
        if(e_krajobrazu[i]->czy_nad(w) == false){
            std :: cout << "Zbyt mała wysokość przelotowa" << std :: endl;
           return false;
        }
       
        
    }
    return true;

}
t_wektor<2> t_scena :: sprawdz_ladowanie(t_inter_dron *d, t_wektor<3> w){
    std :: vector<t_wektor<2>> pozwolenia;
    t_wektor<2> ladawanie;
    for(int i = 0; i < e_krajobrazu.size(); ++i){
        pozwolenia.push_back(e_krajobrazu[i]->czy_ladowac(d,w));
        
    }
    ladawanie = pozwolenia[0];
    for(int i = 1; i < pozwolenia.size(); ++i){
        if(pozwolenia[i].get_wartosc(0) < ladawanie.get_wartosc(0)){
            ladawanie = pozwolenia[i];
        }
    }
    return ladawanie;
}

void t_scena :: kreator_przeszkod(t_uklad_wspolrzednych *uk){
    std :: cout << "**********KREATOR PRZESZKOD************* " <<std :: endl;
    std :: cout<<"1. wzgorze" <<std ::endl;
    std :: cout<<"2. plaskowyz"<<std ::endl;
    std :: cout<<"3. plaskowyz prostopadloscienny"<<std ::endl;
    std :: cout<<"4. przeszkoda losowa"<< std ::endl;
    std :: cout<<"5. usun ostatni element" <<std ::endl;
    std :: cout<<"6. zakoczenie pracy kreatora" <<std ::endl;
    int numer = 0;

    while(numer != 6){
        std ::cout << "Aby dodać przeszkode lub zakonczyc prace kreatora  podaj odpowiedni numer: "<<std :: endl;
        std ::cin >> numer;
        switch (numer)
        {
        case 1:
            this->dodaj_elem_krajobrazu(wzgorze, uk);
            break;
        case 2:
            this->dodaj_elem_krajobrazu(plaskowyz, uk);
            break;
        case 3:
            this->dodaj_elem_krajobrazu(palskowyz_pros, uk);
            break;
        case 4:
            this->dodaj_elem_krajobrazu(figura_losowa, uk);
            break;
        case 5:
            this->usun_ostatni_krajobrazu();
            break;
        case 6:
            std ::cout << "Koniec pract kreatora!"<< std ::endl;
            break;
        default:
           std :: cout <<"Brak takiej opcji!" << std ::endl;
            break;
        }

    }

}

void t_scena :: kreator_dronow(t_uklad_wspolrzednych *uk){
    std :: cout << "*************KREATOR DRONOW******************" << std :: endl;
    std :: cout << "1. dodaj drona" << std :: endl;
    std :: cout << "2. usun ostatniego drona" << std :: endl;
    std :: cout << "3. zakoncz prace kreatora" << std :: endl;
    int numer  = 0;
    while(numer != 3 ){
    std :: cout << "Aby dodać, usunąć drona lub zakończyć prace kreatora wybierz właściwy numer" << std :: endl;
    std :: cin >> numer;
    switch (numer)
    {
    case 1:
        this->dodaj_dorna(uk);
        break;
    case 2: 
        this->usun_ostatni_drona();
        break;

    default:
        std :: cout << "Nie ma takiej opcji w menu!" << std :: endl;
        break;
    }

    }



}

t_dron* t_scena :: zworc_dorna(int numer_drona){
   
    if(numer_drona > 0){
         if(numer_drona <= e_rys_drony.size()){
         t_dron *dron;
         dron = dynamic_cast<t_dron*>(e_rys_drony[numer_drona - 1]);
         return dron;
         }
         else{
             std :: cout << "Nie ma takiego drona!" << std :: endl;
             std :: cout << "Podaj numer drona:" << std :: endl;
             int numer;
             std :: cin >> numer;
             this->zworc_dorna(numer);
         }

    }
    else{
        int nr_dorna;
        std :: cout << " Drony numerujemy od 1!" << std :: endl;
        std :: cout << "Podaj numer drona:" << std :: endl;
        std :: cin >> nr_dorna;
        this->zworc_dorna(nr_dorna);
    }
}