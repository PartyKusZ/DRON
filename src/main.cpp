#include <iostream>
#include "uklad_wspolrzednych.hh"
#include "figury_geometryczne.hh"
#include "Dr3D_gnuplot_api.hh"
#include "scena.hh"
#include "dron.hh"


using std :: cout;
using std :: cin;
using std :: endl;


 // TODO: dokumentacja 

int main(){
    srand(time(NULL));
    drawNS :: Draw3DAPI *rysownik = new drawNS:: APIGnuPlot3D(-90,90,-90,90,-10,110,-1);
    t_powierzchnia powierzchnia (0);
    t_scena scena;
    t_uklad_wspolrzednych baza {{0,0,0},0,'z',nullptr}; // układ globalny
    t_dron dron ({0,0,0},0,'z',&baza);
    t_wektor<3> wsp;
    t_dron *wskdron;
    int numer_drona;


    char sterowanie;
    sterowanie = 'l' ;

    
    scena.kreator_przeszkod(&baza);
    scena.dodaj_elem_krajobrazu(&powierzchnia);
    scena.kreator_dronow(&baza);
    
    
    scena.rysuj_wszystkie_przeszkody(rysownik);
    scena.rysuj_wszystkie_drony(rysownik);

    while(sterowanie != 'q'){
        cout << "Sumaryczna ilość obiektów typu wektor: " << t_wektor<3> :: get_suma() << endl;
        cout << "Aktualna ilość obiektów typu wektor: " << t_wektor<3> :: get_aktualna() << endl;

        cout << "Podaj punkt, do którego ma polecieć największy  dron w polsce: " << endl;
        cout << "Uwaga !!! współrzędna z określa wysokość, na którą wzbije sie dron" << endl;
        cin >> wsp;
        
         while(cin.fail()){
            cout << "Wektor podaj w formacie [x,y,z] : " << std :: endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> wsp;
            
            }
        cout << "Podaj numer drona. Uwaga, drony są numerowane od 1:" << endl;
        cin >> numer_drona;
        wskdron = scena.zworc_dorna(numer_drona);
        wskdron->lec(wsp,rysownik,2,70,scena.sprawdz_wysokosc(scena.zworc_dorna(numer_drona),wsp),scena.sprawdz_ladowanie(scena.zworc_dorna(numer_drona),wsp));
        

        cout << "aby zakończyć wsiśnij 'q', a jesli chcesz dalej latać to wciśnij cokolwiek innego, jakis klawisz i potem enter" << endl;
        cin >> sterowanie;
        system("clear");
    }

    delete rysownik;

}
