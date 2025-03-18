#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi struct untuk menyimpan data billing
struct Billing {
    string username;
    int nomor_PC;
    int jam, menit, detik, total_detik;
    int total_biaya;
};

// function void (tidak mengembalikan nilai) untuk menampilkan header program
void headerWarnet(){
    cout << endl;
    cout << "///////////////////  WELCOME TO WARNET  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "/////////////////        SACHI.NET        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl << endl;
    cout << "                ~~ Warnet ANTI PEKALONGAN ~~" << endl;
    cout << "        'Kami siap memenuhi pengalaman bermain anda'" << endl << endl;
}

// function untuk menghitung total harga billing
int hargaBilling(int jam, int menit, int detik){
    // Konversi semua waktu ke dalam detik
    int totalDetik = (jam * 3600) + (menit * 60) + detik;
    // Tarif: 30 detik = Rp. 130
    int biaya = (totalDetik / 30) * 130;

    return biaya;
}

// Tampil struk pelanggan
void strukBilling(int total_detik, Billing bill){
    cout << endl;
    cout << "  ===================== >< ====================" << endl;
    cout << "  |                 SACHI.NET                 |"<< endl;
    cout << "  =============================================" << endl;
    cout << "  |               DETAIL BILLING              |" << endl;
    cout << "  |                                           |" << endl;
    cout << "  |   "<<setw(35)<<left<<bill.username<<"     |" << endl;
    cout << "  |   PC NO."<<setw(2)<<left<<bill.nomor_PC<<"                                |" << endl;
    cout << "  |                                           |" << endl;
    cout << "  |   Rincian Billing (Rp.130/30 detik) :     |" << endl;
    cout << "  |   "<<setw(6)<<left<< to_string(bill.jam)+" jam"<<" "<<setw(8)<<left<<to_string(bill.menit)+" menit"<<" "<<setw(8)<<left<<to_string(bill.detik)+" detik"<<"                |" << endl;
    cout << "  |   "<<setw(16)<<left<< to_string(total_detik)+" detik"<<"                        |" << endl;
    cout << "  | ----------------------------------------- |" << endl;
    cout << "  |  Total Biaya :                Rp."<<setw(7)<<left<<bill.total_biaya<<"  |"<<endl;
    cout << "  =============================================" << endl;
    cout << "  |       Terima kasih telah berkunjung       |"<< endl;
    cout << "  ===================== >< ====================" << endl;
}

int main(){
    Billing bill;
    headerWarnet();

    cout << "||  Ketik Username Anda :\n  => ";
    getline(cin, bill.username);

    // Menampilkan layout Nomor PC
    cout << "                      KANTIN" << endl;
    cout << "--      --------------------------------------------" << endl;
    cout << " |                     |         KASIR" << endl;
    cout << " | Pintu Masuk         |_______________________|" << endl;
    cout << " |" << endl;

    // tampil total PC (50 PC dalam format 5x10)
    int seatNumber = 1;
    cout << "    ";
    for (int j = 0; j < 50; j++) {
        // Menampilkan nomor kursi dengan format 2 digit
        cout << "[" << (seatNumber < 10 ? "0" : "") << seatNumber << "] ";
        seatNumber++;

        // Ganti baris setiap 10 kursi
        if ((j + 1) % 10 == 0) {
            cout << endl << "    ";
        }
        // Tambahkan tab setelah 5 kursi untuk pemisahan visual
        else if ((j + 1) % 5 == 0) {
            cout << "\t";
        }
    }

    cout << endl << "||  Pilih Nomor PC :\n  => ";
    cin >> bill.nomor_PC;

    // Validasi input jam
    do {
        cout <<endl<< "||  Input jam (angka) :\n  => ";
        cin >> bill.jam;

        if (bill.jam < 0 || bill.jam > 24) {
            cout <<endl<< "!! Jam harus antara 0 - 24. Silakan coba lagi.";
        }
    } while (bill.jam < 0 || bill.jam > 24);

    // Validasi input menit
    do {
        cout <<endl<< "||  Input menit (angka) :\n  => ";
        cin >> bill.menit;

        if (bill.menit < 0 || bill.menit >= 60) {
            cout <<endl<< "!! Menit harus antara 0 - 59. Silakan coba lagi.";
        }
    } while (bill.menit < 0 || bill.menit >= 60);

    // Validasi input detik
    do {
        cout <<endl<< "||  Input detik (angka) :\n  => ";
        cin >> bill.detik;

        if (bill.detik < 0 || bill.detik >= 60) {
            cout <<endl<< "!! Detik harus antara 0 - 59. Silakan coba lagi.";
        }
    } while (bill.detik < 0 || bill.detik >= 60);

    bill.total_biaya = hargaBilling(bill.jam, bill.menit, bill.detik);
    int totalDetik = (bill.jam * 3600) + (bill.menit * 60) + bill.detik;

    // memanggil function strukBilling
    strukBilling(totalDetik, bill);

    return 0;
}
