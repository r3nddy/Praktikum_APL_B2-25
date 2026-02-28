#include <iostream> // io
#include <string> // untuk tipe data string
#include <cstdlib> // untuk clear terminal system()
#include <limits> // buat bersihin buffer

#ifdef _WIN32
    #define CLEAR system("cls") // bersihkan terminal (windows)
    #include <windows.h> // untuk ascii art dan warna (windows)
#else
    #define CLEAR system("clear") // bersihkan terminal (linux, macOs)
#endif

// palette warna
#define RESET       "\033[0m"
#define HIJAU       "\033[38;5;82m"
#define COKELAT     "\033[38;5;94m"
#define ABU_TERANG  "\033[38;5;246m" 
#define UNGU_GELAP  "\033[38;5;55m"  
#define BIRU        "\033[38;5;87m"  
#define EMAS        "\033[38;5;220m" 
#define MERAH       "\033[38;5;196m" 
#define TOSKA       "\033[38;5;48m" 
#define PUTIH       "\033[97m"      
#define KUNING      "\033[93m"      
#define UNGU        "\033[38;5;129m"
#define ABU_REDUP   "\033[90m"     


using namespace std;

int main() {
    string nama, nim;
    int pilihan;
    int percobaan = 3;
    bool login = false;

    double kilometer, centimeter, meter;

    #ifdef _WIN32
    SetConsoleOutputCP(65001); 
    #endif

    string penggaris10Cm = 
    string(TOSKA)    +  "    (cm)  0         1         2         3         4         5         6         7         8         9         10\n" +
    string(UNGU) +      "        |         |         |         |         |         |         |         |         |         |         |\n" +
    string(UNGU_GELAP)+ "        |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |\n" +
    string(UNGU_GELAP)+ "        |....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|\n" +
    string(UNGU) +      "        +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+" + RESET;

    // logic login
    for (int i = 0; i < percobaan; i++){
        CLEAR;
        cout << HIJAU <<"  █▄▀ █▀█ █▄ █ █ █ ██▀ █▀█ ▄▀▀ █" << endl;
        cout << HIJAU <<"  █▀▄ █▄█ █ ▀█ ▀▄▀ █▄▄ █▀▄ ▄▄▀ █" << endl;
        cout << ABU_TERANG <<"  ──────────────────────────────" << endl;
        cout << PUTIH <<"  █▀█ █▀█ █▄ █  ▀█ █▀█ █▄ █ █▀▀ " << endl;
        cout << PUTIH <<"  █▀▀ █▀█ █ ▀█ █▄█ █▀█ █ ▀█ █▄█ " << endl;
        cout << ABU_TERANG <<"  ──────────────────────────────" << endl;
        cout << ABU_REDUP <<"============================================" << endl;
        cout << EMAS <<"||            LOGIN SESSION  # " << i + 1 << "          ||" << endl;
        cout << ABU_REDUP <<"============================================" << endl;
        cout << PUTIH <<"  [>] Masukkan Username: " << BIRU;
        getline(cin, nama);
        cout << PUTIH <<"  [>] Masuk Password: " << BIRU;
        cin >> nim;
        cout << RESET;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if ((nama == "rendy" || nama == "Rendy" || nama == "RENDY") && nim == "069") {
            login = true;
            break;
        } else {
            cout << MERAH << "\n\n [!] " << PUTIH << "Username atau Password Salah!" << RESET << endl;
            cout << ABU_TERANG << " Tekan Enter untuk mencoba lagi..." << RESET;
            cin.get();
        }
    }

    // menu utama
    if (login) {
        do {
            CLEAR;
            cout << penggaris10Cm << endl;
            cout << ABU_TERANG << "\n\n=========================================================" << endl;
            cout << HIJAU << "|            MENU KONVERSI BESARAN PANJANG              |" << endl;
            cout << ABU_TERANG << "=========================================================" << endl;
            cout << PUTIH << "| No | Opsi Konversi                                    |" << endl;
            cout << ABU_TERANG << "|----|--------------------------------------------------|" << endl;
            cout << PUTIH << "| 1. | Meter      →  Kilometer & Centimeter             |" << endl;
            cout << PUTIH << "| 2. | Kilometer  →  Meter & Centimeter                 |" << endl;
            cout << PUTIH << "| 3. | Centimeter →  Meter & Kilometer                  |" << endl;
            cout << PUTIH << "| 4. | Keluar Program                                   |" << endl;
            cout << ABU_TERANG << "=========================================================" << endl;
            cout << KUNING <<" Pilih Opsi > " << RESET;

            if (!(cin >> pilihan)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                pilihan = 0; 
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (pilihan == 1) {
                CLEAR;
                cout << ABU_TERANG << "--- [" << BIRU << " KONVERSI METER "<< ABU_TERANG <<"] ---" << RESET <<endl;
                cout << PUTIH << "Masukkan Meter (>= 0): " << KUNING;
                while (true) {
                    if (!(cin >> meter)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << MERAH << "Input harus angka! " << PUTIH << "Masukkan Meter (>= 0): " << KUNING;
                        continue;
                    }
                    if (meter < 0) {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << MERAH << "Panjang tidak boleh negatif! " << PUTIH << "Masukkan Meter (>= 0): " << KUNING;
                        continue;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                kilometer = meter / 1000;
                centimeter = meter * 100;

                cout << "\n" << ABU_REDUP << "  Hasil Konversi:" << endl;
                cout << PUTIH << "  " << meter << " m " << ABU_TERANG << "diubah ke " << EMAS << "km: " << KUNING << kilometer << " km" << endl;
                cout << PUTIH << "  " << meter << " m " << ABU_TERANG << "diubah ke " << EMAS << "cm: " << KUNING << centimeter << " cm" << endl;
                cout << ABU_TERANG << "\nTekan Enter untuk kembali..." << RESET;
                cin.get();

            } else if (pilihan == 2) {
                CLEAR;
                cout << ABU_TERANG << "--- [" << BIRU << " KONVERSI KILOMETER " << ABU_TERANG << "] ---" << RESET << endl;
                cout << PUTIH << "Masukkan Kilometer (>= 0): " << KUNING;
                while (true) {
                    if (!(cin >> kilometer)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << MERAH << "Input harus angka! " << PUTIH << "Masukkan Kilometer (>= 0): " << KUNING;
                        continue;
                    }
                    if (kilometer < 0) {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << MERAH << "Panjang tidak boleh negatif! " << PUTIH << "Masukkan Kilometer (>= 0): " << KUNING;
                        continue;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                meter = kilometer * 1000;
                centimeter = kilometer * 100000;

                cout << PUTIH << "  " << kilometer << " km " << ABU_TERANG << "diubah ke " << EMAS << "m: " << KUNING << meter << " m" << endl;
                cout << PUTIH << "  " << kilometer << " km " << ABU_TERANG << "diubah ke " << EMAS << "cm: " << KUNING << centimeter << " cm" << endl;
                cout << ABU_TERANG << "\nTekan Enter untuk kembali..." << RESET;
                cin.get();

            } else if (pilihan == 3) {
                CLEAR;
                cout << ABU_TERANG << "--- [" << BIRU << " KONVERSI CENTIMETER " << ABU_TERANG << "] ---" << RESET << endl;
                cout << PUTIH << "Masukkan Centimeter (>= 0): " << KUNING;
                while (true) {
                    if (!(cin >> centimeter)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << MERAH << "Input harus angka! " << PUTIH << "Masukkan Centimeter (>= 0): " << KUNING;
                        continue;
                    }
                    if (centimeter < 0) {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << MERAH << "Panjang tidak boleh negatif! " << PUTIH << "Masukkan Centimeter (>= 0): " << KUNING;
                        continue;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                meter = centimeter  / 100;
                kilometer = centimeter / 100000;

                cout << PUTIH << "  " << centimeter << " cm " << ABU_TERANG << "diubah ke " << EMAS << "m: " << KUNING << meter << " m" << endl;
                cout << PUTIH << "  " << centimeter << " cm " << ABU_TERANG << "diubah ke " << EMAS << "km: " << KUNING << kilometer << " km" << endl;
                cout << ABU_TERANG << "\nTekan Enter untuk kembali..." << RESET; 
                cin.get();
                
            } else if (pilihan == 4) {
                cout << MERAH << "  Shutting down... " << PUTIH << "Keluar program." << RESET << endl;
            } else {
                cout << MERAH <<"\n " << "[!] Opsi tidak ditemukan. Silakan pilih 1-4!" << endl;
                cout << ABU_TERANG << "\nTekan Enter untuk kembali..." << RESET;
                cin.get();

            }
        } while(pilihan != 4);
    } else {
        cout << MERAH << " [!] BATAS PERCOBAAN HABIS " << RESET << endl;
    }

    return 0;
}