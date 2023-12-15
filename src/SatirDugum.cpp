/** 
* @file SatirDugum.cpp 
* @description SatirListesiDugumunden veri,onceki,sonrakileri olusturdum.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/

#include "SatirDugum.hpp"

SatirListesiDugumu::SatirListesiDugumu(int veri)
{
    this->veri = veri;
    this->sonraki=0;
    this->onceki=0;
}
SatirListesiDugumu::~SatirListesiDugumu()
{

}