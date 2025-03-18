#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi struct Nilai yang menyimpan berbagai variabel nilai
struct Nilai {
    float nilai_absen, nilai_tugas, nilai_uts, nilai_uas, nilai_akhir;
    char nilai_huruf, nilai_h_absen, nilai_h_tugas, nilai_h_uts, nilai_h_uas;
};

// Deklarasi struct Mahasiswa yang menyimpan data mahasiswa
// Nested struct, struct Nilai dipanggil didalam struct Mahasiswa
struct Mahasiswa {
    string NPM;
    string nama;
    Nilai nilai;
};

// function tampil menu tama
void tampilMenuUtama(){
    cout << endl;
    cout << ">>>>>>>>>>>>>>>  Universitas Singaperbangsa Karawang  <<<<<<<<<<<<<<<<<" << endl;
    cout << " |               # Sistem Manajemen Nilai Mahasiswa #                |" << endl;
    cout << " |                                                                   |" << endl;
    cout << " |     Dosen          : Asep Jamaludin, S.Si., M.Kom.                |" << endl;
    cout << " |     Asisten Dosen  : Nabila Putri Asy-Syifa                       |" << endl;
    cout << " |                                                                   |" << endl;
    cout << " |     ~~ Menu Utama :                                               |" << endl;
    cout << " |     [1] Input Data Mahasiswa                                      |" << endl;
    cout << " |     [2] Tampil Data Mahasiswa                                     |" << endl;
    cout << " |     [3] Edit Data Mahasiswa                                       |" << endl;
    cout << " |     [4] Hapus Data Mahasiswa                                      |" << endl;
    cout << " |     [5] Keluar Dari Program                                       |" << endl;
    cout << " |                                                                   |" << endl;
    cout << " |                  # jika kamu mengalami kendala #                  |" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>  Contact : 0895-1711-7162  <<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}

// function tampil data mahasiswa
void tampilDataMahasiswa (Mahasiswa mhs[], int size){
    for (int i = 0; i < size; i++){ // size = maks index array
        if (mhs[i].NPM == "" && i == 0){ // pada iterasi pertama (data pertama) jika npm kosong dan i == 0 (iterasi pertama)
            cout << "||  Belum ada Mahasiswa yang ditambahkan." << endl << endl; // maka tampil pesan
            break; // dan langsung berhenti, tidak melanjutkan for loopnya lagi
        } else if (mhs[i].NPM == "") {
            break;
        }
        cout << "   # Mahasiswa ke-" <<i+1 << " #"<< endl;
        cout << "  ______________________________________________________________________" << endl;
        cout << "(                                                                        )" << endl;
        cout << " |   UNIVERSITAS SINGAPERBANGSA KARAWANG                                |" << endl;
        cout << " |   www.unsika.ac.id                                                   |" << endl;
        cout << " | ____________________________________________________________________ |" << endl;
        cout << " |                           KARTU  HASIL  STUDI                        |" << endl;
        cout << " |                         STRUKTUR DATA  -  SMT.2                      |" << endl;
        cout << " |   "<< setw(40) << left << mhs[i].nama <<"       S1 INFORMATIKA      |" << endl;
        cout << " |   "<< setw(15) << left << mhs[i].NPM <<"                                F. ILMU KOMPUTER    |" << endl;
        cout << " |                                                                      |" << endl;
        cout << " |   Nilai Absen                |  "<<setw(5)<<left<<mhs[i].nilai.nilai_absen<<"  |  "<<mhs[i].nilai.nilai_h_absen<<"  |                       |" << endl;
        cout << " |   Nilai Tugas                |  "<<setw(5)<<left<<mhs[i].nilai.nilai_tugas<<"  |  "<<mhs[i].nilai.nilai_h_tugas<<"  |                       |" << endl;
        cout << " |   Nilai UTS                  |  "<<setw(5)<<left<<mhs[i].nilai.nilai_uts<<"  |  "<<mhs[i].nilai.nilai_h_uts<<"  |                       |" << endl;
        cout << " |   Nilai UAS                  |  "<<setw(5)<<left<<mhs[i].nilai.nilai_uas<<"  |  "<<mhs[i].nilai.nilai_h_uas<<"  |                       |" << endl;
        cout << " |  ------------------------------------------------                    |" << endl;
        cout << " |   Nilai Akhir                |  "<<setw(5)<<left<<mhs[i].nilai.nilai_akhir<<"  |  "<<mhs[i].nilai.nilai_huruf<<"  |                       |" << endl;
        cout << " |                                                                      |" << endl;
        cout << "( ______________________________________________________________________ )" << endl << endl;
    }
}

void headerInputMhs(int jumData){
    cout << endl;
    cout << ">>>>>>>>>>>>>>>  Universitas Singaperbangsa Karawang  <<<<<<<<<<<<<<<<<" << endl;
    cout << "                 # Sistem Manajemen Nilai Mahasiswa #" << endl << endl;
    cout << "                   ~~ Input Data Nilai Mahasiswa ~~" << endl;
    cout << "                         Data Mahasiswa ke-"<<jumData+1<<""<< endl << endl;
    cout << "                         ketik 0 untuk batal" << endl << endl;
}

void headerTampilMhs(){
    cout << endl;
    cout << ">>>>>>>>>>>>>>>  Universitas Singaperbangsa Karawang  <<<<<<<<<<<<<<<<<" << endl;
    cout << "                 # Sistem Manajemen Nilai Mahasiswa #" << endl << endl;
    cout << "                   ~~ Tampil Data Nilai Mahasiswa ~~" << endl << endl;
}

void headerEditMhs(){
    cout << endl;
    cout << ">>>>>>>>>>>>>>>  Universitas Singaperbangsa Karawang  <<<<<<<<<<<<<<<<<" << endl;
    cout << "                 # Sistem Manajemen Nilai Mahasiswa #" << endl << endl;
    cout << "                    ~~ Edit Data Nilai Mahasiswa ~~" << endl;
    cout << "                         ketik 0 untuk batal" << endl << endl;
}

void headerHapusMhs(){
    cout << endl;
    cout << ">>>>>>>>>>>>>>>  Universitas Singaperbangsa Karawang  <<<<<<<<<<<<<<<<<" << endl;
    cout << "                 # Sistem Manajemen Nilai Mahasiswa #" << endl << endl;
    cout << "                   ~~ Hapus Data Nilai Mahasiswa ~~" << endl;
    cout << "                         ketik 0 untuk batal" << endl << endl;
}

void headerTerimakasih(){
    cout << endl;
    cout << ">>>>>>>>>>>>>>>  Universitas Singaperbangsa Karawang  <<<<<<<<<<<<<<<<<" << endl;
    cout << "                 # Sistem Manajemen Nilai Mahasiswa #" << endl << endl;
    cout << "                 ~~ Anda Sudah Keluar Dari Program ~~" << endl << endl;
    cout << "                             Terima kasih" << endl << endl;
}

int main(){
    int size = 20;
    Mahasiswa mhs[size];
    int pilihan, index;
    int jumlah_data = 0;
    float nilai_absen, nilai_tugas, nilai_uts, nilai_uas, nilai_akhir;
    string nama, npm;
    char exit, yesorno, nilai_huruf, nilai_h_absen, nilai_h_tugas, nilai_h_uts, nilai_h_uas;
    bool backToMainMenu, tidakDitemukan = false;

    do {
        tampilMenuUtama();
        do {
            cout << "||  Masukkan Pilihan (1/2/3/4) :\n  => ";
            cin >> pilihan;
            cin.ignore();
            if (pilihan < 1 || pilihan > 5) {
                system("cls");
                tampilMenuUtama();
                cout << "Pilihan " << pilihan << " tidak tersedia!\n" << endl;
            }
        } while (pilihan < 1 || pilihan > 5);
        switch (pilihan){
            case 1:
                do {
                    system("cls");
                    jumlah_data = 0;
                    for (int i = 0; i < size; i++){
                        if (mhs[i].NPM != ""){
                            jumlah_data++;
                        } else {
                            break;
                        }
                    }
                    headerInputMhs(jumlah_data);
                    if (jumlah_data >= size) {
                        cout << "Data mahasiswa sudah penuh!\n";
                        break;
                    }
                    do {
                        cout << "||  Masukkan Nama Mahasiswa      :\n  => ";
                        getline(cin, nama);
                        if (nama == ""){
                            system("cls");
                            headerInputMhs(jumlah_data);
                            cout << "Input kosong. Mohon input nama kembali." << endl;
                        }
                    } while (nama == "");
                    if (nama == "0"){
                        system("cls");
                        backToMainMenu = true;
                        break;
                    }
                    system("cls");
                    headerInputMhs(jumlah_data);
                    cout << "||  Masukkan Nama Mahasiswa      :\n  => ";
                    cout << nama << endl << endl;
                    do {
                        cout << "||  Masukkan NPM Mahasiswa       :\n  => ";
                        getline(cin, npm);
                        if (npm == ""){
                            system("cls");
                            headerInputMhs(jumlah_data);
                            cout << "||  Masukkan Nama Mahasiswa      :\n  => ";
                            cout << nama << endl << endl;
                            cout << "Input kosong. Mohon input NPM kembali." << endl;
                        }
                    } while (npm == "");
                    if (npm == "0"){
                        system("cls");
                        backToMainMenu = true;
                        break;
                    }
                    system("cls");
                    headerInputMhs(jumlah_data);
                    cout << "||  Masukkan Nama Mahasiswa      :\n  => ";
                    cout << nama << endl << endl;
                    cout << "||  Masukkan NPM Mahasiswa       :\n  => ";
                    cout << npm << endl;

                    do {
                        cout << endl << "||  Masukkan Nilai Absen (0-100) :\n  => ";
                        cin >> nilai_absen;
                        if (nilai_absen < 0 || nilai_absen > 100){
                            cout << endl << "Nilai tidak valid. Mohon input nilai kembali.";
                        }
                    } while (nilai_absen < 0 || nilai_absen > 100);
                    do {
                        cout << endl << "||  Masukkan Nilai Tugas (0-100) :\n  => ";
                        cin >> nilai_tugas;
                        if (nilai_tugas < 0 || nilai_tugas > 100){
                            cout << endl << "Nilai tidak valid. Mohon input nilai kembali." << endl;
                        }
                    } while (nilai_tugas < 0 || nilai_tugas > 100);
                    do {
                        cout << endl << "||  Masukkan Nilai UTS (0-100) :\n  => ";
                        cin >> nilai_uts;
                        if (nilai_uts < 0 || nilai_uts > 100){
                            cout << endl << "Nilai tidak valid. Mohon input nilai kembali." << endl;
                        }
                    } while (nilai_uts < 0 || nilai_uts > 100);
                    do {
                        cout << endl << "||  Masukkan Nilai UAS (0-100) :\n  => ";
                        cin >> nilai_uas;
                        if (nilai_uas < 0 || nilai_uas > 100){
                            cout << endl << "Nilai tidak valid. Mohon input nilai kembali." << endl;
                        }
                    } while (nilai_uas < 0 || nilai_uas > 100);

                    nilai_akhir = (0.10 * nilai_absen) +
                                  (0.20 * nilai_tugas) +
                                  (0.30 * nilai_uts) +
                                  (0.40 * nilai_uas);

                    if ((nilai_akhir > 80 && nilai_akhir <= 100) ||
                        (nilai_absen > 80 && nilai_absen <= 100) ||
                        (nilai_tugas > 80 && nilai_tugas <= 100) ||
                        (nilai_uts > 80 && nilai_uts <= 100) ||
                        (nilai_uas > 80 && nilai_uas <= 100)) {
                        nilai_huruf = 'A';
                        nilai_h_absen = 'A';
                        nilai_h_tugas = 'A';
                        nilai_h_uts = 'A';
                        nilai_h_uas = 'A';
                    } else if ((nilai_akhir > 70 && nilai_akhir <= 80) ||
                               (nilai_absen > 70 && nilai_absen <= 80) ||
                               (nilai_tugas > 70 && nilai_tugas <= 80) ||
                               (nilai_uts > 70 && nilai_uts <= 80) ||
                               (nilai_uas > 70 && nilai_uas <= 80)) {
                        nilai_huruf = 'B';
                        nilai_h_absen = 'B';
                        nilai_h_tugas = 'B';
                        nilai_h_uts = 'B';
                        nilai_h_uas = 'B';
                    } else if ((nilai_akhir > 60 && nilai_akhir <= 70) ||
                               (nilai_absen > 60 && nilai_absen <= 70) ||
                               (nilai_tugas > 60 && nilai_tugas <= 70) ||
                               (nilai_uts > 60 && nilai_uts <= 70) ||
                               (nilai_uas > 60 && nilai_uas <= 70)) {
                        nilai_huruf = 'C';
                        nilai_h_absen = 'C';
                        nilai_h_tugas = 'C';
                        nilai_h_uts = 'C';
                        nilai_h_uas = 'C';
                    } else {
                        nilai_huruf = 'D';
                        nilai_h_absen = 'D';
                        nilai_h_tugas = 'D';
                        nilai_h_uts = 'D';
                        nilai_h_uas = 'D';
                    }

                    mhs[jumlah_data].nama = nama;
                    mhs[jumlah_data].NPM = npm;
                    mhs[jumlah_data].nilai = {nilai_absen, nilai_tugas, nilai_uts, nilai_uas, nilai_akhir, nilai_huruf,
                                              nilai_h_absen, nilai_h_tugas, nilai_h_uts, nilai_h_uas};

                    cout << "\nBerhasil menambahkan mahasiswa '"<< nama <<"'!" << endl << endl;
                    do {
                        cout << "Apakah ingin menambahkan mahasiswa kembali? (y/n) : ";
                        cin >> yesorno;
                        cin.ignore();
                        if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                            cout << "Input tidak valid!" << endl;
                        }
                    } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                } while (yesorno == 'Y' || yesorno == 'y');
                backToMainMenu = true;
                system("cls");
                break;
            case 2:
                system("cls");
                headerTampilMhs();
                tampilDataMahasiswa(mhs, size);
                cout << "||  Ketik '0' untuk kembali ke menu utama :\n  => ";
                do {
                    cin >> exit;
                    if (exit != '0'){
                        system("cls");
                        headerTampilMhs();
                        tampilDataMahasiswa(mhs, size);
                        cout << "Input harus '0'!" << endl;
                        cout << "||  Ketik '0' untuk kembali ke menu utama :\n  => ";
                    }
                } while (exit != '0');

                backToMainMenu = true;
                system("cls");
                break;
            case 3:
                for (int i = 0; i < size; i++){
                    if (mhs[i].NPM == "" && i == 0){
                        system("cls");
                        headerEditMhs();
                        cout << "||  Belum ada Mahasiswa yang ditambahkan." << endl << endl;
                        cout << "||  Ketik '0' untuk kembali ke menu utama :\n  => ";
                        do {
                            cin >> exit;
                            if (exit != '0'){
                                system("cls");
                                headerEditMhs();
                                cout << "||  Belum ada Mahasiswa yang ditambahkan." << endl << endl;
                                cout << "Input harus '0'!" << endl;
                                cout << "||  Ketik '0' untuk kembali ke menu utama :\n  => ";
                            }
                        } while (exit != '0');

                        backToMainMenu = true;
                        system("cls");
                        break;
                    }
                    do {
                        do {
                            system("cls");
                            headerEditMhs();
                            tidakDitemukan = false;
                            do {
                                cout << "||  Cari Mahasiswa Berdasarkan NPM     :\n  => ";
                                cin >> npm;
                                if (npm == ""){
                                    system("cls");
                                    headerEditMhs();
                                    cout << "Input kosong. Mohon input NPM kembali." << endl;
                                }
                            } while (npm == "");
                            if (npm == "0"){
                                system("cls");
                                backToMainMenu = true;
                                break;
                            }
                            for (int i = 0; i < size; i++){
                                if (npm == mhs[i].NPM){
                                    index = i;
                                    cout << endl << "  Data Mahasiswa " << npm << " Ditemukan!" << endl;
                                    tidakDitemukan = true;
                                    yesorno = 'y';
                                }
                            }
                            if (tidakDitemukan == false){
                                cout << endl << "Data Mahasiswa " << npm << " Tidak Ada!" << endl;
                                cout << "||  Ingin mencari lagi? (y/n) :\n  => ";
                                cin >> yesorno;
                            }
                        } while (tidakDitemukan == false && (yesorno == 'Y' || yesorno == 'y'));
                        if (yesorno == 'N' || yesorno == 'n'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }

                        for (int i = 0; i < 10; i++){
                            if (npm == mhs[i].NPM){
                                cout << endl;
                                cout << "  Nama Mahasiswa : " << mhs[i].nama << endl;
                                cout << "  NPM            : " << mhs[i].NPM << endl;
                                cout << "  Nilai Absen    : " << mhs[i].nilai.nilai_absen << " - " << mhs[i].nilai.nilai_h_absen << endl;
                                cout << "  Nilai Tugas    : " << mhs[i].nilai.nilai_tugas << " - " << mhs[i].nilai.nilai_h_tugas << endl;
                                cout << "  Nilai UTS      : " << mhs[i].nilai.nilai_uts << " - " << mhs[i].nilai.nilai_h_uts << endl;
                                cout << "  Nilai UAS      : " << mhs[i].nilai.nilai_uas << " - " << mhs[i].nilai.nilai_h_uas << endl;
                                cout << "  Nilai Akhir    : " << mhs[i].nilai.nilai_akhir << " - " << mhs[i].nilai.nilai_huruf << endl;
                            }
                        }

                        do {
                            cout << endl << "||  Apakah ingin mengedit nama mahasiswa? (y/n) :\n  => ";
                            cin >> yesorno;
                            cin.ignore();
                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << endl << "Input tidak valid!" << endl;
                            }
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        if (yesorno == '0'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'Y' || yesorno == 'y'){
                            do {
                                cout << "||  Masukkan Nama Mahasiswa      :\n  => ";
                                getline(cin, nama);
                                if (nama == ""){
                                    cout << endl << "Input kosong. Mohon input nama kembali." << endl;
                                }
                            } while (nama == "");
                            if (nama == "0"){
                                system("cls");
                                backToMainMenu = true;
                                break;
                            }
                        } else {
                            nama = mhs[index].nama;
                        }
                        do {
                            cout << endl << "||  Apakah ingin mengedit NPM mahasiswa? (y/n) :\n  => ";
                            cin >> yesorno;
                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << endl << "Input tidak valid!" << endl;
                            }
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        if (yesorno == '0'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'Y' || yesorno == 'y'){
                            do {
                                cout << "||  Masukkan NPM Mahasiswa       :\n  => ";
                                getline(cin, npm);
                                if (npm == ""){
                                    cout << endl << "Input kosong. Mohon input NPM kembali." << endl;
                                }
                            } while (npm == "");
                            if (npm == "0"){
                                system("cls");
                                backToMainMenu = true;
                                break;
                            }
                        } else {
                            npm = mhs[index].NPM;
                        }
                        do {
                            cout << endl << "||  Apakah ingin mengedit Nilai Absen? (y/n) :\n  => ";
                            cin >> yesorno;
                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << endl << "Input tidak valid!" << endl;
                            }
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        if (yesorno == '0'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'Y' || yesorno == 'y'){
                            do {
                                cout << "||  Masukkan Nilai Absen (0-100) :\n  => ";
                                cin >> nilai_absen;
                                if (nilai_absen < 0 || nilai_absen > 100){
                                    cout << endl << "Nilai tidak valid. Mohon input nilai kembali.";
                                }
                            } while (nilai_absen < 0 || nilai_absen > 100);
                        } else {
                            nilai_absen = mhs[index].nilai.nilai_absen;
                        }
                        do {
                            cout << endl << "||  Apakah ingin mengedit Nilai Tugas? (y/n) :\n  => ";
                            cin >> yesorno;
                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << endl << "Input tidak valid!" << endl;
                            }
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        if (yesorno == '0'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'Y' || yesorno == 'y'){
                            do {
                                cout << "||  Masukkan Nilai Tugas (0-100) :\n  => ";
                                cin >> nilai_tugas;
                                if (nilai_tugas < 0 || nilai_tugas > 100){
                                    cout << endl << "Nilai tidak valid. Mohon input nilai kembali." << endl;
                                }
                            } while (nilai_tugas < 0 || nilai_tugas > 100);
                        } else {
                            nilai_tugas = mhs[index].nilai.nilai_tugas;
                        }
                        do {
                            cout << endl << "||  Apakah ingin mengedit Nilai UTS? (y/n) :\n  => ";
                            cin >> yesorno;
                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << endl << "Input tidak valid!" << endl;
                            }
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        if (yesorno == '0'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'Y' || yesorno == 'y'){
                            do {
                                cout << "||  Masukkan Nilai UTS (0-100) :\n  => ";
                                cin >> nilai_uts;
                                if (nilai_uts < 0 || nilai_uts > 100){
                                    cout << endl << "Nilai tidak valid. Mohon input nilai kembali." << endl;
                                }
                            } while (nilai_uts < 0 || nilai_uts > 100);
                        } else {
                            nilai_uts = mhs[index].nilai.nilai_uts;
                        }
                        do {
                            cout << endl << "||  Apakah ingin mengedit Nilai UAS? (y/n) :\n  => ";
                            cin >> yesorno;
                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << endl << "Input tidak valid!" << endl;
                            }
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        if (yesorno == '0'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'Y' || yesorno == 'y'){
                            do {
                                cout << "||  Masukkan Nilai UAS (0-100) :\n  => ";
                                cin >> nilai_uas;
                                if (nilai_uas < 0 || nilai_uas > 100){
                                    cout << endl << "Nilai tidak valid. Mohon input nilai kembali." << endl;
                                }
                            } while (nilai_uas < 0 || nilai_uas > 100);
                        } else {
                            nilai_uas = mhs[index].nilai.nilai_uas;
                        }

                        nilai_akhir = (0.10 * nilai_absen) +
                                      (0.20 * nilai_tugas) +
                                      (0.30 * nilai_uts) +
                                      (0.40 * nilai_uas);

                        if ((nilai_akhir > 80 && nilai_akhir <= 100) ||
                            (nilai_absen > 80 && nilai_absen <= 100) ||
                            (nilai_tugas > 80 && nilai_tugas <= 100) ||
                            (nilai_uts > 80 && nilai_uts <= 100) ||
                            (nilai_uas > 80 && nilai_uas <= 100)) {
                            nilai_huruf = 'A';
                            nilai_h_absen = 'A';
                            nilai_h_tugas = 'A';
                            nilai_h_uts = 'A';
                            nilai_h_uas = 'A';
                        } else if ((nilai_akhir > 70 && nilai_akhir <= 80) ||
                                   (nilai_absen > 70 && nilai_absen <= 80) ||
                                   (nilai_tugas > 70 && nilai_tugas <= 80) ||
                                   (nilai_uts > 70 && nilai_uts <= 80) ||
                                   (nilai_uas > 70 && nilai_uas <= 80)) {
                            nilai_huruf = 'B';
                            nilai_h_absen = 'B';
                            nilai_h_tugas = 'B';
                            nilai_h_uts = 'B';
                            nilai_h_uas = 'B';
                        } else if ((nilai_akhir > 60 && nilai_akhir <= 70) ||
                                   (nilai_absen > 60 && nilai_absen <= 70) ||
                                   (nilai_tugas > 60 && nilai_tugas <= 70) ||
                                   (nilai_uts > 60 && nilai_uts <= 70) ||
                                   (nilai_uas > 60 && nilai_uas <= 70)) {
                            nilai_huruf = 'C';
                            nilai_h_absen = 'C';
                            nilai_h_tugas = 'C';
                            nilai_h_uts = 'C';
                            nilai_h_uas = 'C';
                        } else {
                            nilai_huruf = 'D';
                            nilai_h_absen = 'D';
                            nilai_h_tugas = 'D';
                            nilai_h_uts = 'D';
                            nilai_h_uas = 'D';
                        }

                        mhs[index].nama = nama;
                        mhs[index].NPM = npm;
                        mhs[index].nilai = {nilai_absen, nilai_tugas, nilai_uts, nilai_uas, nilai_akhir, nilai_huruf,
                                                  nilai_h_absen, nilai_h_tugas, nilai_h_uts, nilai_h_uas};

                        cout << "\nBerhasil mengedit mahasiswa '"<< npm <<"'!" << endl << endl;

                        do {
                            cout << "||  Apakah ingin mencari data kembali? (y/n):\n  => ";
                            cin >> yesorno;

                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << "Pilihan tidak valid! Mohon Input Kembali." << endl;
                            }
                            cin.ignore();
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');

                    } while (yesorno == 'y' || yesorno == 'Y');
                    backToMainMenu = true;
                    system("cls");
                    break;
                }
                backToMainMenu = true;
                system("cls");
                break;
            case 4:
                for (int i = 0; i < size; i++){
                    if (mhs[i].NPM == "" && i == 0){
                        system("cls");
                        headerHapusMhs();
                        cout << "||  Belum ada Mahasiswa yang ditambahkan." << endl << endl;
                        cout << "||  Ketik '0' untuk kembali ke menu utama :\n  => ";
                        do {
                            cin >> exit;
                            if (exit != '0'){
                                system("cls");
                                headerHapusMhs();
                                tampilDataMahasiswa(mhs, size);
                                cout << "Input harus '0'!" << endl;
                                cout << "||  Ketik '0' untuk kembali ke menu utama :\n  => ";
                            }
                        } while (exit != '0');

                        backToMainMenu = true;
                        system("cls");
                        break;
                    }
                    do {
                        do {
                            system("cls");
                            headerHapusMhs();
                            tidakDitemukan = false;
                            do {
                                cout << "||  Cari Mahasiswa Berdasarkan NPM     :\n  => ";
                                cin >> npm;
                                if (npm == ""){
                                    system("cls");
                                    headerHapusMhs();
                                    cout << "Input kosong. Mohon input NPM kembali." << endl;
                                }
                            } while (npm == "");
                            if (npm == "0"){
                                system("cls");
                                backToMainMenu = true;
                                break;
                            }
                            for (int i = 0; i < size; i++){
                                if (npm == mhs[i].NPM){
                                    index = i;
                                    nama = mhs[index].nama;
                                    cout << endl << "  Data Mahasiswa " << npm << " Ditemukan!" << endl;
                                    tidakDitemukan = true;
                                    yesorno = 'y';
                                }
                            }
                            if (tidakDitemukan == false){
                                cout << endl << "Data Mahasiswa " << npm << " Tidak Ada!" << endl;
                                cout << "||  Ingin mencari lagi? (y/n) :\n  => ";
                                cin >> yesorno;
                            }
                        } while (tidakDitemukan == false && (yesorno == 'Y' || yesorno == 'y'));
                        if (yesorno == 'N' || yesorno == 'n'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }

                        for (int i = 0; i < 10; i++){
                            if (npm == mhs[i].NPM){
                                cout << endl;
                                cout << "  Nama Mahasiswa : " << mhs[i].nama << endl;
                                cout << "  NPM            : " << mhs[i].NPM << endl;
                                cout << "  Nilai Absen    : " << mhs[i].nilai.nilai_absen << " - " << mhs[i].nilai.nilai_h_absen << endl;
                                cout << "  Nilai Tugas    : " << mhs[i].nilai.nilai_tugas << " - " << mhs[i].nilai.nilai_h_tugas << endl;
                                cout << "  Nilai UTS      : " << mhs[i].nilai.nilai_uts << " - " << mhs[i].nilai.nilai_h_uts << endl;
                                cout << "  Nilai UAS      : " << mhs[i].nilai.nilai_uas << " - " << mhs[i].nilai.nilai_h_uas << endl;
                                cout << "  Nilai Akhir    : " << mhs[i].nilai.nilai_akhir << " - " << mhs[i].nilai.nilai_huruf << endl;
                            }
                        }

                        do {
                            cout << endl << "||  Apakah anda yakin ingin menghapus data mahasiswa "<< mhs[index].nama <<"? (y/n) :\n  => ";
                            cin >> yesorno;
                            cin.ignore();
                            if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                cout << endl << "Input tidak valid!" << endl;
                            }
                        } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        if (yesorno == '0'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'N' || yesorno == 'n'){
                            system("cls");
                            backToMainMenu = true;
                            break;
                        }
                        if (yesorno == 'Y' || yesorno == 'y'){
                            // Kosongkan elemen terakhir
                            mhs[index].NPM = "";
                            mhs[index].nama = "";
                            mhs[index].nilai.nilai_absen = 0;
                            mhs[index].nilai.nilai_tugas = 0;
                            mhs[index].nilai.nilai_uts = 0;
                            mhs[index].nilai.nilai_uas = 0;
                            mhs[index].nilai.nilai_akhir = 0;
                            mhs[index].nilai.nilai_huruf = 'D';
                            mhs[index].nilai.nilai_h_absen = 'D';
                            mhs[index].nilai.nilai_h_tugas = 'D';
                            mhs[index].nilai.nilai_h_uts = 'D';
                            mhs[index].nilai.nilai_h_uas = 'D';

                            for (int i = index; i < jumlah_data; i++) {
                                mhs[i].nama = mhs[i + 1].nama;
                                mhs[i].NPM = mhs[i + 1].NPM;
                                mhs[i].nilai.nilai_absen = mhs[i + 1].nilai.nilai_absen;
                                mhs[i].nilai.nilai_tugas = mhs[i + 1].nilai.nilai_tugas;
                                mhs[i].nilai.nilai_uts = mhs[i + 1].nilai.nilai_uts;
                                mhs[i].nilai.nilai_uas = mhs[i + 1].nilai.nilai_uas;
                                mhs[i].nilai.nilai_akhir = mhs[i + 1].nilai.nilai_akhir;
                                mhs[i].nilai.nilai_huruf = mhs[i + 1].nilai.nilai_huruf;
                                mhs[i].nilai.nilai_h_absen = mhs[i + 1].nilai.nilai_h_absen;
                                mhs[i].nilai.nilai_h_tugas = mhs[i + 1].nilai.nilai_h_tugas;
                                mhs[i].nilai.nilai_h_uts = mhs[i + 1].nilai.nilai_h_uts;
                                mhs[i].nilai.nilai_h_uas = mhs[i + 1].nilai.nilai_h_uas;
                            }

                            jumlah_data--;

                            cout << "\nBerhasil menghapus data mahasiswa '"<< nama <<"'!" << endl << endl;

                            do {
                                cout << endl << "||  Apakah ingin menghapus data kembali? (y/n):\n  => ";
                                cin >> yesorno;

                                if (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N'){
                                    cout << "Pilihan tidak valid! Mohon Input Kembali." << endl;
                                }
                                cin.ignore();
                            } while (yesorno != 'y' && yesorno != 'Y' && yesorno != 'n' && yesorno != 'N');
                        }
                    } while (yesorno == 'y' || yesorno == 'Y');
                    backToMainMenu = true;
                    system("cls");
                    break;
                }
                backToMainMenu = true;
                system("cls");
                break;
            case 5:
                backToMainMenu = false;
                system("cls");
                break;
            default:
                backToMainMenu = true;
                system("cls");
                break;
        }
    } while (backToMainMenu == true);
    headerTerimakasih();

    return 0;
}
