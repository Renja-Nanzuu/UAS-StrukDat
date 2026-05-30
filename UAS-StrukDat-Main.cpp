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

void Tampilanmenu() {
    string pesan = "Selamat Datang, " + userAktif;
    cout << string(70, '=') << endl;
    CenterText(pesan,70);
    CenterText("Silahkan pilih Fitur yang ingin digunakan",70);
    cout << string(70, '=') << endl;
    cout << "1. Beli Tiket" << endl;
    cout << "2. Cek Tiket" << endl;
    cout << "3. Batalkan Tiket" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu : ";
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
                cout << "Gak ada pilihannya bang!" << endl;
                pilihLogin = 0;
                break;
        }
    }

    Tampilanmenu();

//     string username, password;

//     // data akun
//     string user[10];
//     string pass[10];

//     // akun awal
//     user[0] = "ridho";
//     pass[0] = "ridho005";

//     user[1] = "anandya";
//     pass[1] = "anandya026";

//     user[2] = "sri";
//     pass[2] = "sri014";

//     user[3] = "wildan";
//     pass[3] = "wildan069";

//     int jumlahAkun = 4;

//     int pilihAwal;

//     cout << "======================================" << endl;
//     cout << "   SISTEM PEMESANAN TIKET KERETA" << endl;
//     cout << "======================================" << endl;

//     cout << "\n1. Login" << endl;
//     cout << "2. Registrasi" << endl;
//     cout << "Pilih : ";
//     cin >> pilihAwal;

//     // REGISTRASI
//     if (pilihAwal == 2) {

//         cout << "\n===== REGISTRASI =====" << endl;

//         cout << "Buat Username : ";
//         cin >> user[jumlahAkun];

//         cout << "Buat Password : ";
//         cin >> pass[jumlahAkun];

//         jumlahAkun++;

//         cout << "\nRegistrasi berhasil!" << endl;
//     }

//     // LOGIN
//     bool login = false;

//     cout << "\n===== LOGIN =====" << endl;

//     cout << "Username : ";
//     cin >> username;

//     cout << "Password : ";
//     cin >> password;

//     for (int i = 0; i < jumlahAkun; i++) {

//         if (username == user[i] && password == pass[i]) {
//             login = true;
//         }
//     }

//     if (login == false) {
//         cout << "\nLogin gagal!" << endl;
//         return 0;
//     }

//     cout << "\nLogin berhasil!1" << endl;

//     int menu;

//     do {

//         cout << "\n========== MENU UTAMA ==========" << endl;
//         cout << "1. Beli Tiket" << endl;
//         cout << "2. Cek Tiket" << endl;
//         cout << "3. Batalkan Tiket" << endl;
//         cout << "4. Keluar" << endl;
//         cout << "Pilih menu : ";
//         cin >> menu;

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
