/** 
* @file main.cpp 
* @description Yonetici listesinden menudeGoster fonksiyonunu cagirdim.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/

#include<iostream>
#include<iomanip>
#include<string>
#include <fstream>
#include <sstream>
#include "Dosyaoku.hpp"
#include "YoneticiListe.hpp"
#include "SatirListe.hpp"
#include "SatirDugum.hpp"
#include "YoneticiDugum.hpp"


using namespace std;



int main()
{
    YoneticiListe* yoneticiliste;
    yoneticiliste->menudeGoster();
}
