#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

string databperjalan[3] = {"Murah","Sedang","Mahal"};

string datajperjalan[3] = {"Dekat","Sedang","Jauh"};

string datawperjalan[3] = {"Singkat","Sedang","Lama"};

float nilaibperjalan[8], nilaijperjalan [8], nilaiwperjalan[8], nilaikelayakkan[48];

int i,j,k;

int z;

int sampel;

char* datanilaikelayakkan[12];

float kendaraanA = 0;

float kendaraanB = 0;

float kendaraanC = 0;

float biayamurah(float bperjalan)
{
    float bpermurah = 0;

    if(bperjalan <= 1)
    {
        bpermurah =1;
    }
    else if(bperjalan >=1 && bperjalan < 3)
    {
        bpermurah = (3-bperjalan)/2;
    }
    else if(bperjalan >=3)
    {
        bpermurah = 0;
    }
    return bpermurah;
}

float biayasedang (float bperjalan)
{
    float bpersedang = 0;

    if(bperjalan <=1 || bperjalan >= 5)
    {
        bpersedang = 0;
    }
    else if(bperjalan > 3 && bperjalan <5)
    {
        bpersedang = (bperjalan-3)/2;
    }
    else if (bperjalan >1 && bperjalan <3)
    {
        bpersedang = (bperjalan-1)/2;
    }
    else
    {
        bpersedang = 1;
    }
    return bpersedang;
}

float biayamahal(float bperjalan)
{
    float bpermahal = 0;

    if (bperjalan >= 5)
    {
        bpermahal  = 1;
    }
    else if(bperjalan >=3 && bperjalan < 5)
    {
        bpermahal = (bperjalan-3)/2;
    }
    else if(bperjalan <= 3)
    {
        bpermahal = 0;
    }
    return bpermahal;
}

float jarakdekat (float jperjalan)
{
    float jperdekat =0;

    if (jperjalan <= 300)
    {
        jperdekat = 1;
    }
    else if(jperjalan >=300 && jperjalan < 600)
    {
        jperdekat = (600 - jperjalan)/300;
    }
    else if(jperjalan < 600)
    {
        jperdekat = 0;
    }
    return jperdekat;
}

float jaraksedang(float jperjalan)
{
    float jpersedang = 0;

    if (jperjalan <= 300 || jperjalan >= 900)
    {
        jpersedang = 0;
    }
    else if(jperjalan >= 300 && jperjalan <600)
    {
        jpersedang = (jperjalan-300)/300;
    }
    else if (jperjalan >= 600 && jperjalan <900)
    {
        jpersedang = (900-jperjalan)/300;
    }
    else if(jperjalan = 600)
    {
        jpersedang = 1;
    }
    return jpersedang;
}

float jarakjauh(float jperjalan)
{
    float jperjauh = 0;

    if (jperjalan >= 900)
    {
        jperjauh = 1;
    }
    else if (jperjalan >= 600 && jperjalan < 900)
    {
        jperjauh = (jperjalan-600)/300;
    }
    else if(jperjalan <= 600)
    {
        jperjauh = 0;
    }
    return jperjauh;
}

float waktusingkat (float wperjalan)
{
    float wpersingkat = 0;

    if (wperjalan <= 5)
    {
        wpersingkat = 1;
    }
    else if (wperjalan >= 5 && wperjalan < 7)
    {
        wpersingkat = (7-wperjalan)/2;
    }
    else if(wperjalan >= 7)
    {
        wpersingkat = 0;
    }
    return wpersingkat;
}

float waktusedang (float wperjalan)
{
    float wpersedang = 0;

    if(wperjalan <= 5 || wperjalan >= 11)
    {
        wpersedang = 0;
    }
    else if (wperjalan >= 5 && wperjalan<= 7)
    {
        wpersedang = (wperjalan-5)/2;
    }
    else if (wperjalan >9 && wperjalan< 11)
    {
        wpersedang = (11-wperjalan)/2;
    }
    else if( wperjalan >= 7 && wperjalan <=9)
    {
        wpersedang = 1;
    }
    return wpersedang;
}

float waktulama (float wperjalan)
{
    float wperlama = 0;

    if(wperjalan >= 11)
    {
        wperlama = 1;
    }
    else if (wperjalan >= 9 && wperjalan <= 11)
    {
        wperlama = (wperjalan-9)/2;
    }
    else if(wperjalan <= 9)
    {
        wperlama = 0;
    }
    return wperlama;
}

void fuzzifikasi()
{
//Data Biaya Perjalanan
    for(i=0; i<3; i++)
    {
        if(nilaibperjalan[i] > 0)
        {
            cout << endl;
            cout << "Data Biaya Perjalanan\t: "<< databperjalan[i]<< ", dengan NK\t= "<< nilaibperjalan[i];
        }
    }

//Data Waktu Perjalanan
    for (i=0; i<3; i++)
    {
        if(nilaiwperjalan[i] > 0)
        {
            cout << endl;
            cout << "Data Waktu Perjalanan\t: "<< datawperjalan[i]<< ", dengan NK\t = "<< nilaiwperjalan[i];
        }
    }
//Data Jarak Perjalanan
    for(i=0; i<3; i++)
    {
        if(nilaijperjalan[i] > 0)
        {
            cout << endl;
            cout << "Data Jarak Perjalanan\t: "<< datajperjalan[i]<< ", dengan NK\t = "<< nilaijperjalan[i];
        }
    }
}

void inferensi()
{
    for(i=0; i <= 2; i++)
    {
        for(j=0; j <= 2; j++)
        {
            for(k=0; k <= 2; k++)
            {
            //Nilai Kelayakan
                if((nilaibperjalan[i] > 0) && (nilaiwperjalan[j] > 0) && (nilaijperjalan[k] > 0))
                {
                    if((nilaibperjalan[i] <= nilaiwperjalan[j]) && (nilaibperjalan[i] <= nilaijperjalan[k]))
                    {
                        nilaikelayakkan[z] = nilaibperjalan[i];
                    }
                    else if((nilaiwperjalan[j] <= nilaibperjalan[i]) && (nilaiwperjalan[j] <= nilaijperjalan[k]))
                    {
                        nilaikelayakkan[z] = nilaiwperjalan[j];
                    }
                    else
                    {
                        nilaikelayakkan[z] = nilaijperjalan[k];
                    }

                //Rules dan juga Output!!!!
                //Pada saat I=0 & J=0
                    if((i==0) && (j==0) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==0) && (j==0) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==0) && (j==0) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }

                //Pada saat I=0 & J=1
                    else if((i==0) && (j==1) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==0) && (j==1) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==0) && (j==1) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }

                //Pada saat I=0 & J=2
                    else if((i==0) && (j==2) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }
                    else if((i==0) && (j==2) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }
                    else if((i==0) && (j==2) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }


                //Pada saat I=1 & J=0
                    else if((i==1) && (j==0) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==1) && (j==0) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==1) && (j==0) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }



                    //Pada saat I=1 & J=1
                    else if((i==1) && (j==1) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==1) && (j==1) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }
                    else if((i==1) && (j==1) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Kendaraan Umum";
               		}


                    //Pada saat I=1 & J=2
                    else if((i==1) && (j==2) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }
                    else if((i==1) && (j==2) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Kendaraan Umum";
                    }
                    else if((i==1) && (j==2) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Kendaraan Umum";
                    }



                    //Pada saat I=2 & J=0
                    else if((i==2) && (j==0) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }
                    else if((i==2) && (j==0) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }
                    else if((i==2) && (j==0) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Motor";
                    }



                    //Pada saat I=2 & J=1
                    else if((i==2) && (j==1) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }
                    else if((i==2) && (j==1) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }
                    else if((i==2) && (j==1) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Kendaraan Umum";
                    }



                    //Pada saat I=2 & J=2
                    else if((i==2) && (j==2) && (k==0))
                    {
                        datanilaikelayakkan[z] = "Kendaraan Umum";
                    }
                    else if((i==2) && (j==2) && (k==1))
                    {
                        datanilaikelayakkan[z] = "Kendaraan Umum";
                    }
                    else if((i==2) && (j==2) && (k==2))
                    {
                        datanilaikelayakkan[z] = "Mobil";
                    }


                    cout << endl;
                    cout << "Ketika biaya perjalanan \t: " << databperjalan[i] << "\ndengan Waktu yang ditempuh \t: " << datawperjalan[j] << "\ndan jarak tempuh \t\t: " << datajperjalan[k] << "\nmaka nilai kelayakkan jenis kendaraan \t\t: " << datanilaikelayakkan[z] << " dengan nilai \t= " << nilaikelayakkan[z] << endl;
                    z = z + 1;
                }
            }
        }
    }

//Nilai Output
    for(i=0; i <= z; i++)
    {
        if(datanilaikelayakkan[i]=="Motor")
        {
            if(i==0)
            {
                kendaraanA = nilaikelayakkan[i];
            }
            else
            {
                if(nilaikelayakkan[i] > kendaraanA)
                {
                    kendaraanA = nilaikelayakkan[i];
                }
            }
        }
        else if(datanilaikelayakkan[i]=="Mobil")
        {
            if(i==1)
            {
                kendaraanB = nilaikelayakkan[i];
            }
            else
            {
                if(nilaikelayakkan[i] > kendaraanB)
                {
                    kendaraanB = nilaikelayakkan[i];
                }
            }
        }
        else if(datanilaikelayakkan[i]=="Kendaraan Umum")
        {
            if(i==2)
            {
                kendaraanC = nilaikelayakkan[i];
            }
            else
            {
                if(nilaikelayakkan[i] > kendaraanC)
                {
                    kendaraanC = nilaikelayakkan[i];
                }
            }
        }
    }

    cout  << endl;
    cout << "\tFUZZY OUTPUT" << endl;
    cout << "==============================";

    if(kendaraanA > 0)
    {
        cout << endl;
        cout << "Nilai Kelayakan dari Motor = " << kendaraanA << endl;
    }
    if(kendaraanB > 0)
    {
        cout<< endl;
        cout << "Nilai Kelayakan dari Mobil = " << kendaraanB << endl;
    }
    if(kendaraanC > 0)
    {
        cout << endl;
        cout << "Nilai Kelayakan dari Kendaraan Umum = " << kendaraanC << endl;
    }

}


float defuzzifikasi(int sampel, int batas)
{
    float pengaliA, pengaliB, pengaliC;

    float total_pembilang = 0;
    float total_penyebut= 0;

    float kosong;

    float pembilangA = 0;
    float pembilangB = 0;
    float pembilangC = 0;

    float pembilangAnaik = 0;
    float pembilangBturun = 0;

    float hasil;

    int titik_sampel = 0;
    float jumlahA = 0;
    float jumlahB = 0;
    float jumlahC = 0;

    float titik_sampelX[100], titik_sampelY[100];
    int delta = 0;

    z = 0;

    pengaliA = kendaraanA;
    pengaliB = kendaraanB;
    pengaliC = kendaraanC;

    delta = batas / sampel;

    cout << "\tTitik Sampel Yang Diambil" << endl;
    cout << "============================================" << endl;

    for(i=1; i <= sampel; i++)
    {

    titik_sampel = titik_sampel + delta;

    cout << endl;
    cout << "Titik Sampelnya berada pada \t: " << titik_sampel << endl;

    //Pembilang

        if(titik_sampel < 83)
        {
            kosong = (titik_sampel * 0);

            cout << "Nilai Pembilangnya \t\t: " << setprecision(2) << kosong << endl;
        }

        else if((titik_sampel >= 83)  && (titik_sampel <= 127))
        {
            jumlahA = jumlahA + 1;

            cout << "Banyaknya Jumlah \t\t: " << jumlahA <<endl;

            pembilangA = (titik_sampel * pengaliA);

            cout << "Nilai Pembilangnya \t\t: " << setprecision(2) << pembilangA << endl;
        }

        else if((titik_sampel > 127) && (titik_sampel < 154))
        {
            titik_sampelX[z] = titik_sampel;
            titik_sampelX[z] = ((titik_sampelX[z] - 127) / (154 - 127));

            cout << "Nilai Kenaikan \t\t\t: " << setprecision(2) <<  titik_sampelX[z] << endl;

            pembilangAnaik = (titik_sampel * titik_sampelX[z]);

            z = z + 1;

            cout << "Nilai Pembilangnya \t\t: " << setprecision(2) << pembilangAnaik << endl;
        }

        else if((titik_sampel >= 154) && (titik_sampel <= 228))
        {
            jumlahB = jumlahB + 1;

            cout << "Banyaknya Jumlah \t\t: " << jumlahB << endl;

            pembilangB = (titik_sampel * pengaliB);

            cout << "Nilai Pembilangnya \t\t: " << setprecision(2) << pembilangB << endl;
        }

        else if((titik_sampel > 228) && (titik_sampel < 255))
        {
            titik_sampelY[z] = titik_sampel;
            titik_sampelY[z] = ((255 - titik_sampelY[z]) / (255 - 228));

            cout << "Nilai Penurunan \t\t: " << setprecision(4) << titik_sampelY[z] << endl;

            pembilangBturun = (titik_sampel * titik_sampelY[z]);

            z = z +1;

            cout << "Nilai Pembilangnya \t\t: " << pembilangBturun << endl;
        }

        else if((titik_sampel >= 255) && (titik_sampel <= batas))
        {
            jumlahC = jumlahC + 1;

            cout << "Jumlah \t\t\t\t: " << jumlahC << endl;

            pembilangC =(titik_sampel * pengaliC);

            cout << "Nilai Pembilangnya \t\t: " << pembilangC << endl;
        }
    }

    cout << endl;
    cout << "\tHasil Akhir Defuzzifikasi" << endl;
    cout << "=============================================" << endl;

//Pembilang

    total_pembilang = pembilangA + pembilangAnaik + pembilangB + pembilangBturun + pembilangC;

    cout << endl;
    cout << "Total Pembilang \t: " << total_pembilang << endl;

//Penyebut


    total_penyebut = (jumlahA * pengaliA) + (jumlahB * pengaliB) + (jumlahC * pengaliC);

    for(i=1; i <= z; i++)
    {
        total_penyebut = total_penyebut + titik_sampelX[z] + titik_sampelY[z];
    }

    cout << endl;
    cout << "Total Penyebut \t\t: " << total_penyebut << endl;

    hasil = total_pembilang / total_penyebut;

    cout << endl;
    cout << "Maka Hasil Akhir Dari Logika Fuzzy = " << hasil << endl;

    return hasil;
}


int main()
{
    float biaya, waktu, jarak;

    int sampel;
    int batas;
    int pilihan;

    daftar2:

    cout << "\tPenentuan Jenis Kendaraan Untuk Mudik" << endl;
    cout << "=====================================" << endl;
    cout << "Masukan nilai total biaya perjalanan (Juta) \t: ";
    cin >> biaya;
    cout << "Masukan waktu tempuh perjalanan (Jam)\t: ";
    cin >> waktu;
    cout << "Masukan jarak tempuh perjalanan (KM)\t: ";
    cin >> jarak;
    cout << endl << endl;

    //keterangan

    nilaibperjalan[0] = biayamurah(biaya);
    nilaibperjalan[1] = biayasedang(biaya);
    nilaibperjalan[2] = biayamahal(biaya);

    nilaiwperjalan[0] = waktusingkat(waktu);
    nilaiwperjalan[1] = waktusedang(waktu);
    nilaiwperjalan[2] = waktulama(waktu);

    nilaijperjalan[0] = jarakdekat(jarak);
    nilaijperjalan[1] = jaraksedang(jarak);
    nilaijperjalan[2] = jarakjauh(jarak);


    cout << "\tFUZZIFIKASI" << endl;
    cout << "======================" << endl;
    fuzzifikasi();
    cout << endl << endl;

    //Keterangan

    cout << "\tINFERENSI" << endl;
    cout << "======================" << endl;
    inferensi();
    cout << endl << endl;

    daftar1:

    cout << "\tDEFUZZIFIKASI" << endl;
    cout << "========================" << endl;
    cout << "Masukan Jangkauan Sampel \t: ";
    cin >> batas;
    cout << endl;
    cout << "Masukan Banyaknya Sampel \t: ";
    cin >> sampel;
    cout << endl;

    defuzzifikasi(sampel, batas);
    cout << endl<< endl;

    cout << "Running Demo Telah Selesai, Silahkan Pilih List Berikut" << endl;
    cout << "=============================================" << endl;
    cout << "1) Mengganti Batas Dan Sampel" << endl;
    cout << "2) Input Data Kembali" << endl;
    cout << "3) Matikan Program Demo" << endl;
    cout << endl;
    cout << "Silahkan Pilih \t: ";
    cin >> pilihan;

    if(pilihan == 1)
    {

        goto daftar1;
    }
    else if(pilihan == 2)
    {

        goto daftar2;
    }
    else
    {
        cout << "\tTerima Kasih Telah Menggunakan Program Ini, Sekian Dan Terima Kasih" << endl;
        cout << "====================================================================================" << endl;
    }
    return 0;
}
