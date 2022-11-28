#include "array1d.h"
#include "barang.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

struct Balita {
  string namaBal, ibBal;
  int tingBal, bertBal;
} blt[1000];

class Admin {
public:
  Array1D<barang> X;
  int toInt(string x) {
    int y;

    stringstream ss;
    ss << x;
    ss >> y;

    return y;
  }





void tokenizeBB(string sb, string delb = " ", int idxb = 0) {
    string tmpb;
    int i = 1;
    int startb, endb = -1 * delb.size();
    do {
      startb = endb + delb.size();
      endb = sb.find(delb, startb);
      tmpb = sb.substr(startb, endb - startb);

      if (i == 1) {
        blt[idxb].namaBal = tmpb;

      } else if (i == 2) {
        blt[idxb].ibBal = tmpb;
      } else if (i == 3) {
        blt[idxb].tingBal = toInt(tmpb);
      } else {
        blt[idxb].bertBal = toInt(tmpb);
      }
      i++;

    } while (endb != -1);
  }





  void LihatdataBalita() {
    int idxb = 0;
    string tb;
    ambilb.open("dataBalita.txt");

    while (!ambilb.eof()) {
      ambilb >> tb;
      tokenizeBB(tb, ";", idxb);
      idxb++;
      
    }
    ambilb.close();
    for (int s = 0; s < idxb-1; s++) {
      cout << "----------------------------------------------" << endl;
      cout << " Nama Balita       :  " << blt[s].namaBal <<endl ;
      cout << " Nama Ibu          : " << blt[s].ibBal<<endl;
      cout << " Tinggi Balita     : " << blt[s].tingBal<<endl;
      cout << " Berat Balita      : " << blt[s].bertBal<<endl;
      cout << "----------------------------------------------" << endl;
    }
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirm;
  }





  void ambildataDinamis() {
    int idx = 0;
    string t;
    ambil.open("data.txt");
    while (!ambil.eof()) {
      ambil >> t;
      tokenize(t, ";", idx);
      idx++;
      // X.ReSize(idx);
    }
    ambil.close();
    // Array1D<barang> X(idx);
    X.ReSize(idx);
    for (int i = 0; i < idx; i++) {
      barang tambah(brg[i].id, brg[i].nama, brg[i].stok, brg[i].harga);
      X[i] = tambah;
    }
    cout << X;
  }





  void tokenize(string s, string del = " ", int idx = 0) {
    string tmp;
    int i = 1;
    int start, end = -1 * del.size();
    do {
      start = end + del.size();
      end = s.find(del, start);
      tmp = s.substr(start, end - start);

      if (i == 1) {
        brg[idx].id = tmp;

      } else if (i == 2) {
        brg[idx].nama = tmp;
      } else if (i == 3) {
        brg[idx].stok = toInt(tmp);
      } else {
        brg[idx].harga = toInt(tmp);
      }
      i++;

    } while (end != -1);
  }

  int menu();
  void tambahdata();
  void tambahdataBalita();
  void hapusdataBalita();
  void lihatdataDinamis();
  void hapusdata();
  int pilih;
  char konfirm;



private:
  string id, nama;
  int harga, stok;
  string namaBalita, ibu;
  int tinggi, berat;
  ofstream tulis;
  ifstream ambil;
  ofstream tulisb;
  ifstream ambilb;
  int size, loc;
  string DataBalita[1000];
  barang *brg = new barang[1000];
};






void Admin::tambahdataBalita() {
  int ssx;
  tulisb.open("dataBalita.txt", ios::app);
  cout << endl;
  cout << "Berikut Tambah Data Balita Posyandu Bahagia..." << endl;
  cout << endl;
  cout << "Silahakan Tambah Data Balita..." << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Ingin Menanbah Berapa Data : ";
  cin >> ssx;
  for (int z = 0; z < ssx; z++) {
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan Nama Balita           : ";
    cin >> namaBalita;
    cout << "Masukkan Nama Ibu              : ";
    cin >> ibu;
    cout << "Masukkan Tinggi Balita         : ";
    cin >> tinggi;
    cout << "Masukkan Berat badan Balita    : ";
    cin >> berat;
    cout << "----------------------------------------------" << endl;
    tulisb << namaBalita << ";" << ibu << ";" << tinggi << ";" << berat << endl;
  }
  tulisb.close();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}






void Admin::hapusdataBalita() {
  int idxb = 0;
    string tb;
    ambilb.open("dataBalita.txt");

    while (!ambilb.eof()) {
      ambilb >> tb;
      tokenizeBB(tb, ";", idxb);
      idxb++;
      
    }
    ambilb.close();
    for (int s = 0; s < idxb-1; s++) {
      cout << "----------------------------------------------" << endl;
      cout << " Nama Balita       : " << blt[s].namaBal <<endl ;
      cout << " Nama Ibu          : " << blt[s].ibBal<<endl;
      cout << " Tinggi Balita     : " << blt[s].tingBal<<endl;
      cout << " Berat Balita      : " << blt[s].bertBal<<endl;
      cout << "----------------------------------------------" << endl;
    }
  string pilihnama;
  bool ketemu;
  int datake;
  cout << endl << endl;
  cout << "Silahkan Pilih Nama Balita Yang Ingin DiHapus : ";
  cin >> pilihnama;
  for (int i = 0; i < idxb-1; i++) {
    if (pilihnama == blt[i].namaBal) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu) {
    ofstream tulis;
    tulis.open("dataBalita.txt");
    for (int i = 0; i < idxb - 1; ++i) {
      if (i != datake) {
        tulis << blt[i].namaBal << ";" << blt[i].ibBal << ";" << blt[i].tingBal << ";"<< blt[i].bertBal << endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "Data Balita Yang Anda Pilih Berhasil Di Hapus " << endl;
    cout << "----------------------------------------------" << endl;
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}






void Admin::tambahdata() {
  int sz;
  tulis.open("data.txt", ios::app);
  cout << endl;
  cout << "Berikut Tambah Data Vaksin Posyandu Bahagia..." << endl;
  cout << endl;
  cout << "Silahakan Tambah Data Vaskin..." << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Ingin Menanbah Berapa data : ";
  cin >> sz;
  for (int z = 0; z < sz; z++) {
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan ID          : ";
    cin >> id;
    cout << "Masukkan Nama Vaskin : ";
    cin >> nama;
    cout << "Masukkan Stok        : ";
    cin >> stok;
    cout << "Masukkan Harga       : ";
    cin >> harga;
    cout << "----------------------------------------------" << endl;
    tulis << id << ";" << nama << ";" << stok << ";" << harga << endl;
  }
  tulis.close();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}






void Admin::lihatdataDinamis() {
  ambildataDinamis();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}






void Admin::hapusdata() {
  int idx = 0;
  string t;
  ambil.open("data.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenize(t, ";", idx);
    idx++;
  }
  // ambildataDinamis();
  for (int i = 0 ; i<idx-1;i++){
    cout << "----------------------------------------------" << endl;
    cout << "ID      : " << brg[i].id << endl;
    cout << "nama    : " << brg[i].nama << endl;
    cout << "stok    : " << brg[i].stok << endl;
    cout << "harga   : " << brg[i].harga << endl;
    cout << "----------------------------------------------" << endl;
  }
  string pilihid;
  bool ketemu;
  int datake;
  cout << endl << endl;
  cout << "Silahkan Pilih (ID) Data Yang Ingin DiHapus : ";
  cin >> pilihid;
  for (int i = 0; i < idx-1; i++) {
    if (pilihid == brg[i].id) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu) {
    ofstream tulis;
    tulis.open("data.txt");
    for (int i = 0; i < idx-1; ++i) {
      if (i != datake) {
        tulis << brg[i].id << ";" << brg[i].nama << ";" << brg[i].stok << ";"<< brg[i].harga << endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "ID Vaksin Yang Anda Pilih Berhasil Di Hapus " << endl;
    cout << "----------------------------------------------" << endl;
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}





int Admin::menu() {

  cout << endl;
  cout << "|------------------Menu Admin-----------------|" << endl;
  cout << "| \t\t\t\t\t\t\t\t\t\t\t  |" << endl;
  cout << "| Main Menu Posyandu Bahagia\t\t\t\t  |" << endl;
  cout << "| 1. Tambah Data Vaskin\t\t\t\t\t\t  |" << endl;
  cout << "| 2. Lihat Data Vaksin \t\t\t\t\t\t  |" << endl;
  cout << "| 3. Hapus Data Vaksin\t\t\t\t\t\t  |" << endl;
  cout << "| 4. Tambah Data Balita\t\t\t\t\t\t  |" << endl;
  cout << "| 5. Lihat Data Balita\t\t\t\t\t\t  |" << endl;
  cout << "| 6. Hapus Data Balita\t\t\t\t\t\t  |" << endl;
  cout << "| 7. Keluar \t\t\t\t\t\t\t      |" << endl;
  cout << "| \t\t\t\t\t\t\t\t\t\t\t  |" << endl;
  cout << "|------------------Menu Admin-----------------|" << endl;
  cout << "Masukkan Pilihan[1/2/3/4/5/6/7 ] : ";
  cin >> pilih;
  return pilih;
}