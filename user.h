#include "KTP.h"
#include "Transaksi.h"
#include "linklist.h"
#include "ArrayDinamisBalita.h"
#include "doublell.h"
#include "balita.h"

#include <fstream>
#include <iostream>
#include <sstream>


// #include "Login.h"
using namespace std;

class User
{
public:

    List<Transaksi> x;
    DinamisBalita<balita> G;
    DoubleLinkedList Z[1000];

    int toInt(string x)
    {
        int y;

        stringstream ss;
        ss << x;
        ss >> y;

        return y;
    }

    void tokenizez(string sz, string delz = " ")
    {
        string tmpz;
        int i = 1;
        int startz, end = -1 * delz.size();
        do
        {
            startz = end + delz.size();
            end = sz.find(delz, startz);
            tmpz = sz.substr(startz, end - startz);

            if (i == 1)
            {
                dataKTP.nik = tmpz;
            }
            else if (i == 2)
            {
                dataKTP.nama = tmpz;
            }
            else
            {
                dataKTP.prov = tmpz;
            }
            i++;

        } while (end != -1);
    }





void tokenizee(string se, string dele = " ", int idxe = 0)
    {

        string tmpe;
        int i = 1;
        int starte, ende = -1 * dele.size();
        do
        {
            starte = ende + dele.size();
            ende = se.find(dele, starte);
            tmpe = se.substr(starte, ende - starte);

            if (i == 1)
            {
                brggu[idx].id = tmpe;
            }
            else if (i == 2)
            {
                brggu[idx].nama = tmpe;
            }
            else if (i == 3)
            {
                brggu[idx].stok = toInt(tmpe);
            }
            else if (i == 4)
            {
                brggu[idx].harga = toInt(tmpe);
            }
            else if (i == 5)
            {
                brggu[idx].jumlah = toInt(tmpe);
            }
            else
            {
                brggu[idx].total = toInt(tmpe);
            }
            i++;

        } while (ende != -1);
    }





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
                brgg[idx].id = tmp;
            }
            else if (i == 2)
            {
                brgg[idx].nama = tmp;
            }
            else if (i == 3)
            {
                brgg[idx].stok = toInt(tmp);
            }
            else
            {
                brgg[idx].harga = toInt(tmp);
            }
            i++;

        } while (end != -1);
    }





void ambildatabeli()
    {
        idx = 0;
        string t;
        ambil.open("daftarBelanja.txt");
        while (!ambil.eof())
        {
            ambil >> t;
            tokenizee(t, ";", idx);
            idx++;
        }
        ambil.close();
    }





void ambildatabrg()
    {
        idx = 0;
        string t;
        ambil.open("data.txt");
        while (!ambil.eof())
        {
            ambil >> t;
            tokenize(t, ";", idx);
            idx++;
        }
        ambil.close();
    }

    void Menu();
    void MenuTampilData();
    void TampilBalitaDinamis();
    void tampil();
    void Beli();
    void lihat();
    void cetakinvoice();
    void ambildataLogin();
    void syaratBeli();
    bool sttsBeli = false;
    KTP2 dataKTP;
    int pilihusr,pilihtampil;
    char konfirmasi;





void tokenizeBlt(string s, string del = " ", int idx = 0)
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
                blt[idx].namaBalita = tmp;
            }
            else if (i == 2)
            {
                blt[idx].ibu = tmp;
            }
            else if (i == 3)
            {
                blt[idx].tinggi = toInt(tmp);
            }
            else
            {
                blt[idx].berat = toInt(tmp);
            }
            i++;

        } while (end != -1);
    }


    

void ambildataDinamisBlt()
    {    
        // DinamisBalita<balita> X;
        int idxx = 0;
        batas = 0;
        string t;
        ambil.open("dataBalita.txt");
        while (!ambil.eof())
        {
            ambil >> t;
            tokenizeBlt(t, ";", idxx);
            idxx++;
            // X.ReSize(idx);
        }
        ambil.close();
        batas = idxx;
        // X.ReSize(idxx);
        G.ReSize(idxx);
      for (int i = 0; i < idxx; i++)
        {
            balita tambah(blt[i].namaBalita, blt[i].ibu, blt[i].tinggi, blt[i].berat);
            G[i] = tambah;
        }  
    }




void ambilLinklist(){
    int idxx = 0;
        // batas = 0;
        string t;
        ambil.open("dataBalita.txt");
        while (!ambil.eof())
        {
            ambil >> t;
            tokenizeBlt(t, ";", idxx);
            idxx++;
            // X.ReSize(idx);
        }
        ambil.close();
    // ambildataDinamisBlt();
    Z->inisialisasi();
    for (int i = 0;i<idxx; i++){
      
      Z->inputData(blt[i].namaBalita, blt[i].ibu, blt[i].tinggi, blt[i].berat);
      } 
  }





void lihatdataBlt(){
  //cout<< Y <<endl;
  // ambildataDinamisBlt();
  ambilLinklist();
  Z->tampilData();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;
  // Z.cetak();
}





void tambahdataBlt()
{
    int sz;
    tulis.open("dataBalita.txt", ios::app);
    cout<<endl;
    cout <<"Berikut Tambah Data Balita Posyandu Bahagia..."<<endl;
    cout<<endl;
    cout<<"Silahakan Tambah Data Balita..."<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Ingin Menanbah Berapa data : ";
    cin >> sz;
    for (int z = 0; z < sz; z++)
    {
        cout<<"----------------------------------------------"<<endl;
        cout << "Masukkan Nama Balita          : ";
        cin >> namaBalita;
        cout << "Masukkan Nama Ibu  : ";
        cin >> ibu;
        cout << "Masukkan Tinggi Balita        : ";
        cin >> tinggi;
        cout << "Masukkan Berat badan Balita       : ";
        cin >> berat;
        cout<<"----------------------------------------------"<<endl;
        tulis << namaBalita << ";" << ibu << ";" <<tinggi << ";" << berat << endl;
    }
    tulis.close();
  }
   
    //LLBalita<balita> Y;
    // doubleLL<balita> Z;
    // DoubleLinkedList Z[1000];

    balita *blt = new balita[1000];
    string namaBalita, ibu;
    double tinggi, berat;

    

private:
    string nikbeli;
    int idx, idxe, pilih,batas;
    int totbayar, jumbayar;
    Transaksi *brgg = new Transaksi[1000];
    Transaksi *brggu = new Transaksi[1000];
    // string dataKTP[1000];
    ofstream tulis;
    ifstream ambil;
};





void User::MenuTampilData(){
  
    cout<<endl;
    cout<<"|--------------Menu Data Balita---------------|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t  |"<<endl;
    cout<<"| Menu Tampil Data Balita\t\t\t\t\t  |"<<endl;
    cout<<"| 1. Secara Dinamis\t\t\t\t\t\t\t  |"<<endl;
    cout<<"| 2. Pakai Linklist\t\t\t\t\t\t\t  |"<<endl;
    cout<<"| 3. Keluar \t\t\t\t\t\t\t\t  |"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t  |"<<endl;
    cout<<"|--------------Menu Data Balita---------------|"<<endl;
    cout<<"Masukkan Pilihan[1/2/3] : ";
    cin >> pilihtampil;
  
}





void User::ambildataLogin()
{

    // ifstream ambil;

    // idxe = 0;
    string t;
    ambil.open("dataLogin.txt");
    while (!ambil.eof())
    {
        ambil >> t;
        tokenizez(t, ";");
        // idxe++;
    }
    ambil.close();
}





void User :: TampilBalitaDinamis(){
  ambildataDinamisBlt();
  cout << G <<endl;
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmasi;
}

// void User::syaratBeli() {
// awals:
//   ambildataLogin();
//   cout<<endl;
//   cout<<"Mohon maaf, Silakan Masukkan Nik Anda Kembali Untuk Pendataan..."<<endl;
//   cout << "Masukkan Nik Anda  : ";
//   cin >> nikbeli;
//   cout << "----------------------------------------------" << endl;
//   for (int i = 1; i < idxe; i++) {
//      //cout<< dataKTP[i].nik<<endl;
//     if (nikbeli == dataKTP[i].nik) {
//       cout << "Nik Terdaftar, Silahkan Lanjut..." << endl;
//       // system("claer"); // claer nya gabisa
//       sttsBeli = true;
//       // Beli();
//       break;
//     } else {
//       // system clear
//       cout << "Nik Tidak Terdaftar, Silahkan Ulangi!!!" << endl;
//       // system("claer"); // claernya gabisa
//       goto awals;
//     }
//   }
// }

void User::Menu()
{
    cout<<endl;
    cout<<"|------------------Menu User------------------|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t  |"<<endl;
    cout<<"| Main Menu User Posyandu Bahagia\t\t\t  |"<<endl;
    cout<<"| 1. Lihat Data Balita\t\t\t\t\t\t  |"<<endl;
    cout<<"| 2. Lihat Data Vaksin\t\t\t\t\t\t  |"<<endl;
    cout<<"| 3. Keluar \t\t\t\t\t\t\t\t  |"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t  |"<<endl;
    cout<<"|------------------Menu User------------------|"<<endl;
    cout<<"Masukkan Pilihan[1/2/3] : ";
    cin >> pilihusr;
}





void User::tampil()
{
    // ambildataLogin();
    cout << endl;
    // nikbeli = dataKTP.nik;
    // cout << dataKTP.nik <<endl;
    cout << "-------------Vaksin Yang Tersedia-------------" << endl;
    ambildatabrg();
    for (int i = 0; i < idx - 1; i++)
    {
        cout << "----------------------------------------------" << endl;
        cout << "ID Vaksin    : " << brgg[i].id << endl;
        cout << "Nama Vaksin  : " << brgg[i].nama << endl;
        cout << "Stok Vakin   : " << brgg[i].stok << endl;
        cout << "Harga Vaksin : " << brgg[i].harga << endl;
        cout << "----------------------------------------------" << endl;
    }
}





void User::Beli()
{
daftar:
    tampil();
    ambildataLogin();
    int jumlah;
    string masuk;
    bool ketemu;
    int datake;
    cout << endl;
    cout << "Masukkan ID Vaksin Yang Ingin Di Beli  : ";
    cin >> masuk;
    for (int i = 0; i < idx - 1; i++)
    {
        if (masuk == brgg[i].id)
        {
            ketemu = true;
            datake = i;
            break;
        }
    }
    // nik , if
    if (ketemu)
    {
        cout << "Masukkan Jumlah Yang Ingin di Beli     : ";
        cin >> jumlah;
        cout << "----------------------------------------------" << endl;
        brgg[datake].stok = brgg[datake].stok - jumlah;
        int total = brgg[datake].harga * jumlah;
        tulis.open("data.txt");
        for (int i = 0; i < idx - 1; i++)
        {
            tulis << brgg[i].id << ";" << brgg[i].nama << ";" << brgg[i].stok << ";"
                  << brgg[i].harga << endl;
        }
        tulis.close();

        tulis.open("daftarBelanja.txt", ios::app);
        for (int i = 0; i < idx - 1; i++)
        {
            if (i == datake)
            {

                tulis << brgg[i].id << ";" << brgg[i].nama << ";" << brgg[i].stok << ";"
                      << brgg[i].harga << ";" << jumlah << ";" << total << endl;
            }
        }
        tulis.close();
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Barang Anda Berhasil Di Tambah Ke Keranjang... " << endl;
    cout << "----------------------------------------------" << endl;
    // char p;
    // cout << "Apakah Anda Ingin Belanja Lagi? [y/n] : ";
    // cin >> p;
    // if (p == 'y' || p == 'Y')
    // {
    //     goto daftar;
    // }
}





void User::lihat()
{
    ambildatabeli();
    // int totbayar;
    totbayar = 0;
    for (int i = 0; i < idx - 1; i++)
    {
        Transaksi transaksiN(brggu[i].id, brggu[i].nama, brggu[i].stok,
                             brggu[i].harga, brggu[i].jumlah, brggu[i].total);
        totbayar += brggu[i].total;
        x.sisipBelakang(transaksiN);
    }
    cout << endl;
    cout << "--------Berikut Keranjang Belanja Dari--------" << endl;
    // nikbeli = dataKTP.nik;
    // for (int i = 1; i < idxe-1; i++) {
    //   if (nikbeli == dataKTP[i].nik) {
    //     cout << "NIK : "<< dataKTP[i].nik << endl;
    //     }
    //   }
    cout << endl;
    cout << "                            Tn/ny : " << dataKTP.nama << endl;
    cout << "----------------------------------------------" << endl;
    cout << "ID \tNAMA BARANG\t    HARGA\tJUMLAH\t TOTAL " << endl;
    cout << "----------------------------------------------" << endl;
    cout << x;
    cout << "----------------------------------------------" << endl
         << endl;
    cout << "Total Belanjaan Yang Harus DiBayar : " << totbayar << endl;
    cout << "\n";
    cout << "----------------------------------------------" << endl;
    cout << "Lakukan Pembayaran Dan Cetak Invoice... " << endl;
    cout << "Tekan Enter Untuk Lanjut ⏎ ";
    getchar();
    cout << "----------------------------------------------" << endl;
    cetakinvoice();
}





void User::cetakinvoice()
{
    cout << "\n";
pembayaran:
    cout << "Masukkan Jumlah Bayar Anda : ";
    cin >> jumbayar;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\t\t\t   Pembayaran Berhasil " << endl;
    cout << "\t\t   Terima Kasih Telah Berbelanja" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Enter Untuk Liat Struck Belanja ⏎ ";
    cin.ignore();
    getchar();
    system("clear");

    if (jumbayar < totbayar)
    {
        cout << "Uang Anda Tidak Cukup, Silahkan Coba Lagi!" << endl;
        cout << "----------------------------------------------" << endl;
        goto pembayaran;
    }
    else
    {
        tulis.open("struck.txt");
        tulis << "----------------------------------------------" << endl;
        tulis << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t |" << endl;
        tulis << "|\t\t\t\t\t\t\t\tPosyandu Bahagia \t\t\t\t\t\t |" << endl;
        tulis << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t |" << endl;
        tulis << "----------------------------------------------" << endl;
        // for (int i = 1; i < idxe-1; i++) {
        //  if (nikbeli == dataKTP[i].nik) {
        tulis << "| NIK    : " << dataKTP.nik << endl;
        tulis << "| Nama   : " << dataKTP.nama << endl;
        tulis << "| Alamat : " << dataKTP.prov << endl;
        //    }
        // }
        // disini nama user yg belanja
        tulis << "----------------------------------------------" << endl;
        tulis << "ID\tNAMA BARANG\t  HARGA\t JUMLAH\t TOTAL " << endl;
        tulis << "----------------------------------------------" << endl;
        tulis << x;
        tulis << "----------------------------------------------" << endl;
        tulis << "| Total Yang Harus Dibayar         : " << totbayar << endl;
        tulis << "| Yang dibayarkan                  : " << jumbayar << endl;
        if (jumbayar > totbayar)
        {
            int kembalian = jumbayar - totbayar;
            tulis << "| Kembalian                        : " << kembalian << endl;
        }
        tulis << "----------------------------------------------" << endl;
        tulis << "  TERIMA KASIH TELAH MELAKUKAN TRANSAKSI" << endl;
        tulis << "----------------------------------------------" << endl;
        tulis.close();
    }

    cout << "----------------------------------------------" << endl;
    cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    cout << "|\t\t\t\tPosyandu Bahagia \t\t\t |" << endl;
    cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    cout << "----------------------------------------------" << endl;
    // for (int i = 1; i < idxe-1; i++) {
    //   if (nikbeli == dataKTP[i].nik) {
    cout << "| NIK    : " << dataKTP.nik << endl;
    cout << "| Nama   : " << dataKTP.nama << endl;
    cout << "| Alamat : " << dataKTP.prov << endl;
    //   }
    // }
    // disini nama user yg belanja
    cout << "----------------------------------------------" << endl;
    cout << "ID\tNAMA BARANG\t  HARGA\t JUMLAH\t TOTAL " << endl;
    cout << "----------------------------------------------" << endl;
    cout << x;
    cout << "----------------------------------------------" << endl;
    cout << "| Total Yang Harus Dibayar          : " << totbayar << endl;
    cout << "| Yang dibayarkan                   : " << jumbayar << endl;
    if (jumbayar > totbayar)
    {
        int kembalian = jumbayar - totbayar;
        cout << "| Kembalian                         : " << kembalian << endl;
    }
    cout << "----------------------------------------------" << endl;
    cout << "  TERIMA KASIH TELAH MELAKUKAN TRANSAKSI" << endl;
    cout << "----------------------------------------------" << endl;

    tulis.open("daftarBelanja.txt");
    tulis << "";
    tulis.close();
}