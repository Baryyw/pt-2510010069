// UTS Praktikum Paket A: Parkir Kampus.
// Lengkapi TODO 1 sampai TODO 6 sesuai lembar soal. Bagian yang sudah ada jangan diubah kecuali diminta.
// Bangun dengan baseline kelas; program harus bebas warning. Uji dengan: ./parkir < contoh_masukan.txt
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
const int TARIF_AWAL_MOTOR = 2000;
const int TARIF_LANJUT_MOTOR = 1000;
const int MAKS_MOTOR = 10000;
const int TARIF_AWAL_MOBIL = 5000;
const int TARIF_LANJUT_MOBIL = 3000;
const int MAKS_MOBIL = 30000;

int jumlah = 0;
cout << "=== Parkir Kampus ===\n";
cout << "Jumlah kendaraan: ";
cin >> jumlah;
while (cin.fail() || jumlah < 1) {           // contoh pembacaan aman; pakai pola ini untuk durasi
cin.clear();
cin.ignore(1000, '\n');
cout << "Harus bilangan bulat paling sedikit 1. Jumlah kendaraan: ";
cin >> jumlah;
    }
cin.ignore(1000, '\n');

cout << fixed << setprecision(2);

int total = 0;
int banyak_motor = 0;
int banyak_mobil = 0;
    // TODO 5a: deklarasikan penampung biaya tertinggi (mulai -1) dan plat pemiliknya.
int biaya_tertinggi = -1;
string plat_tertinggi;

for (int i = 1; i <= jumlah; i++) {
string plat;
char jenis = ' ';
int durasi = 0;

cout << "\n--- Kendaraan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1: baca plat dengan getline sampai sah (tidak kosong dan bukan hanya spasi),
        //         lalu ubah semua hurufnya menjadi huruf besar. Pesan penolakan: "Plat tidak boleh kosong."
cout << "Plat nomor : ";
getline(cin, plat);
bool plat_sah = false;
while (!plat_sah) {
    for (size_t k = 0; k < plat.size(); k++) {
        if (!isspace(plat[k])) {
            plat_sah = true;
        }
    }
    if (!plat_sah) {
        cout << "Plat tidak boleh kosong. Plat nomor : ";
        getline(cin, plat);
    }
}
for (size_t k = 0; k < plat.size(); k++) {
    plat[k] = toupper(plat[k]);
}

        // TODO 2: baca jenis (char), jadikan huruf besar, ulangi selama bukan 'M' atau 'R'.
        //         Pesan penolakan: "Hanya M (motor) atau R (roda empat). Jenis (M/R): "
cout << "Jenis (M/R): ";
cin >> jenis;
jenis = toupper(jenis);
while (jenis != 'M' && jenis != 'R') {
    cout << "Hanya M (motor) atau R (roda empat). Jenis (M/R): ";
    cin >> jenis;
    jenis = toupper(jenis);
}

        // TODO 3: baca durasi dengan aman (bilangan bulat 1 sampai 24), pola seperti jumlah di atas.
        //         Pesan penolakan: "Harus bilangan bulat 1 sampai 24. Durasi (jam): "
cout << "Durasi (jam, 1-24): ";
cin >> durasi;
while (cin.fail() || durasi < 1 || durasi > 24) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Harus bilangan bulat 1 sampai 24. Durasi (jam): ";
    cin >> durasi;
}
cin.ignore(1000, '\n');

        // TODO 4: hitung biaya dan tentukan nama_jenis ("Motor" atau "Mobil"):
        //         biaya = tarif awal + (durasi - 1) * tarif lanjut, lalu dibatasi tarif maksimum jenisnya.
        //         Tambah banyak_motor atau banyak_mobil.
int biaya = 0;
string nama_jenis;
if (jenis == 'M') {
    biaya = TARIF_AWAL_MOTOR + (durasi - 1) * TARIF_LANJUT_MOTOR;
    if (biaya > MAKS_MOTOR) {
        biaya = MAKS_MOTOR;
    }
    nama_jenis = "Motor";
    banyak_motor++;
} else {
    biaya = TARIF_AWAL_MOBIL + (durasi - 1) * TARIF_LANJUT_MOBIL;
    if (biaya > MAKS_MOBIL) {
        biaya = MAKS_MOBIL;
    }
    nama_jenis = "Mobil";
    banyak_mobil++;
}

cout << "  " << left << setw(12) << plat << setw(8) << nama_jenis
<< right << setw(4) << durasi << " jam" << setw(9) << biaya << "\n";

total += biaya;
        // TODO 5b: perbarui biaya tertinggi dan plat pemiliknya bila biaya ini lebih tinggi.
if (biaya > biaya_tertinggi) {
    biaya_tertinggi = biaya;
    plat_tertinggi = plat;
}
    }

cout << "\n=== Rekap Hari Ini ===\n";
cout << "Jumlah kendaraan : " << jumlah << "\n";
cout << "Motor            : " << banyak_motor << "\n";
cout << "Mobil            : " << banyak_mobil << "\n";
cout << "Total pendapatan : " << total << "\n";
cout << "Rata-rata biaya  : " << static_cast<double>(total) / jumlah << "\n";
    // TODO 5c: cetak "Tertinggi        : " diikuti plat dan biaya tertinggi dalam kurung.
cout << "Tertinggi        : " << plat_tertinggi << " (" << biaya_tertinggi << ")\n";

cout << "\nSebaran jenis:\n";
    // TODO 6: dua baris batang, satu untuk Motor dan satu untuk Mobil, memakai perulangan bersarang:
    //         perulangan luar memilih label dan jumlahnya, perulangan dalam mencetak tanda # sebanyak itu.
    //         Format tiap baris: label rata kiri selebar 6, lalu "| ", batang, spasi, jumlah. Contoh: "Motor | ## 2"
for (int baris = 0; baris < 2; baris++) {
    string label = (baris == 0) ? "Motor" : "Mobil";
    int banyak = (baris == 0) ? banyak_motor : banyak_mobil;
    cout << left << setw(6) << label << "| ";
    for (int k = 0; k < banyak; k++) {
        cout << '#';
    }
    cout << " " << banyak << "\n";
}

return 0;
}