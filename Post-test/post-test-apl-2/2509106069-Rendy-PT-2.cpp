#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>

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


struct User {
    string username;
    string password;
    bool isAdmin;
};

struct Logistik {
    string idLogistik;

    struct DetailMineral {
        string namaMineral;
        string jenisMineral;
        double kuantitas;
        string satuan;     
    } mineral;

    struct Alamat {
        string asalTambang;
    } asal;

    string tanggal;
};

const int MAX_USERS = 100;
const int MAX_LOGISTIK = 100;


int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(65001); 
    #endif

    User users[MAX_USERS];
    int jumlahUser = 0;

    // User default (admin)
    users[0].username = "rendy";
    users[0].password = "069";
    users[0].isAdmin  = true;
    jumlahUser = 1;

    Logistik logistik[MAX_LOGISTIK];
    int jumlahLogistik = 0;
    int idCounter = 1; // counter untuk auto-increment ID

    // Data dummy
    logistik[0].idLogistik              = "LOG001";
    logistik[0].mineral.namaMineral     = "Bijih Nikel";
    logistik[0].mineral.jenisMineral    = "Laterit";
    logistik[0].mineral.kuantitas       = 100.0;
    logistik[0].mineral.satuan          = "ton";
    logistik[0].asal.asalTambang        = "Tambang A - Sulawesi";
    logistik[0].tanggal                 = "01-01-2026";
    jumlahLogistik = 1;

    while (true) {
        CLEAR;
        cout << HIJAU  << "  ▄▀▀ █ ▄▀▀ ▀█▀ ██▀ █▄▀▄█" << endl;
        cout << HIJAU  << "  ▄▄▀ █ ▄▄▀  █  █▄▄ █   █" << endl;
        cout << ABU_TERANG << "  ───────────────────────────────────────────────────" << endl;
        cout << PUTIH  << "  █   █▀█ █▀▀ █ ▄▀▀ ▀█▀ █ █▄▀" << endl;
        cout << PUTIH  << "  █▄▄ █▄█ █▄█ █ ▄▄▀  █  █ █▀▄" << endl;
        cout << ABU_TERANG << "  ───────────────────────────" << endl;
        cout << TOSKA  << "  █▀█ ██▀ █▀█ ▀█▀ █▀█ █▄▀▄█ █▀▄ █▀█ █▄ █ █▀▀ █▀█ █▄ █" << endl;
        cout << TOSKA  << "  █▀▀ █▄▄ █▀▄  █  █▀█ █   █ █▄█ █▀█ █ ▀█ █▄█ █▀█ █ ▀█" << endl;
        cout << ABU_TERANG << "  ───────────────────────────────────────────────────" << endl;
        cout << UNGU   << "  █▄▀▄█ █ █▄ █ ██▀ █▀█ █▀█ █  " << endl;
        cout << UNGU   << "  █   █ █ █ ▀█ █▄▄ █▀▄ █▀█ █▄▄" << endl;
        cout << ABU_TERANG << "  ───────────────────────────────────────────────────" << RESET << endl;
        cout << ABU_REDUP << "\n\n=========================================================" << endl;
        cout << EMAS   << "|           SISTEM LOGISTIK MINERAL PERTAMBANGAN        |" << endl;
        cout << ABU_REDUP << "=========================================================" << endl;
        cout << PUTIH  << "| No | Autentikasi                                      |" << endl;
        cout << ABU_TERANG << "|----|--------------------------------------------------|" << endl;
        cout << PUTIH  << "| 1. | Login Akun                                       |" << endl;
        cout << PUTIH  << "| 2. | Register Akun Baru                               |" << endl;
        cout << PUTIH  << "| 3. | Keluar Program                                   |" << endl;
        cout << ABU_REDUP << "=========================================================" << RESET << endl;
        int autentikasi = 0;
        while (true) {
            cout << KUNING << "\nPilih Menu (1-3): " << RESET;
            if (cin >> autentikasi) {
                cin.ignore();
                if (autentikasi >= 1 && autentikasi <= 3) break;
                cout << MERAH << "[!] " << PUTIH << "harus 1 - 3." << RESET << endl;
            } else {
                cout << MERAH << "[!] " << PUTIH << "input tidak valid." << RESET << endl;
                cin.clear();
                cin.ignore();
            }
        }

        // === LOGIN ===
        if (autentikasi == 1) {
            if (jumlahUser == 0) {
                CLEAR;
                cout << ABU_REDUP << "============================================================" << endl;
                cout << EMAS   << "         Sistem Logistik Mineral Pertambangan          " << endl;
                cout << PUTIH  << "                          LOGIN" << endl;
                cout << ABU_REDUP << "============================================================" << endl;
                cout << MERAH << "[i] " << PUTIH << "Belum ada user terdaftar. Silakan register dulu." << RESET << endl;
                cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                cin.ignore(1000, '\n');
                continue;
            }

            int idxLogin = -1;
            for (int percobaan = 1; percobaan <= 3; percobaan++) {
                CLEAR;
                cout << ABU_REDUP << "============================================" << endl;
                cout << EMAS   << "||            LOGIN SESSION  # " << percobaan << "          ||" << endl;
                cout << ABU_REDUP << "============================================" << RESET << endl;

                string username, password;
                while (true) {
                    cout << PUTIH << "\n  [>] Masukkan Username: " << BIRU;
                    getline(cin, username);
                    cout << RESET;
                    if (!username.empty()) break;
                    cout << MERAH << "[!] " << PUTIH << "Input tidak boleh kosong." << RESET << endl;
                }
                while (true) {
                    cout << PUTIH << "  [>] Masuk Password: " << BIRU;
                    getline(cin, password);
                    cout << RESET;
                    if (!password.empty()) break;
                    cout << MERAH << "[!] " << PUTIH << "Input tidak boleh kosong." << RESET << endl;
                }

                for (int i = 0; i < jumlahUser; i++) {
                    if (users[i].username == username && users[i].password == password) {
                        idxLogin = i;
                        break;
                    }
                }

                if (idxLogin != -1) {
                    cout << HIJAU << "\n[OK] " << PUTIH << "Login berhasil. Selamat datang, " << BIRU << users[idxLogin].username << PUTIH << "." << RESET << endl;
                    cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                    cin.ignore(1000, '\n');
                    break;
                }

                cout << MERAH << "\n[!] " << PUTIH << "Username atau Password salah." << RESET << endl;
                if (percobaan < 3) {
                    cout << ABU_TERANG << "\nTekan Enter untuk mencoba lagi..." << RESET;
                    cin.ignore(1000, '\n');
                }
            }

            if (idxLogin == -1) {
                cout << MERAH << "\n[!] BATAS PERCOBAAN HABIS " << PUTIH << "Program akan keluar." << RESET << endl;
                exit(0);
            }

            // MENU UTAMA (CRUD) - looping sampai user pilih Keluar
            while (true) {
                CLEAR;
                cout << ABU_REDUP << "\n=========================================================" << endl;
                cout << EMAS   << "|                     STATUS LOGIN                      |" << endl;
                cout << ABU_REDUP << "=========================================================" << endl;
                cout << PUTIH  << "| Username : " << BIRU << left << setw(43) << users[idxLogin].username << PUTIH << "|" << endl;
                cout << PUTIH  << "| Role     : " << TOSKA << left << setw(43) << (users[idxLogin].isAdmin ? "ADMIN" : "USER") << PUTIH << "|" << endl;
                cout << ABU_REDUP << "=========================================================" << RESET << endl;

                if (users[idxLogin].isAdmin) {
                    cout << ABU_REDUP << "\n\n=========================================================" << endl;
                    cout << EMAS   << "|            MENU UTAMA (ADMIN)                         |" << endl;
                    cout << ABU_REDUP << "=========================================================" << endl;
                    cout << PUTIH  << "| No | Fitur Logistik                                   |" << endl;
                    cout << ABU_TERANG << "|----|--------------------------------------------------|" << endl;
                    cout << PUTIH  << "| 1. | Tambah Data     (Create)                         |" << endl;
                    cout << PUTIH  << "| 2. | Lihat Data      (Read)                           |" << endl;
                    cout << PUTIH  << "| 3. | Ubah Data       (Update)                         |" << endl;
                    cout << PUTIH  << "| 4. | Hapus Data      (Delete)                         |" << endl;
                    cout << PUTIH  << "| 5. | Keluar ke Menu Login                             |" << endl;
                    cout << ABU_REDUP << "=========================================================" << RESET << endl;
                } else {
                    cout << ABU_REDUP << "\n=========================================================" << endl;
                    cout << EMAS   << "|                   MENU UTAMA (USER)                   |" << endl;
                    cout << ABU_REDUP << "=========================================================" << endl;
                    cout << PUTIH  << "| No | Fitur Logistik                                   |" << endl;
                    cout << ABU_TERANG << "|----|--------------------------------------------------|" << endl;
                    cout << PUTIH  << "| 1. | Lihat Data (Read)                                |" << endl;
                    cout << PUTIH  << "| 2. | Keluar ke Menu Login                             |" << endl;
                    cout << ABU_REDUP << "=========================================================" << RESET << endl;
                }

                int menu = 0;
                if (users[idxLogin].isAdmin) {
                    while (true) {
                        cout << KUNING << "\nPilih Menu (1-5): " << RESET;
                        if (cin >> menu) {
                            cin.ignore(1000, '\n');
                            if (menu >= 1 && menu <= 5) break;
                            cout << MERAH << "[!] " << PUTIH << "Harus 1 - 5." << RESET << endl;
                        } else {
                            cout << MERAH << "[!] " << PUTIH << "Input tidak valid." << RESET << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                        }
                    }
                } else {
                    while (true) {
                        cout << KUNING << "\nPilih menu (1-2): " << RESET;
                        if (cin >> menu) {
                            cin.ignore(1000, '\n');
                            if (menu >= 1 && menu <= 2) break;
                            cout << MERAH << "[!] " << PUTIH << "Harus 1 - 2." << RESET << endl;
                        } else {
                            cout << MERAH << "[!] " << PUTIH << "Input tidak valid." << RESET << endl;
                            cin.clear();
                            cin.ignore(1000, '\n');
                        }
                    }
                }

                // CREATE (hanya untuk admin)
                if (menu == 1 && users[idxLogin].isAdmin) {
                    CLEAR;
                    cout << ABU_REDUP << "============================================================" << endl;
                    cout << ABU_TERANG << "--- [" << BIRU << " TAMBAH DATA " << ABU_TERANG << "] ---" << RESET << endl;
                    cout << ABU_REDUP << "============================================================" << endl;
                    if (jumlahLogistik < MAX_LOGISTIK) {
                        Logistik item;

                        // Auto-generate ID: LOG001, LOG002, ...
                        idCounter = jumlahLogistik + 1;
                        string nomorId = to_string(idCounter);
                        while (nomorId.length() < 3) nomorId = "0" + nomorId;
                        item.idLogistik = "LOG" + nomorId;

                        cout << PUTIH << "ID Logistik           : " << TOSKA << item.idLogistik << ABU_TERANG << " (otomatis)" << RESET << endl;

                        cout << PUTIH << "Komoditas             : " << KUNING;
                        getline(cin, item.mineral.namaMineral);

                        cout << PUTIH << "Jenis                 : " << KUNING;
                        getline(cin, item.mineral.jenisMineral);

                        cout << PUTIH << "Satuan                : " << KUNING;
                        getline(cin, item.mineral.satuan);

                        cout << PUTIH << "Qty                   : " << KUNING;
                        cin >> item.mineral.kuantitas;
                        cin.ignore(1000, '\n');

                        cout << PUTIH << "Lokasi                : " << KUNING;
                        getline(cin, item.asal.asalTambang);

                        cout << PUTIH << "Tanggal (dd-mm-yyyy)  : " << KUNING;
                        getline(cin, item.tanggal);
                        cout << RESET;

                        // Simpan ke array
                        logistik[jumlahLogistik] = item;
                        jumlahLogistik++;

                        cout << HIJAU << "\n[OK] " << PUTIH << "Data berhasil ditambahkan!" << RESET << endl;
                    } else {
                        cout << MERAH << "[!] " << PUTIH << "Kapasitas data logistik penuh!" << RESET << endl;
                    }

                    cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                    cin.ignore(1000, '\n');
                // READ (untuk admin menu 2, untuk user biasa menu 1)
                } else if ((menu == 2 && users[idxLogin].isAdmin) || (menu == 1 && !users[idxLogin].isAdmin)) {
                    CLEAR;
                    cout << ABU_REDUP << "\n=========================================================" << endl;
                    cout << EMAS   << "|               DAFTAR DATA LOGISTIK MINERAL            |" << endl;
                    cout << ABU_REDUP << "=========================================================" << RESET << endl;
                    if (jumlahLogistik == 0) {
                        cout << MERAH << "[i] " << PUTIH << "Belum ada data." << RESET << endl;
                        cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                        cin.ignore(1000, '\n');
                        continue;
                    }

                    // Header tabel: ID | Komoditas | Jenis | Satuan | Qty | Lokasi | Tanggal
                    cout << left;
                    cout << ABU_REDUP << "===========================================================================================================================" << endl;
                    cout << EMAS << "| " << setw(10) << "ID"
                         << "| " << setw(20) << "Komoditas"
                         << "| " << setw(15) << "Jenis"
                         << "| " << setw(8) << "Satuan"
                         << "| " << setw(10) << "Qty"
                         << "| " << setw(25) << "Lokasi"
                         << "| " << setw(20) << "Tanggal"
                         << "|" << endl;
                    cout << ABU_TERANG << "---------------------------------------------------------------------------------------------------------------------------" << endl;

                    for (int i = 0; i < jumlahLogistik; i++) {
                        cout << PUTIH << "| " << BIRU << setw(10) << logistik[i].idLogistik
                             << PUTIH << "| " << setw(20) << logistik[i].mineral.namaMineral
                             << PUTIH << "| " << setw(15) << logistik[i].mineral.jenisMineral
                             << PUTIH << "| " << setw(8) << logistik[i].mineral.satuan
                             << PUTIH << "| " << KUNING << setw(10) << logistik[i].mineral.kuantitas
                             << PUTIH << "| " << setw(25) << logistik[i].asal.asalTambang
                             << PUTIH << "| " << setw(20) << logistik[i].tanggal
                             << PUTIH << "|" << endl;
                    }
                    cout << ABU_REDUP << "===========================================================================================================================" << RESET << endl;
                    cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                    cin.ignore(1000, '\n');
                // UPDATE
                } else if (menu == 3 && users[idxLogin].isAdmin) {
                    CLEAR;
                    if (jumlahLogistik == 0) {
                        cout << MERAH << "[!] " << PUTIH << "Belum ada data logistik untuk diubah." << RESET << endl;
                    } else {
                        cout << ABU_TERANG << "--- [" << BIRU << " UBAH DATA " << ABU_TERANG << "] ---" << RESET << endl;
                        cout << ABU_REDUP << "====================" << RESET << endl;
                        for (int i = 0; i < jumlahLogistik; i++) {
                            cout << PUTIH << "Data ke-" << EMAS << i + 1 << endl;
                            cout << PUTIH << "ID: " << BIRU << logistik[i].idLogistik << endl;
                            cout << PUTIH << "Komoditas: " << KUNING << logistik[i].mineral.namaMineral << RESET << endl;
                            cout << endl;
                        }
                        cout << PUTIH << "Masukkan nomor data yang akan diubah: " << KUNING;
                        int index;
                        cin >> index;
                        cout << RESET;
                        if (index > 0 && index <= jumlahLogistik) {
                            cin.ignore();
                            cout << PUTIH << "Masukkan Komoditas baru: " << KUNING;
                            getline(cin, logistik[index - 1].mineral.namaMineral);
                            cout << PUTIH << "Masukkan Jenis baru: " << KUNING;
                            getline(cin, logistik[index - 1].mineral.jenisMineral);
                            cout << PUTIH << "Masukkan Satuan baru: " << KUNING;
                            getline(cin, logistik[index - 1].mineral.satuan);
                            cout << PUTIH << "Masukkan Qty baru: " << KUNING;
                            cin >> logistik[index - 1].mineral.kuantitas;
                            cout << PUTIH << "Masukkan Lokasi baru: " << KUNING;
                            cin.ignore();
                            getline(cin, logistik[index - 1].asal.asalTambang);
                            cout << PUTIH << "Masukkan Tanggal baru (dd-mm-yyyy): " << KUNING;
                            getline(cin, logistik[index - 1].tanggal);
                            cout << RESET;
                            cout << HIJAU << "\n[OK] " << PUTIH << "Data logistik berhasil diubah" << RESET << endl;
                        } else {
                            cout << MERAH << "[!] " << PUTIH << "Nomor data tidak valid" << RESET << endl;
                        }
                    }
                    cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                    cin.ignore(1000, '\n');
                // DELETE
                } else if (menu == 4 && users[idxLogin].isAdmin) {
                    CLEAR;
                    if (jumlahLogistik == 0) {
                        cout << MERAH << "[!] " << PUTIH << "Belum ada data logistik untuk dihapus." << RESET << endl;
                    } else {
                        cout << ABU_TERANG << "--- [" << BIRU << " HAPUS DATA " << ABU_TERANG << "] ---" << RESET << endl;
                        cout << ABU_REDUP << "====================" << RESET << endl;
                        for (int i = 0; i < jumlahLogistik; i++) {
                            cout << PUTIH << "Data ke-" << EMAS << i + 1 << endl;
                            cout << PUTIH << "ID: " << BIRU << logistik[i].idLogistik << endl;
                            cout << PUTIH << "Komoditas: " << KUNING << logistik[i].mineral.namaMineral << RESET << endl;
                            cout << endl;
                        }
                        cout << PUTIH << "Masukkan nomor data yang akan dihapus: " << KUNING;
                        int index;
                        cin >> index;
                        cout << RESET;
                        if (index > 0 && index <= jumlahLogistik) {
                            for (int i = index - 1; i < jumlahLogistik - 1; i++) {
                                logistik[i] = logistik[i + 1];
                            }
                            jumlahLogistik--;
                            cout << HIJAU << "\n[OK] " << PUTIH << "Data logistik berhasil dihapus" << RESET << endl;
                        } else {
                            cout << MERAH << "[!] " << PUTIH << "Nomor data tidak valid" << RESET << endl;
                        }
                    }
                    cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                    cin.ignore(1000, '\n');
                } else if (menu == 5 || (menu == 2 && !users[idxLogin].isAdmin)) {
                    cout << MERAH << "  Logging out... " << PUTIH << "Kembali ke menu login." << RESET << endl;
                    break; // Keluar dari menu utama, kembali ke menu login
                }
            }

            // === REGISTER ===
        } else if (autentikasi == 2) {
            CLEAR;
            cout << ABU_REDUP << "============================================================" << endl;
            cout << EMAS   << "         Sistem Logistik Mineral Pertambangan          " << endl;
            cout << PUTIH  << "                        REGISTER" << endl;
            cout << ABU_REDUP << "============================================================" << RESET << endl;
            
            if (jumlahUser >= MAX_USERS) {
                cout << MERAH << "[!] " << PUTIH << "Kapasitas user penuh. Tidak bisa mendaftar user baru." << RESET << endl;
                cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
                cin.ignore(1000, '\n');
                continue;
            }

            User userBaru;
            string username, password;
            
            while (true) {
                cout << PUTIH << "Username: " << BIRU;
                getline(cin, username);
                cout << RESET;
                if (!username.empty()) {
                    // Cek apakah username sudah ada
                    bool usernameAda = false;
                    for (int i = 0; i < jumlahUser; i++) {
                        if (users[i].username == username) {
                            usernameAda = true;
                            break;
                        }
                    }
                    if (usernameAda) {
                        cout << MERAH << "[!] " << PUTIH << "Username sudah digunakan. Silakan gunakan username lain." << RESET << endl;
                    } else {
                        break;
                    }
                } else {
                    cout << MERAH << "[!] " << PUTIH << "Input tidak boleh kosong." << RESET << endl;
                }
            }

            while (true) {
                cout << PUTIH << "Password: " << BIRU;
                getline(cin, password);
                cout << RESET;
                if (!password.empty()) break;
                cout << MERAH << "[!] " << PUTIH << "Input tidak boleh kosong." << RESET << endl;
            }

            userBaru.username = username;
            userBaru.password = password;
            userBaru.isAdmin = false; // User baru default bukan admin

            users[jumlahUser] = userBaru;
            jumlahUser++;

            cout << HIJAU << "\n[OK] " << PUTIH << "Registrasi berhasil. Silakan login dengan akun baru." << RESET << endl;
            cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
            cin.ignore(1000, '\n');

        // === KELUAR ===
        } else if (autentikasi == 3) {
            cout << MERAH << "\n  Shutting down... " << PUTIH << "Program akan keluar." << RESET << endl;
            exit(0);
        }
    }

    return 0;
}