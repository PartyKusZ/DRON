#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <vector>
#include<iostream>


template <int  ROZMIAR>
class t_wektor{

    private:
    inline static int ilosc_suma = 0;
    inline static int ilosc_aktualna = 0;
    std :: vector<double> pkt;

    public:

    t_wektor<ROZMIAR>(std :: initializer_list<double> il) : pkt(il) {ilosc_aktualna++; ilosc_suma++;};

    t_wektor<ROZMIAR>(){
        for(int i = 0; i < ROZMIAR; ++i){
            pkt.push_back(0);
        }
        ilosc_aktualna++; ilosc_suma++;
    };  
    t_wektor(const t_wektor & nowy){
        pkt = nowy.pkt;
        ilosc_aktualna++;
        ilosc_suma++;
    };
    ~t_wektor<ROZMIAR>(){ilosc_aktualna--;};

    t_wektor<ROZMIAR> operator +             (const t_wektor<ROZMIAR> &x) const;
    t_wektor<ROZMIAR> operator -             (const t_wektor<ROZMIAR> &x) const;
    double            operator *             (const t_wektor<ROZMIAR> &x) const;
    t_wektor<ROZMIAR> operator *             (const double  &x) const;
    double            get_wartosc            (const int x) {return pkt[x];};
    double            operator []            (const int x) {return pkt[x];};
    void              set_pkt_wartosc_indeks (double war, int ind){pkt[ind] = war;};
    double            dlugosc_odcinka        (const t_wektor<ROZMIAR> &x) const;
    bool              prostopadlosc          (const t_wektor<ROZMIAR> &x) const;
    double            dlugosc_wektora        ();
    static int        get_suma               () {return ilosc_suma;};           
    static int        get_aktualna           () {return ilosc_aktualna;};
    t_wektor<ROZMIAR>  przeciwny            ();

};
template<int ROZMIAR>
std :: ostream & operator << (std :: ostream &strm, t_wektor<ROZMIAR> w);
template<int ROZMIAR>
std :: istream & operator >> (std :: istream &strm, t_wektor<ROZMIAR> &w);


#endif 