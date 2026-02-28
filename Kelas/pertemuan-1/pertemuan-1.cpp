#include <iostream>
using namespace std;

int main() {

    // string literal
    cout << "Hello world" << endl;


    // variabel & getline()
    // string nama;
    // cout << "Masukkan Nama: ";
    // getline(cin, nama);
    
    // cout << "nama : " << nama << endl;
    
    
    // percabangan
    bool mengantuk = true;
    if (mengantuk) {
        cout << "Saya tidur" << endl;
    } else if (mengantuk) {
        cout << "saya bangun" << endl;
    } else {
        cout << "pilihan tidak valid" << endl;
    }

    // perulang forEach
    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr) {
        cout << x << endl;
    }





    return 0;
}