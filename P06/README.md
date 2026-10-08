# P06 Perulangan Lanjutan: Bersarang, break, continue, Debugger, iomanip

Folder kode Pertemuan 6 Pemrograman Terstruktur. Setiap program berpasangan dengan flowchart di modul;
pada perulangan bersarang ada dua panah yang kembali, dan pada break/continue ada panah yang
"memotong jalan".

## Isi

| Berkas | Kegunaan |
|---|---|
| `bersarang_tabel.cpp` | for di dalam for: tabel perkalian dengan kolom lurus (setw) |
| `break_tebak.cpp` | break: berhenti lebih awal begitu tebakan benar, paling banyak 5 kesempatan |
| `continue_remediasi.cpp` | continue: lewati mahasiswa yang nilainya cukup, daftar hanya yang perlu remediasi |
| `rapi_iomanip.cpp` | fixed, setprecision, setw, left, right: keluaran berkolom rapi |
| `debug_rerata.cpp` | Program dengan kesalahan logika yang sengaja ditanam; dicari dengan debugger, bukan dibaca |
| `masukan_debug.txt` | Masukan untuk `debug_rerata`: 3 nilai (80, 70, 90), rata-rata yang benar 80 |
| `sinilai_v05_awal.cpp` | Starter SiNilai v0.5: v0.4 lengkap, lengkapi iomanip, penghitung huruf, tertinggi, sebaran batang |
| `contoh_masukan.txt` | Enam mahasiswa untuk menguji v0.5 |
| `.vscode/launch.json` | Konfigurasi debugger VS Code (gdb MSYS2); tekan F5 pada berkas .cpp yang terbuka |
| `.vscode/settings.json`, `tasks.json`, `.gitignore` | Sama dengan pertemuan sebelumnya |

## Kasus uji SiNilai v0.5 (`./sinilai_v05 < contoh_masukan.txt`)

| Mahasiswa | Komponen | Nilai akhir (2 desimal) | Huruf | Status |
|---|---|---|---|---|
| Siti Aminah | 100, 85.5, 78, 80 | 83.97 | A | Lulus |
| Budi Santoso | 80, 70, 65, 60 | 67.75 | C+ | Lulus |
| Rina Wati | 60, 50, 40, 55 | 49.50 | D | Belum lulus |
| Dewi Lestari | 90, 90, 90, 90 | 90.00 | A | Lulus |
| Eko Prasetyo | 75, 72, 70, 68 | 71.00 | B | Lulus |
| Fajar Nugroho | 30, 20, 35, 25 | 25.75 | E | Belum lulus |

Laporan kelas: 6 mahasiswa, 4 lulus, 2 belum lulus, rata-rata 64.66, tertinggi Dewi Lestari (90.00).
Sebaran huruf: A 2, B 1, C 1, D 1, E 1 (B+ dihitung sebagai B, C+ sebagai C).

Catatan: 83.975 tampil sebagai 83.97, bukan 83.98, karena di dalam komputer 83.975 tersimpan
sebagai 83.97499...; pembulatan mengikuti angka yang tersimpan.

## Debugger

`launch.json` memakai `C:/msys64/ucrt64/bin/gdb.exe` dan program `<nama>.exe` hasil tasks.json.
Di Linux hapus akhiran `.exe` dan ganti `miDebuggerPath` menjadi `/usr/bin/gdb`; di macOS ganti
`MIMode` menjadi `lldb` dan hapus `miDebuggerPath`. Panduan lengkap: `03_Modul/Panduan_Debugger_VS_Code.docx`.

## Yang dikumpulkan mahasiswa

Folder `p06` di repository `pt-NPM` berisi `sinilai_v05.cpp`. Lihat Modul Pertemuan 6 bagian E.

## Deklarasi AI

Tuliskan AI yang digunakan, prompt, dan umpan balik AI

# Prompt :


        *// TODO 4: ganti kartu enam baris ini dengan SATU baris berkolom:*

        *//   dua spasi, nama rata kiri selebar 20, nilai_akhir rata kanan selebar 7,*

        *//   dua spasi, huruf_mutu rata kiri selebar 3, lalu Lulus atau Belum lulus.*

        cout << "\n--- Kartu Nilai Mahasiswa ---\n";

        cout << "Nama        : " << nama << "\n";

        cout << "NPM         : " << npm << "\n";

        cout << "Nilai akhir : " << nilai_akhir << "\n";

        cout << "Huruf mutu  : " << huruf_mutu << "\n";

        if (lulus) {

            cout << "Status      : Lulus\n";

        } else {

            cout << "Status      : Belum lulus\n";

        }

maksudnya gimana ini

# Hasil 
Maksudnya, kamu diminta mengubah tampilan kartu nilai mahasiswa yang awalnya terdiri dari beberapa baris menjadi satu baris saja, dengan format kolom yang rapi menggunakan `setw()` dari library `<iomanip>`.

### 1. Contoh hasil yang diinginkan

Misalnya datanya:

* Nama: Akbar

* Nilai akhir: 85.5

* Huruf mutu: A

* Status: Lulus

Hasilnya akan seperti ini:

```
--- Kartu Nilai Mahasiswa ---
  Akbar                    85.5  A   Lulus
```

Penjelasan formatnya:

| Format                            | Maksud                                               |
| --------------------------------- | ---------------------------------------------------- |
|                                   | Dua spasi di awal                                    |
| `setw(20) << left << nama`        | Nama rata kiri dengan lebar kolom 20 karakter        |
| `setw(7) << right << nilai_akhir` | Nilai akhir rata kanan dengan lebar kolom 7 karakter |
|                                   | Dua spasi setelah nilai                              |
| `setw(3) << left << huruf_mutu`   | Huruf mutu rata kiri dengan lebar 3 karakter         |
| `Lulus` atau `Belum lulus`        | Status kelulusan                                     |

### 2. Kode C++ yang perlu kamu gunakan

Pastikan di bagian atas program ada `#include <iomanip>`.

Ganti kode kartu nilai lama kamu dengan kode berikut:

C++

```
cout << "\n--- Kartu Nilai Mahasiswa ---\n";

cout << "  "
     << left << setw(20) << nama
     << right << setw(7) << nilai_akhir
     << "  "
     << left << setw(3) << huruf_mutu;

if (lulus) {
    cout << "Lulus\n";
} else {
    cout << "Belum lulus\n";
}
```

### 3. Kenapa menggunakan `left`, `right`, dan `setw()`?

* `left` membuat teks rata kiri.

* `right` membuat angka rata kanan.

* `setw(20)` menentukan lebar kolom 20 karakter.

* `setw(7)` menentukan lebar kolom 7 karakter.

* `setw()` hanya berlaku untuk output berikutnya, sehingga perlu ditulis kembali untuk setiap kolom yang membutuhkan lebar tertentu.

Intinya: kamu tidak perlu lagi menampilkan `Nama`, `NPM`, `Nilai akhir`, `Huruf mutu`, dan `Status` pada baris terpisah. Kamu cukup menampilkan nama, nilai, huruf mutu, dan status dalam satu baris sesuai format yang diminta.
