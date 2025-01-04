#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    double nilai;
};

vector<Mahasiswa> dataMahasiswa;

void tambahData() {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; ++i) {
        Mahasiswa mhs;
        cout << "Masukkan NIM: ";
        cin >> mhs.nim;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, mhs.nama);
        cout << "Masukkan Nilai Akhir: ";
        cin >> mhs.nilai;
        dataMahasiswa.push_back(mhs);
    }
}

void tampilkanData() {
    if (dataMahasiswa.empty()) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }

    for (const auto& mhs : dataMahasiswa) {
        cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai Akhir: " << mhs.nilai << endl;
    }
}

void cariData() {
    string nim;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nim;

    for (const auto& mhs : dataMahasiswa) {
        if (mhs.nim == nim) {
            cout << "Data ditemukan:" << endl;
            cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai Akhir: " << mhs.nilai << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan." << endl;
}

void urutkanData() {
    sort(dataMahasiswa.begin(), dataMahasiswa.end(), [](Mahasiswa a, Mahasiswa b) {
        return a.nilai > b.nilai;
    });
    cout << "Data berhasil diurutkan berdasarkan nilai akhir secara menurun." << endl;
}

void simpanKeFile() {
    ofstream file("dataMahasiswa.txt");
    for (const auto& mhs : dataMahasiswa) {
        file << mhs.nim << "," << mhs.nama << "," << mhs.nilai << endl;
    }
    cout << "Data berhasil disimpan ke file." << endl;
}

void bacaDariFile() {
    ifstream file("dataMahasiswa.txt");
    if (!file.is_open()) {
        cout << "File tidak ditemukan." << endl;
        return;
    }

    dataMahasiswa.clear();
    string nim, nama, nilaiStr;
    while (getline(file, nim, ',') && getline(file, nama, ',') && getline(file, nilaiStr)) {
        Mahasiswa mhs{nim, nama, stod(nilaiStr)};
        dataMahasiswa.push_back(mhs);
    }
    cout << "Data berhasil dibaca dari file." << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu:\n1. Tambah Data\n2. Tampilkan Data\n3. Cari Data\n4. Urutkan Data\n5. Simpan ke File\n6. Baca dari File\n7. Keluar\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilkanData(); break;
            case 3: cariData(); break;
            case 4: urutkanData(); break;
            case 5: simpanKeFile(); break;
            case 
