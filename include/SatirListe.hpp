/** 
* @file SatirListe.hpp 
* @description SatirListe.cpp icin gerekli fonksiyon ve degiskenlerin tanımladım.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/


#ifndef SatirListe_hpp
#define SatirListe_hpp

#include "SatirDugum.hpp"
#include <iostream>
using namespace std;

class SatirListesi
{
public:
    SatirListesi();
    double ortalama;
    SatirListesi* veri;
    void ekle(int veri);
    void cikar(int slsira);
    void yazdir(int sira);
    void leaveSpace(int line);
    SatirListesiDugumu* sldGetir(int sira);
    //double ortHesapla();
    friend ostream& operator<<(ostream& os,SatirListesi& liste);
    ~SatirListesi();

private:
    SatirListesiDugumu* ilk;


};




#endif 