/** 
* @file YoneticiDugum.cpp 
* @description YoneticiDugumden veri,onceki,sonrakileri olusturdum.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/

#include "YoneticiDugum.hpp"
#include "SatirListe.hpp"
#include "Dosyaoku.hpp"
#include <iostream>
#include<iomanip>
using namespace std;


YoneticiDugum::YoneticiDugum(SatirListesi* veri)
{
    this->veri = veri;
    this->sonraki=0;
    this->onceki=0;
}

YoneticiDugum::~YoneticiDugum()
{

}

