/** 
* @file Dosyaoku.cpp 
* @description Yonetici listesi ve satir listesi olusturup "veriler.txt" dosyasındaki verileri  olusturulan listelere ekledim. Ortalama hesapladım ve satir listesine ekledim.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/


#include "Dosyaoku.hpp"
#include "YoneticiListe.hpp"
#include "SatirListe.hpp"
#include "SatirDugum.hpp"
#include "YoneticiDugum.hpp"
#include <fstream>
#include <sstream>

Dosyaoku::Dosyaoku()
{
    satirSayi = 0;
    bosAdet = 0;
    sutunsayisi = 0;
}
YoneticiListe* list = new YoneticiListe();
//SatirListesi *liste = new SatirListesi();
YoneticiListe *Dosyaoku::dosyaoku(string dosyaadi)
    {
        int deger;
        ifstream dosyaOku;
        dosyaOku.open("veriler.txt");
        double avg=0;
        double total = 0;
        
         
        if (dosyaOku.is_open())
        {
                while (getline(dosyaOku, karakter))
                {
                    SatirListesi *liste = new SatirListesi();
                    
                    istringstream istst(karakter);
                    for (int j = 0; j < karakter.length(); j++)
                    {
                        if (isspace(karakter.at(j)))
                        {
                            bosAdet++;
                        }
                    }
                    
                    for (int i = 0; i < bosAdet; i++)
                    {
                        istst >> deger;
                        liste->ekle(deger);
                        total+=deger;                             
                    }
                    list->ekle(liste);
                    avg=total/  bosAdet;
                    liste->ortalama=avg;
                        
                    satirSayi++;
                    bosAdet = 0;
                    total=0;                        
                }
                list->sayac=satirSayi;                                   
        }
        return list;       
    }
    