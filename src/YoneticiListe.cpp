/** 
* @file YoneticiListe.cpp 
* @description YoneticiListesi icin gerekli olan ve odevin istenilen hale gelmesi icin gerekli tum fonksiyonlar yazıldı.
* @course Veri Yapilari 2C
* @assignment 1
* @date 04.11.2022
* @author Muhammet Ali Sahal muhammet.sahal@ogr.sakarya.edu.tr
*/

#include "YoneticiListe.hpp"
#include "YoneticiDugum.hpp"
#include "Dosyaoku.hpp"
#include <iostream>
#include<iomanip>
using namespace std;
YoneticiListe::YoneticiListe(){
    ilk=0;
    dugum=0;
    sayac=0;
}
void YoneticiListe::ekle(SatirListesi* veri)
{
    YoneticiDugum* yeniDugum = new YoneticiDugum(veri);
    dugum=yeniDugum;
    if(ilk==0)
    {
        ilk = yeniDugum;
    }
    else
    {
        YoneticiDugum* gec = ilk;
        while(gec->sonraki!=0)
        {
            gec = gec->sonraki;
        }
        ortSirala();
        gec ->sonraki = yeniDugum;
        yeniDugum->onceki=gec;
        
        
        
    }
}

void YoneticiListe::ortSirala()
{
    YoneticiDugum *gec = ilk;
    SatirListesi *temp;
    
    
    if (ilk == NULL)
    {
        return;
    }
    else
    {
        int i=0;
        while (i<sayac-1)
        {
      
            int j=0;
            while (j<sayac-i-1)
            {

                if (ydGetir(j)->veri->ortalama > ydGetir(j+1)->veri->ortalama)
                {
                    temp = ydGetir(j)->veri;
                    ydGetir(j)->veri = ydGetir(j+1)->veri;
                    ydGetir(j+1)->veri = temp;
                }
                j++;
            }
            i++;
        }
    }
}

YoneticiDugum* YoneticiListe::ydGetir(int sira)
{
    YoneticiDugum* gec = ilk;
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

void YoneticiListe::yazdir()
{
    

    cout << setw(15) << "dugum adresi" << setw(15) << "veri" << setw(15) << "onceki" << setw(15) << "sonraki" << endl;
        YoneticiDugum *gec = ilk; // ilk düğümü verir
        while (gec != 0)
        {
            //cout << setw(15) << gec << setw(15) << gec->veri->ortalama << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;
            gec = gec->sonraki;
            sayac++;
        }
        cout << "-----------------------" << endl;

        cout << endl;
    delete gec;

}

void YoneticiListe::ustcizgicizdir(int adet)
{
    for(int i=0;i<adet;i++)
    {
        cout<<"---------  ";
    }
    cout<<endl;
}

void YoneticiListe::cikar()
{
    if (ilk == 0)
    {
        return;
    }
        
    if (ilk->sonraki == 0)
    {
        delete ilk;
        ilk = 0;
    }
    else
    {
        YoneticiDugum *gec = ilk;
        while (gec->sonraki->sonraki != 0)
            gec = gec->sonraki;

        delete gec->sonraki;
        gec->sonraki = 0;
    }
}



void YoneticiListe::dugumCikar(int cikar) {
    if (cikar < 0 || cikar >= sayac) throw "Index out of Range";
    YoneticiDugum *del;
    if (cikar == 0) {
        del = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL) ilk->onceki = NULL;
    } else {
        YoneticiDugum *prev = ydGetir(cikar)->onceki;
        del = prev->sonraki;
        prev->sonraki = del->sonraki;
        if (del->sonraki != NULL)
            del->sonraki->onceki = prev;
    }
    sayac--;
    delete del;
}

YoneticiListe *YoneticiListe::yoneticiYazdir(string dosyaadi, int tutucu)
{

    if (sayac - tutucu < 8)
    {
        cout << "<--onceki--" << setw(28) << "--son-->" << endl;
        for (int i = tutucu; i < sayac; i++)
        {
            cout << setw(11) << ydGetir(i) << setw(2) << "";
        }
        cout << endl;
        cout << " ";
        for (int i = tutucu; i < sayac; i++)
        {
            cout << "-----------" << setw(2) << "";
        }
        cout << endl;
        cout << " ";
        for (int i = tutucu; i < sayac; i++)
        {
            cout << "|" << setw(9) << ydGetir(i)->onceki << "|" << setw(2) << " ";
        }
        cout << endl;
        cout << " ";
        for (int i = tutucu; i < sayac; i++)
        {
            cout << "-----------" << setw(2) << "";
        }
        cout << endl;
        cout << " ";
        for (int i = tutucu; i < sayac; i++)
        {
            cout << "|" << setw(9) << ydGetir(i)->veri->ortalama << "|" << setw(2) << " ";
        }
        cout << endl;
        cout << " ";
        for (int i = tutucu; i < sayac; i++)
        {
            cout << "-----------" << setw(2) << "";
        }
        cout << endl;
        cout << " ";
        for (int i = tutucu; i < sayac; i++)
        {
            cout << "|" << setw(9) << ydGetir(i)->sonraki
                 << "|" << setw(2) << " ";
        }
        cout << endl;
        cout << " ";
        for (int i = tutucu; i < sayac; i++)
        {
            cout << "-----------" << setw(2) << "";
        }
        cout << endl;
        cout << " ";
    }
    else
    {
        if (tutucu == 0)
        {
            cout << "<--ilk--" << setw(96) << "--sonraki-->" << endl;

            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << setw(11) << ydGetir(i) << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "|" << setw(9) << ydGetir(i)->onceki << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "|" << setw(9) << ydGetir(i)->veri->ortalama << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "|" << setw(9) << ydGetir(i)->sonraki
                     << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
        }
        else if (tutucu >= 8)
        {
            cout << "<--onceki--" << setw(91) << "--sonraki-->" << endl;

            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << setw(11) << ydGetir(i) << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "|" << setw(9) << ydGetir(i)->onceki << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "|" << setw(9) << ydGetir(i)->veri->ortalama << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "|" << setw(9) << ydGetir(i)->sonraki
                     << "|" << setw(2) << " ";
            }
            cout << endl;
            cout << " ";
            for (int i = tutucu; i < tutucu + 8; i++)
            {
                cout << "-----------" << setw(2) << "";
            }
            cout << endl;
            cout << " ";
        }
    }
}


ostream& operator<<(ostream& os,YoneticiListe& liste)
{
    os<<setw(15)<<"Dugum adresi"<< setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
    YoneticiDugum* gec = liste.ilk;
    while(gec!=0)
    {
        os<<setw(15)<<gec<<setw(15)<<gec->veri<<setw(15)<<gec->onceki<<setw(15)<<gec->sonraki<<endl;
        gec = gec->sonraki;
    }
    return os;
}


int YoneticiListe::menudeGoster()
{
    string dosyaadi = "veriler.txt";
    Dosyaoku* dosyaoku = new Dosyaoku();
    YoneticiListe *yonetici = dosyaoku->dosyaoku(dosyaadi);

    int sira = 0;
    int yonetici_index = 0;
    int increaseRow = 0;

    while (true)
    {
        system("cls");
        string karar = "";
        yonetici->ortSirala();

        yonetici->yoneticiYazdir(dosyaadi, yonetici_index);
        yonetici->ydGetir(increaseRow)->veri->yazdir(sira);
         


        cin >> karar;

        if (karar == "d")
        {
            if (yonetici->sayac - yonetici_index < 8)
            {
                
            }
            else if(yonetici->sayac-increaseRow<=8)
            {
                increaseRow = yonetici->sayac - 1;
                yonetici_index+=8;
                sira=yonetici->sayac-yonetici_index-1;
            }
            else
            {
                yonetici_index += 8;
                increaseRow += 8;
            }
        }
        else if (karar == "c")
        {
            if (yonetici->sayac - increaseRow <= 1)
            {
                // throw std::out_of_range("Index out of Range");
            }
            else
            {
                sira++;
                increaseRow++;
                if (sira % 8 == 0)
                {

                    yonetici_index += 8;
                    sira = 0;
                }
            }
        }
        else if (karar == "z")
        {
            if (sira == 0 && increaseRow == 0)
            {
                sira = 0;
                increaseRow = 0;
            }
            else
            {
                sira--;
                increaseRow--;
                if (yonetici_index % 8 == 0)
                {
                    if (sira < 0)
                    {
                        sira = 7;
                        yonetici_index -= 8;
                    }
                }
            }
        }

        else if (karar == "a")
        {
            if (increaseRow < 8)
            {
                yonetici_index = 0;
            }
            else if (sira == 0 && increaseRow == 0)
            {

                sira = 0;
                increaseRow = 0;
            }
            else
            {
                yonetici_index -= 8;
                increaseRow -= 8;
            }
        }

        else if(karar=="p")
        {
             yonetici->dugumCikar(increaseRow);
            if(increaseRow>=yonetici->sayac-1)
            {
                increaseRow--;
                sira--;
                if(sira<0)
                {
                    yonetici_index-=8;
                    sira=7;
                }
            }

           
        }
        else if (karar == "m")
            return 0;
    }
    

}