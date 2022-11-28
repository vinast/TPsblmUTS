#include <iostream>
#include "admin.h"
#include "Login.h"
#include "user.h"

using namespace std;

int main()
{
  //cek
    cout << "----------------------------------------------" << endl;
    cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    cout << "|\t\t\t\tPosyandu Bahagia \t\t\t |" << endl;
    cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;

    Admin adm;
    User usr;

awal:
    lo.mainLogin();
    if (lo.isLogin() == true)
    {
        if (lo.isAdmin() == true)
        {
            // cout << " admin.h";
            // system("cls");
            system("clear"); // replit
            cout << "----------------------------------------------" << endl;
            cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
            cout << "|\t\t\t\tPosyandu Bahagia \t\t\t |" << endl;
            cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
            cout << "----------------------------------------------" << endl
                 << endl;
            cout << "Selamat Datang Admin => " << toLogin[lo.no].namatxt
                 << endl;
            cin.ignore();
            cout << endl;
            cout << "Tekan Enter Untuk Melanjutkan ⏎ ";
            getchar();

        // panggil isi library admin.h
        awalAdmin:
            adm.menu();
            if (adm.pilih == 1)
            {
                system("clear");
                adm.tambahdata();
                if (adm.konfirm == 'y' || adm.konfirm == 'y')
                {
                    system("clear");
                    goto awalAdmin;
                }
            }
            else if (adm.pilih == 2)
            {
                system("clear");
                adm.lihatdataDinamis();
                if (adm.konfirm == 'y' || adm.konfirm == 'y')
                {
                    system("clear");
                    goto awalAdmin;
                }
            }
            else if (adm.pilih == 3)
            {
                system("clear");
                adm.hapusdata();
                if (adm.konfirm == 'y' || adm.konfirm == 'y')
                {
                    system("clear");
                    goto awalAdmin;
                }
            }
            else if (adm.pilih == 4)
            {
                system("clear");
                adm.tambahdataBalita();
                //adm.hapusdata();
                if (adm.konfirm == 'y' || adm.konfirm == 'y')
                {
                    system("clear");
                    goto awalAdmin;
                }
            }
              else if (adm.pilih == 5)
            {
                system("clear");
                adm.LihatdataBalita();
                //adm.hapusdata();
                if (adm.konfirm == 'y' || adm.konfirm == 'y')
                {
                    system("clear");
                    goto awalAdmin;
                }
            } 
            else if (adm.pilih == 6)
            {
                
                adm.hapusdataBalita();
                if (adm.konfirm == 'y' || adm.konfirm == 'y')
                {
                    system("clear");
                    goto awalAdmin;
                }
            }     
            else
            {
                goto akhir;
            }
        }
        else
        {
            // cout << " user.h";
            // system("cls");
            system("clear"); // replit
            cout << "----------------------------------------------" << endl;
            cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
            cout << "|\t\t\t\tPosyandu Bahagia \t\t\t |" << endl;
            cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "\nSelamat Datang User => " << toLogin[lo.no].namatxt
                 << endl;
            cin.ignore();
            cout << " \nTekan Enter Untuk Melanjutkan ⏎ ";
            getchar();

          awalUser:
            usr.Menu();
            if (usr.pilihusr == 1)
            {
                system("clear");
                usr.MenuTampilData();
                  if(usr.pilihtampil== 1){
                    system("clear");
                    usr.TampilBalitaDinamis();
                    if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                {
                    system("clear");
                    goto awalUser;
                }
                
                }
                  else if(usr.pilihtampil == 2 ){
                    system("clear");
                    usr.lihatdataBlt();
                    if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                  {
                    system("clear");
                    goto awalUser;
                  }
                    else {
                      goto akhir;
                    }
              }
                
                
            }
            else if (usr.pilihusr == 2)
            {
              
        Beli:
            usr.Beli();
            cout << endl;
            char backUser;
            cout << "Apakah Anda Ingin Membeli Lagi? [y/n] ";
            cin >> backUser;
            if (backUser == 'y' || backUser == 'Y')
            {
                system("clear");
                goto Beli;
            }
            else
            {
                cout << endl;
                cout << "\nTekan Enter Untuk Melihat Keranjang Anda ⏎ ";
                cin.ignore();
                getchar();

                system("clear");
                goto Keranjang;
            }
            cout << "----------------------------------------------" << endl;
        Keranjang:
            // Lihat Daftar Keranjang
            usr.lihat();
            char backKer;
            // cout << "Apakah Anda Ingin Melihat Keranjang\nAnda Lagi ? [y/n] ";
            // cin >> backKer;
            // if (backKer == 'y' || backKer == 'Y'){
            //   system("clear");
            //   goto Keranjang;
            // }
            // else {

            cout << endl;
            // system("clear");
            goto akhir;
            //}
        }
    }
      }
    else
    {
        // system("cls");
        system("clear"); // replit
        cout << "\nUsername Atau NIK Tidak Terdaftar!!!";
        cout << "\nTekan Enter Untuk Login Kembali ⏎ " << endl;
        cout << "----------------------------------------------" << endl;
        cin.ignore();
        getchar();
        goto awal;
    }

akhir:
    cout << "\nTekan Enter Untuk Keluar ⏎ ";
    cin.ignore();
    getchar();
    cout << "\n----------------------------------------------" << endl;
    cout << "\t\t\t\tTerimakasih..." << endl;
    cout << "----------------------------------------------" << endl;
    return 0;
}