#include <iostream>

using namespace std;

int main() {

    int bilangan[5];
    string nama[4]; 
    float nilai[10];

    string buah[4] = {
        "apel", "anggur", "jeruk", "pisang"
    };

    for (int i = 0; i < 4; i++) {
        cout << buah[i] << endl;
    }

    cout << '\n';
    // cout << buah;

    // For each perulangan
    for (string x : buah) {
        cout << x << endl;
    }

    int angka[5] = {10, 20, 30, 40, 50};

    // sizeof(angka) = 20 bytes (5 elemen × 4 bytes per int)
    // sizeof(angka[0]) = 4 bytes (1 elemen int)

    int panjang = sizeof(angka) / sizeof(angka[0]);
    cout << "Panjang array: " << panjang << endl;

    return 0;
}