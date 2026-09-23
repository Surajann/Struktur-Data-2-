#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// Menambahkan karakter ke stack
void push(char value) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow! Stack penuh." << endl;
    } else {
        top++;
        stack[top] = value;
    }
}

// Mengambil karakter paling atas
char pop() {
    if (top < 0) {
        cout << "Stack Underflow! Stack kosong." << endl;
        return '\0'; // Mengembalikan karakter null jika kosong
    } else {
        char value = stack[top];
        top--;
        return value;
    }
}

int main() {
    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // Memasukkan setiap karakter ke stack
    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    cout << "Kata setelah dibalik: ";
    
    // Mengeluarkan karakter dari stack untuk membalikkan kata
    while (top >= 0) {
        cout << pop();
    }
    
    cout << endl;

    return 0;
}