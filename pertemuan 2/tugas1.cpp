#include <iostream>
using namespace std;

// Struktur untuk Node
struct Node {
    int data;
    Node* next;
};

// Pointer global untuk head
Node* head = NULL;

// Fungsi untuk menampilkan isi Linked List
void tampilkanLinkedList() {
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n\n";
}

// 1. Fungsi untuk menambah node di awal
void tambahDiAwal(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
    tampilkanLinkedList();
}

// 2. Fungsi untuk menambah node di akhir
void tambahDiAkhir(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    tampilkanLinkedList();
}

// 3. Fungsi untuk menambah node setelah nilai tertentu
void tambahSetelah(int nilaiBaru, int nilaiCari) {
    Node* temp = head;
    while (temp != NULL && temp->data != nilaiCari) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        Node* newNode = new Node();
        newNode->data = nilaiBaru;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Nilai " << nilaiCari << " tidak ditemukan di dalam list.\n";
    }
    tampilkanLinkedList();
}

// 4. Fungsi untuk menghapus node berdasarkan nilai
void hapusBerdasarkanNilai(int nilai) {
    if (head == NULL) {
        cout << "Linked list masih kosong.\n";
        return;
    }
    
    // Jika nilai yang ingin dihapus ada di head
    if (head->data == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        tampilkanLinkedList();
        return;
    }
    
    // Mencari nilai di node selain head
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != nilai) {
        temp = temp->next;
    }
    
    if (temp->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    } else {
        cout << "Nilai " << nilai << " tidak ditemukan di dalam list.\n";
    }
    tampilkanLinkedList();
}

int main() {
    int pilihan, nilai, nilaiBaru, nilaiCari;
    
    do {
        cout << "===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDiAwal(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDiAkhir(nilai);
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilaiBaru;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                tambahSetelah(nilaiBaru, nilaiCari);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusBerdasarkanNilai(nilai);
                break;
            case 5:
                tampilkanLinkedList();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n\n";
        }
    } while (pilihan != 0);

    return 0;
}