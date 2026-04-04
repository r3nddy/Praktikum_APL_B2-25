#include <iostream>
#include <iomanip>

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
    string status;
};

const int MAX_USERS = 100;
const int MAX_LOGISTIK = 100;

void tekanEnter() {
    cout << "\n" << "    Tekan Enter untuk melanjutkan...";
    cin.ignore(1000, '\n');
}

void asciiArt() {
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
    cout << UNGU   << "  █   █ █ █ ▀█ █▄▄ █▀▄ █▀█ █▄▄" <<endl;
    cout << ABU_TERANG << "  ───────────────────────────────────────────────────" << RESET << endl;
}

void menuAdmin() {
    cout << ABU_REDUP << "\n\n=========================================================" << endl;
    cout << EMAS   <<    "|            MENU UTAMA (ADMIN)                         |" << endl;
    cout << ABU_REDUP << "=========================================================" << endl;
    cout << PUTIH  <<    "| No | Fitur Logistik                                   |" << endl;
    cout << ABU_TERANG <<"|----|--------------------------------------------------|" << endl;
    cout << PUTIH  <<    "| 1. | Tambah Data     (Create)                         |" << endl;
    cout << PUTIH  <<    "| 2. | Lihat Data      (Read)                           |" << endl;
    cout << PUTIH  <<    "| 3. | Ubah Data       (Update)                         |" << endl;
    cout << PUTIH  <<    "| 4. | Hapus Data      (Delete)                         |" << endl;
    cout << PUTIH  <<    "| 5. | Keluar ke Menu Login                             |" << endl;
    cout << ABU_REDUP << "=========================================================" << RESET << endl;
}

void menuUser() {
    cout << ABU_REDUP << "\n=========================================================" << endl;
    cout << EMAS   <<    "|                   MENU UTAMA (USER)                   |" << endl;
    cout << ABU_REDUP << "=========================================================" << endl;
    cout << PUTIH  <<    "| No | Fitur Logistik                                   |" << endl;
    cout << ABU_TERANG <<"|----|--------------------------------------------------|" << endl;
    cout << PUTIH  <<    "| 1. | Lihat Data (Read)                                |" << endl;
    cout << PUTIH  <<    "| 2. | Keluar ke Menu Login                             |" << endl;
    cout << ABU_REDUP << "=========================================================" << RESET << endl;
}

void displayDataLogistik(Logistik *logistik, int *jumlahLogistik) {
    // Header tabel: ID | Komoditas | Jenis | Satuan | Qty | Lokasi | Tanggal
    cout << left;
    cout << ABU_REDUP << "===========================================================================================================================" << endl;
    cout << EMAS      << "| " << setw(10) << "ID"
                      << "| " << setw(20) << "Komoditas"
                      << "| " << setw(15) << "Jenis"
                      << "| " << setw(8) << "Satuan"
                      << "| " << setw(10) << "Qty"
                      << "| " << setw(25) << "Lokasi"
                      << "| " << setw(20) << "Tanggal"
                      << "|" << endl;
    cout << ABU_TERANG << "---------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < *jumlahLogistik; i++) {
        Logistik *ptr = logistik + i;
        cout << PUTIH << "| " << BIRU << setw(10) << ptr->idLogistik
             << PUTIH << "| " << setw(20) << ptr->mineral.namaMineral
             << PUTIH << "| " << setw(15) << ptr->mineral.jenisMineral
             << PUTIH << "| " << setw(8) << ptr->mineral.satuan
             << PUTIH << "| " << KUNING << setw(10) << ptr->mineral.kuantitas
             << PUTIH << "| " << setw(25) << ptr->asal.asalTambang
             << PUTIH << "| " << setw(20) << ptr->tanggal
             << PUTIH << "|" << endl;
    }
    cout << ABU_REDUP << "===========================================================================================================================" << RESET << endl;
}


// ==== Auth ====

void displayMenuAuth() {
    cout << ABU_REDUP << "\n\n=========================================================" << endl;
    cout << EMAS   <<    "|           SISTEM LOGISTIK MINERAL PERTAMBANGAN        |" << endl;
    cout << ABU_REDUP << "=========================================================" << endl;
    cout << PUTIH  <<    "| No | Autentikasi                                      |" << endl;
    cout << ABU_TERANG <<"|----|--------------------------------------------------|" << endl;
    cout << PUTIH  <<    "| 1. | Login Akun                                       |" << endl;
    cout << PUTIH  <<    "| 2. | Register Akun Baru                               |" << endl;
    cout << PUTIH  <<    "| 3. | Keluar Program                                   |" << endl;
    cout << ABU_REDUP << "=========================================================" << RESET << endl;
}

// validasi input
int inputMenu(int minOpsi, int maxOpsi) {
    int opsi = 0;
    while (true) {
        cout << "\nPilih Menu: ";
        if (cin >> opsi) {
            cin.ignore(1000, '\n');
            if (opsi >= minOpsi && opsi <= maxOpsi) {
                return opsi;
            }
            cout << "[!] " << "harus 1 - 3." << endl;
        } else {
            cout << "[!] " << "input tidak valid." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

// Function Overloading: inputMenu dengan pesan custom
int inputMenu(int minOpsi, int maxOpsi, string pesan) {
    int opsi = 0;
    while (true) {
        cout << "\n" << pesan;
        if (cin >> opsi) {
            cin.ignore(1000, '\n');
            if (opsi >= minOpsi && opsi <= maxOpsi) {
                return opsi;
            }
            cout << "[!] " << "harus " << minOpsi << " - " << maxOpsi << "." << endl;
        } else {
            cout << "[!] " << "input tidak valid." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}


int login(User *users, int *jumlahUser) {
    if (*jumlahUser == 0) {
        CLEAR;
        cout << "============================================================" << endl;
        cout << "         Sistem Logistik Mineral Pertambangan          " << endl;
        cout << "                          LOGIN" << endl;
        cout << "============================================================" << endl;
        cout << "[i] " << "Belum ada user terdaftar. Silakan register dulu." << endl;
        tekanEnter();
        return -2;
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
            cout << MERAH << "[!] " << PUTIH << "Username tidak boleh kosong." << RESET << endl;
        }
        while (true) {
            cout << PUTIH << "  [>] Masuk Password: " << BIRU;
            getline(cin, password);
            cout << RESET;
            if (!password.empty()) break;
            cout << MERAH << "[!] " << PUTIH << "Password tidak boleh kosong." << RESET << endl;
        }

        for (int i = 0; i < *jumlahUser; i++) {
            User *ptrUser = users + i; // pointer arithmetic
            if (ptrUser->username == username && ptrUser->password == password) {
                idxLogin = i;
                break;
            }
        }

        if (idxLogin != -1) {
            User *ptrLogin = users + idxLogin; // pointer ke user yang login
            cout << HIJAU << "\n[OK] " << PUTIH << "Login berhasil. Selamat datang, " << BIRU << ptrLogin->username << PUTIH << "." << RESET << endl;
            tekanEnter();
            return idxLogin;
        }

        cout << MERAH << "\n[!] " << PUTIH << "Username atau Password salah." << RESET << endl;
        if (percobaan < 3) {
            tekanEnter();
        }
    }

    cout << MERAH << "\n[!] BATAS PERCOBAAN HABIS " << PUTIH << "Program akan keluar." << RESET << endl;
    return -1;
}

bool registerUser(User *users, int *jumlahUser) {
    CLEAR;
    cout << ABU_REDUP << "============================================================" << endl;
    cout << EMAS   << "         Sistem Logistik Mineral Pertambangan          " << endl;
    cout << PUTIH  << "                        REGISTER" << endl;
    cout << ABU_REDUP << "============================================================" << RESET << endl;

    if (*jumlahUser >= MAX_USERS) {
        cout << MERAH << "[!] " << PUTIH << "Kapasitas user penuh. Tidak bisa mendaftar user baru." << RESET << endl;
        tekanEnter();
        return false;
    }

    // Pointer ke slot user baru menggunakan pointer arithmetic
    User *ptrUserBaru = users + (*jumlahUser);

    string username, password;

    while (true) {
        cout << PUTIH << "Username: " << BIRU;
        getline(cin, username);
        cout << RESET;
        if (!username.empty()) {
            // Cek apakah username sudah ada
            bool usernameAda = false;
            for (int i = 0; i < *jumlahUser; i++) {

                User *ptrCek = users + i; // pointer arithmetic
                if (ptrCek->username == username) {
                    usernameAda = true;
                    break;
                }
            }
            if (usernameAda) {
                cout << MERAH << "[!] " << PUTIH << "Username sudah digunakan. Silakan gunakan Username lain." << RESET << endl;
            } else {
                break;
            }
        } else {
            cout << MERAH << "[!] " << PUTIH << "Username tidak boleh kosong." << RESET << endl;
        }
    }

    while (true) {
        cout << PUTIH << "Password: " << BIRU;
        getline(cin, password);
        cout << RESET;
        if (!password.empty()) break;
        cout << MERAH << "[!] " << PUTIH << "Password tidak boleh kosong." << RESET << endl;
    }

    // Mengisi data melalui pointer ke struct
    ptrUserBaru->username = username;
    ptrUserBaru->password = password;
    ptrUserBaru->isAdmin = false;

    // dereference pointer lalu increment
    (*jumlahUser)++;

    cout << HIJAU << "\n[OK] " << PUTIH << "Registrasi berhasil. Silakan login dengan akun baru." << RESET << endl;
    tekanEnter();
    return true;
}


void dataDummy(Logistik *logistik, int *jumlahLogistik) {
    Logistik *ptr = logistik + 0;
    ptr->idLogistik = "LOG001";
    ptr->mineral.namaMineral = "Batu Bara";
    ptr->mineral.jenisMineral = "Bituminous";
    ptr->mineral.kuantitas = 1200.0;
    ptr->mineral.satuan = "ton";
    ptr->asal.asalTambang = "Kalimantan";
    ptr->tanggal = "10-02-2025";
    ptr->status = "Delivered";
    *jumlahLogistik = 1;
}


// Fungsi Rekursif
string generateIdRekursif(Logistik *logistik, int *jumlahLogistik, int n = 1) {
    string nomorId = to_string(n);
    while (nomorId.length() < 3) nomorId = "0" + nomorId;
    string idBaru = "LOG" + nomorId;

    // Cek apakah ID sudah ada di array
    for (int i = 0; i < *jumlahLogistik; i++) {
        Logistik *ptr = logistik + i; // pointer arithmetic
        if (ptr->idLogistik == idBaru) {
            return generateIdRekursif(logistik, jumlahLogistik, n + 1); // rekursi: coba ID berikutnya
        }
    }
    return idBaru;
}

void create(Logistik *logistik, int *jumlahLogistik) {
    CLEAR;
    cout << ABU_REDUP << "============================================================" << endl;
    cout << ABU_TERANG << "--- [" << BIRU << " TAMBAH DATA " << ABU_TERANG << "] ---" << RESET << endl;
    cout << ABU_REDUP << "============================================================" << endl;

    if (*jumlahLogistik < MAX_LOGISTIK) {

        Logistik *ptrBaru = logistik + (*jumlahLogistik);

        // Auto-generate ID secara rekursif
        ptrBaru->idLogistik = generateIdRekursif(logistik, jumlahLogistik);

        cout << PUTIH << "ID Logistik           : " << TOSKA << ptrBaru->idLogistik << ABU_TERANG << " (otomatis)" << RESET << endl;

        cout << PUTIH << "Komoditas             : " << KUNING;
        getline(cin, ptrBaru->mineral.namaMineral);

        cout << PUTIH << "Jenis                 : " << KUNING;
        getline(cin, ptrBaru->mineral.jenisMineral);

        cout << PUTIH << "Satuan                : " << KUNING;
        getline(cin, ptrBaru->mineral.satuan);

        cout << PUTIH << "Qty                   : " << KUNING;
        cin >> ptrBaru->mineral.kuantitas;
        cin.ignore(1000, '\n');

        cout << PUTIH << "Lokasi                : " << KUNING;
        getline(cin, ptrBaru->asal.asalTambang);

        cout << PUTIH << "Tanggal (dd-mm-yyyy)  : " << KUNING;
        getline(cin, ptrBaru->tanggal);
        cout << RESET;

        // Pilih status
        cout << "\n" << PUTIH << "    Status Pengiriman:" << endl;
        cout << KUNING << "    [1]  Pending" << endl;
        cout << BIRU <<   "    [2]  Shipped" << endl;
        cout << HIJAU <<  "    [3] Delivered" << RESET << endl;

        int statusPilihan = inputMenu(1, 3, "Pilih Status: ");
        switch (statusPilihan) {
            case 1: ptrBaru->status = "Pending"; break;
            case 2: ptrBaru->status = "Shipped"; break;
            case 3: ptrBaru->status = "Delivered"; break;
        }

        // dereference pointer lalu increment
        (*jumlahLogistik)++;

        cout << HIJAU << "\n[OK] " << PUTIH << "Data berhasil ditambahkan!" << RESET << endl;
    } else {
        cout << MERAH << "[!] " << PUTIH << "Kapasitas data logistik penuh!" << RESET << endl;
    }

    cout << ABU_TERANG << "\nTekan Enter untuk melanjutkan..." << RESET;
    cin.ignore(1000, '\n');
}

void read(Logistik *logistik, int *jumlahLogistik) {
    CLEAR;
    cout << ABU_REDUP << "\n=========================================================" << endl;
    cout << EMAS      << "|               DAFTAR DATA LOGISTIK MINERAL            |" << endl;
    cout << ABU_REDUP << "=========================================================" << RESET << endl;

    if (*jumlahLogistik == 0) {
        cout << MERAH << "[i] " << PUTIH << "Belum ada Logistik." << RESET << endl;
    } else {
        displayDataLogistik(logistik, jumlahLogistik);
    }

    tekanEnter();
}

void update(Logistik *logistik, int *jumlahLogistik) {
    CLEAR;
    cout << ABU_REDUP << "\n=========================================================" << endl;
    cout << EMAS      << "|               UPDATE DATA LOGISTIK MINERAL            |" << endl;
    cout << ABU_REDUP << "=========================================================" << RESET << endl;

    if (*jumlahLogistik == 0) {
        cout << MERAH << "[!] " << PUTIH << "Belum ada data logistik untuk diubah." << RESET << endl;
        tekanEnter();
        return;
    }

    cout << ABU_TERANG << "--- [" << BIRU << " UBAH DATA " << ABU_TERANG << "] ---" << RESET << endl;
    cout << ABU_REDUP << "====================" << RESET << endl;

    for (int i = 0; i < *jumlahLogistik; i++) {
        Logistik *ptr = logistik + i;
        cout << PUTIH << "Data ke-" << EMAS << i + 1 << endl;
        cout << PUTIH << "ID: " << BIRU << ptr->idLogistik << endl;
        cout << PUTIH << "Komoditas: " << KUNING << ptr->mineral.namaMineral << RESET << endl;
        cout << endl;
    }

    cout << PUTIH << "Masukkan nomor data yang akan diubah: " << KUNING;
    int index;
    cin >> index;
    cin.ignore(1000, '\n');
    cout << RESET;
    if (index > 0 && index <= *jumlahLogistik) {

        // pointer arithmetic (Pointer ke elemen yang akan diubah)
        Logistik *ptrUpdate = logistik + (index - 1);

        cout << PUTIH << "Masukkan Komoditas baru: " << KUNING;
        getline(cin, ptrUpdate->mineral.namaMineral);

        cout << PUTIH << "Masukkan Jenis baru: " << KUNING;
        getline(cin, ptrUpdate->mineral.jenisMineral);

        cout << PUTIH << "Masukkan Satuan baru: " << KUNING;
        getline(cin, ptrUpdate->mineral.satuan);

        cout << PUTIH << "Masukkan Qty baru: " << KUNING;
        cin >> ptrUpdate->mineral.kuantitas;

        cout << PUTIH << "Masukkan Lokasi baru: " << KUNING;
        cin.ignore();
        getline(cin, ptrUpdate->asal.asalTambang);

        cout << PUTIH << "Masukkan Tanggal baru (dd-mm-yyyy): " << KUNING;
        getline(cin, ptrUpdate->tanggal);

        cout << "\n" << PUTIH << "    Status baru:" << endl;
        cout << KUNING << "    [1] Pending" << endl;
        cout << BIRU <<   "    [2] Shipped" << endl;
        cout << HIJAU <<  "    [3] Delivered" << RESET << endl;
        
        int statusPilihan = inputMenu(1, 3, "Pilih Status: ");
        switch (statusPilihan) {
            case 1: ptrUpdate->status = "Pending"; break;
            case 2: ptrUpdate->status = "Shipped"; break;
            case 3: ptrUpdate->status = "Delivered"; break;
        }
        cout << RESET;

        cout << HIJAU << "\n[OK] " << PUTIH << "Data logistik berhasil diubah" << RESET << endl;
    } else {
        cout << MERAH << "[!] " << PUTIH << "Nomor data tidak valid" << RESET << endl;
    }
    tekanEnter();
}

void deleteLogistik(Logistik *logistik, int *jumlahLogistik) {
    CLEAR;
    cout << ABU_REDUP << "\n=========================================================" << endl;
    cout << EMAS      << "|               DELETE DATA LOGISTIK MINERAL            |" << endl;
    cout << ABU_REDUP << "=========================================================" << RESET << endl;

    if (*jumlahLogistik == 0) {
        cout << MERAH << "[!] " << PUTIH << "Belum ada data logistik untuk dihapus." << RESET << endl;
    } else {
        cout << ABU_TERANG << "--- [" << BIRU << " HAPUS DATA " << ABU_TERANG << "] ---" << RESET << endl;
        cout << ABU_REDUP << "====================" << RESET << endl;

        for (int i = 0; i < *jumlahLogistik; i++) {

            Logistik *ptr = logistik + i; // pointer arithmetic

            cout << PUTIH << "Data ke-" << EMAS << i + 1 << endl;
            cout << PUTIH << "ID: " << BIRU << ptr->idLogistik << endl;
            cout << PUTIH << "Komoditas: " << KUNING << ptr->mineral.namaMineral << RESET << endl;
            cout << endl;
        }

        cout << PUTIH << "Masukkan nomor data yang akan dihapus: " << KUNING;
        int index;
        cin >> index;
        cin.ignore(1000, '\n');
        cout << RESET;
        if (index > 0 && index <= *jumlahLogistik) {

            // Pointer arithmetic untuk menggeser elemen array
            for (int i = index - 1; i < *jumlahLogistik - 1; i++) {
                Logistik *ptrCurrent = logistik + i;       // pointer ke elemen saat ini
                Logistik *ptrNext    = logistik + (i + 1); // pointer ke elemen selanjutnya
                *ptrCurrent = *ptrNext; // dereference: salin isi struct
            }

            (*jumlahLogistik)--; // dereference pointer lalu decrement

            cout << HIJAU << "\n[OK] " << PUTIH << "Data logistik berhasil dihapus" << RESET << endl;
        } else {
            cout << MERAH << "[!] " << PUTIH << "Nomor data tidak valid" << RESET << endl;
        }
    }
    tekanEnter();
}



void mainMenu(User *users, Logistik *logistik, int idxLogin, int *jumlahLogistik) {
    User *ptrCurrentUser = users + idxLogin;

    while (true) {
        CLEAR;
        if (ptrCurrentUser->isAdmin) { // akses struct via pointer (->)
           menuAdmin();
           int menu = inputMenu(1, 5);

           switch (menu) {
            case 1: create(logistik, jumlahLogistik); break;
            case 2: read(logistik, jumlahLogistik); break;
            case 3: update(logistik, jumlahLogistik); break;
            case 4: deleteLogistik(logistik, jumlahLogistik); break;
            case 5: return;
           }
        } else {
            menuUser();
            int menu = inputMenu(1, 2);

            switch (menu) {
                case 1: read(logistik, jumlahLogistik); break;
                case 2: return;
            }
        }
    }
}



int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(65001); 
    #endif

     // init users
    User users[MAX_USERS];
    int jumlahUser = 0;

    users[0] = {"rendy", "069", true}; // admin
    users[1] = {"rendi", "1234", false}; // user
    jumlahUser = 2;

    // init logistik
    Logistik logistik[MAX_LOGISTIK];
    int jumlahLogistik = 0;
    dataDummy(logistik, &jumlahLogistik); // init data dummy
    

    while (true) {
        CLEAR;
        asciiArt();
        displayMenuAuth();

        int auth = inputMenu(1, 3);

        if (auth == 1) {
            int idx = login(users, &jumlahUser);
            if (idx == -1) {
                exit(0);
            } else if (idx == -2) {
                continue;
            }
            mainMenu(users, logistik, idx, &jumlahLogistik);
        } else if (auth == 2) {
            registerUser(users, &jumlahUser);
        } else if (auth == 3) {
            CLEAR;
            cout << MERAH << "\n  Shutting down... " << PUTIH << "Program akan keluar." << RESET << endl;
            exit(0);
        }
    } 

    return 0;
}