/** 
* @file SatirDugum.hpp 
* @description SatirDugum.cpp icin gerekli fonksiyon ve degiskenlerin tanımladım.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/

#ifndef SatirDugum_hpp
#define SatirDugum_hpp

#include <iostream>
using namespace std;

class SatirListesiDugumu {
public:
    int veri;
    SatirListesiDugumu *sonraki;
    SatirListesiDugumu *onceki;
    //SatirListesiDugumu(int veri);
    ~SatirListesiDugumu();

    // SatirListesiDugumu(const int veri, SatirListesiDugumu *sonraki, SatirListesiDugumu *onceki);
    // SatirListesiDugumu(const int veri, SatirListesiDugumu *sonraki);
    SatirListesiDugumu(const int veri);
};


#endif