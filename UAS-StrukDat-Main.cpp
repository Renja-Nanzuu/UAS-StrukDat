#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>
#define MAX_AKUN 100
using namespace std;

// Anggap Aja Saldo bawaan APPS nya:
int saldo = 1000000;

// Nampung Data Akun
string username[MAX_AKUN];
string password[MAX_AKUN];
int jumlahAkun = 4;

// Untuk Menampung Username yang sedang Login saat ini
string userAktif = ""; // nanti akan berubah saat berhasil login!

// Untuk Centering Text
void CenterText(string Teks, int width) {
    int padding = (width - Teks.length()) / 2;
    cout << string(padding, ' ') << Teks << endl;
}

// Nampung Users yang sudah ada
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

// Registerr
void Register() {
    if(jumlahAkun >= MAX_AKUN) {
        cout << "Kapasitas akun penuh!\n";
        return;
    }

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
    kereta[0].kursiTersedia = 250;

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
    kereta[1].kursiTersedia = 250;

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
    kereta[2].kursiTersedia = 200;
}

// Nampung Data Penumpang
struct Penumpang {
    string nama;
    string nik;
};

// Nampung Data Tiket
struct Tiket {
    string kodeBooking;
    string usernamePemesan;
    int idKereta;
    int asal;
    int tujuan;
    Penumpang penumpang[4];
    int jumlahPenumpang;
    int totalHarga;
};

Tiket tiket[100];
int jumlahTiket = 0;

void tampilStasiun() {
    cout << string(30, '=') << endl;
    CenterText("DAFTAR STASIUN",30);
    cout << string(30, '=') << endl;
    for(int i=0; i<jumlahStasiun; i++) {
        cout << i+1
             << ". "
             << stasiun[i].nama
             << endl;
    }
    cout << string(30, '=') << endl;
}

void pilihRute(int &asal, int &tujuan) {
    do {
        tampilStasiun();

        cout << "Pilih Stasiun Asal (angka): ";
        cin >> asal;

        cout << "Pilih Stasiun Tujuan (angka): ";
        cin >> tujuan;

        if(asal < 1 || asal > jumlahStasiun || tujuan < 1 || tujuan > jumlahStasiun) {
            cout << "Stasiun tidak valid!\n";
            cout << "Tekankan Enter untuk input ulang:";
            cin.ignore();
            cin.get();
            cout << "\nMohon tunggu...";
            Sleep(250);
            system("cls");
            continue;
        }

        if(asal == tujuan) {
            cout << "Asal dan tujuan tidak boleh sama!\n";
            cout << "Tekankan Enter untuk input ulang:";
            cin.ignore();
            cin.get();
            cout << "\nMohon tunggu...";
            Sleep(250);
            system("cls");
        }

    } while(asal == tujuan || asal < 1 || asal > jumlahStasiun || tujuan < 1 || tujuan > jumlahStasiun);

    asal--;
    tujuan--;

    cout << "Sedang mencari kereta yang tersedia, mohon tunggu..." << endl;
    Sleep(1500);
}

void tampilKeretaTersedia(int asal, int tujuan) {
    int nomor = 1;

    cout << string(30, '=') << endl;
    cout << "Kereta yang tersedia:\n";
    cout << string(30, '=') << endl;

    for(int i = 0; i < jumlahKereta; i++) {
        int posisiAsal = -1;
        int posisiTujuan = -1;

        for(int j = 0; j < kereta[i].jumlahRute; j++) {
            if(kereta[i].rute[j] == asal) {
                posisiAsal = j;
            }
            if(kereta[i].rute[j] == tujuan) {
                posisiTujuan = j;
            }
        }

        if(posisiAsal != -1 && posisiTujuan != -1 && posisiAsal < posisiTujuan) {
            cout << "[" << nomor << "] " << kereta[i].namaKereta << endl;
            nomor++;
        }
    }
}

int CariDanPilihKereta(int asal, int tujuan) {
    int pilihan;
    int mapping[10];
    int nomor = 1;

    cout << string(30, '=') << endl;
    cout << "Kereta yang tersedia:\n";
    cout << string(30, '=') << endl;

    for(int i = 0; i < jumlahKereta; i++) {
        int posisiAsal = -1;
        int posisiTujuan = -1;

        for(int j = 0; j < kereta[i].jumlahRute; j++) {
            if(kereta[i].rute[j] == asal) {
                posisiAsal = j;
            }
            if(kereta[i].rute[j] == tujuan) {
                posisiTujuan = j;
            }
        }

        if(posisiAsal != -1 && posisiTujuan != -1 && posisiAsal < posisiTujuan) {
            cout << "[" << nomor << "] " << kereta[i].namaKereta << endl;
            mapping[nomor] = i;
            nomor++;
        }
    }

    if(asal > tujuan) {
        cout << "Untuk saat ini perjalanan arah balik belum tersedia!\n\n";
    }

    if(nomor == 1) {
        cout << "Tidak ada kereta yang melayani rute:\n" << stasiun[asal].nama<< " -> " << stasiun[tujuan].nama << "!\n";
        cout << string(30, '=') << endl;
        return -1;
    }

    cout << string(30, '=') << endl;

    do {
        cout << "\nPilih Kereta (angka): ";
        cin >> pilihan;

        if(pilihan < 1 || pilihan >= nomor) {
            cout << "Pilihan tidak valid!\n";
            cout << "Tekankan Enter untuk input ulang:";
            cin.ignore();
            cin.get();
            cout << "\nMohon tunggu...";
            Sleep(250);
            system("cls");
            tampilKeretaTersedia(asal, tujuan);
            cout << string(30, '=') << endl;
        }
    } while(pilihan < 1 || pilihan >= nomor);

    return mapping[pilihan];
}

int hitungHarga (int asal, int tujuan) {
    int selisih = abs(tujuan - asal);
    return selisih * 50000;
}

int totalHarga (int asal, int tujuan, int jumlahPenumpang) {
    int hargaPerOrang = hitungHarga(asal, tujuan);

    int hargaTotal = hargaPerOrang * jumlahPenumpang;
    return hargaTotal;
}

bool inputPenumpang(int idKereta, int asal, int tujuan) {
    if(jumlahTiket >= 100) {
        cout << "Penyimpanan tiket penuh!\n";
        return false;
    }
    int jumlahPenumpang = 0;

    tiket[jumlahTiket].kodeBooking = "KAI" + to_string(100 + jumlahTiket);
    tiket[jumlahTiket].idKereta = idKereta;
    tiket[jumlahTiket].asal = asal;
    tiket[jumlahTiket].tujuan = tujuan;
    tiket[jumlahTiket].usernamePemesan = userAktif;

    do {
        cout << string(50, '=') << endl;
        CenterText("INPUT DATA PENUMPANG",50);
        cout << string(50, '=') << endl;
        cout << "Input Jumlah Penumpang (1-4): ";
        cin >> jumlahPenumpang;

        if(jumlahPenumpang < 1 || jumlahPenumpang > 4) {
            cout << string(50, '=') << endl;
            cout << "Jumlah tidak valid!\n";
            cout << "Tekankan Enter untuk input ulang:";
            cin.ignore();
            cin.get();
            cout << "\nMohon tunggu...";
            Sleep(250);
            system("cls");
        }
    } while(jumlahPenumpang < 1 || jumlahPenumpang > 4);

    if(jumlahPenumpang > kereta[idKereta].kursiTersedia) {
        cout << string(50, '=') << endl;
        cout << "Kursi tidak cukup!\n";
        return false;
    }

    tiket[jumlahTiket].jumlahPenumpang = jumlahPenumpang;
    cin.ignore();

    for(int i = 0; i < jumlahPenumpang; i++) {
        cout << "\nPenumpang " << i+1 << endl;

        do {
            cout << "Nama : ";
            getline(cin, tiket[jumlahTiket].penumpang[i].nama);

            if(tiket[jumlahTiket].penumpang[i].nama.empty()) {
                cout << "Nama tidak boleh kosong!\n";
            }

        } while(tiket[jumlahTiket].penumpang[i].nama.empty());

        do {
            cout << "NIK : ";
            getline(cin,tiket[jumlahTiket].penumpang[i].nik);

            if(tiket[jumlahTiket].penumpang[i].nik.empty()) {
                cout << "NIK tidak boleh kosong!\n";
            }
        } while(tiket[jumlahTiket].penumpang[i].nik.empty());
    }

    cout << string(50, '=') << endl;
    tiket[jumlahTiket].totalHarga = totalHarga(asal, tujuan, jumlahPenumpang);
    return true;
}

void pembayaran(int idKereta) {
    cout << "Total Harga: " << tiket[jumlahTiket].totalHarga << endl;
    cout << string(50, '=') << endl;
    cout << "Tekankan Enter untuk Lanjut ke Pembayaran:";
    cin.get();
    cout << "\nMohon tunggu...";
    Sleep(250);
    system("cls");

    cout << string(50, '=') << endl;
    CenterText("PEMBAYARAN",50);
    cout << string(50, '=') << endl;
    cout << "Total Harga: " << tiket[jumlahTiket].totalHarga << endl;
    cout << "Saldo yang anda miliki: " << saldo << endl;
    cout << "Validasi Saldo... Mohon tunggu" << endl;
    Sleep(1500);
    if (saldo >= tiket[jumlahTiket].totalHarga) {
        cout << "\nSaldo Mencukupi! Pembayaran diproses" << endl;
        saldo -= tiket[jumlahTiket].totalHarga;
        kereta[idKereta].kursiTersedia -= tiket[jumlahTiket].jumlahPenumpang;
        jumlahTiket++;
        Sleep(2000);
        cout << "Pembayaran Berhasil!\nSaldo anda sekarang: " << saldo << endl;
        cout << string(50, '=') << endl;
    } else {
        cout << "\nSaldo Tidak Mencukupi!" << endl;
        cout << string(50, '=') << endl;
        return;
    }
}

void cekTiket() {
    bool ditemukan = false;
    int nomorTiket = 1;
    cout << string(50, '=') << endl;
    CenterText("DAFTAR TIKET",50);
    cout << string(50, '=') << endl;

    for(int i = 0; i < jumlahTiket; i++) {
        if(tiket[i].usernamePemesan == userAktif) {
            if (nomorTiket > 1) {
                cout << string(50, '-') << endl;
            }
            cout << "Tiket ke-" << i+1 << endl;
            cout << "Kode Booking : " << tiket[i].kodeBooking << endl;
            cout << "Kereta       : " << kereta[tiket[i].idKereta].namaKereta << endl;
            cout << "Rute         : " << stasiun[tiket[i].asal].nama << " -> " << stasiun[tiket[i].tujuan].nama<< endl;
            cout << "Penumpang    : " << tiket[i].jumlahPenumpang << " Orang" << endl;
            cout << "Total Harga  : " << tiket[i].totalHarga << endl;

            ditemukan = true;
            nomorTiket++;
        }
    }

    if(!ditemukan) {
        cout << "Belum ada tiket yang dipesan.\n";
    }

    cout << string(50, '=') << endl;
}

void batalkanTiket() {

    int daftar[100];
    int nomor = 1;

    cout << string(50, '=') << endl;
    CenterText("BATALKAN TIKET",50);
    cout << string(50, '=') << endl;

    for(int i = 0; i < jumlahTiket; i++) {

        if(tiket[i].usernamePemesan == userAktif) {
            cout << "[" << nomor << "] " << tiket[i].kodeBooking << endl;
            daftar[nomor] = i;
            nomor++;
        }
    }

    if(nomor == 1) {
        cout << "Tidak ada tiket yang bisa dibatalkan.\n";
        cout << string(50, '=') << endl;
        return;
    }

    int pilih;
    do {
        cout << "\nPilih tiket yang ingin dibatalkan (angka): ";
        cin >> pilih;

        if(pilih < 1 || pilih >= nomor) {
            cout << "Pilihan tidak valid!\n";
            cout << "Tekankan Enter untuk input ulang:";
            cin.ignore();
            cin.get();
            cout << "\nMohon tunggu...";
            Sleep(250);
            system("cls");
        }
    } while(pilih < 1 || pilih >= nomor);

    char yakin;

    cout << "Yakin ingin membatalkan tiket ini? (Y/T): ";
    cin >> yakin;
    if(yakin == 'Y' || yakin == 'y') {
        cout << "Tiket akan dibatalkan dalam: " << endl;
        for(int i = 3; i >= 1; i--) {
            cout << i << "...\n";
            Sleep(900);
        }
        cout << endl;
        cout << "Memproses pembatalan";
        for(int i = 0; i < 3; i++) {
            cout << ".";
            Sleep(300);
        }
        cout << endl;
        int idx = daftar[pilih];
        saldo += tiket[idx].totalHarga;
        kereta[tiket[idx].idKereta].kursiTersedia += tiket[idx].jumlahPenumpang;

        for(int i = idx; i < jumlahTiket - 1; i++) {
            tiket[i] = tiket[i + 1];
        }

        jumlahTiket--;

        cout << "Tiket berhasil dibatalkan!\n";
        cout << string(50, '=') << endl;
    } else {
        cout << "Tiket yang sudah terpesan tidak Jadi Dibatalkan!" << endl;
        cout << string(50, '=') << endl;
        return;
    }
}

int main() {
    users();
    initStasiun();
    initKereta();
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
        cout << string(60, '=') << endl;
        cout << "Pilih (1-2): ";
        cin >> pilihLogin;
        cout << "\nMohon tunggu...";
        Sleep(250);
        switch (pilihLogin) {
            case 1:
                system("cls");
                cout << string(30, '=') << endl;
                CenterText("Login Page",30);
                cout << string(30, '=') << endl;
                loginBerhasil = login();
                if (loginBerhasil) {
                    LoginSelesai = true;
                    cout << string(30, '=') << endl;
                    cout << "Login Berhasil! Mohon tunggu.." << endl;
                    Sleep(1000);
                    system("cls");
                } else {
                    cout << string(30, '=') << endl;
                    cout << "Username atau Password Salah!" << endl;
                    cout << "Tekankan Enter untuk kembali:";
                    cin.get();
                    cout << "\nMohon tunggu...";
                    Sleep(250);
                    system("cls");
                }
                break;
            case 2:
                system("cls");
                cout << string(30, '=') << endl;
                CenterText("Register Page",30);
                cout << string(30, '=') << endl;
                Register();
                cout << string(30, '=') << endl;
                cout << "Tekankan Enter untuk kembali:";
                cin.get();
                cout << "\nMohon tunggu...";
                Sleep(250);
                system("cls");
                break;
            default:
                cout << "\nPilihan Tidak ada!" << endl;
                pilihLogin = 0;
                cout << "Tekankan Enter untuk input ulang:";
                cin.ignore();
                cin.get();
                cout << "\nMohon tunggu...";
                Sleep(250);
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
        cout << "Saldo kamu saat ini: " << saldo << endl;
        cout << string(70, '=') << endl;
        TampilanMenu();
        cout << string(70, '=') << endl;
        cout << "Pilih Fitur (1-4): ";
        cin >> pilihMenu;
        cout << "\nMohon tunggu...";
        Sleep(250);
        switch (pilihMenu) {
            case 1: {
                system("cls");
                int asal;
                int tujuan;
                pilihRute(asal, tujuan);
                system("cls");
                int idKereta = CariDanPilihKereta(asal, tujuan);
                if(idKereta == -1) {
                    cout << "Tekan Enter untuk kembali...";
                    cin.ignore();
                    cin.get();
                    cout << "\nMohon tunggu...";
                    Sleep(250);
                    system("cls");
                    break;
                }
                cout << "\nMohon tunggu...";
                Sleep(250);
                system("cls");
                if(inputPenumpang(idKereta, asal, tujuan))
                {
                    pembayaran(idKereta);
                } else {
                    cout << "Pembelian dibatalkan!" << endl;
                }
                cout << "Tekankan Enter untuk kembali:";
                cin.get();
                cout << "\nMohon tunggu...";
                Sleep(250);
                system("cls");
                break;
            }
            case 2:
                system("cls");
                cekTiket();
                cin.ignore();
                cout << "Tekankan Enter untuk kembali:";
                cin.get();
                cout << "\nMohon tunggu...";
                Sleep(250);
                system("cls");
                break;
            case 3:
                system("cls");
                batalkanTiket();
                cin.ignore();
                cout << "Tekankan Enter untuk kembali:";
                cin.get();
                cout << "\nMohon tunggu...";
                Sleep(250);
                system("cls");
                break;
            case 4: {
                system("cls");
                cout << string(70, '=') << endl;
                CenterText("Terima Kasih sudah menggunakan Mini APP KAI ACCESS!",70);
                CenterText("Sampai Jumpa Kembali!",70);
                cout << string(70, '=') << endl;
                Selesai = true;
                break;
            }
            default:
                cout << "Pilihan Tidak ada!" << endl;
                pilihMenu = 0;
                cout << "Tekankan Enter untuk input ulang:";
                cin.ignore();
                cin.get();
                system("cls");
        }
    }
    return 0;
}
