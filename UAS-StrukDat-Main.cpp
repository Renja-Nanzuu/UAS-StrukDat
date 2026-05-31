#include <iostream>
#include <string>
#include <windows.h>
#define MAX_AKUN 100
using namespace std;

// Nampung Data Akun
string username[MAX_AKUN];
string password[MAX_AKUN];
int jumlahAkun = 4;

// Untuk Menampung Username yang sedang Login saat ini
string userAktif = ""; // nanti akan berubah saat berhasil login!

// Nampung Data Stasiun
struct Stasiun {
    string kode;
    string nama;
};

Stasiun stasiun[20];
int jumlahStasiun = 0;

void initStasiun() {
    stasiun[0] = {"GMR", "Gambir"};
    stasiun[1] = {"BKS", "Bekasi"};
    stasiun[2] = {"KW", "Karawang"};
    stasiun[3] = {"CRB", "Cirebon"};
    stasiun[4] = {"PWT", "Purwokerto"};
    stasiun[5] = {"YK", "Yogyakarta"};
    stasiun[6] = {"SLO", "Solo Balapan"};
    stasiun[7] = {"SMT", "Semarang Tawang"};
    stasiun[8] = {"SPT", "Surabaya Pasar Turi"};

    jumlahStasiun = 9;
}

// Nampung Data Jenis Kereta Api
struct Kereta {
    string kode;
    string namaKereta;
    int rute[20];
    int jumlahRute;
    int kursiTersedia;
};

Kereta kereta[10];
int jumlahKereta = 3;

void initKereta() {
    // KA Anggrek
    kereta[0].kode = "KA001";
    kereta[0].namaKereta = "KA Anggrek";

    kereta[0].rute[0] = 0; // Gambir
    kereta[0].rute[1] = 1; // Bekasi
    kereta[0].rute[2] = 2; // Karawang
    kereta[0].rute[3] = 3; // Cirebon
    kereta[0].rute[4] = 7; // Semarang Tawang
    kereta[0].rute[5] = 8; // Surabaya Pasar Turi
    kereta[0].jumlahRute = 6;

    // KA Taksaka
    kereta[1].kode = "KA002";
    kereta[1].namaKereta = "KA Taksaka";

    kereta[1].rute[0] = 0; // Gambir
    kereta[1].rute[1] = 1; // Bekasi
    kereta[1].rute[2] = 2; // Karawang
    kereta[1].rute[3] = 3; // Cirebon
    kereta[1].rute[4] = 4; // Purwokerto
    kereta[1].rute[5] = 5; // Yogyakarta
    kereta[1].jumlahRute = 6;

    // KA Fajar Utama Solo
    kereta[2].kode = "KA003";
    kereta[2].namaKereta = "KA Fajar Utama Solo";

    kereta[2].rute[0] = 0; // Gambir
    kereta[2].rute[1] = 1; // Bekasi
    kereta[2].rute[2] = 2; // Karawang
    kereta[2].rute[3] = 3; // Cirebon
    kereta[2].rute[4] = 4; // Purwokerto
    kereta[2].rute[5] = 6; // Solo Balapan
    kereta[2].jumlahRute = 6;
}

// Nampung Data Jadwal
struct Jadwal {
    string kodeJadwal;
    int idKereta;
    int jamBerangkat;
    int menitBerangkat;
    int jamTiba;
    int menitTiba;
    int kursiTersedia;
    bool arahPulang;
};

Jadwal jadwal[20];
int jumlahJadwal = 0;

void initJadwal() {
    jadwal[0] = {
        "JD001",
        0,
        8,0,
        17,30,
        300,
        false
    };
    jadwal[1] = {
        "JD002",
        0,
        20,0,
        5,30,
        300,
        true
    };
    jadwal[2] = {
        "JD003",
        1,
        9,0,
        15,30,
        250,
        false
    };
    jadwal[3] = {
        "JD004",
        2,
        6,0,
        14,0,
        250,
        false
    };
    jumlahJadwal = 4;
}

void OutputJadwal() {
    initKereta();
    initJadwal();
    for(int i=0; i<jumlahJadwal; i++) {
        cout << i+1 << ". "
             << kereta[jadwal[i].idKereta].namaKereta
             << " | ";

        if(jadwal[i].jamBerangkat < 10)
            cout << "0";

        cout << jadwal[i].jamBerangkat << ":";

        if(jadwal[i].menitBerangkat < 10)
            cout << "0";

        cout << jadwal[i].menitBerangkat;
        cout << endl;
    }

}

void tampilStasiun() {
    initStasiun();
    cout << string(30, '=') << endl;
    CenterText("DAFTAR STASIUN",30);
    cout << string(30, '=') << endl;
    for(int i=0; i<jumlahStasiun; i++) {
        cout << i+1
             << ". "
             << stasiun[i].nama
             << endl;
    }
}

void pilihRute(int &asal, int &tujuan) {
    cout << "\nPilih Stasiun Asal : ";
    cin >> asal;
    cout << "Pilih Stasiun Tujuan : ";
    cin >> tujuan;
    asal--;
    tujuan--;
}

void CenterText(string Teks, int width) {
    int padding = (width - Teks.length()) / 2;
    cout << string(padding, ' ') << Teks << endl;
}

void users() {
    // Akun yang sudah terdaftar:
    // username
    username[0] = "ridho";
    username[1] = "anandya";
    username[2] = "sri";
    username[3] = "wildan";

    // password
    password[0] = "ridho005";
    password[1] = "anandya026";
    password[2] = "sri014";
    password[3] = "wildan069";
}

void Register() {
    cout << "Buat Username : ";
    cin.ignore();
    getline(cin,username[jumlahAkun]);

    cout << "Buat Password : ";
    cin >> password[jumlahAkun];
    cin.ignore();
    jumlahAkun++;
}

bool login() {
    string user, pass;
    cin.ignore();
    cout << "Username : ";
    getline(cin,user);

    cout << "Password : ";
    cin >> pass;
    cin.ignore();

    for (int i = 0; i < jumlahAkun; i++) {
        if (user == username[i] && pass == password[i]) {
            userAktif = username[i];
            return true;
        }
    }

    return false;
}

void TampilanMenu() {
    cout << "1. Beli Tiket" << endl;
    cout << "2. Cek Tiket" << endl;
    cout << "3. Batalkan Tiket" << endl;
    cout << "4. Keluar" << endl;
}

int main() {
    users();
    // Loginkan dulu lee...
    int pilihLogin;
    bool LoginSelesai = false;
    bool loginBerhasil = false;
    while (!LoginSelesai) {
        cout << string(60, '=') << endl;
        CenterText("SELAMAT DATANG DI MINI KAI ACCESS!",60);
        CenterText("Silahkan Login/Register terlebih dahulu",60);
        cout << string(60, '=') << endl;
        cout << "1. Login\n2. Register" << endl;
        cout << "Pilih (1-2): ";
        cin >> pilihLogin;
        switch (pilihLogin) {
            case 1:
                system("cls");
                cout << string(30, '-') << endl;
                CenterText("Login Page",30);
                cout << string(30, '-') << endl;
                loginBerhasil = login();
                if (loginBerhasil) {
                    LoginSelesai = true;
                    cout << string(30, '-') << endl;
                    system("cls");
                } else {
                    cout << "Username atau Password Salah!" << endl;
                    cout << string(30, '-') << endl;
                    cout << "Tekankan Enter untuk kembali:";
                    cin.get();
                    system("cls");
                }
                break;
            case 2:
                system("cls");
                cout << string(30, '-') << endl;
                CenterText("Register Page",30);
                cout << string(30, '-') << endl;
                Register();
                cout << string(30, '-') << endl;
                cout << "Tekankan Enter untuk kembali:";
                cin.get();
                system("cls");
                break;
            default:
                cout << "Pilihan Tidak ada!" << endl;
                pilihLogin = 0;
                cout << "Tekankan Enter untuk input ulang:";
                cin.ignore();
                cin.get();
                system("cls");
        }
    }

    int pilihMenu;
    bool Selesai = false;

    while (!Selesai) {
        string pesan = "Selamat Datang, " + userAktif;
        cout << string(70, '=') << endl;
        CenterText(pesan,70);
        CenterText("Silahkan pilih Fitur yang ingin digunakan",70);
        cout << string(70, '=') << endl;
        TampilanMenu();
        cout << "Pilih Fitur (1-4): ";
        cin >> pilihMenu;
        switch (pilihMenu) {
            case 1:
                system("cls");
                int asal;
                int tujuan;

                tampilStasiun();
                //pilihRute(asal, tujuan);
                cout << "Tekankan Enter untuk input ulang:";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << string(70, '=') << endl;
                cout << "Terima Kasih sudah menggunakan Mini APP KAI ACCESS!\nSampai Jumpa Kembali!" << endl;
                Selesai = true;
                break;
            default:
                cout << "Pilihan Tidak ada!" << endl;
                pilihMenu = 0;
                cout << "Tekankan Enter untuk input ulang:";
                cin.ignore();
                cin.get();
                system("cls");
        }
    }
//         // BELI TIKET
//         if (menu == 1) {

//             int jenisKereta;
//             string asal, tujuan, tanggal;
//             string namaPenumpang;
//             int kursi;
//             int harga = 0;
//             int bayar;

//             cout << "\n===== PEMBELIAN TIKET =====" << endl;

//             cout << "Jenis Kereta :" << endl;
//             cout << "1. Antar Kota" << endl;
//             cout << "2. Lokal" << endl;
//             cout << "3. Whoosh" << endl;
//             cout << "Pilih : ";
//             cin >> jenisKereta;

//             if (jenisKereta < 1 || jenisKereta > 3) {
//                 cout << "Pilihan tidak tersedia!" << endl;
//                 continue;
//             }

//             cout << "\nStasiun Asal   : ";
//             cin >> asal;

//             cout << "Stasiun Tujuan : ";
//             cin >> tujuan;

//             cout << "Tanggal Berangkat : ";
//             cin >> tanggal;

//             // harga tiket
//             if (asal == "Bandung" && tujuan == "Jakarta") {
//                 harga = 150000;
//             }
//             else if (asal == "Jakarta" && tujuan == "Surabaya") {
//                 harga = 300000;
//             }
//             else if (asal == "Bandung" && tujuan == "Yogyakarta") {
//                 harga = 250000;
//             }
//             else {
//                 harga = 100000;
//             }

//             cout << "\n===== JADWAL KERETA =====" << endl;
//             cout << "Kereta tersedia sesuai tujuan" << endl;
//             cout << "Harga tiket : Rp" << harga << endl;

//             cout << "\nInput Nama Penumpang : ";
//             cin >> namaPenumpang;

//             cout << "Pilih Nomor Kursi : ";
//             cin >> kursi;

//             // pembayaran
//             cout << "\n===== PEMBAYARAN =====" << endl;
//             cout << "Total Bayar : Rp" << harga << endl;

//             cout << "Masukkan uang pembayaran : Rp";
//             cin >> bayar;

//             if (bayar >= harga) {

//                 cout << "\nPembayaran berhasil!" << endl;
//                 cout << "Kembalian : Rp" << bayar - harga << endl;

//                 cout << "\n===== TIKET BERHASIL =====" << endl;
//                 cout << "Nama Penumpang : " << namaPenumpang << endl;
//                 cout << "Asal           : " << asal << endl;
//                 cout << "Tujuan         : " << tujuan << endl;
//                 cout << "Tanggal        : " << tanggal << endl;
//                 cout << "Nomor Kursi    : " << kursi << endl;
//                 cout << "Harga Tiket    : Rp" << harga << endl;
//             }

//             else {

//                 cout << "\nSaldo / uang tidak mencukupi!" << endl;
//             }
//         }

//         // CEK TIKET
//         else if (menu == 2) {

//             cout << "\n===== CEK TIKET =====" << endl;
//             cout << "Data tiket berhasil ditampilkan" << endl;
//         }

//         // PEMBATALAN
//         else if (menu == 3) {

//             cout << "\n===== PEMBATALAN TIKET =====" << endl;
//             cout << "Tiket berhasil dibatalkan" << endl;
//             cout << "Refund sedang diproses" << endl;
//         }

//         // KELUAR
//         else if (menu == 4) {

//             cout << "\nProgram selesai." << endl;
//         }

//         else {

//             cout << "\nMenu tidak tersedia!" << endl;
//         }

//     } while (menu != 4);

     return 0;
}
