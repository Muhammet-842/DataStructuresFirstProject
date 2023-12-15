/** 
* @file SatirListe.cpp 
* @description Satirlistesi islemlerini yapabilmek icin gerekli olan temel fonksiyonlar yazıldı.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/

#include "SatirListe.hpp"
#include "Dosyaoku.hpp"
#include <iostream>
#include<iomanip>
using namespace std;

SatirListesi::SatirListesi()
{

    ilk =0;
}
// ~SatirListesi()
// {
//     SatirListesiDugumu* gec = ilk;
// }

void SatirListesi::ekle(int veri)
{
    SatirListesiDugumu* yeniDugum = new SatirListesiDugumu(veri);
    if(ilk==0)
    {
        ilk = yeniDugum;
    }
    else
    {
        SatirListesiDugumu* gec = ilk;
        while(gec->sonraki!=0)
        {
            gec = gec->sonraki;
        }
        gec ->sonraki = yeniDugum;
        yeniDugum->onceki=gec;
    }
}

void SatirListesi::leaveSpace(int line)
{
    cout << setw(13 * line) << "";
}


SatirListesiDugumu* SatirListesi::sldGetir(int sira)
{
    SatirListesiDugumu* gec = ilk;
    while (sira>=0 && gec!=0)
    {
        if(sira==0)
        {
            return gec;
        }
        gec = gec->sonraki;
        sira--;
    }
    return 0;
    
}

void SatirListesi::yazdir(int slsira)
{
    SatirListesiDugumu *gec = ilk;

    while (gec != 0)
    {
        cout << endl;
        leaveSpace(slsira);
        cout << ""
             << "^^^^^^^^^^^" << endl;
        leaveSpace(slsira);
        cout << ""
             << "-----------";

        cout << endl;

        leaveSpace(slsira);
        cout << "|" << setw(9) << gec
             << "|" << setw(2) << " ";

        cout << endl;

        leaveSpace(slsira);
        cout << ""
             << "-----------";

        cout << endl;

        leaveSpace(slsira);
        cout << "|" << setw(9) << gec->veri
             << "|" << setw(2) << " ";

        cout << endl;

        leaveSpace(slsira);
        cout << ""
             << "-----------";

        cout << endl;

        leaveSpace(slsira);
        cout << "|" << setw(9) << gec->sonraki
             << "|" << setw(2) << " ";

        cout << endl;

        leaveSpace(slsira);
        cout << ""
             << "-----------";

        cout << endl;

        gec = gec->sonraki;
    }

    cout << endl;
}

void SatirListesi::cikar(int sira)
{
    
}



ostream& operator<<(ostream& os,SatirListesi& liste)
{
    os<<setw(15)<<"Dugum adresi"<< setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
    SatirListesiDugumu* gec = liste.ilk;
    while(gec!=0)
    {
        os<<setw(15)<<gec<<setw(15)<<gec->veri<<setw(15)<<gec->onceki<<setw(15)<<gec->sonraki<<endl;
        gec = gec->sonraki;
    }
    return os;
}   