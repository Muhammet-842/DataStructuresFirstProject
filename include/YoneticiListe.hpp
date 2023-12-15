/** 
* @file YoneticiListe.hpp 
* @description YoneticiListe.cpp icin gerekli fonksiyon ve degiskenlerin tanımladım.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/


#ifndef YoneticiListe_hpp
#define YoneticiListe_hpp

#include "SatirListe.hpp"
#include "SatirDugum.hpp"
#include "YoneticiDugum.hpp"
class YoneticiListe
{
public:
    YoneticiListe();
    void ekle(SatirListesi* veri);
    void cikar();
    void dugumCikar(int cikar);
    void yazdir();
    void ortSirala();
    int menudeGoster();
    void ustcizgicizdir(int adet);
    int sayac;
    YoneticiDugum* dugum;
    YoneticiListe* yoneticiYazdir(string dosyaadi,int tutucu);
    YoneticiDugum* ydGetir(int sira);
    friend ostream& operator<<(ostream& os,YoneticiListe& liste);
    int dugumSay;
    ~YoneticiListe();
private:
    YoneticiDugum* ilk ;

};


#endif