#include <iostream>
using namespace std;

const int MAKS_TIM = 10;

struct Tim {
    char nama[50];
    int main = 0;
    int menang = 0;
    int seri = 0;
    int kalah = 0;
    int golMasuk = 0;
    int golKemasukan = 0;
    int poin = 0;
};

Tim daftarTim[MAKS_TIM];
int jumlahTim = 0;

int cariTim(const char nama[]) {
    for (int i = 0; i < jumlahTim; ++i) {
        int j = 0;
        while (nama[j] == daftarTim[i].nama[j] && nama[j] != '\0') j++;
        if (nama[j] == '\0' && daftarTim[i].nama[j] == '\0') {
            return i;
        }
    }
    return -1;
}

void tambahTim() {
    if (jumlahTim >= MAKS_TIM) {
        cout << "Jumlah tim sudah maksimal.\n";
        return;
    }

    cout << "Masukkan nama tim: ";
    cin.ignore();
    cin.getline(daftarTim[jumlahTim].nama, 50);

    if (cariTim(daftarTim[jumlahTim].nama) != -1) {
        cout << "Tim sudah terdaftar.\n";
        return;
    }

    jumlahTim++;
    cout << "Tim berhasil ditambahkan.\n";
}

void tambahPertandingan() {
    char tim1[50], tim2[50];
    int skor1, skor2;

    cout << "Nama tim 1: ";
    cin.ignore();
    cin.getline(tim1, 50);
    cout << "Nama tim 2: ";
    cin.getline(tim2, 50);
    cout << "Skor " << tim1 << ": ";
    cin >> skor1;
    cout << "Skor " << tim2 << ": ";
    cin >> skor2;

    int i1 = cariTim(tim1);
    int i2 = cariTim(tim2);

    if (i1 == -1 || i2 == -1) {
        cout << "Salah satu tim tidak ditemukan.\n";
        return;
    }

    daftarTim[i1].main++; 
    daftarTim[i2].main++;

    daftarTim[i1].golMasuk += skor1;
    daftarTim[i1].golKemasukan += skor2;
    daftarTim[i2].golMasuk += skor2;
    daftarTim[i2].golKemasukan += skor1;

    if (skor1 > skor2) {
        daftarTim[i1].menang++; daftarTim[i1].poin += 3;
        daftarTim[i2].kalah++;
    } else if (skor1 < skor2) {
        daftarTim[i2].menang++; daftarTim[i2].poin += 3;
        daftarTim[i1].kalah++;
    } else {
        daftarTim[i1].seri++; daftarTim[i2].seri++;
        daftarTim[i1].poin++; daftarTim[i2].poin++;
    }

    cout << "Hasil pertandingan ditambahkan.\n";
}

void tampilKlasemen() {
    // Bubble sort berdasarkan poin
    for (int i = 0; i < jumlahTim - 1; ++i) {
        for (int j = 0; j < jumlahTim - i - 1; ++j) {
            if (daftarTim[j].poin < daftarTim[j+1].poin) {
                Tim temp = daftarTim[j];
                daftarTim[j] = daftarTim[j+1];
                daftarTim[j+1] = temp;
            }
        }
    }

    cout << "\n--- Klasemen Liga ---\n";
    cout << "Tim\t\tMain Menang Seri Kalah Gol Poin\n";
    for (int i = 0; i < jumlahTim; ++i) {
        cout << daftarTim[i].nama << "\t\t"
             << daftarTim[i].main << "    "
             << daftarTim[i].menang << "     "
             << daftarTim[i].seri << "     "
             << daftarTim[i].kalah << "     "
             << daftarTim[i].golMasuk << "-" << daftarTim[i].golKemasukan << "  "
             << daftarTim[i].poin << "\n";
    }
}

void cariDanTampilkanTim() {
    char namaCari[50];
    cout << "Masukkan nama tim yang dicari: ";
    cin.ignore();
    cin.getline(namaCari, 50);

    int idx = cariTim(namaCari);
    if (idx == -1) {
        cout << "Tim tidak ditemukan.\n";
    } else {
        cout << "\n--- Detail Tim: " << daftarTim[idx].nama << " ---\n";
        cout << "Main       : " << daftarTim[idx].main << "\n";
        cout << "Menang     : " << daftarTim[idx].menang << "\n";
        cout << "Seri       : " << daftarTim[idx].seri << "\n";
        cout << "Kalah      : " << daftarTim[idx].kalah << "\n";
        cout << "Gol        : " << daftarTim[idx].golMasuk << " - " << daftarTim[idx].golKemasukan << "\n";
        cout << "Poin       : " << daftarTim[idx].poin << "\n";
    }
}

void menu() {
    int pilihan;
    do {
        cout << "\n--- Menu Manajemen Liga ---\n";
        cout << "1. Tambah Tim\n";
        cout << "2. Tambah Pertandingan\n";
        cout << "3. Tampilkan Klasemen\n";
        cout << "4. Cari Tim\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
              tambahTim(); 
              break;
            case 2: 
              tambahPertandingan(); 
              break;
            case 3: 
              tampilKlasemen(); 
              break;
            case 4: 
              cariDanTampilkanTim(); 
              break;
            case 0: 
              cout << "Keluar dari program.\n"; 
              break;
            default: 
              cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}
