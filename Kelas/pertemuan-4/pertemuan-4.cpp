#include <iostream>

using namespace std;

struct Address {
    string kota;
    string provinsi;
    string negara;
};

int ubahNilai(int &a, int b){
    return a = b;
}

int main() {

    int angka1, angka2;

    Address address1, address2;

    address1.kota = "Samarinda";
    address1.negara = "Kalimantan timur";
    address1.provinsi = "Indonesia";

    address2 = address1;

    string nama = "john doe";
    cout << &nama << " adalah alamatnya " << nama << endl;

    cout << "Pointer yang menunjuk ke arah elemen array" << endl;

    int b[5] = {1, 2, 3, 4, 5};
    int *bPtr = b;

    for (int i = 0; i < 5; i++){
        cout << bPtr << endl;
        cout << *bPtr <<endl;
        bPtr++;
    }


    angka1=5;
    angka2=20;

    ubahNilai(angka1, angka2);
    cout << angka1;

    return 0;
}