#include <iostream>
#include <string>
using namespace std;

class balita
{
public:
    balita(string NAMA = "", string IBU = "", int TINGGI = 0, int BERAT = 0)
    {
        namaBalita = NAMA;
        ibu = IBU;
        tinggi = TINGGI;
        berat = BERAT;
    }

    double tinggi, berat;
    string namaBalita, ibu;
};