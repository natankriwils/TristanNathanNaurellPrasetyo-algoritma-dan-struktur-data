#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j+1] = arr[j]; j--; }
        arr[j+1] = key;
    }
}

void merge(string arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    string L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) { if (L[i] <= R[j]) arr[k++] = L[i++]; else arr[k++] = R[j++]; }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(string arr[], int l, int r) {
    if (l < r) { int m = l+(r-l)/2; mergeSort(arr,l,m); mergeSort(arr,m+1,r); merge(arr,l,m,r); }
}

void shellSort(string arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            string temp = arr[i]; int j = i;
            while (j >= gap && arr[j-gap] > temp) { arr[j] = arr[j-gap]; j -= gap; }
            arr[j] = temp;
        }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low-1;
    for (int j = low; j < high; j++) if (arr[j] <= pivot) { i++; swap(arr[i], arr[j]); }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) { int pi = partition(arr,low,high); quickSort(arr,low,pi-1); quickSort(arr,pi+1,high); }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) if (arr[j] > arr[j+1]) { swap(arr[j],arr[j+1]); swapped = true; }
        if (!swapped) break;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) if (arr[j] < arr[minIdx]) minIdx = j;
        if (minIdx != i) swap(arr[i], arr[minIdx]);
    }
}

int splitNama(string baris, string arr[]) {
    int n = 0;
    for (int i = 0; i < (int)baris.size(); i++)
        if (baris[i] != ' ') arr[n++] = string(1, baris[i]);
    return n;
}

int splitNIM(string nim, int arr[]) {
    int n = 0;
    for (int i = 0; i < (int)nim.size(); i++) arr[n++] = nim[i] - '0';
    return n;
}

void printArrStr(string arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) { cout << arr[i]; if (i < n-1) cout << ", "; }
    cout << " ]" << endl;
}

void printArrInt(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) { cout << arr[i]; if (i < n-1) cout << ", "; }
    cout << " ]" << endl;
}

void runInsertionSort() {
    string baris; string arr[100];
    cin.ignore();
    cout << "Masukkan Nama : "; getline(cin, baris);
    int n = splitNama(baris, arr);
    cout << endl << "Insertion Sort (Nama)" << endl;
    cout << "Nama   : " << baris << endl;
    cout << "Sebelum: "; printArrStr(arr, n);
    insertionSort(arr, n);
    cout << "Sesudah: "; printArrStr(arr, n);
}

void runMergeSort() {
    string baris; string arr[100];
    cin.ignore();
    cout << "Masukkan Nama : "; getline(cin, baris);
    int n = splitNama(baris, arr);
    cout << endl << "Merge Sort (Nama)" << endl;
    cout << "Nama   : " << baris << endl;
    cout << "Sebelum: "; printArrStr(arr, n);
    mergeSort(arr, 0, n-1);
    cout << "Sesudah: "; printArrStr(arr, n);
}

void runShellSort() {
    string baris; string arr[100];
    cin.ignore();
    cout << "Masukkan Nama : "; getline(cin, baris);
    int n = splitNama(baris, arr);
    cout << endl << "Shell Sort (Nama)" << endl;
    cout << "Nama   : " << baris << endl;
    cout << "Sebelum: "; printArrStr(arr, n);
    shellSort(arr, n);
    cout << "Sesudah: "; printArrStr(arr, n);
}

void runQuickSort() {
    string nim; int arr[100];
    cout << "Masukkan NIM : "; cin >> nim;
    int n = splitNIM(nim, arr);
    cout << endl << "Quick Sort (NIM)" << endl;
    cout << "NIM    : " << nim << endl;
    cout << "Sebelum: "; printArrInt(arr, n);
    quickSort(arr, 0, n-1);
    cout << "Sesudah: "; printArrInt(arr, n);
}

void runBubbleSort() {
    string nim; int arr[100];
    cout << "Masukkan NIM : "; cin >> nim;
    int n = splitNIM(nim, arr);
    cout << endl << "Bubble Sort (NIM)" << endl;
    cout << "NIM    : " << nim << endl;
    cout << "Sebelum: "; printArrInt(arr, n);
    bubbleSort(arr, n);
    cout << "Sesudah: "; printArrInt(arr, n);
}

void runSelectionSort() {
    string nim; int arr[100];
    cout << "Masukkan NIM : "; cin >> nim;
    int n = splitNIM(nim, arr);
    cout << endl << "Selection Sort (NIM)" << endl;
    cout << "NIM    : " << nim << endl;
    cout << "Sebelum: "; printArrInt(arr, n);
    selectionSort(arr, n);
    cout << "Sesudah: "; printArrInt(arr, n);
}

int main() {
    int pil; char pilihan[2];

    menu:
    system("cls");
    cout << "==============================" << endl;
    cout << "=          SORTING           =" << endl;
    cout << "==============================" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Shell Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Bubble Sort" << endl;
    cout << "6. Selection Sort" << endl;
    cout << "7. Exit" << endl;
    cout << "------------------------------" << endl;
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
    pil = atoi(pilihan);
    system("cls");

    switch (pil) {
        case 1: runInsertionSort(); break;
        case 2: runMergeSort();     break;
        case 3: runShellSort();     break;
        case 4: runQuickSort();     break;
        case 5: runBubbleSort();    break;
        case 6: runSelectionSort(); break;
        case 7:
            cout << "\nTERIMA KASIH" << endl;
            cout << "Program dibuat oleh Tristan Nathan Naurell Prasetyo (2510817310005)." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    cout << "\nPress any key to continue!" << endl;
    getch();
    goto menu;

    return 0;
}
