#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct KTP
{
    string namatxt = "admin";
    string niktxt = "1";
    string provtxt;
} toLogin[10];

class Login
{
private:
    // pengubah status
    bool statusAdmin = false;
    bool statusLogin = false;
    int indeks;
    string inputnama;
    string inputnik;
    string inputnamaL;
    string inputnikL;
    string provinput;

public:
    void tokenize(string s, string del = " ", int idx = 0)
    {
        string tmp;
        int i = 1;
        int start, end = -1 * del.size();
        do
        {
            start = end + del.size();
            end = s.find(del, start);
            tmp = s.substr(start, end - start);

            if (i == 1)
            {
                toLogin[idx].namatxt = tmp;
            }
            else if (i == 2)
            {
                toLogin[idx].niktxt = tmp;
            }
            else
            {
                toLogin[idx].provtxt = tmp;
            }
            i++;

        } while (end != -1);
    }

    void tulisKTP();
    void ambilKTP();
    void mainLogin();
    bool isLogin();
    bool isAdmin();
    int no;
} lo;

bool Login::isLogin() { return statusLogin; }

bool Login::isAdmin() { return statusAdmin; }

void Login::mainLogin()
{
    cout << "\nSilahkan Login Terlebih Dahulu...!" << endl;
    // ambiltoLogin
    ambilKTP();
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan Username    : ";
    cin >> inputnamaL;
    cout << "Masukkan NIK Anda    : ";
    cin >> inputnikL;
    cout << "----------------------------------------------" << endl;

    if (toLogin[0].namatxt == inputnamaL && toLogin[0].niktxt == inputnikL)
    {
        statusLogin = true;
        no = 0;
        statusAdmin = true;
    }
    else if (toLogin[1].namatxt == inputnamaL && toLogin[1].niktxt == inputnikL)
    {

        statusLogin = true;
        no = 1;
        ofstream tulis;

        tulis.open("dataLogin.txt");
        tulis << toLogin[no].niktxt << ";" << toLogin[no].namatxt << ";" << toLogin[no].provtxt;

        tulis.close();
        statusAdmin = false;
    }
    else if (toLogin[2].namatxt == inputnamaL && toLogin[2].niktxt == inputnikL)
    {

        statusLogin = true;
        no = 2;
        ofstream tulis;

        tulis.open("dataLogin.txt");
        tulis << toLogin[no].niktxt << ";" << toLogin[no].namatxt << ";" << toLogin[no].provtxt;

        tulis.close();
        statusAdmin = false;
    }
    else
    {
        statusLogin = false;
    }
}





void Login::tulisKTP()
{
    ofstream writedata;
    writedata.open("ktp.txt");

    cout << "Masukkan Username       : ";
    cin >> inputnama;
    cout << "Masukkan NIK Anda       : ";
    cin >> inputnik;
    cout << "Masukkan Alamat Anda    : ";
    cin >> provinput;

    if (!writedata.fail())
    {
        writedata << inputnama << ";" << inputnik << ";" << provinput;
        writedata.close();
        cout << "Sukses" << endl;
    }
    else
    {
        cout << "Error!!!! ";
    }
}

void Login::ambilKTP()
{


    ifstream readData;
    // string t;

    int idx = 0;
    string t;
    readData.open("ktp.txt");
    while (!readData.eof())
    {
        readData >> t;
        tokenize(t, ";", idx);
        idx++;
    }
    readData.close();

    // readData.open("ktp.txt");
    // if (!readData.fail())
    // {
    //     // cout << " \n Bisa open ktp.txt " <<endl;

    //     indeks = 0;
    //     bool ceknik;
    //     ceknik = true;
    //     while (!readData.eof())
    //     {

    //         if (ceknik)
    //         {
    //             readData >> toLogin[indeks].niktxt;

    //             ceknik = false;
    //         }

    //         else
    //         {
    //             readData >> toLogin[indeks].namatxt;
    //             ceknik = true;
    //             indeks++;
    //         }
    //     }
    //     readData.close();
    // }
    // else
    // {
    //     cout << " \nerror " << endl;
    // }

    // test 02
    // cout << endl;
    //   cout << " isi namatxt[0] : " << toLogin[0].namatxt << endl;
    //   cout << " isi niktxt[0]  : " << toLogin[0].niktxt << endl;
    //   cout << " isi provtxt[0] : " << toLogin[0].provtxt << endl;
    // cout << " isi namatxt[0] : " << toLogin[1].namatxt << endl;
    //   cout << " isi niktxt[0]  : " << toLogin[1].niktxt << endl;
    //   cout << " isi provtxt[0] : " << toLogin[1].provtxt << endl;
    // cout << " isi namatxt[1] : " << toLogin[1].namatxt << endl;
    // cout << " isi niktxt[1]  : " << toLogin[1].niktxt << endl;
}