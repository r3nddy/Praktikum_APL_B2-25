#include <iostream>
using namespace std;

// Fungsi ditaruh sebelum main
int kuadrat(int x) {
    return x * x;
}

// Prosedur ditulis sebelum main
void sapa(string nama) {
    cout << "Halo, " << nama << "!" << endl;
}

// prosedur ini menerima nilai dari variable gajiSaya
void cobaUbahGaji(int gajiSaya) {
    gajiSaya = 1000000000; // gaji di dalam prosedur
    cout << "Gaji pas di dalam fungsi: " << gajiSaya << endl;
}

int main() {

    sapa("lowlight");
    cout << "Hasil 5 kuadrat: " << kuadrat(5) << endl;

    int gajiSaya = 5000000; // gaji di dalam main

    cout << "Gaji awal: " << gajiSaya << endl;

    cobaUbahGaji(gajiSaya); // kirim ke fungsi

    cout << "Gaji setelah fungsi dipanggil: " << gajiSaya << endl;

    return 0;
}