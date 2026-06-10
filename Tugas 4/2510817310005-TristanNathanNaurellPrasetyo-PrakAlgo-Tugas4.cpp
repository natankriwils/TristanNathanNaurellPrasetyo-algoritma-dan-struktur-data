#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int nilai;
    Node* kiri;
    Node* kanan;
    Node(int v) : nilai(v), kiri(nullptr), kanan(nullptr) {}
};

Node* sisipkan(Node* akar, int nilai) {
    if (!akar) return new Node(nilai);
    if (nilai < akar->nilai)
        akar->kiri = sisipkan(akar->kiri, nilai);
    else
        akar->kanan = sisipkan(akar->kanan, nilai);
    return akar;
}

int diameter = 0;

int tinggi(Node* node) {
    if (!node) return -1;
    int kiri = tinggi(node->kiri);
    int kanan = tinggi(node->kanan);
    diameter = max(diameter, kiri + kanan + 2);
    return max(kiri, kanan) + 1;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> elemen(N);
    for (int i = 0; i < N; i++) {
        cin >> elemen[i];
    }

    Node* akar = nullptr;
    for (int i = 0; i < N; i++) {
        akar = sisipkan(akar, elemen[i]);
    }

    tinggi(akar);
    cout << diameter << "\n";

    return 0;
}