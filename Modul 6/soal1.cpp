#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int randomNum(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequentialSearching() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;

    randomize();

    printf("Generating 100 number . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = randomNum(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\n\ndone.\n\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d\n", save);
    } else {
        printf("Data tidak ada!\n");
    }

    printf("\nTekan Enter untuk kembali ke menu...");
    cin.ignore();
    cin.get();
}

void binarySearching() {
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];

    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\n--------------------------------------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n--------------------------------------------------------------------------------\n";

    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true) {
        cout << "\nAngka ditemukan! ";
        cout << "Berada pada indeks ke-" << tengah << endl;
    } else {
        cout << "\nAngka tidak ditemukan!" << endl;
    }

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void jelaskanPerbedaan() {
    clrscr();
    cout << "========================================================\n";
    cout << "   PERBEDAAN SEQUENTIAL SEARCHING & BINARY SEARCHING\n";
    cout << "========================================================\n\n";

    cout << "[ SEQUENTIAL SEARCHING ]\n\n";
    cout << "  Cara Kerja :\n";
    cout << "  Sequential searching bekerja dengan cara mencari data\n";
    cout << "  secara berurutan dimulai dari indeks pertama hingga\n";
    cout << "  indeks terakhir pada array. Program akan membandingkan\n";
    cout << "  data yang dicari dengan setiap elemen satu per satu.\n";
    cout << "  Jika data belum ditemukan, pencarian dilanjutkan ke\n";
    cout << "  elemen berikutnya sampai data ditemukan atau seluruh\n";
    cout << "  data selesai diperiksa. Algoritma ini dapat digunakan\n";
    cout << "  pada data yang belum terurut.\n\n";
    cout << "  Kompleksitas :\n";
    cout << "    Best case    : O(1)\n";
    cout << "    Average case : O(n)\n";
    cout << "    Worst case   : O(n)\n";
    cout << "  Termasuk kompleksitas linear karena jumlah pengecekan\n";
    cout << "  bertambah mengikuti jumlah data.\n\n";
    cout << "  Kelebihan :\n";
    cout << "    + Dapat digunakan pada data yang belum terurut.\n";
    cout << "    + Implementasinya sederhana dan mudah dipahami.\n";
    cout << "    + Tidak memerlukan proses sorting sebelum pencarian.\n\n";
    cout << "  Kekurangan :\n";
    cout << "    - Proses pencarian lambat jika data sangat banyak.\n";
    cout << "    - Pada kasus terburuk, seluruh isi array diperiksa.\n";
    cout << "    - Kurang efisien dibanding binary search.\n\n";

    cout << "--------------------------------------------------------\n\n";

    cout << "[ BINARY SEARCHING ]\n\n";
    cout << "  Cara Kerja :\n";
    cout << "  Binary searching bekerja dengan cara membagi data\n";
    cout << "  menjadi dua bagian secara terus menerus. Program\n";
    cout << "  memeriksa data di posisi tengah terlebih dahulu.\n";
    cout << "  Jika sama dengan data yang dicari, pencarian selesai.\n";
    cout << "  Jika lebih kecil, pencarian ke bagian kiri, jika lebih\n";
    cout << "  besar, ke bagian kanan. Proses ini terus dilakukan\n";
    cout << "  sampai data ditemukan atau tidak dapat dibagi lagi.\n";
    cout << "  Algoritma ini hanya dapat digunakan pada data terurut.\n\n";
    cout << "  Kompleksitas :\n";
    cout << "    Best case    : O(1)\n";
    cout << "    Average case : O(log n)\n";
    cout << "    Worst case   : O(log n)\n";
    cout << "  Termasuk kompleksitas logaritmik karena data yang dicek\n";
    cout << "  selalu dibagi dua setiap proses pencarian.\n\n";
    cout << "  Kelebihan :\n";
    cout << "    + Proses pencarian jauh lebih cepat dari sequential.\n";
    cout << "    + Sangat efisien digunakan pada data berukuran besar.\n";
    cout << "    + Jumlah pengecekan lebih sedikit karena data dibagi 2.\n\n";
    cout << "  Kekurangan :\n";
    cout << "    - Hanya dapat digunakan pada data yang sudah terurut.\n";
    cout << "    - Jika belum terurut, perlu dilakukan sorting dahulu.\n";
    cout << "    - Kurang efektif untuk data yang jumlahnya sedikit.\n\n";

    cout << "========================================================\n";
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

int main() {
    int pilih;

    do {
        clrscr();
        cout << "========================================\n";
        cout << "          PROGRAM SEARCHING\n";
        cout << "========================================\n";
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                sequentialSearching();
                break;
            case 2:
                binarySearching();
                break;
            case 3:
                jelaskanPerbedaan();
                break;
            case 4:
                cout << "Terima Kasih";
                cout << "\nProgram dibuat oleh Tristan Nathan Naurell Prasetyo (2510817310005).\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Coba lagi.\n";
                break;
        }

    } while (pilih != 4);

    return 0;
}