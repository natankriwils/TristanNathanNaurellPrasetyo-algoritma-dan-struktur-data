#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru) {
    if (*root == NULL) {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
        cout << "Data bertambah!\n";
    } 
    else if (databaru < (*root)->data) {
        tambah(&(*root)->kiri, databaru);
    } 
    else if (databaru > (*root)->data) {
        tambah(&(*root)->kanan, databaru);
    } 
    else if (databaru == (*root)->data) {
        cout << "Data sudah ada!\n";
    }
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    int pil, data;
    Node *pohon = NULL;
    
    do {
        system("cls"); 
        cout << "=======================\n";
        cout << " PROGRAM BINARY TREE \n";
        cout << "=======================\n";
        cout << "1. Tambah Node\n";
        cout << "2. Cetak PreOrder\n";
        cout << "3. Cetak InOrder\n";
        cout << "4. Cetak PostOrder\n";
        cout << "5. Exit\n";
        cout << "-----------------------\n";
        cout << "Pilihan : ";
        cin >> pil;
        
        switch (pil) {
            case 1:
                cout << "\n INPUT DATA";
                cout << "\n -----------";
                cout << "\n Data baru: ";
                cin >> data;
                tambah(&pohon, data);
                break;
                
            case 2:
                cout << "\nPreOrder Traversal\n";
                cout << "-----------------\n";
                if (pohon != NULL) {
                    preOrder(pohon);
                } else {
                    cout << "Masih Kosong";
                }
                cout << "\n";
                break;
                
            case 3:
                cout << "\nInOrder Traversal\n";
                cout << "-----------------\n";
                if (pohon != NULL) {
                    inOrder(pohon);
                } else {
                    cout << "Masih Kosong";
                }
                cout << "\n";
                break;
                
            case 4:
                cout << "\nPostOrder Traversal\n";
                cout << "-----------------\n";
                if (pohon != NULL) {
                    postOrder(pohon);
                } else {
                    cout << "Masih Kosong";
                }
                cout << "\n";
                break;
                
            case 5:
                cout << "\nKeluar dari program...\n";
                return 0;
                
            default:
                cout << "\nPilihan tidak valid!\n";
        }
        cout << "\nTekan sembarang tombol untuk melanjutkan...";
        getch();
    } while (pil != 5);
    
    return 0;
}