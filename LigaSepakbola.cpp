#include <iostream>

using namespace std;

int Max_TIM = 10; 

struct Tim {
    char nama[50];
    
};

Tim liga[10]; 
int jumlahTim = 0; 

void tampilkanMenu() {
    cout << "=== Manajemen Liga Sepak Bola ===" << endl;
    cout << "1. Tambah Tim " << endl;;
    cout << "2. Keluar " << endl;;
    cout << "Pilih opsi: ";
}

void tambahTim() {
    if (jumlahTim >= Max_TIM) {
        cout << "Kapasitas tim penuh! " << endl;
        return;
    }

    cout << "Masukkan nama tim: ";
    cin.ignore();
    cin.getline(liga[jumlahTim].nama, 50);
    jumlahTim++;
    cout << "Tim berhasil ditambahkan! " << endl;
}
int main() {
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahTim();
                break;
            case 2:
                cout << "Keluar dari Program " << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi. " << endl;
        }
    } while (pilihan != 2);

    return 0;
}