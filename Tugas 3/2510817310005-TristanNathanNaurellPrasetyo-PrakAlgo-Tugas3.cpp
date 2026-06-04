#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int cariBatasKiri(const vector<int>& arr, int left, int right, int target) {
    int posisi = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            posisi = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return posisi;
}

int cariBatasKanan(const vector<int>& arr, int left, int right, int target) {
    int posisi = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            posisi = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return posisi;
}

int main() {
    srand(time(NULL));
    
    int N, X;
    if (!(cin >> N >> X)) return 0;
    
    vector<int> angka(N);
    for (int i = 0; i < N; i++) {
        angka[i] = (rand() % 20) + 1; 
        cout << angka[i] << " ";
    }
    cout << "\n";
    
    sort(angka.begin(), angka.end());
    
    int total_pasangan = 0;
    
    for (int i = 0; i < N; i++) {
        int target_dicari = X - angka[i];
        int batas_kiri = cariBatasKiri(angka, i + 1, N - 1, target_dicari);
        if (batas_kiri != -1) {
            int batas_kanan = cariBatasKanan(angka, i + 1, N - 1, target_dicari);
            int jumlah_kemunculan = batas_kanan - batas_kiri + 1;
            total_pasangan += jumlah_kemunculan;
        }
    }
    
    cout << total_pasangan << "\n";
    
    return 0;
}