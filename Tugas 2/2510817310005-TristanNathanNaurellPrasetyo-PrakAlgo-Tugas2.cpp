#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string inputBaris;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void hapusTargetH();
void hapusTargetHT();
void clearH();
void clearHT();

int main()
{
    menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"========================================"<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    cin.ignore();
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"================================================"<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (Node ke-N)"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset (Clear Bergantian)"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            cin.ignore();
            pil=atoi(pilihan);

            switch(pil) {
            case 1:
                tambahDepanH();
                break;
            case 2:
                tambahBelakangH();
                break;
            case 3:
                tampilkanH();
                break;
            case 4:
                hapusDepanH();
                break;
            case 5:
                hapusBelakangH();
                break;
            case 6:
                hapusTargetH();
                break;
            case 7:
                clearH();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<8);
    } else if(menu==2){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"========================================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (Node ke-N)"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset (Clear Bergantian)"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            cin.ignore();
            pil=atoi(pilihan);

            switch(pil) {
            case 1:
                tambahDepanHT();
                break;
            case 2:
                tambahBelakangHT();
                break;
            case 3:
                tampilkanHT();
                break;
            case 4:
                hapusDepanHT();
                break;
            case 5:
                hapusBelakangHT();
                break;
            case 6:
                hapusTargetHT();
                break;
            case 7:
                clearHT();
                break;
            default:
                system("cls");
                goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<8);
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made by Tristan Nathan Naurell Prasetyo (2510817310005)."<<endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(head == NULL) return 1; 
    else return 0;
}

vector<string> ambilDataSatuBaris() {
    cout << "Masukkan data (pisahkan dengan spasi): ";
    getline(cin, inputBaris);
    stringstream ss(inputBaris);
    string kata;
    vector<string> listData;
    while (ss >> kata) {
        listData.push_back(kata);
    }
    return listData;
}

void tambahDepanH() {
    vector<string> listData = ambilDataSatuBaris();
    if(listData.empty()) return;

    for(int i = listData.size() - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = listData[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyH() == 1) {
            head = baru;
        } else {
            baru->next = head;   
            head->prev = baru;   
            head = baru;         
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan sesuai urutan input.\n";
}

void tambahDepanHT() {
    vector<string> listData = ambilDataSatuBaris();
    if(listData.empty()) return;

    for(int i = listData.size() - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = listData[i];
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan sesuai urutan input.\n";
}

void tambahBelakangH() {
    vector<string> listData = ambilDataSatuBaris();
    for(string data : listData) {
        TNode *baru = new TNode;
        baru->data = data;
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyH() == 1) {
            head = baru;
        } else {
            TNode *bantu = head;
            while(bantu->next != NULL){
                bantu = bantu->next;
            }
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    cout << "Data berhasil dimasukkan di bagian belakang sesuai urutan input.\n";
}

void tambahBelakangHT() {
    vector<string> listData = ambilDataSatuBaris();
    for(string data : listData) {
        TNode *baru = new TNode;
        baru->data = data;
        baru->next = NULL;
        baru->prev = NULL;

        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian belakang sesuai urutan input.\n";
}

void tampilkanH() {
    TNode *bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout << bantu->data << " <-> ";
            bantu = bantu->next;
        }
        cout << "NULL" << endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}

void tampilkanHT() {
    TNode *bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != NULL) {
            cout << bantu->data << " <-> ";
            bantu = bantu->next;
        }
        cout << "NULL" << endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusDepanH() {
    if(isEmptyH() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusDepanHT() {
    if(isEmptyHT() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusBelakangH() {
    if(isEmptyH() == 1) {
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }
    
    int n, jumlahNode = 0;
    cout << "Masukkan urutan Node ke-N dari belakang yang ingin dihapus: ";
    cin >> n;

    TNode *bantu = head;
    while(bantu != NULL) {
        jumlahNode++;
        bantu = bantu->next;
    }

    if (n > jumlahNode) {
        int sisa = n % jumlahNode;
        n = (sisa == 0) ? jumlahNode : sisa;
        cout << "[Sistem Mundur Aktif] Target bergeser ke-N dari belakang: " << n << endl;
    }

    int posisiDariDepan = jumlahNode - n + 1;
    bantu = head;
    for(int i = 1; i < posisiDariDepan; i++) {
        bantu = bantu->next;
    }

    TNode *hapus = bantu;
    string data = hapus->data;

    if(hapus == head) {
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
    } else if(hapus->next == NULL) {
        hapus->prev->next = NULL;
    } else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }

    delete hapus;
    cout<<"Data \""<<data<<"\" telah berhasil dihapus.";
}

void hapusBelakangHT() {
    if(isEmptyHT() == 1) {
        cout<<"Tidak terdapat data pada Linked List";
        return;
    }

    int n, jumlahNode = 0;
    cout << "Masukkan urutan Node ke-N dari belakang yang ingin dihapus: ";
    cin >> n;

    TNode *bantu = head;
    while(bantu != NULL) {
        jumlahNode++;
        bantu = bantu->next;
    }

    if (n > jumlahNode) {
        int sisa = n % jumlahNode;
        n = (sisa == 0) ? jumlahNode : sisa;
        cout << "[Sistem Mundur Aktif] Target bergeser ke-N dari belakang: " << n << endl;
    }

    bantu = tail;
    for(int i = 1; i < n; i++) {
        bantu = bantu->prev;
    }

    TNode *hapus = bantu;
    string data = hapus->data;

    if(hapus == head && hapus == tail) {
        initHT();
    } else if(hapus == head) {
        head = head->next;
        head->prev = NULL;
    } else if(hapus == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }

    delete hapus;
    cout<<"Data \""<<data<<"\" telah berhasil dihapus.";
}

void hapusTargetH() {
    if(isEmptyH() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;

    TNode *bantu = head;
    bool ditemukan = false;

    while(bantu != NULL) {
        TNode *nextNode = bantu->next; 
        if(bantu->data == target) {
            ditemukan = true;
            TNode *hapus = bantu;
            if(hapus == head) {
                if(head->next != NULL) {
                    head = head->next;
                    head->prev = NULL;
                } else {
                    head = NULL;
                }
            } else if(hapus->next == NULL) {
                hapus->prev->next = NULL;
            } else {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }
            delete hapus;
        }
        bantu = nextNode;
    }
    if(ditemukan) cout << "Semua data \"" << target << "\" berhasil dihapus.";
    else cout << "Data target tidak ditemukan!";
}

void hapusTargetHT() {
    if(isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus: ";
    cin >> target;

    TNode *bantu = head;
    bool ditemukan = false;

    while(bantu != NULL) {
        TNode *nextNode = bantu->next;
        if(bantu->data == target) {
            ditemukan = true;
            TNode *hapus = bantu;
            if(hapus == head && hapus == tail) {
                head = NULL;
                tail = NULL;
            } else if(hapus == head) {
                head = head->next;
                head->prev = NULL;
            } else if(hapus == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                hapus->prev->next = hapus->next;
                hapus->next->prev = hapus->prev;
            }
            delete hapus;
        }
        bantu = nextNode;
    }
    if(ditemukan) cout << "Semua data \"" << target << "\" berhasil dihapus.";
    else cout << "Data target tidak ditemukan!";
}

void clearH() {
    if(isEmptyH() == 1) {
        cout << "Linked List sudah kosong.";
        return;
    }
    int urutan = 1;
    bool hapusDariDepan = true;

    while(head != NULL) {
        TNode *hapus = NULL;
        if(hapusDariDepan) {
            hapus = head;
            if(head->next != NULL) {
                head = head->next;
                head->prev = NULL;
            } else {
                head = NULL;
            }
        } else {
            TNode *bantu = head;
            while(bantu->next != NULL) {
                bantu = bantu->next;
            }
            hapus = bantu;
            if(hapus->prev != NULL) {
                hapus->prev->next = NULL;
            } else {
                head = NULL;
            }
        }
        cout << "Urutan ke-" << urutan << ": Menghapus node bertuliskan \"" << hapus->data << "\"\n";
        delete hapus;
        urutan++;
        hapusDariDepan = !hapusDariDepan;
    }
    initH();
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT() {
    if(isEmptyHT() == 1) {
        cout << "Linked List sudah kosong.";
        return;
    }
    int urutan = 1;
    bool hapusDariDepan = true;

    while(head != NULL) {
        TNode *hapus = NULL;
        if(hapusDariDepan) {
            hapus = head;
            if(head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }
        } else {
            hapus = tail;
            if(head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }
        }
        cout << "Urutan ke-" << urutan << ": Menghapus node bertuliskan \"" << hapus->data << "\"\n";
        delete hapus;
        urutan++;
        hapusDariDepan = !hapusDariDepan;
    }
    initHT();
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}