/** 
* @file YoneticiDugum.hpp 
* @description YoneticiDugum.cpp icin gerekli fonksiyon ve degiskenlerin tanımladım.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/


#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp

#include "SatirDugum.hpp"
#include "SatirListe.hpp"

#include <iostream>
using namespace std;

class YoneticiDugum {
public:
    SatirListesi* veri;
    double ortalama;
    YoneticiDugum *sonraki;
    YoneticiDugum *onceki;
    YoneticiDugum();
    ~YoneticiDugum();
    

    // YoneticiDugum(SatirListesiDugumu* veri, YoneticiDugum *sonraki, YoneticiDugum *onceki);
    // YoneticiDugum(SatirListesiDugumu* veri, YoneticiDugum *sonraki);
    YoneticiDugum(SatirListesi* veri);
    
};



#endif