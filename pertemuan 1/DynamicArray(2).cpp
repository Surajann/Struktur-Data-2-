#include <iostream>
using namespace std;

int main(){
    int n;
    
    cout << "Masukkan Jumlah Elemen Array: ";
    cin >> n;

    int* arr = new int[n]; //Dyanmic Array

    cout << "Masukkan " << n << " angka: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Isi Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}