/** 
* @file Dosyaoku.hpp 
* @description Dosyaoku.cpp icin gerekli fonksiyon ve degiskenlerin tanımladım.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/



#ifndef Dosyaoku_HPP
#define Dosyaoku_HPP
#include "YoneticiListe.hpp"
#include "SatirListe.hpp"
#include "YoneticiDugum.hpp"
#include "SatirDugum.hpp"


class Dosyaoku
{
public:
    Dosyaoku();
    string karakter;
    int satirSayi;
    int bosAdet;
    int sutunsayisi;
    YoneticiListe* dosyaoku(string dosyaadi);
    ~Dosyaoku();
};
#endif