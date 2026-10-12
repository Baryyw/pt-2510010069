# P07 std::string dan Validasi Masukan

Folder kode Pertemuan 7 Pemrograman Terstruktur, pertemuan terakhir sebelum UTS. Program yang punya
keputusan atau perulangan berpasangan dengan flowchart di modul; dua program yang alurnya lurus
(`gabung_banding.cpp`, `getline_campur.cpp`) tidak.

## Isi

| Berkas | Kegunaan |
|---|---|
| `gabung_banding.cpp` | `+`, `==`, `<`, `.length()`, `[posisi]`: dasar-dasar string |
| `huruf_per_huruf.cpp` | for dari 0 sampai `length() - 1`: hitung kata dan vokal, balik, kapital |
| `rapikan_nama.cpp` | Huruf Besar Di Awal Kata dengan bendera `awal_kata`, `toupper`, `tolower` |
| `getline_campur.cpp` | Jebakan Enter yang tersisa setelah `cin >>`; obatnya `cin.ignore(1000, '\n')` disisipkan di praktikum |
| `input_aman.cpp` | Membaca angka dengan aman: `cin.fail()`, `cin.clear()`, `cin.ignore()`; penyembuh perulangan tanpa henti P5 |
| `validasi_nama.cpp` | do-while sampai nama sah: tidak kosong, bukan hanya spasi, tanpa angka |
| `sinilai_v06_awal.cpp` | Starter SiNilai v0.6: v0.5 utuh, lengkapi pembacaan aman dan validasi serta perapian nama |
| `contoh_masukan.txt` | Enam mahasiswa dengan masukan sengaja berantakan: nama kosong, `r2d2`, `abc`, `120` |
| `.vscode/`, `.gitignore` | Sama dengan Pertemuan 6 (termasuk `launch.json` debugger) |

## Kasus uji SiNilai v0.6 (`./sinilai_v06 < contoh_masukan.txt`)

Data mahasiswanya sama dengan Pertemuan 6, tetapi berkasnya berisi jebakan: nama ditulis
`siti AMINAH` dan `BUDI SANTOSO`, ada baris kosong sebelum nama Budi, ada nama `r2d2` sebelum Rina,
ada `abc` untuk nilai mingguan Dewi, dan `120` untuk UTS Eko. Program yang benar menolak semua jebakan
itu, meminta ulang, merapikan nama, dan menghasilkan laporan yang persis sama dengan v0.5:

| Mahasiswa (sudah dirapikan) | Nilai akhir | Huruf | Status |
|---|---|---|---|
| Siti Aminah | 83.97 | A | Lulus |
| Budi Santoso | 67.75 | C+ | Lulus |
| Rina Wati | 49.50 | D | Belum lulus |
| Dewi Lestari | 90.00 | A | Lulus |
| Eko Prasetyo | 71.00 | B | Lulus |
| Fajar Nugroho | 25.75 | E | Belum lulus |

Laporan kelas: 6 mahasiswa, 4 lulus, 2 belum lulus, rata-rata 64.66, tertinggi Dewi Lestari (90.00),
sebaran A 2, B 1, C 1, D 1, E 1.

Starter (`sinilai_v06_awal.cpp`) berjalan benar untuk masukan yang bersih, tetapi menghasilkan
laporan kacau untuk `contoh_masukan.txt`: itulah yang harus kamu perbaiki.

## Yang dikumpulkan mahasiswa

Folder `p07` di repository `pt-NPM` berisi `sinilai_v06.cpp`. Lihat Modul Pertemuan 7 bagian E.

## Deklarasi AI

Tuliskan AI yang digunakan, prompt, dan umpan balik AI
AI : Chat GPT

#Prompt : 
*// SiNilai v0.6: v0.5 yang tangguh terhadap masukan salah. Dibangun di atas v0.5 (laporan kelas).*

*// Yang baru: angka dibaca dengan aman (cin.fail, clear, ignore), nama divalidasi dan dirapikan*

*// huruf per huruf. Perhatikan: pola pembacaan aman ditulis berulang untuk empat komponen;*

*// itu sengaja, supaya di Pertemuan 9 kamu merasakan sendiri gunanya fungsi.*

\#include \<cctype>

\#include \<iomanip>

\#include \<iostream>

\#include \<string>

using namespace std;

int main()

{

    const double BOBOT_KEHADIRAN = 0.10;

    const double BOBOT_MINGGUAN = 0.45;

    const double BOBOT_UTS = 0.25;

    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;

    cout << "=== SiNilai v0.6 ===\n";

    do

    {

        cout << "Jumlah mahasiswa (paling sedikit 1): ";

        cin >> jumlah_mahasiswa;

        if (cin.fail() || jumlah_mahasiswa < 1)

        {

            cin.clear();

            cin.ignore(1000, '\n');

            jumlah_mahasiswa = 0;

        }

    } while (jumlah_mahasiswa < 1);

    *// TODO 1: do-while di atas berputar tanpa henti kalau pengguna mengetik huruf (cin gagal, isi jadi 0).*

    *//         Ganti dengan pola input_aman.cpp: baca sekali, lalu while (cin.fail() || jumlah_mahasiswa < 1)*

    *//         { cin.clear(); cin.ignore(1000, '\n'); minta lagi; }.*

    cin.ignore(1000, '\n'); *// buang Enter yang tersisa setelah angka, supaya getline nama tidak memungutnya*

    cout << fixed << setprecision(2);

    double total_nilai = 0;

    int jumlah_lulus = 0;

    int jumlah_a = 0;

    int jumlah_b = 0;

    int jumlah_c = 0;

    int jumlah_d = 0;

    int jumlah_e = 0;

    double nilai_tertinggi = -1;

    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; i++)

    {

        string nama;

        string npm;

        double kehadiran = 0;

        double mingguan = 0;

        double uts = 0;

        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i << " dari " << jumlah_mahasiswa << " ---\n";

        cout << "Nama      : ";

        getline(cin, nama);

        *// TODO 2: bungkus pembacaan nama dengan do-while seperti validasi_nama.cpp: ulangi selama nama*

        *//         kosong atau hanya spasi, atau mengandung angka. Periksa huruf per huruf dengan for.*

        do

        {

            bool valid = true;

            for (char c : nama)

            {

                if (isdigit(c))

                {

                    valid = false;

                    break;

                }

            }

            if (nama.empty() || !valid)

            {

                cout << "Nama tidak valid. Masukkan nama lagi: ";

                getline(cin, nama);

            }

            else

            {

                break;

            }

        } while (true);

        *// TODO 3: rapikan nama seperti rapikan_nama.cpp: huruf pertama tiap kata besar, sisanya kecil.*

        int panjang = nama.length();

        bool awal_kata = true;

        for (int i = 0; i < panjang; i++)

        {

            if (nama[i] == ' ')

            {

                awal_kata = true;

            }

            else if (awal_kata)

            {

                nama[i] = toupper(nama[i]);

                awal_kata = false;

            }

            else

            {

                nama[i] = tolower(nama[i]);

            }

        }

        cout << "NPM       : ";

        getline(cin, npm);

        cout << "Kehadiran : ";

        cin >> kehadiran;

        *// TODO 4: tambahkan while (cin.fail() || kehadiran < 0 || kehadiran > 100) { clear; ignore; minta lagi; }*

        while (cin.fail() || kehadiran < 0 || kehadiran > 100)

        {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Kehadiran tidak valid. Masukkan lagi: ";

            cin >> kehadiran;

        }

        cout << "Mingguan  : ";

        cin >> mingguan;

        while (cin.fail() || mingguan < 0 || mingguan > 100)

        {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Mingguan tidak valid. Masukkan lagi: ";

            cin >> mingguan;

        }

        cout << "UTS       : ";

        cin >> uts;

        while (cin.fail() || uts < 0 || uts > 100)

        {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "UTS tidak valid. Masukkan lagi: ";

            cin >> uts;

        }

        cout << "UAS       : ";

        cin >> uas;

        while (cin.fail() || uas < 0 || uas > 100)

        {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "UAS tidak valid. Masukkan lagi: ";

            cin >> uas;

        }

        *// TODO 5: ulangi pola TODO 4 untuk mingguan, uts, dan uas (ya, empat kali; catat rasanya).*

        cin.ignore(1000, '\n'); *// buang Enter setelah uas, supaya getline nama mahasiswa berikutnya bersih*

        double nilai_akhir = kehadiran \* BOBOT_KEHADIRAN + mingguan \* BOBOT_MINGGUAN + uts \* BOBOT_UTS + uas \* BOBOT_UAS;

        string huruf_mutu;

        if (nilai_akhir >= 80)

        {

            huruf_mutu = "A";

        }

        else if (nilai_akhir >= 75)

        {

            huruf_mutu = "B+";

        }

        else if (nilai_akhir >= 70)

        {

            huruf_mutu = "B";

        }

        else if (nilai_akhir >= 65)

        {

            huruf_mutu = "C+";

        }

        else if (nilai_akhir >= 60)

        {

            huruf_mutu = "C";

        }

        else if (nilai_akhir >= 40)

        {

            huruf_mutu = "D";

        }

        else

        {

            huruf_mutu = "E";

        }

        bool lulus = nilai_akhir >= 60;

        cout << "  " << left << setw(20) << nama << right << setw(7) << nilai_akhir

             << "  " << left << setw(3) << huruf_mutu;

        if (lulus)

        {

            cout << "Lulus\n";

        }

        else

        {

            cout << "Belum lulus\n";

        }

        total_nilai += nilai_akhir;

        if (lulus)

        {

            jumlah_lulus++;

        }

        switch (huruf_mutu[0])

        {

        case 'A':

            jumlah_a++;

            break;

        case 'B':

            jumlah_b++;

            break;

        case 'C':

            jumlah_c++;

            break;

        case 'D':

            jumlah_d++;

            break;

        default:

            jumlah_e++;

        }

        if (nilai_akhir > nilai_tertinggi)

        {

            nilai_tertinggi = nilai_akhir;

            nama_tertinggi = nama;

        }

    }

    cout << "\n=== Laporan Kelas ===\n";

    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";

    cout << "Lulus            : " << jumlah_lulus << "\n";

    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";

    cout << "Rata-rata kelas  : " << total_nilai / jumlah_mahasiswa << "\n";

    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";

    for (char huruf = 'A'; huruf <= 'E'; huruf++)

    {

        int banyak = 0;

        if (huruf == 'A')

        {

            banyak = jumlah_a;

        }

        else if (huruf == 'B')

        {

            banyak = jumlah_b;

        }

        else if (huruf == 'C')

        {

            banyak = jumlah_c;

        }

        else if (huruf == 'D')

        {

            banyak = jumlah_d;

        }

        else

        {

            banyak = jumlah_e;

        }

        cout << huruf << " | ";

        for (int j = 1; j <= banyak; j++)

        {

            cout << "#";

        }

        cout << " " << banyak << "\n";

    }

    return 0;

}

periksa apakah ada yang salah

# Hasil :
Saya periksa kode SiNilai v0.6 kamu. Secara umum, struktur programnya sudah benar: menghitung nilai akhir, menentukan huruf mutu, menentukan kelulusan, mencari nilai tertinggi, dan membuat laporan kelas. Namun, ada beberapa hal yang perlu diperbaiki, terutama pada validasi input dan penghitungan sebaran huruf mutu.

## 1. Kesalahan dan kekurangan yang ditemukan

1. Validasi jumlah mahasiswa — TODO 1

Kode kamu sebenarnya sudah bisa menangani input huruf karena menggunakan `cin.fail()`, `cin.clear()`, dan `cin.ignore()`. Namun, bentuknya belum mengikuti pola yang diminta pada TODO 1, yaitu membaca sekali lalu menggunakan `while`.

Perbaikannya:

C++

```
cout << "Jumlah mahasiswa (paling sedikit 1): ";
cin >> jumlah_mahasiswa;

while (cin.fail() || jumlah_mahasiswa < 1)
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Input tidak valid. Masukkan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;
}
```

Dengan pola ini, input diminta ulang sampai berupa bilangan bulat minimal 1.

2. Validasi nama — TODO 2

Kode kamu hanya memeriksa apakah nama kosong atau mengandung angka. Ada dua kekurangan:

* Nama yang berisi spasi saja masih diterima.

* Nama yang mengandung simbol seperti `@`, `#`, atau `123` dalam bentuk campuran simbol dan huruf masih bisa diterima.

Untuk memperbaiki masalah spasi, kamu bisa menggunakan `isspace()` untuk memeriksa apakah nama hanya berisi spasi. Untuk validasi yang lebih ketat, izinkan huruf, spasi, tanda hubung, dan apostrof saja.

Contoh validasi sederhana yang lebih baik:

C++

```
bool valid;

do
{
    valid = !nama.empty();
    bool ada_huruf = false;

    for (unsigned char c : nama)
    {
        if (isalpha(c))
            ada_huruf = true;

        if (isdigit(c))
            valid = false;
    }

    if (!ada_huruf)
        valid = false;

    if (!valid)
    {
        cout << "Nama tidak valid. Masukkan nama lagi: ";
        getline(cin, nama);
    }

} while (!valid);
```

Catatan: kode ini tetap mengizinkan simbol selain angka jika ada huruf dalam nama. Jika ingin validasi yang benar-benar ketat, perlu pemeriksaan karakter tambahan.

3. Merapikan nama — TODO 3

Logikanya sudah benar. Nama seperti `aKbar mUhammad` akan menjadi `Akbar Muhammad`.

Namun, penggunaan `toupper()` dan `tolower()` untuk huruf UTF-8 seperti `é` atau karakter beraksen lainnya tidak sepenuhnya didukung oleh pendekatan ini. Untuk nama biasa dengan huruf ASCII, kode kamu sudah cukup.

4. Validasi nilai kehadiran, mingguan, UTS, dan UAS — TODO 4 dan 5

Pola validasi kamu sudah benar secara umum. Akan tetapi, ketika pengguna memasukkan angka yang valid diikuti karakter lain, seperti `80abc`, `cin >> kehadiran` dapat membaca `80` sebagai angka yang valid dan meninggalkan `abc` di input.

Selain itu, input seperti `nan` atau `inf` perlu ditangani agar tidak menghasilkan nilai akhir yang tidak valid. Kamu bisa menambahkan `isfinite()` dari `<cmath>`.

Contoh:

C++

```
#include <cmath>
```

Lalu gunakan pola ini untuk setiap komponen nilai:

C++

```
cout << "Kehadiran : ";
cin >> kehadiran;

while (cin.fail() || !isfinite(kehadiran) ||
       kehadiran < 0 || kehadiran > 100)
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Kehadiran tidak valid. Masukkan lagi: ";
    cin >> kehadiran;
}
```

Ulangi pola yang sama untuk `mingguan`, `uts`, dan `uas`. Jika ingin menolak seluruh input yang mengandung karakter tambahan, gunakan pembacaan satu baris dan parsing angka secara terpisah.

5. Sebaran huruf mutu — bagian `switch`

Ini bagian yang paling perlu diperhatikan.

Kode kamu:

C++

```
switch (huruf_mutu[0])
{
case 'A':
    jumlah_a++;
    break;
case 'B':
    jumlah_b++;
    break;
case 'C':
    jumlah_c++;
    break;
case 'D':
    jumlah_d++;
    break;
default:
    jumlah_e++;
}
```

Masalahnya, nilai `B+` masuk ke `jumlah_b`, tetapi nilai `C+` masuk ke `jumlah_c`. Itu sebenarnya sesuai jika kategori laporan memang hanya A, B, C, D, dan E.

Namun, laporan kamu sekarang menampilkan `A`, `B`, `C`, `D`, `E` saja. Jadi, jika tugas meminta sebaran berdasarkan huruf mutu lengkap (`A`, `B+`, `B`, `C+`, `C`, `D`, `E`), program belum memenuhi kebutuhan tersebut.

Jika kategori memang dikelompokkan berdasarkan huruf awal, kode kamu sudah benar. Jika ingin menghitung setiap nilai mutu secara terpisah, gunakan variabel dan kondisi berdasarkan string lengkap.

6. Perhitungan nilai akhir dan status kelulusan

Bagian ini sudah benar:

C++

```
double nilai_akhir =
    kehadiran * BOBOT_KEHADIRAN +
    mingguan * BOBOT_MINGGUAN +
    uts * BOBOT_UTS +
    uas * BOBOT_UAS;

bool lulus = nilai_akhir >= 60;
```

Total bobotnya adalah 0.10+0.45+0.25+0.20=1.000.10 + 0.45 + 0.25 + 0.20 = 1.000.10+0.45+0.25+0.20=1.00, sehingga perhitungan nilai akhir sudah sesuai.

7. Kartu nilai satu baris

Kode berikut sudah sesuai dengan format yang kamu gunakan:

C++

```
cout << "  " << left << setw(20) << nama
     << right << setw(7) << nilai_akhir
     << "  " << left << setw(3) << huruf_mutu;
```

Status kelulusan juga sudah ditampilkan dengan benar setelahnya.

## 2. Catatan penting tentang laporan kelas

Perulangan berikut:

C++

```
for (char huruf = 'A'; huruf <= 'E'; huruf++)
```

akan menghasilkan kategori A sampai E. Kode ini tidak menampilkan kategori `B+` dan `C+` secara terpisah. Jika tugas meminta kategori lengkap, kamu perlu mengubah variabel penghitung dan bagian laporan kelas juga.

## 3. Kesimpulan

| Bagian                        | Status                                           |
| ----------------------------- | ------------------------------------------------ |
| Input jumlah mahasiswa        | Perlu disesuaikan dengan TODO 1                  |
| Validasi nama                 | Perlu diperketat                                 |
| Perapian nama                 | Benar untuk huruf ASCII                          |
| Validasi nilai                | Perlu menangani `nan`, `inf`, dan input campuran |
| Perhitungan nilai akhir       | Benar                                            |
| Penentuan huruf mutu          | Benar                                            |
| Penentuan kelulusan           | Benar                                            |
| Kartu nilai satu baris        | Benar                                            |
| Penghitungan sebaran huruf    | Benar jika kategori berdasarkan huruf awal       |
| Rata-rata dan nilai tertinggi | Benar untuk input nilai yang valid               |

Saran saya: karena program ini disebut v0.6 yang berfokus pada ketahanan terhadap masukan salah, prioritas utamanya adalah memastikan semua input divalidasi dengan konsisten. Setelah itu, tentukan apakah laporan sebaran huruf mutu harus mengelompokkan `B+` bersama `B` dan `C+` bersama `C`, atau menampilkan semuanya secara terpisah.
